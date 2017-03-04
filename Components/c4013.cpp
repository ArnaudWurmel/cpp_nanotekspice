//
// c4013.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Sat Mar  4 01:20:12 2017 Victorien Fischer
//

#include <iostream>
#include "c4013.hpp"
#include "Errors.hpp"

/*
** Constructor
*/
nts::c4013::c4013(const std::string &value) : Component(value)
{
  _prevClock = nts::Tristate::UNDEFINED;
  _previous[0] = nts::Tristate::UNDEFINED;
  _previous[1] = nts::Tristate::UNDEFINED;
  addComputeFunction(1);
  addComputeFunction(2);
  addComputeFunction(12);
  addComputeFunction(13);
  _computeFunctions.insert(std::make_pair(7, std::bind(&nts::c4013::ComputeOnVSS, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(14, std::bind(&nts::c4013::ComputeOnVDD, this, std::placeholders::_1)));
}

/*
** Link a pin to a compute function
*/
void		nts::c4013::addComputeFunction(size_t pin)
{
  _computeFunctions.insert(std::make_pair(pin, std::bind(&nts::c4013::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Computing
*/
nts::Tristate	nts::c4013::ComputeOutput(size_t pin_num_this)
{
  size_t	set;
  size_t       	reset;
  size_t	clock;
  size_t	data;
  size_t	num;
  bool		vset;
  bool		vreset;
  bool		vclock;
  bool		vdata;

  if (pin_num_this == 1 || pin_num_this == 2)
    {
      num = 0;
      clock = 3;
      reset = 4;
      data = 5;
      set = 6;
    }
  else if (pin_num_this == 12 || pin_num_this == 13)
    {
      num = 1;
      set = 8;
      data = 9;
      reset = 10;
      clock = 11;
    }
  else
    throw Errors("Compute on no output pin");
  if (!alreadyLink(set) || !alreadyLink(reset) || !alreadyLink(data) || !alreadyLink(clock))
    throw Errors("Missing link for pin in 4013");
  vclock = getValueForPin(clock);
  vset = getValueForPin(set);
  vreset = getValueForPin(reset);
  vdata = getValueForPin(data);
  if (_prevClock != nts::Tristate::UNDEFINED)
    if (!vset && !vreset)
      if (vclock)
	_previous[num] = ((vdata) ? (nts::Tristate::TRUE) : (nts::Tristate::FALSE));
  if (vreset || vset)
    {
      if (vreset && !vset)
	_previous[num] = nts::Tristate::FALSE;
      else
	_previous[num] = nts::Tristate::TRUE;
    }
  _prevClock = (vclock) ? (nts::Tristate::TRUE) : (nts::Tristate::FALSE);
  if (pin_num_this == 2 || pin_num_this == 12)
    {
      if (vreset && vset)
	return (_previous[num]);
      else
	{
	  if (_previous[num] == nts::Tristate::UNDEFINED)
	    return (nts::Tristate::UNDEFINED);
	  else if (_previous[num] == nts::Tristate::TRUE)
	    return (nts::Tristate::FALSE);
	  else
	    return (nts::Tristate::TRUE);
	}
    }
  return (_previous[num]);
}

/*
** Setting link
*/
void		nts::c4013::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if ((pin_num_this >= 1 && pin_num_this <= 6) || (pin_num_this >= 8 && pin_num_this <= 13))
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already linked for 4013");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4013");
}

/*
** Dumping
*/
void	nts::c4013::Dump() const
{
}

/*
** Destructor
*/
nts::c4013::~c4013()
{

}
