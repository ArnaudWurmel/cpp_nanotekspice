//
// cOutput.cpp for cOutput in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Mon Feb 27 16:12:24 2017 Arnaud WURMEL
//

#include <iostream>
#include "cOutput.hpp"
#include "Errors.hpp"

nts::cOutput::cOutput(const std::string &value)
{
  (void)value;
  _component = NULL;
  _link = new std::pair<size_t, size_t>();
  _link->first = 0;
  _link->second = 0;
}

nts::Tristate	nts::cOutput::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    return (nts::Tristate::UNDEFINED);
  return (this->_component->Compute());

}

void	nts::cOutput::SetLink(size_t pin_num_this, nts::IComponent &component,
			     size_t pin_num_target)
{
  if (pin_num_this != 1)
    throw Errors("Wrong pin link for output");
  _link->first = pin_num_this;
  _link->second = pin_num_target;
  _component = &component;
}

void	nts::cOutput::Dump() const
{
  std::cout << "Output" << std::endl;
  std::cout << "\tpin #1: ";
  if (_component)
    std::cout << "linked";
  else
    std::cout << "NULL";
  std::cout << std::endl;
}

nts::cOutput::~cOutput()
{
}
