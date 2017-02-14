//
// NanoTekSpice.hpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:22 2017 Arnaud WURMEL
// Last update Tue Feb 14 17:55:09 2017 Arnaud WURMEL
//

#ifndef NANOTEKSPICE_HPP_
# define NANOTEKSPICE_HPP_

# define NOT_FOUND ": Command not found"
# define SYNTAXE_ERROR ": Syntax error"

namespace nts
{
  class	NanoTekSpice
  {
  public:
    NanoTekSpice();
    ~NanoTekSpice();
    
  public:
    void	start();
    bool	executeAction(std::string const&);
    void	setTree(nts::t_ast_node *);

    /*
    ** Interpreted function from command line
    */
  public:
    void	exit();
    void	simulate();
    void	loop();
    void	dump();
    void	display();
    void	setInputValue(std::string const&);
    bool	isInputConfiguration(std::string const&);
    
  private:
    std::map<std::string, void(NanoTekSpice::*)()>	_action;
    bool						_continue;
    nts::t_ast_node					*_tree;
  };
}
  
#endif /* !NANOTEKSPICE_HPP_ */
