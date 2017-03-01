//
// c4069.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Wed Mar  1 16:48:33 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include "Errors.hpp"
#include "c4069.hpp"

nts::c4069::c4069(const std::string &value)
{
  (void)value;
  _outputs[2] = 1;
  _outputs[4] = 3;
  _outputs[6] = 5;
  _outputs[8] = 9;
  _outputs[10] = 11;
  _outputs[12] = 13;
}

nts::Tristate	nts::c4069::Compute(size_t pin_num_this)
{
  if (!alreadyLink(_outputs[pin_num_this]))
    throw Errors("Missing link for c4069");
  if (getValueForPin(_outputs[pin_num_this]))
    return (nts::Tristate::FALSE);
  return (nts::Tristate::TRUE);
}

bool		nts::c4069::getValueForPin(size_t pin)
{
  std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >::iterator	it;

  it = _links.begin();
  while (it != _links.end())
    {
      if ((*it).first == pin)
	return ((*it).second.second->Compute((*it).second.first));
      ++it;
    }
  return (false);
}

bool	nts::c4069::alreadyLink(size_t pin)
{
  std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >::iterator	it;

  it = _links.begin();
  while (it != _links.end())
    {
      if ((*it).first == pin)
	return ((*it).second.second->Compute((*it).second.first));
      ++it;
    }
  return (false);
}

void	nts::c4069::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 1 && pin_num_this <= 13 && pin_num_this != 7)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already link for 4069");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
      return ;
    }
  throw Errors("Wrong link for pin on 4069");
}

void	nts::c4069::Dump() const
{

}

nts::c4069::~c4069()
{

}
