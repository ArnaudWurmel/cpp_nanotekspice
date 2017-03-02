//
// c4008.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Fri Mar  3 00:49:12 2017 Arnaud WURMEL
//

#ifndef __C4008_HPP__
# define __C4008_HPP__

#include <string>
#include <vector>
#include "Component.hpp"
#include "IComponent.hpp"

namespace nts
{
  class	c4008 : public nts::Component
  {
  public:
    c4008(const std::string &);
    virtual ~c4008();
    
  public:
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump(void) const;
    
  public:
    virtual nts::Tristate	ComputeOutput(size_t);
  private:
    std::vector<std::pair<size_t, size_t> >	_outputs;
  };
}

#endif
