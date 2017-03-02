//
// c4013.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Thu Mar  2 20:27:53 2017 Victorien Fischer
//

#include "c4013.hpp"
#include "Errors.hpp"

/*
** Constructor
*/
nts::c4013::c4013(const std::string &value) : Component(value)
{
}

/*
** Getting Output Value from Pins' value
*/
nts::Tristate	nts::c4013::getOutputValue(bool set, bool reset, bool data) const
{
  if (!set && !reset)
    return (((data) ? (nts::Tristate::TRUE) : (nts::Tristate::FALSE)));
  else if (set && !reset)
    return (nts::Tristate::TRUE);
  else if (!set && reset)
    return (nts::Tristate::FALSE);
  else
    return (nts::Tristate::TRUE);
}

/*
** Computing
*/
nts::Tristate	nts::c4013::Compute(size_t pin_num_this)
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
  if (!(vclock && !vreset && !vset))
    _previous[num] = getOutputValue(vset, vreset, vdata);
  if ((pin_num_this == 2 || pin_num_this == 12) && !(vset && vreset))
    {
      if (_previous[num] == nts::Tristate::TRUE)
	return (nts::Tristate::FALSE);
      return (nts::Tristate::TRUE);
    }
  return (_previous[num]);
}

/*
** Setting link
*/
void		nts::c4013::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if ((pin_num_this >= 3 && pin_num_this <= 6) || (pin_num_this >= 8 && pin_num_this <= 11))
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
