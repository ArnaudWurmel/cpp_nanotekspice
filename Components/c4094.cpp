//
// c4094.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Sat Mar  4 19:05:27 2017 Arnaud WURMEL
//

#include <iostream>
#include "Errors.hpp"
#include "c4094.hpp"

/*
** Constructor
*/
nts::c4094::c4094(const std::string &value) : Component(value), _sim_id(0)
{
  _computeFunctions.insert(std::make_pair(8, std::bind(&nts::c4094::ComputeOnVSS, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(16, std::bind(&nts::c4094::ComputeOnVDD, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(4, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(5, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(6, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(7, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(14, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(13, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(12, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(11, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(10, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(9, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
  _outputs.insert(std::make_pair(4, 0));
  _outputs.insert(std::make_pair(5, 1));
  _outputs.insert(std::make_pair(6, 2));
  _outputs.insert(std::make_pair(7, 3));
  _outputs.insert(std::make_pair(14, 4));
  _outputs.insert(std::make_pair(13, 5));
  _outputs.insert(std::make_pair(12, 6));
  _outputs.insert(std::make_pair(11, 7));
  _outputs.insert(std::make_pair(10, 8));
  _outputs.insert(std::make_pair(9, 9));
  for (size_t i = 0; i < 8; i++) {
    _value[i] = nts::Tristate::FALSE;
  }
  _value[8] = nts::Tristate::UNDEFINED;
  _value[9] = nts::Tristate::UNDEFINED;
  _prev_clock = nts::Tristate::UNDEFINED;
}

/*
** Link a pin to a compute function
*/
void		nts::c4094::addComputeFunction(size_t pin)
{
  _computeFunctions.insert(std::make_pair(pin, std::bind(&nts::c4094::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Compute on output
*/
nts::Tristate	nts::c4094::ComputeOutput(size_t pin_num_this)
{
  bool	clock = getValueForPin(CLOCK);
  bool	data = getValueForPin(DATA);
  bool	strobe = getValueForPin(STROBE);
  bool	output = getValueForPin(OUTPUT);
  size_t	bit_decal;

  if (_sim_id != nts::NanoTekSpice::_sim_id)
    {
      _sim_id = nts::NanoTekSpice::_sim_id;
      if (clock && _prev_clock != nts::Tristate::UNDEFINED)
	{
	  bit_decal = 8;
	  while (bit_decal > 0)
	    {
	      _value[bit_decal] = _value[bit_decal - 1];
	      --bit_decal;
	    }
	}
      else if (!clock && _prev_clock != nts::Tristate::UNDEFINED)
	_value[9] = _value[8];
      if (strobe)
	_value[0] = data ? nts::Tristate::TRUE : nts::Tristate::FALSE;
      else
	_value[0] = nts::Tristate::FALSE;
      _prev_clock = clock ? nts::Tristate::TRUE : nts::Tristate::FALSE;
    }
  if (output && _outputs.find(pin_num_this) != _outputs.end())
    return (_value[_outputs[pin_num_this]]);
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4094::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 16)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4094");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4094");
}

/*
** Dumping
*/
void	nts::c4094::Dump() const
{
}

/*
** Destructor
*/
nts::c4094::~c4094()
{
}
