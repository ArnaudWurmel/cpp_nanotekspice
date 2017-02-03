//
// Helper.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:52:50 2017 Arnaud WURMEL
// Last update Fri Feb  3 19:29:24 2017 Arnaud WURMEL
//

#include <string>
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
  if (*it == ' ' || *it == '\t')
    str.erase(it);
}
