//
// cOutput.cpp for cOutput in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 23:18:20 2017 Victorien Fischer
// Last update Wed Feb 15 23:59:45 2017 Victorien Fischer
//

#include "cOutput.hpp"

nts::cOutput::cOutput(const std::string &value)
{
  (void)value;
}

nts::Tristate	nts::cOutput::Compute(size_t pin_num_this)
{
}

void	nts::cOutput::SetLink(size_t pin_num_this, nts::IComponent &component,
			     size_t pin_num_target)
{
}

void	nts::cOutput::Dump() const
{
}

nts::cOutput::~cOutput()
{
}
