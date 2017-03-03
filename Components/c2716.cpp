//
// c2716.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 08:25:50 2017 Victorien Fischer
//

#include "c2716.hpp"

/*
** Constructor
*/
nts::c2716::c2716(const std::string &value) : Component(value)
{
  _computeFunctions.insert(std::make_pair(12, std::bind(&nts::c2716::ComputeOnVSS, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(24, std::bind(&nts::c2716::ComputeOnVDD, this, std::placeholders::_1)));
}

/*
** Link a pin to a compute function
*/
void		nts::c2716::addComputeFunction(size_t pin)
{
  _computeFunctions.insert(std::make_pair(pin, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
}

/*
** Called from map in order to compute a output
*/
nts::Tristate	nts::c2716::ComputeOutput(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c2716::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

/*
** Dumping
*/
void	nts::c2716::Dump() const
{
}

/*
** Destructor
*/
nts::c2716::~c2716()
{
}
