//
// NanoTekSpice.cpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:24 2017 Arnaud WURMEL
// Last update Fri Feb  3 19:01:07 2017 Arnaud WURMEL
//

#include <iostream>
#include <map>
#include "NanoTekSpice.hpp"
#include "Helper.hpp"

nts::NanoTekSpice::NanoTekSpice()
{
  _continue = true;
  _action["exit"] = &nts::NanoTekSpice::exit;
}

nts::NanoTekSpice::~NanoTekSpice()
{

}

void		nts::NanoTekSpice::start()
{
  std::string	input;

  while (_continue)
    {
      std::cout << "> ";
      if (!getline(std::cin, input))
	return;
      Helper::epurStr(input);
      std::cout << "Line : " << input << std::endl;
    }
}

void	nts::NanoTekSpice::exit()
{
  _continue = false;
}
