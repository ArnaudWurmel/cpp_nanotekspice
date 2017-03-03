//
// c4514.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 01:11:17 2017 Victorien Fischer
//

#include <string>
#include "Errors.hpp"
#include "c4514.hpp"

/*
** Output Map
*/
const static size_t	_output[17][5] =
  {
    // A, B, C, D, SX
    { 0, 0, 0, 0, 11 },
    { 1, 0, 0, 0, 10 },
    { 0, 1, 0, 0, 9 },
    { 1, 1, 0, 0, 8 },
    { 0, 0, 1, 0, 7 },
    { 1, 0, 1, 0, 6 },
    { 0, 1, 1, 0, 5 },
    { 1, 1, 1, 0, 4 },
    { 0, 0, 0, 1, 18 },
    { 1, 0, 0, 1, 17 },
    { 0, 1, 0, 1, 20 },
    { 1, 1, 0, 1, 19 },
    { 0, 0, 1, 1, 16 },
    { 1, 0, 1, 1, 15 },
    { 1, 1, 1, 0, 14 },
    { 1, 1, 1, 1, 13 },
    0
  };

/*
** Constructor
*/
nts::c4514::c4514(const std::string &value) : Component(value)
{
  size_t	i;

  i = 3;
  while (++i < 21)
    if (i != 12)
      addComputeFunction(i);
}

/*
** Link a pin to a compute function
*/
void		nts::c4514::addComputeFunction(size_t pin)
{
  _computeFunctions.insert(std::make_pair(pin, std::bind(&nts::c4514::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Getting Output for Pin
*/
nts::Tristate		nts::c4514::getOutputForPin(size_t pin)
{
  int			i;

  i = 0;
  while (_output[i] && _output[i][4] != pin)
    i++;
  if (_output[i])
    if (_output[i][0] == getValueForPin(2) && _output[i][1] == getValueForPin(3) &&
	_output[i][2] == getValueForPin(21) && _output[i][3] == getValueForPin(22))
      return (nts::Tristate::TRUE);
  return (nts::Tristate::FALSE);
}

/*
** Computing
*/
nts::Tristate	nts::c4514::ComputeOutput(size_t pin)
{
  if (getValueForPin(1))
    return (nts::Tristate::FALSE);
  else
    {
      if (!alreadyLink(2) || !alreadyLink(3) || !alreadyLink(21) || !alreadyLink(22))
	throw Errors("Missing link for pin in 4514");
      return (getOutputForPin(pin));
    }
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4514::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this == 12 || pin_num_this == 24)
    throw Errors("Wrong pin for 4514");
  if (alreadyLink(pin_num_this))
    throw Errors("Pin already link for 4514");
  _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
}

/*
** Dumping
*/
void	nts::c4514::Dump() const
{
}

/*
** Destructor
*/
nts::c4514::~c4514()
{
}
