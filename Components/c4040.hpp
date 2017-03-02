//
// c4040.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Thu Mar  2 14:42:11 2017 Victorien Fischer
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
    virtual nts::Tristate	Compute(size_t pin_num_this = 1);
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump() const;

  public:
    bool			isCorrectPin(size_t);
    void			resetOutput(void);
    
  private:
    std::map<size_t, size_t>	_pins;
    char			_outputs[12];
    size_t			_sim_id;
  };
}

#endif
