//
// 4040.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Tue Feb 14 16:36:00 2017 Victorien Fischer
//

#ifndef __4040_HPP__
# define __4040_HPP__

#include "IComponent.hpp"

class	4040 : public IComponent
{
public:
  4040();
  virtual ~4040();

public:
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
  virtual void		SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  virtual void		Dump(void) const;
};

#endif
