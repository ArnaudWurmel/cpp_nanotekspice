//
// Parser.cpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:25:47 2017 Arnaud WURMEL
// Last update Sun Mar  5 20:53:00 2017 Arnaud WURMEL
//

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
#include "IParser.hpp"
#include "Parser.hpp"
#include "Helper.hpp"
#include "Errors.hpp"

/*
** Ctor
*/
nts::Parser::Parser()
{
  _input = "";
  _chipset["input"] = true;
  _chipset["output"] = true;
  _chipset["false"] = true;
  _chipset["true"] = true;
  _chipset["clock"] = true;
  _chipset["4001"] = true;
  _chipset["4008"] = true;
  _chipset["4011"] = true;
  _chipset["4013"] = true;
  _chipset["4017"] = true;
  _chipset["4030"] = true;
  _chipset["4040"] = true;
  _chipset["4069"] = true;
  _chipset["4071"] = true;
  _chipset["4081"] = true;
  _chipset["4094"] = true;
  _chipset["4514"] = true;
  _chipset["4801"] = true;
  _chipset["2716"] = true;
}

/*
** Dtor
*/
nts::Parser::~Parser()
{

}

/*
** Feed the input string
*/
void	nts::Parser::feed(std::string const& input)
{
  _input += input;
}

/*
** Regroup different section together, throw a Errors if failed
*/
void	nts::Parser::regroupSection(nts::t_ast_node& root) const
{
  std::vector<nts::t_ast_node *>::iterator	it;
  std::vector<nts::t_ast_node *>::iterator	tmp;
  

  it = root.children->begin();
  while (it != root.children->end())
    {
      if ((*it)->type != nts::ASTNodeType::SECTION)
	throw Errors(DEF_OUTSIDE);
      tmp = it;
      ++tmp;
      while (tmp != root.children->end())
	{
	  if ((*it)->value.compare((*tmp)->value) == 0)
	    {
	      (*it)->children->insert((*it)->children->end(), (*tmp)->children->begin(),
				      (*tmp)->children->end());
	      tmp = root.children->erase(tmp);
	    }
	  else
	    ++tmp;
	}
      ++it;
    }
  if (root.children->size() == 2)
    {
      if (((*root.children)[0]->value.compare(LINK_SECTION) == 0 &&
	   ((*root.children)[1])->value.compare(CHIPSET_SECTION) == 0) ||
	  (((*root.children)[0])->value.compare(CHIPSET_SECTION) == 0 &&
	   ((*root.children)[1])->value.compare(LINK_SECTION) == 0))
	{
	  return ;
	}
    }
  throw Errors(SECTION_ERROR);
}

/*
** Create component from root (input, etc...)
** Transform STRING into COMPONENT type
** Throw a error if syntax failed
*/
void	nts::Parser::createChipset(nts::t_ast_node& chipset)
{
  std::vector<nts::t_ast_node *>::iterator	it;

  it = chipset.children->begin();
  while (it != chipset.children->end())
    {
      if (_chipset[(*it)->lexeme] != true)
	throw Errors("Unkwown keyword in chipset");
      (*it)->type = nts::ASTNodeType::COMPONENT;
      if ((*it)->lexeme == "input")
	{
	  if (checkInput(*(*it)) == false)
	    throw Errors("Wrong input parameters");
	}
      else
	{
	  if (checkComponent(*(*it)) == false)
	    throw Errors("Wrong component parameters");
	}
      ++it;
    }
}

/*
** Create link from root
** Transform String into LINK / LINK_END type
** Throw a error if syntax failed
*/
void	nts::Parser::createLink(nts::t_ast_node& link) const
{
  std::vector<nts::t_ast_node *>::iterator	it;

  it = link.children->begin();
  while (it != link.children->end())
    {
      (*it)->type = nts::ASTNodeType::LINK;
      if (checkLink(*(*it)) == false)
	throw Errors("Failed to eval link");
      ++it;
    }
} 

/*
** Check tree syntax, raise a error else
*/
void	nts::Parser::parseTree(nts::t_ast_node& root)
{
  regroupSection(root);
  if ((*root.children->begin())->value.compare(CHIPSET_SECTION) == 0)
    {
      createChipset(*(*root.children->begin()));
      createLink(*(*root.children)[1]);
    }
  
  else
    {
      std::reverse(root.children->begin(), root.children->end());
      parseTree(root);
    }
}

/*
** Delete comment of string started by '#' and finished by '\0'
*/
void	nts::Parser::RemoveCommentaryFromInput(std::string& input)
{
  std::string::iterator	it;

  it = input.begin();
  while (it != input.end() && *it != '#')
    ++it;
  if (*it == '#')
    {
      while (it != input.end())
	input.erase(it);
    }
}

