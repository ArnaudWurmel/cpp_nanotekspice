//
// cInput.cpp for cInput in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Mon Feb 27 15:10:56 2017 Arnaud WURMEL
//

#include <iostream>
#include "Errors.hpp"
#include "cInput.hpp"

/*
** Constructor
*/
nts::cInput::cInput(const std::string &value)
{
  if (value.compare("0") == 0)
    _value = nts::Tristate::FALSE;
  else if (value.compare("1") == 0)
    _value = nts::Tristate::TRUE;
  else
    _value = nts::Tristate::UNDEFINED;
  _component = NULL;
  _link = new std::pair<size_t, size_t>();
  _link->first = 0;
  _link->second = 0;
}

/*
** Compute
*/
nts::Tristate	nts::cInput::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (nts::Tristate::UNDEFINED);
  return (_value);
}

/*
** SetLink
*/
void	nts::cInput::SetLink(size_t pin_num_this, nts::IComponent &component,
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
void	nts::cInput::Dump() const
{
  std::cout << "Input - value: " << static_cast<int>(_value) << std::endl;
  std::cout << "\tpin #1: ";
  if (_component)
    std::cout << "linked";
  else
    std::cout << "NULL";
  std::cout << std::endl;
}

void	nts::cInput::setValue(nts::Tristate const& value)
{
  _value = value;
}

/*
** Destructor
*/
nts::cInput::~cInput()
{

}
