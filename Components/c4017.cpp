//
// c4017.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Sun Mar  5 03:19:51 2017 Victorien Fischer
//

#include "c4017.hpp"
#include "Errors.hpp"

/*
** Constructor
*/
nts::c4017::c4017(const std::string &value) : Component(value)
{
  size_t	i;

  _simid = 1;
  _simidout = 1;
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
  _currentOut = 0;
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
  if (pin_num_this == 12)
    {
      if (_currentOut < 5)
	return (nts::Tristate::TRUE);
      if (_simidout == nts::NanoTekSpice::_sim_id - 1)
	if (_currentOut < 6)
	  return (nts::Tristate::TRUE);
      if (_prevCP0 == FALSE && _currentOut == 10)
	return (nts::Tristate::TRUE);
      return (nts::Tristate::FALSE);
    }
  if (_simid != nts::NanoTekSpice::_sim_id)
    {
      _simid = nts::NanoTekSpice::_sim_id;
      _prevCP0 = (getValueForPin(14)) ? (nts::Tristate::TRUE) : (nts::Tristate::FALSE);
      _prevCP1 = (getValueForPin(13)) ? (nts::Tristate::TRUE) : (nts::Tristate::FALSE);
    }
  if (getValueForPin(15))
    return (nts::Tristate::UNDEFINED);
  if (_prevCP0 == nts::Tristate::TRUE)
    {
      if (_currentOut == 10)
	_currentOut = 0;
      if (_output[_currentOut] == pin_num_this)
	if (_simidout != nts::NanoTekSpice::_sim_id)
	  {
	    _simidout = nts::NanoTekSpice::_sim_id;
	    _currentOut += 1;
	    return (nts::Tristate::TRUE);
	  }
      return (nts::Tristate::FALSE);
    }
  else if (_prevCP0 == nts::Tristate::FALSE)
    {
      if (_currentOut == 0)
	_currentOut += 1;
      if (_output[_currentOut - 1] == pin_num_this)
	return (nts::Tristate::TRUE);
      return (nts::Tristate::FALSE);
    }
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
