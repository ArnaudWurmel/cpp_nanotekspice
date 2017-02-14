//
// ComponentFactory.hpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 17:12:17 2017 Victorien Fischer
// Last update Tue Feb 14 23:41:34 2017 Victorien Fischer
//

#ifndef __COMPONENTFACTORY_HPP__
# define __COMPONENTFACTORY_HPP__

#include <map>
#include <string>
#include <functional>
#include <utility>
#include "IComponent.hpp"
#include "c4001.hpp"
#include "c4008.hpp"
#include "c4011.hpp"
#include "c4013.hpp"
#include "c4017.hpp"
#include "c4030.hpp"
#include "c4040.hpp"
#include "c4069.hpp"
#include "c4071.hpp"
#include "c4081.hpp"
#include "c4094.hpp"
#include "c4514.hpp"
#include "c4801.hpp"
#include "c2716.hpp"

namespace nts
{
  class	ComponentFactory
  {
  public:
    ComponentFactory();
    virtual ~ComponentFactory();
    
  public:
    IComponent	*createComponent(const std::string &,
					 const std::string &);
    
  private:
    std::map<std::string, std::function<IComponent *(const std::string &)>>	_mapComponent;
    
  private:
    IComponent	*create4001(const std::string &) const;
    IComponent	*create4008(const std::string &) const;
    IComponent	*create4011(const std::string &) const;
    IComponent	*create4013(const std::string &) const;
    IComponent	*create4017(const std::string &) const;
    IComponent	*create4030(const std::string &) const;
    IComponent	*create4040(const std::string &) const;
    IComponent	*create4069(const std::string &) const;
    IComponent	*create4071(const std::string &) const;
    IComponent	*create4081(const std::string &) const;
    IComponent	*create4094(const std::string &) const;
    IComponent	*create4514(const std::string &) const;
    IComponent	*create4801(const std::string &) const;
    IComponent	*create2716(const std::string &) const;
  };
}

#endif
