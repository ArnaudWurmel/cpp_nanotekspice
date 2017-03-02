//
// c4040.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Thu Mar  2 14:21:09 2017 Victorien Fischer
//

#include <iostream>
#include "Errors.hpp"
#include "c4040.hpp"
#include "NanoTekSpice.hpp"

/*
** Constructor
*/
nts::c4040::c4040(const std::string &value) : Component(value)
{
  size_t	i;

  i = 0;
  _sim_id = 0;
  while (i < 12)
    {
      _outputs[i] = 0;
      ++i;
    }
  _pins[9] = 11;
  _pins[7] = 10;
  _pins[6] = 9;
  _pins[5] = 8;
  _pins[3] = 7;
  _pins[2] = 6;
  _pins[4] = 5;
  _pins[13] = 4;
  _pins[12] = 3;
  _pins[14] = 2;
  _pins[15] = 1;
  _pins[1] = 0;
}

/*
** Resetting Output
*/
void	nts::c4040::resetOutput(void)
{
  size_t	i;

  i = 0;
  while (i < 12)
    {
      _outputs[i] = 0;
      ++i;
    }
}

/*
** Is Correct Pin
*/
bool	nts::c4040::isCorrectPin(size_t pin_num_this)
{
  return ((pin_num_this >= 1 && pin_num_this <= 7) ||
	  (pin_num_this >= 12 && pin_num_this <= 15) ||
	  pin_num_this == 9);
}

/*
** Computing
*/
nts::Tristate	nts::c4040::Compute(size_t pin_num_this)
{
  bool		clock;
  bool		reset;
  int		i;
  size_t	ret;

  if (_sim_id != nts::NanoTekSpice::_sim_id)
    {
      if (isCorrectPin(pin_num_this))
	{
	  clock = getValueForPin(10);
	  reset = getValueForPin(11);
	  if (!clock)
	    {
	      i = 11;
	      _outputs[i] += 1;
	      ret = 0;
	      while (i >= 0)
		{
		  if (ret)
		    {
		      _outputs[i] += ret;
		      ret = 0;
		    }
		  if (_outputs[i] >= 2)
		    {
		      _outputs[i] -= 2;
		      ret = 1;
		    }
		  --i;
		}
	    }
	  if (reset)
	    resetOutput();
	}
      else
	throw Errors("Wrong pin for compute");
    }
  _sim_id = nts::NanoTekSpice::_sim_id;
  if (_outputs[_pins[pin_num_this]] == 1)
    return (nts::Tristate::TRUE);
  return (nts::Tristate::FALSE);
}

/*
** Setting Link
*/
void	nts::c4040::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 15 && pin_num_this != 8)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4040");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
    }
  else
    throw Errors("Wrong pin for 4040");
}

/*
** Dumping
*/
void	nts::c4040::Dump() const
{
}

/*
** Destructor
*/
nts::c4040::~c4040()
{
}
