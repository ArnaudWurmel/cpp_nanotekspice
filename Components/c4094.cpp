//
// c4094.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 08:48:11 2017 Victorien Fischer
//

#include "c4094.hpp"

/*
** Constructor
*/
nts::c4094::c4094(const std::string &value) : Component(value)
{
  _computeFunctions.insert(std::make_pair(8, std::bind(&nts::c4094::ComputeOnVSS, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(16, std::bind(&nts::c4094::ComputeOnVDD, this, std::placeholders::_1)));
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
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4094::SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
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
