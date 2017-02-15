//
// ComponentFactory.cpp for NanoTekSpice in /home/vicky/Bureau/EPITECH/tek2-2/C++/cpp_nanotekspice
// 
// Made by Victorien Fischer
// Login   <victorien.fischer@epitech.eu>
// 
// Started on  Tue Feb 14 17:17:32 2017 Victorien Fischer
// Last update Wed Feb 15 20:57:37 2017 Arnaud WURMEL
//

#include <algorithm>
#include "ComponentFactory.hpp"

nts::ComponentFactory::ComponentFactory()
{
  _mapComponent.insert(std::make_pair("4001", std::bind(&nts::ComponentFactory::create4001, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4008", std::bind(&nts::ComponentFactory::create4008, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4011", std::bind(&nts::ComponentFactory::create4011, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4013", std::bind(&nts::ComponentFactory::create4013, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4017", std::bind(&nts::ComponentFactory::create4017, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4030", std::bind(&nts::ComponentFactory::create4030, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4040", std::bind(&nts::ComponentFactory::create4040, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4069", std::bind(&nts::ComponentFactory::create4069, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4071", std::bind(&nts::ComponentFactory::create4071, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4081", std::bind(&nts::ComponentFactory::create4081, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4094", std::bind(&nts::ComponentFactory::create4094, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4514", std::bind(&nts::ComponentFactory::create4514, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("4801", std::bind(&nts::ComponentFactory::create4801, this, std::placeholders::_1)));
  _mapComponent.insert(std::make_pair("2716", std::bind(&nts::ComponentFactory::create2716, this, std::placeholders::_1)));
}

/*
** Creates a component
*/
nts::IComponent	*nts::ComponentFactory::createComponent(const std::string &type, const std::string &value)
{
  if (_mapComponent.find(type) != _mapComponent.end())
    return (_mapComponent[type](value));
  return (NULL);
}

/*
** Creates c4001
*/
nts::IComponent	*nts::ComponentFactory::create4001(const std::string &value) const
{
  return (new c4001(value));
}

/*
** Creates c4008
*/
nts::IComponent	*nts::ComponentFactory::create4008(const std::string &value) const
{
  return (new c4008(value));
}

/*
** Creates c4011
*/
nts::IComponent	*nts::ComponentFactory::create4011(const std::string &value) const
{
  return (new c4011(value));
}

/*
** Creates c4013
*/
nts::IComponent	*nts::ComponentFactory::create4013(const std::string &value) const
{
  return (new c4013(value));
}

/*
** Creates c4017
*/
nts::IComponent	*nts::ComponentFactory::create4017(const std::string &value) const
{
  return (new c4017(value));
}

/*
** Creates c4030
*/
nts::IComponent	*nts::ComponentFactory::create4030(const std::string &value) const
{
  return (new c4030(value));
}

/*
** Creates c4040
*/
nts::IComponent	*nts::ComponentFactory::create4040(const std::string &value) const
{
  return (new c4040(value));
}

/*
** Creates c4069
*/
nts::IComponent	*nts::ComponentFactory::create4069(const std::string &value) const
{
  return (new c4069(value));
}

/*
** Creates c4071
*/
nts::IComponent	*nts::ComponentFactory::create4071(const std::string &value) const
{
  return (new c4071(value));
}

/*
** Creates c4081
*/
nts::IComponent	*nts::ComponentFactory::create4081(const std::string &value) const
{
  return (new c4081(value));
}

/*
** Creates c4094
*/
nts::IComponent	*nts::ComponentFactory::create4094(const std::string &value) const
{
  return (new c4094(value));
}

/*
** Creates c4514
*/
nts::IComponent	*nts::ComponentFactory::create4514(const std::string &value) const
{
  return (new c4514(value));
}

/*
** Creates c4801
*/
nts::IComponent	*nts::ComponentFactory::create4801(const std::string &value) const
{
  return (new c4801(value));
}

/*
** Creates c2716
*/
nts::IComponent	*nts::ComponentFactory::create2716(const std::string &value) const
{
  return (new c2716(value));
}

nts::ComponentFactory::~ComponentFactory()
{

}
