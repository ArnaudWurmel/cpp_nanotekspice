//
// main.cpp for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Jan 27 19:12:02 2017 Arnaud WURMEL
// Last update Fri Feb  3 22:21:17 2017 Arnaud WURMEL
//

#include <iostream>
#include <map>
#include "NanoTekSpice.hpp"

int	main(int ac, char **av)
{
  nts::NanoTekSpice	*root;

  (void)av;
  if (ac == 1)
    {
      std::cerr << "Error arguments" << std::endl;
      return 1;
    }
  root = new nts::NanoTekSpice();
  root->start();
  delete root;
  return 0;
}
