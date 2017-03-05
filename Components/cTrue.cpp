//
// cTrue.cpp for cTrue in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Sun Mar  5 20:26:12 2017 Arnaud WURMEL
//

#include <iostream>
#include "Errors.hpp"
#include "cTrue.hpp"

/*
** Constructor
*/
nts::cTrue::cTrue(const std::string &value)
{
  static_cast<void>(value);
  _component = NULL;
  _link = new std::pair<size_t, size_t>();
  _link->first = 0;
  _link->second = 0;
}

/*
** Compute
*/
nts::Tristate	nts::cTrue::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (nts::Tristate::UNDEFINED);
  return (nts::Tristate::TRUE);
}

/*
** SetLink
*/
void	nts::cTrue::SetLink(size_t pin_num_this, nts::IComponent &component,
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
void	nts::cTrue::Dump() const
{
  std::cout << "Input - value: true" << std::endl;
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
nts::cTrue::~cTrue()
{

}
