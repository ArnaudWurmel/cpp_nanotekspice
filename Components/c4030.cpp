//
// c4030.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 01:01:40 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include "Errors.hpp"
#include "c4030.hpp"

/*
** Constructor
*/
nts::c4030::c4030(const std::string &value) : Component(value)
{
  _computeFunctions.insert(std::make_pair(3, std::bind(&nts::c4030::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(4, std::bind(&nts::c4030::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(10, std::bind(&nts::c4030::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(11, std::bind(&nts::c4030::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Computing
*/
nts::Tristate	nts::c4030::ComputeOutput(size_t pin_num_this)
{
  size_t	input1;
  size_t	input2;

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
    throw Errors("Missing link for pin in 4030");
  if (getValueForPin(input1) ^ getValueForPin(input2))
    return (nts::Tristate::TRUE);
  else
    return (nts::Tristate::FALSE);
  throw Errors("Compute on no output pin");
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4030::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 13 && pin_num_this != 7)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4030");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4030");
}

/*
** Dumping
*/
void	nts::c4030::Dump() const
{
}

/*
** Destructor
*/
nts::c4030::~c4030()
{
}
