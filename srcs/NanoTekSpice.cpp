//
// NanoTekSpice.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:24 2017 Arnaud WURMEL
// Last update Mon Feb 27 13:09:55 2017 Arnaud WURMEL
//

#include <map>
#include <csignal>
#include <functional>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Helper.hpp"
#include "IParser.hpp"
#include "NanoTekSpice.hpp"
#include "ComponentFactory.hpp"
#include "IComponent.hpp"
#include "Errors.hpp"

bool nts::NanoTekSpice::_loop = false;

/*
** Constructor, assign map function ptr
*/
nts::NanoTekSpice::NanoTekSpice() : _comp(0)
{
  _tree = NULL;
  _continue = true;
  _action["exit"] = &nts::NanoTekSpice::exit;
  _action["simulate"] = &nts::NanoTekSpice::simulate;
  _action["loop"] = &nts::NanoTekSpice::loop;
  _action["dump"] = &nts::NanoTekSpice::dump;
  _action["display"] = &nts::NanoTekSpice::display;
}

/*
** Destructor
*/
nts::NanoTekSpice::~NanoTekSpice()
{
  if (_tree)
    {
      Helper::delete_tree(_tree);
      _tree = NULL;
    }
  if (_comp)
    delete _comp;
  _comp = NULL;
}

/*
** Execute command from input, may be call from main (with argv)
** or from nts::NanoTekSpice::start function
**
** Return value :
** - Command successfully found (and executed) true
** - Command not found false
** This function don't print error message, must be handle from caller's functions
**
** NB: input must be epured (' ', '\t')
*/
bool	nts::NanoTekSpice::executeAction(std::string const& input)
{
  if (_action[input])
    {
      (this->*_action[input])();
      return (true);
    }
  else if (isInputConfiguration(input))
    {
      this->setInputValue(input);
      return (true);
    }
  return (false);
}

/*
** Call from main, loop for program
** It show a prompt and execute user instruction
*/
void		nts::NanoTekSpice::start()
{
  std::string	input;

  while (_continue)
    {
      std::cout << PROMPT;
      if (!getline(std::cin, input))
	return;
      Helper::epurStr(input);
      if (input.empty() == false)
	{
	  if (!this->executeAction(input))
	    std::cerr << input << NOT_FOUND << std::endl;
	}
    }
}

/*
** Call when user enter "simulate" as command line
*/
void	nts::NanoTekSpice::simulate()
{
  std::cout << "Simulate function: NOT IMPLEMENTED YET" << std::endl;
}

/*
** Call when user enter "loop" as command line
*/
void	nts::NanoTekSpice::loop()
{
  nts::NanoTekSpice::_loop = true;
  std::signal(SIGINT, nts::NanoTekSpice::sigintLoop);
  while (nts::NanoTekSpice::_loop)
    simulate();
  std::signal(SIGINT, SIG_DFL);
}

/*
** Call when user enter "dump" as command line
*/
void	nts::NanoTekSpice::dump()
{
  std::cout << "Dump function: NOT IMPLEMENTED YET" << std::endl;
}

/*
** Call when user enter "exit" as command line
** Set _continue to false in order to stop while from start function
*/
void	nts::NanoTekSpice::exit()
{
  _continue = false;
}

/*
** Call when user enter "display" as command line
*/
void	nts::NanoTekSpice::display()
{
  std::cout << "Display function: NOT IMPLEMENTED YET" << std::endl;
}

/*
** Call when user type a command like myval=X
** This function print error message if :
** - myval don't exist
** - X isn't a number
*/
void	nts::NanoTekSpice::setInputValue(std::string const& input)
{
  (void)input;
  std::cout << "Set function: NOT IMPLEMENTED YET" << std::endl;
}

/*
** Check line format : %s=%s
*/
bool	nts::NanoTekSpice::isInputConfiguration(std::string const& input)
{
  std::size_t	equal_pos;

  if ((equal_pos = input.find("=")) != std::string::npos)
    return (true);
  return (false);
}

void	nts::NanoTekSpice::setTree(nts::t_ast_node *node)
{
  _tree = node;
}

/*
** Happens when SIGINT and shell is in loop
*/
void	nts::NanoTekSpice::sigintLoop(int sig)
{
  (void)sig;
  nts::NanoTekSpice::_loop = false;
}

nts::IComponent	*nts::NanoTekSpice::getComponentByName(std::string const& name)
{
  std::vector<std::pair<std::string, IComponent *> >::iterator	it;

  it = _comp->begin();
  while (it != _comp->end())
    {
      if ((*it).first.compare(name) == 0)
	return ((*it).second);
      ++it;
    }
  return (NULL);
}

/*
** Parse tree
*/
void	nts::NanoTekSpice::createComponent(void)
{
  nts::t_ast_node				*chipset;
  nts::t_ast_node				*links;
  std::vector<nts::t_ast_node *>::iterator	it;
  nts::ComponentFactory				componentFactory;
  nts::IComponent				*link_start;
  nts::IComponent				*link_end;
  nts::t_ast_node				*children;

  if (!_tree)
    return ;
  if (!_comp)
    _comp = new std::vector<std::pair<std::string, IComponent *> >();
  _comp->clear();
  chipset = *_tree->children->begin();
  it = chipset->children->begin();
  while (it != chipset->children->end())
    {
      _comp->push_back(std::make_pair((*(*it)->children->begin())->lexeme,
				      componentFactory.createComponent((*it)->lexeme, (*it)->value)));
      ++it;
    }
  links = (*_tree->children)[1];
  it = links->children->begin();
  while (it != links->children->end())
    {
      children = *((*it)->children->begin());
      if ((link_start = getComponentByName((*it)->lexeme)) == NULL)
	throw Errors("Unknown name for link_start");
      if ((link_end = getComponentByName(children->lexeme)) == NULL)
	throw Errors("Unknown name for link_end");
      link_start->SetLink(std::stoi((*it)->value, nullptr, 0), *link_end, std::stoi(children->value, nullptr, 0));
      ++it;
    }
}