/*
** Eval expr of type : COMPONENT(%d)
*/
void			nts::Parser::checkParenthesis(nts::t_ast_node *child) const
{
  size_t		pos;
  size_t		tmp;

  pos = std::string::npos;
  tmp = -1;
  while ((tmp = child->lexeme.find("(", tmp + 1)) != std::string::npos)
    pos = tmp;
  if (pos != std::string::npos && child->lexeme.find(")") != std::string::npos)
    {
      child->value = child->lexeme.substr(pos);
      child->lexeme.erase(pos);
      child->value.erase(child->value.begin());
      child->value.erase(child->value.end() - 1);
    }
}

void	nts::Parser::createLine(nts::t_ast_node *root, std::string line) const
{
  nts::t_ast_node	*child;
  nts::t_ast_node	*contain;
  std::string::iterator	it;
  int			i;

  i = 0;
  it = line.begin();
  contain = NULL;
  while (it != line.end())
    {
      if (i == 0)
	child = new nts::t_ast_node(new std::vector<nts::t_ast_node *>());
      else
	child = new nts::t_ast_node(NULL);
      child->type = nts::ASTNodeType::STRING;
      while (it != line.end() && *it != ' ')
	{
	  child->lexeme += *it;
	  ++it;
	}
      checkParenthesis(child);
      if (contain)
	contain->children->push_back(child);
      else
	{
	  root->children->push_back(child);
	  contain = child;
	}
      while (it != line.end() && *it == ' ')
	++it;
      ++i;
    }
  child = new nts::t_ast_node(NULL);
  child->type = nts::ASTNodeType::NEWLINE;
    if (contain)
      contain->children->push_back(child);
    else
      root->children->push_back(child);
}

/*
** Return parsing tree
*/
nts::t_ast_node	*nts::Parser::createTree()
{
  nts::t_ast_node	*root;
  nts::t_ast_node	*last_section;
  std::stringstream	stream(getFeed());
  std::string		line;

  last_section = NULL;
  root = new nts::t_ast_node(new std::vector<struct nts::s_ast_node *>());
  root->type = nts::ASTNodeType::DEFAULT;
  while (getline(stream, line))
    {
      nts::Parser::RemoveCommentaryFromInput(line);
      Helper::epurStr(line);
      if (!line.empty() && line[0] == '.')
	{
	  last_section = new nts::t_ast_node(new std::vector<struct nts::s_ast_node *>());
	  last_section->type = nts::ASTNodeType::SECTION;
	  line.erase(line.begin());
	  last_section->value = line;
	  root->children->push_back(last_section);
	}
      else if (!line.empty())
	{
	  if (last_section)
	    createLine(last_section, line);
	  else
	    createLine(root, line);
	}
    }
  return (root);
}

/*
** Getter for _input
*/
std::string const&	nts::Parser::getFeed()
{
  return (_input);
}

/*
** Check input parameters
*/
bool	nts::Parser::checkInput(nts::t_ast_node const& node) const
{
  std::vector<nts::t_ast_node *>::const_iterator	it;

  if (node.children == NULL)
    return false;
  it = node.children->begin();
  while (it != node.children->end())
    {
      if ((*it)->type == nts::ASTNodeType::NEWLINE)
	break ;
      if ((*it)->type != nts::ASTNodeType::STRING)
	return false;
      ++it;
    }
  return node.children->size() == 2;
}

/*
** Check component parameters
*/
bool	nts::Parser::checkComponent(nts::t_ast_node const& node) const
{
  if (node.value.empty())
    {
      return node.children && node.children->size() == 2;
    }
  else
    throw Errors("Parsing error for () on component");
  if (node.lexeme == "2716" && !node.value.empty())
    {
      throw Errors("Missing args for 2716");
      return false;
    }
  return false;
}

bool	splitLink(nts::t_ast_node& node)
{
  size_t	pos;

  pos = node.lexeme.find(":");
  if (pos != std::string::npos)
    {
      node.value = node.lexeme.substr(pos + 1);
      node.lexeme.erase(pos);
      return true;
    }
  return false;
}

/*
** Check link parameters %s:%d -> %s:%d
*/
bool		nts::Parser::checkLink(nts::t_ast_node& node) const
{
  if (splitLink(node) == false)
    return false;
  if (node.children && node.children->size() == 2)
    {
      if (splitLink(*(*node.children->begin())) == false)
	return false;
      (*node.children->begin())->type = nts::ASTNodeType::LINK_END;
      return true;
    }
  return false;
}

void		nts::Parser::dumpTree(nts::t_ast_node *node, size_t depth)
{
  std::vector<nts::t_ast_node *>::iterator	it;
  size_t	i;

  i = 0;
  while (i < depth)
    {
      std::cout << "-";
      ++i;
    }
  if (node->type != nts::ASTNodeType::DEFAULT)
    {
      if (node->type == nts::ASTNodeType::SECTION)
	std::cout << " " << node->value << std::endl;
      else
	std::cout << " " << node->lexeme << std::endl;
    }
  if (node->children)
    {
      it = node->children->begin();
      while (it != node->children->end())
	{
	  dumpTree(*it, depth + 1);
	  ++it;
	}
    }
}
