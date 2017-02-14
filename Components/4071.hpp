//
// 4071.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Tue Feb 14 16:37:22 2017 Victorien Fischer
//

#ifndef __4071_HPP__
# define __4071_HPP__

#include "IComponent.hpp"

class	4071 : public IComponent
{
public:
  4071();
  virtual ~4071();

public:
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  virtual void		Dump(void) const;
};

#endif
