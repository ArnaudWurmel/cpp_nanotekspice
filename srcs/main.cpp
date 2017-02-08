//
// main.cpp for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Jan 27 19:12:02 2017 Arnaud WURMEL
// Last update Wed Feb  8 12:27:39 2017 Arnaud WURMEL
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include "IParser.hpp"
#include "Parser.hpp"
#include "NanoTekSpice.hpp"

void		openFile(char *filepath)
{
  std::ifstream	file;
  std::stringstream	ss;
  
  Parser	parser;

  file.open(filepath);
  if (file.is_open())
    {
      ss << file.rdbuf();
      parser.feed(ss.str());
      parser.createTree();
    }
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
  openFile(av[1]);
  root->start();
  delete root;
  return 0;
}
