//
// 4008.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Wed Mar  1 15:32:07 2017 Arnaud WURMEL
//

#include <iostream>
#include <string>
#include "Errors.hpp"
#include "c4008.hpp"

nts::c4008::c4008(const std::string &value) : _outputs(14), _links(0)
{
  (void)value;
  _outputs[10] = std::make_pair(6, 7);
  _outputs[11] = std::make_pair(4, 5);
  _outputs[12] = std::make_pair(2, 3);
  _outputs[13] = std::make_pair(1, 15);
}

bool	nts::c4008::getValueForPin(size_t pin)
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

nts::Tristate	nts::c4008::Compute(size_t pin_num_this)
{
  size_t	i;
  int		input[4];
  char		ret;

  input[0] = 0;
  input[1] = 0;
  input[2] = 0;
  input[3] = 0;
  if (_links.size() < 14)
    throw Errors("Missing link for c4008");
  i = 0;
  ret = 0;
  if (getValueForPin(9))
    ret = 1;
  while (i < 4)
    {
      if (ret)
	{
	  input[i] += 1;
	  ret = 0;
	}
      if (getValueForPin(_outputs[i + 10].first))
	input[i] += 1;
      if (getValueForPin(_outputs[i + 10].second))
	input[i] += 1;
      if (input[i] > 1)
	{
	  input[i] -= 2;
	  ret = 1;
	}
      ++i;
    }
  if (pin_num_this == 14)
    return (ret == 1 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
  return (input[pin_num_this - 10] == 1 ? nts::Tristate::TRUE : nts::Tristate::FALSE);
}

bool	nts::c4008::alreadyLink(size_t pin)
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

void	nts::c4008::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{

  if (pin_num_this >= 1 && pin_num_this <= 15 && pin_num_this != 16 &&
      pin_num_this != 8)
    {
      if (alreadyLink(pin_num_this))
	throw Errors("Pin already linked");
      _links.push_back(std::make_pair(pin_num_this, std::make_pair(pin_num_target, &component)));
      return ;
    }
  throw Errors("Wrong pin for 4008");
}

void	nts::c4008::Dump() const
{
  
}

nts::c4008::~c4008()
{

}
