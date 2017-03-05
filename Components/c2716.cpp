//
// c2716.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:40:02 2017 Victorien Fischer
// Last update Sun Mar  5 20:32:15 2017 Arnaud WURMEL
//

#include <fstream>
#include <iostream>
#include "c2716.hpp"
#include "Errors.hpp"

/*
** Constructor
*/
nts::c2716::c2716(const std::string &value) : Component(value)
{
  throw Errors("Component not implemented yet");
  _computeFunctions.insert(std::make_pair(12, std::bind(&nts::c2716::ComputeOnVSS, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(24, std::bind(&nts::c2716::ComputeOnVDD, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(9, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(10, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(11, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(13, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(14, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(15, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(16, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));
  _computeFunctions.insert(std::make_pair(17, std::bind(&nts::c2716::ComputeOutput, this, std::placeholders::_1)));

  _inputs[10] = 19;
  _inputs[9] = 22;
  _inputs[8] = 23;
  _inputs[7] = 1;
  _inputs[6] = 2;
  _inputs[5] = 3;
  _inputs[4] = 4;
  _inputs[3] = 5;
  _inputs[2] = 6;
  _inputs[1] = 7;
  _inputs[0] = 8; 
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
  static_cast<void>(pin_num_this);
  return (nts::Tristate::UNDEFINED);
}

/*
** Setting Link
*/
void	nts::c2716::SetLink(size_t pin_num_this, nts::IComponent &component,
			    size_t pin_num_target)
{
  static_cast<void>(pin_num_this);
  static_cast<void>(component);
  static_cast<void>(pin_num_target);
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
