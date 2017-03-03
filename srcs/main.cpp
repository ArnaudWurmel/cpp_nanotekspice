//
// main.cpp for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Jan 27 19:12:02 2017 Arnaud WURMEL
// Last update Fri Mar  3 01:22:09 2017 Arnaud WURMEL
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

nts::t_ast_node	*openFile(char *filepath)
{
  std::ifstream	file;
  std::stringstream	ss;
  nts::t_ast_node	*node;  
  Parser	parser;

  node = NULL;
  file.open(filepath);
  if (file.is_open())
    {
      ss << file.rdbuf();
      parser.feed(ss.str());
      try
	{
	  node = parser.createTree();
	  parser.parseTree(*node);
	}
      catch (std::exception& e)
	{
	  std::cout << e.what() << std::endl;
	  return NULL;
	}
    }
  else
    return NULL;
  return node;
}


int	main(int ac, char **av)
{
  nts::NanoTekSpice	*root;
  nts::t_ast_node	*node;

  (void)av;
  if (ac == 1)
    {
      std::cerr << "Error arguments" << std::endl;
      return 1;
    }
  root = new nts::NanoTekSpice();
  if ((node = openFile(av[1])) == NULL)
    return 1;
  root->setTree(node);
  try {
    root->createComponent();
    root->start(ac, av);
  } catch (std::exception& e)
    {
      std::cout << e.what() << std::endl;
      return (1);
    }
  delete root;
  return 0;
}
