//
// Parser.cpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:25:47 2017 Arnaud WURMEL
// Last update Wed Feb  8 20:05:13 2017 Arnaud WURMEL
//

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "IParser.hpp"
#include "Parser.hpp"
#include "Helper.hpp"
#include "Errors.hpp"

Parser::Parser()
{
  _input = "";
}

Parser::~Parser()
{

}

/*
** Feed the input string
*/
void	Parser::feed(std::string const& input)
{
  _input += input;
}

/*
** Check tree syntax, raise a error else
*/
void		Parser::parseTree(nts::t_ast_node& root)
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
	  if ((*it)->value == (*tmp)->value)
	    {
	      (*it)->children->insert((*it)->children->end(), (*tmp)->children->begin(), (*tmp)->children->end());
	      root.children->erase(tmp);
	    }
	  else
	    ++tmp;
	}
      ++it;
    }
}

void	Parser::RemoveCommentaryFromInput(std::string& input)
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
** Return parsing tree
*/
nts::t_ast_node	*Parser::createTree()
{
  nts::t_ast_node	*root;
  nts::t_ast_node	*last_section;
  nts::t_ast_node	*child;
  std::stringstream	stream(getFeed());
  std::string		line;

  last_section = NULL;
  root = new nts::t_ast_node(new std::vector<struct nts::s_ast_node *>());
  root->type = nts::ASTNodeType::DEFAULT;
  while (getline(stream, line))
    {
      Parser::RemoveCommentaryFromInput(line);
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
	  child = new nts::t_ast_node(NULL);
	  child->type = nts::ASTNodeType::STRING;
	  child->value = line;
	  if (last_section)
	    last_section->children->push_back(child);
	  else
	    root->children->push_back(child);
	}
    }
  return (root);
}

/*
** Getter for _input
*/
std::string const&	Parser::getFeed()
{
  return (_input);
}
