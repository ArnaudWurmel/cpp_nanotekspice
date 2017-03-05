//
// cClock.cpp for cClock in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Sun Mar  5 20:27:26 2017 Arnaud WURMEL
//

#include <iostream>
#include "Errors.hpp"
#include "cClock.hpp"

/*
** Constructor
*/
nts::cClock::cClock(const std::string &value)
{
  static_cast<void>(value);
  _value = nts::Tristate::UNDEFINED;
  _component = NULL;
  _link = new std::pair<size_t, size_t>();
  _link->first = 0;
  _link->second = 0;
}

/*
** Compute
*/
nts::Tristate	nts::cClock::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (nts::Tristate::UNDEFINED);
  return (_value);
}

/*
** SetLink
*/
void	nts::cClock::SetLink(size_t pin_num_this, nts::IComponent &component,
			     size_t pin_num_target)
{
  if (pin_num_this != 1)
    throw Errors("Wrong pin link for input");
  _link->first = pin_num_this;
  _link->second = pin_num_target;
  _component = &component;
}

/*
** Dump
*/
void	nts::cClock::Dump() const
{
  std::cout << "Clock - value: " << static_cast<int>(_value) << std::endl;
  std::cout << "\tpin #1: ";
  if (_component)
    std::cout << "linked";
  else
    std::cout << "NULL";
  std::cout << std::endl;
}

void	nts::cClock::setValue(nts::Tristate const& value)
{
  _value = value;
}

/*
** Destructor
*/
nts::cClock::~cClock()
{

}
