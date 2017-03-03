//
// c4040.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Fri Mar  3 15:16:21 2017 Arnaud WURMEL
//

#ifndef __C4040_HPP__
# define __C4040_HPP__

#include <string>
#include <map>
#include "Component.hpp"
#include "IComponent.hpp"

namespace nts
{
  class	c4040 : public nts::Component
  {
  public:
    c4040(const std::string &);
    virtual ~c4040();
    
  public:
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump() const;
    virtual nts::Tristate	ComputeOutput(size_t);

  public:
    bool			isCorrectPin(size_t);
    void			resetOutput(void);

  private:
    void			addComputeFunction(size_t);
    
  private:
    std::map<size_t, size_t>	_pins;
    char			_outputs[12];
    size_t			_sim_id;
    nts::Tristate		_prev_state;
  };
}

#endif
