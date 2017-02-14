//
// c4081.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Tue Feb 14 23:26:16 2017 Victorien Fischer
//

#ifndef __C4081_HPP__
# define __C4081_HPP__

#include <string>
#include "IComponent.hpp"

namespace nts
{
  class	c4081 : public nts::IComponent
  {
  public:
    c4081(const std::string &);
    virtual ~c4081();
    
  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1);
    virtual void		SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target);
    virtual void		Dump(void) const;
  };
}

#endif
