//
// c2716.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 00:10:18 2017 Arnaud WURMEL
//

#include "c2716.hpp"

/*
** Constructor
*/
nts::c2716::c2716(const std::string &value) : Component(value)
{
  
}

/*
** Computing
*/
nts::Tristate	nts::c2716::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

/*
** Called from map in order to compute a output
*/
nts::Tristate	nts::c2716::ComputeOutput(size_t pin_num_this)
{

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
