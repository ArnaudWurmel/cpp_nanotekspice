//
// c4017.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 10:35:38 2017 Victorien Fischer
//

#include "c4017.hpp"
#include "Errors.hpp"

/*
** Constructor
*/
nts::c4017::c4017(const std::string &value) : Component(value)
{
  size_t	i;

  i = 0;
  while (++i < 13)
    addComputeFunction(i);
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
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4017::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  if (pin_num_this >= 13 && pin_num_this <= 15)
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
