//
// Errors.hpp for NTS in /home/wurmel/rendu/cpp_nanotekspice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Wed Feb  8 18:52:24 2017 Arnaud WURMEL
// Last update Wed Feb  8 22:31:49 2017 Arnaud WURMEL
//

#ifndef ERRORS_HPP_
# define ERRORS_HPP_

# define DEF_OUTSIDE "Invalid definition outside of section"
# define SECTION_ERROR "Invalid number of section / name"

class	Errors : virtual public std::exception
{
public:
  Errors(const char *what);
  ~Errors();

public:
  virtual char const* what() const throw();

private:
  std::string	_what;
};

#endif /* !ERRORS_HPP_ */
