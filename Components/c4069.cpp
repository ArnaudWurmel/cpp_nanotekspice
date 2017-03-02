//
// c4069.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Thu Mar  2 14:17:53 2017 Victorien Fischer
//

#include <iostream>
#include <string>
#include "Errors.hpp"
#include "c4069.hpp"

/*
** Constructor
*/
nts::c4069::c4069(const std::string &value) : Component(value)
{
  _outputs[2] = 1;
  _outputs[4] = 3;
  _outputs[6] = 5;
  _outputs[8] = 9;
  _outputs[10] = 11;
  _outputs[12] = 13;
}

/*
** Computing
*/
nts::Tristate	nts::c4069::Compute(size_t pin_num_this)
{
  if (!alreadyLink(_outputs[pin_num_this]))
    throw Errors("Missing link for c4069");
  if (getValueForPin(_outputs[pin_num_this]))
    return (nts::Tristate::FALSE);
  return (nts::Tristate::TRUE);
}

/*
** Setting Link
*/
void	nts::c4069::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 13 && pin_num_this != 7)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4069");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
      return ;
    }
  throw Errors("Wrong link for pin on 4069");
}

/*
** Dumping
*/
void	nts::c4069::Dump() const
{
}

/*
** Destructor
*/
nts::c4069::~c4069()
{
}
