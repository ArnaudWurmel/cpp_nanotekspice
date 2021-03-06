//
// c4801.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Sun Mar  5 20:33:52 2017 Arnaud WURMEL
//

#include <string>
#include "Errors.hpp"
#include "c4801.hpp"

/*
** Constructor
*/
nts::c4801::c4801(const std::string &value) : Component(value)
{
  throw Errors("Component not implemented yet");
  _computeFunctions.insert(std::make_pair(12, std::bind(&nts::c4801::ComputeOnVSS, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(24, std::bind(&nts::c4801::ComputeOnVDD, this, std::placeholders::_1)));
}

/*
** Computing
*/
nts::Tristate	nts::c4801::ComputeOutput(size_t pin_num_this)
{
  static_cast<void>(pin_num_this);
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c4801::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  static_cast<void>(pin_num_this);
  static_cast<void>(component);
  static_cast<void>(pin_num_target);
}

/*
** Dumping
*/
void	nts::c4801::Dump() const
{
}

/*
** Destructor
*/
nts::c4801::~c4801()
{
}
