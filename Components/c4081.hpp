//
// c4081.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Fri Mar  3 01:13:55 2017 Victorien Fischer
//

#ifndef __C4081_HPP__
# define __C4081_HPP__

#include <string>
#include "Component.hpp"
#include "IComponent.hpp"

namespace nts
{
  class	c4081 : public nts::Component
  {
  public:
    c4081(const std::string &);
    virtual ~c4081();
    
  public:
    virtual nts::Tristate	ComputeOutput(size_t);
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump() const;

  private:
    void			addComputeFunction(size_t);
  };
}

#endif
