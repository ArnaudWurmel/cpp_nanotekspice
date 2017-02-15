//
// cInput.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Feb 15 22:29:53 2017 Victorien Fischer
// Last update Wed Feb 15 23:44:34 2017 Victorien Fischer
//

#ifndef __CINPUT_HPP__
# define __CINPUT_HPP__

#include <string>
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
  };
}

#endif
