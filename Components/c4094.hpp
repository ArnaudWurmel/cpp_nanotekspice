//
// c4094.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Sat Mar  4 17:52:49 2017 Arnaud WURMEL
//

#ifndef __C4094_HPP__
# define __C4094_HPP__

# define STROBE 1
# define DATA 2
# define CLOCK 3
# define OUTPUT 15

#include <string>
#include "Component.hpp"
#include "IComponent.hpp"
#include "NanoTekSpice.hpp"

namespace nts
{
  class	c4094 : public nts::Component
  {
  public:
    c4094(const std::string &);
    virtual ~c4094();
    
  public:
    virtual nts::Tristate	ComputeOutput(size_t);
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump() const;

  private:
    void			addComputeFunction(size_t);

  private:
    nts::Tristate		_prev_clock;
    std::map<size_t, size_t>	_outputs;
    nts::Tristate		_value[10];
    size_t			_sim_id;
  };
}

#endif
