//
// main.cpp for Nanotekspice in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Jan 27 19:12:02 2017 Arnaud WURMEL
// Last update Fri Feb  3 15:57:15 2017 Arnaud WURMEL
//

#include <iostream>

static void	loop()
{
  std::string	line;

  while (1)
    {
      std::cout << "> ";
      if (!std::getline(std::cin, line))
	return ;
      std::cout << "Asked : " << line << std::endl;
    }
}

int	main(int ac, char **av)
{
  if (ac == 1)
    {
      std::cerr << "Error arguments" << std::endl;
      return 1;
    }
  loop();
  return 0;
}
