//
// cFalse.cpp for cFalse in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Fri Mar  3 10:51:40 2017 Arnaud WURMEL
//

#include <iostream>
#include "Errors.hpp"
#include "cFalse.hpp"

/*
** Constructor
*/
nts::cFalse::cFalse(const std::string &value)
{
  (void)value;
  _component = NULL;
  _link = new std::pair<size_t, size_t>();
  _link->first = 0;
  _link->second = 0;
}

/*
** Compute
*/
nts::Tristate	nts::cFalse::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (nts::Tristate::UNDEFINED);
  return (nts::Tristate::FALSE);
}

/*
** SetLink
*/
void	nts::cFalse::SetLink(size_t pin_num_this, nts::IComponent &component,
			     size_t pin_num_target)
{
  if (pin_num_this != 1)
    throw Errors("Wrong pin link for false");
  _link->first = pin_num_this;
  _link->second = pin_num_target;
  _component = &component;
}

/*
** Dump
*/
void	nts::cFalse::Dump() const
{
  std::cout << "False - value: false" << std::endl;
  std::cout << "\tpin #1: ";
  if (_component)
    std::cout << "linked";
  else
    std::cout << "NULL";
  std::cout << std::endl;
}

/*
** Destructor
*/
nts::cFalse::~cFalse()
{

}
