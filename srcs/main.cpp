//
// main.cpp for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Jan 27 19:12:02 2017 Arnaud WURMEL
// Last update Mon Feb 13 21:40:58 2017 Arnaud WURMEL
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "Errors.hpp"
#include "IParser.hpp"
#include "Parser.hpp"
#include "NanoTekSpice.hpp"

void	delete_tree(nts::t_ast_node *node)
{
  std::vector<nts::t_ast_node *>::iterator	it;

  if (node->children)
    {
      it = node->children->begin();
      while (it != node->children->end())
	{
	  delete_tree(*it);
	  ++it;
	}
      delete node->children;
    }
  delete node;
}

void	show_node(nts::t_ast_node *node, int deep)
{
  std::vector<nts::t_ast_node *>::iterator	it;
  int						i;

  if (!node)
    return ;
  if (node->type == nts::ASTNodeType::SECTION)
    std::cout << "====" << std::endl << "Under section : " << node->value << std::endl;
  else if (node->type != nts::ASTNodeType::DEFAULT)
    {
      i = 0;
      while (i < deep)
	{
	  std::cout << " ";
	  ++i;
	}
      std::cout << (int)node->type << ": " << node->lexeme << std::endl;
    }
  if (node->children)
    {
      it = node->children->begin();
      while (it != node->children->end())
	{
	  show_node(*it, deep + 1);
	  ++it;
	}
    }
}

bool		openFile(char *filepath)
{
  std::ifstream	file;
  std::stringstream	ss;
  nts::t_ast_node	*node;  
  Parser	parser;

  file.open(filepath);
  if (file.is_open())
    {
      ss << file.rdbuf();
      parser.feed(ss.str());
      try
	{
	  node = parser.createTree();
	  show_node(node, 0);
	  parser.parseTree(*node);
	  show_node(node, 0);
	  /*delete_tree(node);*/
	}
      catch (std::exception& e)
	{
	  std::cout << e.what() << std::endl;
	  return false;
	}
    }
  else
    return false;
  return true;
}

int	main(int ac, char **av)
{
  nts::NanoTekSpice	*root;

  (void)av;
  if (ac == 1)
    {
      std::cerr << "Error arguments" << std::endl;
      return 1;
    }
  root = new nts::NanoTekSpice();
  if (openFile(av[1]) == false)
    return 1;
  root->start();
  delete root;
  return 0;
}
