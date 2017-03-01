//
// c4040.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Wed Mar  1 23:05:17 2017 Arnaud WURMEL
//

#include <iostream>
#include "Errors.hpp"
#include "c4040.hpp"
#include "NanoTekSpice.hpp"

nts::c4040::c4040(const std::string &value)
{
  size_t	i;

  (void)value;
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

bool	nts::c4040::getValueForPin(size_t pin)
{
  std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >::iterator	it;

  it = _links.begin();
  while (it != _links.end())
    {
      if ((*it).first == pin)
  	{
  	  return ((*it).second.second->Compute((*it).second.first));
  	}
      ++it;
    }
  return (false);
}

nts::Tristate	nts::c4040::Compute(size_t pin_num_this)
{
  bool		clock;
  bool		reset;
  int		i;
  size_t	ret;

  if (_sim_id != nts::NanoTekSpice::_sim_id)
    {
      if ((pin_num_this >= 1 && pin_num_this <= 7) || (pin_num_this >= 12 && pin_num_this <= 15) || pin_num_this == 9)
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
	    {
	      i = 0;
	      while (i < 12)
		{
		  _outputs[i] = 0;
		  ++i;
		}
	    }
	}
      else
	{
	  throw Errors("Wrong pin for compute");
	  return (nts::Tristate::UNDEFINED);
	}
    }
  _sim_id = nts::NanoTekSpice::_sim_id;
  if (_outputs[_pins[pin_num_this]] == 1)
    return (nts::Tristate::TRUE);
  return (nts::Tristate::FALSE);
}

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

bool	nts::c4040::alreadyLink(size_t pin)
{
  std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >::iterator	it;

  it = _links.begin();
  while (it != _links.end())
    {
      if ((*it).first == pin)
	return (true);
      ++it;
    }
  return (false);
}

void	nts::c4040::Dump() const
{

}

nts::c4040::~c4040()
{

}
