//
// c4514.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Sat Mar  4 15:15:29 2017 Victorien Fischer
//

#ifndef __C4514_HPP__
# define __C4514_HPP__

#include <string>
#include "Component.hpp"
#include "IComponent.hpp"

namespace nts
{
  class	c4514 : public nts::Component
  {
  public:
    c4514(const std::string &);
    virtual ~c4514();
    
  public:
    virtual nts::Tristate	ComputeOutput(size_t);
    virtual void		SetLink(size_t, nts::IComponent &, size_t);
    virtual void		Dump() const;

  public:
    nts::Tristate		getOutputForPin(size_t);

  private:
    void			addComputeFunction(size_t);
    bool			_inputs[4];
  };
}

#endif
