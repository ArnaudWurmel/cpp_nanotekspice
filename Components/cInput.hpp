//
// cInput.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 22:29:53 2017 Victorien Fischer
// Last update Mon Feb 27 16:05:46 2017 Arnaud WURMEL
//

#ifndef __CINPUT_HPP__
# define __CINPUT_HPP__

#include <string>
#include <utility>
#include <iostream>
#include "IComponent.hpp"

namespace nts
{
  class cInput : public IComponent
  {
  public:
    cInput(const std::string &);
    virtual	~cInput();

  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1);
    virtual void		SetLink(size_t,	nts::IComponent &, size_t);
    virtual void		Dump(void) const;
    void			setValue(nts::Tristate const&);

  private:
    nts::Tristate		_value;
    nts::IComponent		*_component;
    std::pair<size_t, size_t>	*_link;
  };
}

#endif
