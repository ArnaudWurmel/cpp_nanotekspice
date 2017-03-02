//
// c4013.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Thu Mar  2 14:41:21 2017 Victorien Fischer
//

#include "c4013.hpp"

/*
** Constructor
*/
nts::c4013::c4013(const std::string &value) : Component(value)
{
}

/*
** Computing
*/
nts::Tristate	nts::c4013::Compute(size_t pin_num_this)
{
  (void)pin_num_this;
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting link
*/
void	nts::c4013::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
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
