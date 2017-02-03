//
// Parser.hpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:12:08 2017 Arnaud WURMEL
// Last update Fri Feb  3 14:29:50 2017 Arnaud WURMEL
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

class	Parser : public nts::IParser
{
public:
  Parser();
  ~Parser();

public:
  void			feed(std::string const&);
  void			parseTree(nts::t_ast_node& root);
  nts::t_ast_node	*createTree();

private:
  Parser(Parser const&);

private:
  std::string	_toParse;
};

#endif /* !PARSER_HPP_ */
