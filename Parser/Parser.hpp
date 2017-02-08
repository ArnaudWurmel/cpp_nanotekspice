//
// Parser.hpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:12:08 2017 Arnaud WURMEL
// Last update Wed Feb  8 23:35:08 2017 Arnaud WURMEL
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# define LINK_SECTION "links:"
# define CHIPSET_SECTION "chipsets:"

class	Parser : public nts::IParser
{
public:
  Parser();
  ~Parser();

public:
  void			feed(std::string const&);
  void			parseTree(nts::t_ast_node& root);
  nts::t_ast_node	*createTree();

public:
  static void		RemoveCommentaryFromInput(std::string&);
  void			createLink(nts::t_ast_node&);
  void			createChipset(nts::t_ast_node&);
  void			regroupSection(nts::t_ast_node&);

private:
  Parser(Parser const&);

private:
  std::string const&	getFeed();

private:
  std::string	_input;
  std::map<std::string, bool>	_chipset;
};

#endif /* !PARSER_HPP_ */
