//
// NanoTekSpice.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:24 2017 Arnaud WURMEL
// Last update Tue Feb  7 11:08:17 2017 Arnaud WURMEL
//

#include <algorithm>
#include <iostream>
#include <map>
#include "NanoTekSpice.hpp"
#include "Helper.hpp"

/*
** Constructor, assign map function ptr
*/
nts::NanoTekSpice::NanoTekSpice()
{
  _continue = true;
  _action["exit"] = &nts::NanoTekSpice::exit;
  _action["simulate"] = &nts::NanoTekSpice::simulate;
  _action["loop"] = &nts::NanoTekSpice::loop;
  _action["dump"] = &nts::NanoTekSpice::dump;
  _action["display"] = &nts::NanoTekSpice::display;
}

/*
** Destructor: TODO
*/
nts::NanoTekSpice::~NanoTekSpice()
{

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
      std::cout << "> ";
      if (!getline(std::cin, input))
	return;
      Helper::epurStr(input);
      if (!this->executeAction(input))
	std::cerr << input << NOT_FOUND << std::endl;  
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
  std::cout << "Loop function: NOT IMPLEMENTED YET" << std::endl;
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
