//
// cOutput.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 22:29:53 2017 Victorien Fischer
// Last update Mon Feb 27 17:18:47 2017 Arnaud WURMEL
//

#ifndef __COUTPUT_HPP__
# define __COUTPUT_HPP__

#include <string>
#include <utility>
#include <iostream>
#include "IComponent.hpp"

namespace nts
{
  class cOutput : public IComponent
  {
  public:
    cOutput(const std::string &);
    virtual	~cOutput();

  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1);
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump(void) const;
    nts::Tristate const&	getValue() const;

  private:
    nts::IComponent		*_component;
    std::pair<size_t, size_t>	*_link;
    nts::Tristate		_value;
  };
}

#endif
