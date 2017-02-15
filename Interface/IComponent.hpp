//
// IComponent.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 15:50:27 2017 Victorien Fischer
// Last update Wed Feb 15 21:06:46 2017 Arnaud WURMEL
//

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

#include <unistd.h>

namespace	nts
{
  enum		Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };

  class		IComponent
  {
  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1) = 0;
    virtual void		SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target) = 0;
    virtual void		Dump(void) const = 0;
    virtual			~IComponent(void) {}
  };
}

#endif // __ICOMPONENT_HPP__
