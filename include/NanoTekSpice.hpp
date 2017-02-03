//
// NanoTekSpice.hpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:22 2017 Arnaud WURMEL
// Last update Fri Feb  3 21:02:57 2017 Arnaud WURMEL
//

#ifndef NANOTEKSPICE_HPP_
# define NANOTEKSPICE_HPP_

namespace nts
{
  class	NanoTekSpice
  {
  public:
    NanoTekSpice();
    ~NanoTekSpice();
    
  public:
    void	start();

    /*
    ** Interpreted function from command line
    */
  public:
    void	exit();
    void	simulate();
    void	loop();
    void	dump();
    void	display();
    
  private:
    std::map<std::string, void(NanoTekSpice::*)()>	_action;
    bool						_continue;
  };
}
  
#endif /* !NANOTEKSPICE_HPP_ */
