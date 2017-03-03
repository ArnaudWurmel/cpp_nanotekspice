//
// c4011.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 17:37:04 2017 Victorien Fischer
// Last update Fri Mar  3 01:20:28 2017 Victorien Fischer
//

#include <string>
#include "Errors.hpp"
#include "c4011.hpp"

/*
** Constructor
*/
nts::c4011::c4011(const std::string &value) : Component(value)
{
  addComputeFunction(3);
  addComputeFunction(4);
  addComputeFunction(10);
  addComputeFunction(11);
}

/*
** Link a pin to a compute function
*/
void		nts::c4011::addComputeFunction(size_t pin)
{
  _computeFunctions.insert(std::make_pair(pin, std::bind(&nts::c4011::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Computing
*/
nts::Tristate	nts::c4011::ComputeOutput(size_t pin_num_this)
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
    throw Errors("Missing link for pin 4011");
  if (!(getValueForPin(input1) && getValueForPin(input2)))
    return (nts::Tristate::TRUE);
  else
    return (nts::Tristate::FALSE);
  throw Errors("Compute on no output pin");
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4011::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 13 && pin_num_this != 7)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4011");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4011");
}

/*
** Dumping
*/
void	nts::c4011::Dump() const
{
}

/*
** Destructor
*/
nts::c4011::~c4011()
{
}
