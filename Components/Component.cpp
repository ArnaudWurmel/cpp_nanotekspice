//
// Component.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Mar  1 18:51:53 2017 Victorien Fischer
// Last update Fri Mar  3 00:08:21 2017 Arnaud WURMEL
//

#include <iostream>
#include "Component.hpp"

/*
** Constructor
*/
nts::Component::Component(const std::string &value) : _links(0)
{
  (void)value;
}


/*
** Is PIN Already Linked ? 
*/
bool		nts::Component::alreadyLink(size_t pin) const
{
  std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >::const_iterator	it;

  it = _links.begin();
  while (it != _links.end())
    {
      if ((*it).first == pin)
	return (true);
      ++it;
    }
  return (false);
}

/*
** Get Value of PIN
*/
bool		nts::Component::getValueForPin(size_t pin) const
{
  std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >::const_iterator	it;

  it = _links.begin();
  while (it != _links.end())
    {
      if ((*it).first == pin)
	return ((*it).second.second->Compute((*it).second.first));
      ++it;
    }
  return (false);
}

nts::Tristate	nts::Component::ComputeOnVSS(size_t pin) const
{
  std::cerr << "Asked compute on VSS, undefined state returned on pin : " << pin << std::endl;
  return (nts::Tristate::UNDEFINED);
}

nts::Tristate	nts::Component::ComputeOnVDD(size_t pin) const
{
  std::cerr << "Asked compute on VDD, undefined state returned on pin : " << pin << std::endl;
  return (nts::Tristate::UNDEFINED);
}

/*
** Destructor
*/
nts::Component::~Component()
{
}
