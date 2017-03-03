//
// c4001.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Fri Mar  3 01:17:23 2017 Victorien Fischer
//

#ifndef __C4001_HPP__
# define __C4001_HPP__

#include <string>
#include "Component.hpp"
#include "IComponent.hpp"

namespace nts
{
  class	c4001 : public nts::Component
  {
  public:
    c4001(const std::string &);
    virtual ~c4001();
    
  public:
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump() const;
    virtual nts::Tristate	ComputeOutput(size_t);

  private:
    void			addComputeFunction(size_t);
  };
}

#endif
