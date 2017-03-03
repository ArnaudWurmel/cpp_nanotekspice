//
// Errors.cpp for NTS in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Feb  8 18:52:07 2017 Arnaud WURMEL
// Last update Fri Mar  3 12:58:58 2017 Arnaud WURMEL
//

#include <exception>
#include <string>
#include "Errors.hpp"

Errors::Errors(std::string const& what)
{
  _what = what;
}

Errors::Errors(const char *what)
{
  _what = std::string(what);
}

Errors::~Errors()
{

}

const char	*Errors::what() const throw()
{
  return (_what.c_str());
}

