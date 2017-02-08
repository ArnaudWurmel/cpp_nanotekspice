//
// Parser.cpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:25:47 2017 Arnaud WURMEL
// Last update Wed Feb  8 14:07:27 2017 Arnaud WURMEL
//

#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include "IParser.hpp"
#include "Parser.hpp"

Parser::Parser()
{
  _input = "";
}

Parser::~Parser()
{

}

void	Parser::feed(std::string const& input)
{
  _input += input;
}

/*
** Check tree syntax, raise a error else
*/
void	Parser::parseTree(nts::t_ast_node& root)
{
  (void)root;
}

/*
** Parser for link
*/
nts::t_ast_node	*Parser::getLink() const
{
  return (NULL);
}

/*
** Return parsing tree
*/
nts::t_ast_node	*Parser::createTree()
{
  nts::t_ast_node	*root;
  std::stringstream	stream(getFeed());
  std::string		line;

  root = NULL;
  while (getline(stream, line))
    {
      std::cout << line << std::endl;
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
