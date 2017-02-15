//
// cInput.cpp for cInput in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Wed Feb 15 23:59:24 2017 Victorien Fischer
//

#include "cInput.hpp"

nts::cInput::cInput(const std::string &value)
{
  (void)value;
}

nts::Tristate	nts::cInput::Compute(size_t pin_num_this)
{
}

void	nts::cInput::SetLink(size_t pin_num_this, nts::IComponent &component,
			     size_t pin_num_target)
{
}

void	nts::cInput::Dump() const
{
}

nts::cInput::~cInput()
{
}
