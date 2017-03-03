//
// c4017.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Fri Mar  3 00:58:30 2017 Arnaud WURMEL
//

#include "c4017.hpp"

/*
** Constructor
*/
nts::c4017::c4017(const std::string &value) : Component(value)
{
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
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
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
