//
// Helper.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:52:50 2017 Arnaud WURMEL
// Last update Fri Feb  3 19:01:51 2017 Arnaud WURMEL
//

#include <string>
#include "Helper.hpp"

void		Helper::epurStr(std::string& str)
{
  std::string::iterator	it;
  bool			one_space;

  one_space = false;
  it = str.begin();
  while (it != str.end() && (*it == ' ' || *it == '\t'))
    str.erase(it);
  
}
