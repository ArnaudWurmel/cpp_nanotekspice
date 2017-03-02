//
// c4001.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Wed Mar  1 19:11:40 2017 Victorien Fischer
//

#include <string>
#include "Errors.hpp"
#include "c4001.hpp"

/*
** Constructor
*/
nts::c4001::c4001(const std::string &value) : Component(value)
{
}

/*
** Computing
*/
nts::Tristate	nts::c4001::Compute(size_t pin_num_this)
{
  size_t	input1;
  size_t	input2;

  if (pin_num_this == 3 || pin_num_this == 4 || pin_num_this == 10 ||
      pin_num_this == 11)
    {
      if (pin_num_this == 3 || pin_num_this == 10)
	{
	  input1 = pin_num_this - 1;
	  input2 = pin_num_this - 2;
	}
      else
	{
	  input1 = pin_num_this + 1;
	  input2 = pin_num_this + 2;
	}
      if (!alreadyLink(input1) || !alreadyLink(input2))
	throw Errors("Missing link for pin in 4001");
      if (!(getValueForPin(input1) || getValueForPin(input2)))
	return (nts::Tristate::TRUE);
      return (nts::Tristate::FALSE);
    }
  throw Errors("Compute on no output pin");
  return (nts::Tristate::UNDEFINED);
}

/*
** Sets Link
*/
void	nts::c4001::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 13 && pin_num_this != 7)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4001");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4001");
}

/*
** Dumping
*/
void	nts::c4001::Dump() const
{
}

/*
** Destructor
*/
nts::c4001::~c4001()
{
}
