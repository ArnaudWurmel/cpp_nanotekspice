//
// c4017.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Sun Mar  5 01:40:34 2017 Victorien Fischer
//

#include "c4017.hpp"
#include "Errors.hpp"

/*
** Constructor
*/
nts::c4017::c4017(const std::string &value) : Component(value)
{
  size_t	i;

  i = 0;
  while (++i < 13)
    addComputeFunction(i);
  _prevCP0 = nts::Tristate::UNDEFINED;
  _prevCP1 = nts::Tristate::UNDEFINED;
  _output[0] = 3;
  _output[1] = 2;
  _output[2] = 4;
  _output[3] = 7;
  _output[4] = 10;
  _output[5] = 1;
  _output[6] = 5;
  _output[7] = 6;
  _output[8] = 9;
  _output[9] = 11;
  _prevOut = 0;
  addComputeFunction(1);
  addComputeFunction(2);
  addComputeFunction(3);
  addComputeFunction(4);
  addComputeFunction(5);
  addComputeFunction(6);
  addComputeFunction(7);
  addComputeFunction(9);
  addComputeFunction(10);
  addComputeFunction(11);
  addComputeFunction(12);
}

/*
** Link a pin to a compute function
*/
void		nts::c4017::addComputeFunction(size_t pin)
{
  _computeFunctions.insert(std::make_pair(pin, std::bind(&nts::c4017::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Computing
*/
nts::Tristate	nts::c4017::ComputeOutput(size_t pin_num_this)
{
  bool	vcp0;
  bool	vcp1;
  bool	mr;

  if (pin_num_this == 12)
    {
      if (_prevOut < 5)
	return (nts::Tristate::TRUE);
      return (nts::Tristate::FALSE);
    }
  vcp0 = getValueForPin(14);
  vcp1 = getValueForPin(13);
  if ((mr = getValueForPin(15)))
    return (nts::Tristate::UNDEFINED);
  if (_prevCP0 == nts::Tristate::FALSE && vcp0)
    {
      if (_prevOut + 1 == pin_num_this || (pin_num_this == 0 && _prevOut == 9))
	{
	  _prevOut = pin_num_this;
	  return (nts::Tristate::TRUE);
	}
      return (nts::Tristate::FALSE);
    }
  else if (_prevCP0 == nts::Tristate::TRUE && vcp0)
    {
      if (_prevCP1 == nts::Tristate::TRUE && !vcp1)
	if (_prevOut == 0 && pin_num_this == 1)
	  return (nts::Tristate::TRUE);
      return (nts::Tristate::FALSE);
    }
  else
    return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4017::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if ((pin_num_this >= 1 && pin_num_this <= 7) || (pin_num_this >= 9 && pin_num_this <= 15))
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already linked for 4017");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4017");
}

/*
** Dumping
*/
void	nts::c4017::Dump() const
{
}

/*
** Destructor
*/
nts::c4017::~c4017()
{

}
