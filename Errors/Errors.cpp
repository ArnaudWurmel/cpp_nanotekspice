//
// Errors.cpp for NTS in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Feb  8 18:52:07 2017 Arnaud WURMEL
// Last update Wed Feb  8 19:12:52 2017 Arnaud WURMEL
//

#include <exception>
#include <string>
#include "Errors.hpp"

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

