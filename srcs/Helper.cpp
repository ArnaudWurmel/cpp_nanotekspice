//
// Helper.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:52:50 2017 Arnaud WURMEL
// Last update Thu Mar  2 15:27:09 2017 Arnaud WURMEL
//

#include <string>
#include "IParser.hpp"
#include "Helper.hpp"

static bool	isCharacterAfter(std::string::iterator it, std::string::iterator const& end)
{
  while (it != end)
    {
      if (*it != ' ' && *it != '\t')
	return true;
      ++it;
    }
  return false;
}

void		Helper::epurStr(std::string& str)
{
  std::string::iterator	it;
  bool			one_space;

  one_space = false;
  it = str.begin();
  while (it != str.end() && (*it == ' ' || *it == '\t'))
    str.erase(it);
  while (it != str.end())
    {
      if ((*it == ' ' || *it == '\t') && one_space == false && isCharacterAfter(it, str.end()))
	{
	  if (*it == '\t')
	    *it = ' ';
	  ++it;
	  one_space = true;
	}
      else if (*it != ' ' && *it != '\t')
	{
	  ++it;
	  one_space = false;
	}
      else
	str.erase(it);
    }
}

/*
** Static func to free the whole tree
*/
void	Helper::delete_tree(nts::t_ast_node *node)
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
