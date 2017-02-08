//
// IParser.hpp for NanoTekSpice in /home/wurmel/rendu/cpp_nanotekspice/Interface
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 13:44:24 2017 Arnaud WURMEL
// Last update Tue Feb  7 11:15:28 2017 Arnaud WURMEL
//

#ifndef IPARSER_HPP_
# define IPARSER_HPP_

# include <string>
# include <vector>

namespace nts
{
  enum class ASTNodeType : int
  {
      DEFAULT = -1,
      NEWLINE = 0,
      SECTION,
      COMPONENT,
      LINK,
      LINK_END,
      STRING
  };

  typedef struct	s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children) : children(children) {}

    std::string lexeme;
    ASTNodeType	type;
    std::string	value;
    std::vector<struct s_ast_node*>	*children;
  }	t_ast_node;

  class	IParser
  {
  public:
    virtual ~IParser() {}
    
  public:
    virtual void	feed(std::string const& input) = 0;
    virtual void	parseTree(t_ast_node& root) = 0;
    virtual t_ast_node	*createTree() = 0;
  };
}

#endif /* !IPARSER_HPP_ */
