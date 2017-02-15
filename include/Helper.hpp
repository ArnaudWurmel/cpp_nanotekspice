//
// Helper.hpp for Nts in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:54:07 2017 Arnaud WURMEL
// Last update Wed Feb 15 21:15:45 2017 Arnaud WURMEL
//

#ifndef HELPER_HPP_
# define HELPER_HPP_
# include "IParser.hpp"

class	Helper
{
public:
  static void	epurStr(std::string&);
  static void	delete_tree(nts::t_ast_node *);

};

#endif /* !HELPER_HPP_ */
