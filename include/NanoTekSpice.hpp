//
// NanoTekSpice.hpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:22 2017 Arnaud WURMEL
// Last update Mon Feb 27 17:17:58 2017 Arnaud WURMEL
//

#ifndef NANOTEKSPICE_HPP_
# define NANOTEKSPICE_HPP_

# include "IParser.hpp"
# include "IComponent.hpp"
# include "cInput.hpp"
# include "cOutput.hpp"

# define PROMPT		"> "
# define NOT_FOUND	": Command not found"
# define SYNTAXE_ERROR	": Syntax error"

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

    /*
    ** Functions for create component from tree
    */
  public:
    void	setTree(nts::t_ast_node *);
    void	createComponent(void);
    nts::IComponent	*getComponentByName(std::string const&);

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
    static void	sigintLoop(int);
    
  private:
    std::map<std::string, void(NanoTekSpice::*)()>	_action;
    bool						_continue;
    nts::t_ast_node					*_tree;
    std::vector<std::pair<std::string, IComponent *> >	*_comp;
    std::vector<std::pair<std::string, cInput *> >	*_inputs;
    std::vector<std::pair<std::string, cOutput *> >	*_outputs;

  public:
    static bool						_loop;
  };
}

void	sigintLoop(int);

#endif /* !NANOTEKSPICE_HPP_ */
