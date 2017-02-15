//
// NanoTekSpice.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:24 2017 Arnaud WURMEL
// Last update Wed Feb 15 23:02:48 2017 Arnaud WURMEL
//

#include <map>
#include <csignal>
#include <vector>
#include <iostream>
#include <algorithm>
#include "Helper.hpp"
#include "IParser.hpp"
#include "NanoTekSpice.hpp"
#include "ComponentFactory.hpp"

bool nts::NanoTekSpice::_loop = false;

/*
** Constructor, assign map function ptr
*/
nts::NanoTekSpice::NanoTekSpice() : _comp(0), _name(0)
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

/*
** Parse tree
*/
void	nts::NanoTekSpice::createComponent(void)
{
  nts::t_ast_node	*chipset;
  std::vector<nts::t_ast_node *>::iterator	it;
  nts::ComponentFactory	componentFactory;

  if (!_tree)
    return ;
  if (!_comp)
    _comp = new std::vector<IComponent *>();
  if (!_name)
    _name = new std::vector<std::string>();
  _comp->clear();
  _name->clear();
  chipset = *_tree->children->begin();
  it = chipset->children->begin();
  while (it != chipset->children->end())
    {
      _comp->push_back(componentFactory.createComponent((*it)->lexeme, (*it)->value));
      _name->push_back((*(*it)->children->begin())->lexeme);
      ++it;
    }
}
