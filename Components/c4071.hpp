//
// c4071.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice/Components
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 16:17:27 2017 Victorien Fischer
// Last update Tue Feb 28 13:14:01 2017 Arnaud WURMEL
//

#ifndef __C4071_HPP__
# define __C4071_HPP__

#include <string>
#include <vector>
#include <functional>
#include <utility>
#include "IComponent.hpp"

namespace nts
{
  class	c4071 : public nts::IComponent
  {
  public:
    c4071(const std::string &);
    virtual ~c4071();
    
  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1);
    virtual void		SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target);
    virtual void		Dump(void) const;

  public:
    bool			alreadyLink(size_t);
    bool			getValueForPin(size_t);
    
  private:
    std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >	_links;
  };
}

#endif
