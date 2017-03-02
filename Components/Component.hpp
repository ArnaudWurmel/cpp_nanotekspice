//
// Component.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Wed Mar  1 18:45:53 2017 Victorien Fischer
// Last update Fri Mar  3 00:07:51 2017 Arnaud WURMEL
//

#ifndef __COMPONENT_HPP__
# define __COMPONENT_HPP__

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include "IComponent.hpp"

namespace nts
{
  class Component : public nts::IComponent
  {
  public:
    Component(const std::string &);
    virtual ~Component();

  public:
    virtual nts::Tristate	Compute(size_t pin_num_this = 1) = 0;
    virtual void		SetLink(size_t, nts::IComponent &, size_t) = 0;
    virtual void		Dump() const = 0;

  public:
    bool			alreadyLink(size_t) const;
    bool			getValueForPin(size_t) const;

    virtual nts::Tristate		ComputeOnVSS(size_t) const;
    virtual nts::Tristate		ComputeOnVDD(size_t) const;
    virtual nts::Tristate		ComputeOutput(size_t) = 0;

  protected:
    std::vector<std::pair<size_t, std::pair<size_t, IComponent *> > >	_links;
    std::map<size_t, std::function<nts::Tristate (size_t)> >	_computeFunctions;
  };
}
#endif
