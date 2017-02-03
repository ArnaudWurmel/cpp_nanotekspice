//
// Parser.cpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:25:47 2017 Arnaud WURMEL
// Last update Fri Feb  3 22:21:06 2017 Arnaud WURMEL
//

#include <string>
#include "IParser.hpp"
#include "Parser.hpp"

Parser::Parser()
{
  _toParse = "";
}

Parser::~Parser()
{

}

void	Parser::feed(std::string const& input)
{
  _toParse += input;
}

void	Parser::parseTree(nts::t_ast_node& root)
{
  (void)root;
}

nts::t_ast_node	*Parser::createTree()
{
  return (NULL);
}
