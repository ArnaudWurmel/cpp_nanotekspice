//
// Parser.hpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Parser
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:12:08 2017 Arnaud WURMEL
// Last update Wed Feb 15 21:14:43 2017 Arnaud WURMEL
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

  /*
  ** IParser implementation
  */
public:
  void			feed(std::string const&);
  void			parseTree(nts::t_ast_node& root);
  nts::t_ast_node	*createTree();

  /*
  ** Section management
  */
public:
  void			createLink(nts::t_ast_node&) const;
  void			createChipset(nts::t_ast_node&);
  void			regroupSection(nts::t_ast_node&) const;
  void			createLine(nts::t_ast_node *, std::string) const;

  /*
  ** Line modification
  */
public:
  void			checkParenthesis(nts::t_ast_node *) const;
  static void		RemoveCommentaryFromInput(std::string&);

  /*
  ** Syntax checker
  */
public:
  bool			checkLink(nts::t_ast_node&) const;
  bool			checkInput(nts::t_ast_node const&) const;
  bool			checkComponent(nts::t_ast_node const &) const;

private:
  Parser(Parser const&);

private:
  std::string const&	getFeed();

private:
  std::string	_input;
  std::map<std::string, bool>	_chipset;
};

#endif /* !PARSER_HPP_ */
