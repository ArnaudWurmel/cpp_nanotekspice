//
// NanoTekSpice.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:24 2017 Arnaud WURMEL
// Last update Fri Feb  3 21:04:13 2017 Arnaud WURMEL
//

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
      if (_action[input])
	(this->*_action[input])();
      else
	std::cerr << "Action not found" << std::endl;
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
