//
// c4013.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Fri Mar  3 00:56:54 2017 Arnaud WURMEL
//

#ifndef __C4013_HPP__
# define __C4013_HPP__

#include <string>
#include "Component.hpp"
#include "IComponent.hpp"

namespace nts
{
  class	c4013 : public nts::Component
  {
  public:
    c4013(const std::string &);
    virtual ~c4013();
    
  public:
    virtual nts::Tristate	ComputeOutput(size_t pin_num_this = 1);
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump() const;

  public:
    nts::Tristate		getOutputValue(bool, bool, bool) const;

  private:
    nts::Tristate		_previous[2];
  };
}

#endif
