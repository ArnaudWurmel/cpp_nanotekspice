//
// NanoTekSpice.hpp for nts in /home/wurmel/rendu/cpp_nanotekspice/NanoTekSpice
// 
// Made by Arnaud WURMEL
// Login   <wurmel_a@epitech.net>
// 
// Started on  Fri Feb  3 18:36:22 2017 Arnaud WURMEL
// Last update Fri Mar  3 13:29:02 2017 Arnaud WURMEL
//

#ifndef NANOTEKSPICE_HPP_
# define NANOTEKSPICE_HPP_

# include "IParser.hpp"
# include "IComponent.hpp"
# include "cInput.hpp"
# include "cOutput.hpp"
# include "cClock.hpp"

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
    void	start(int, char **);
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
    static bool	sortComparator(std::pair<std::string, IComponent *>, std::pair<std::string, IComponent *>);

  private:
    void	setClock();

  private:
    void	addInput();
    void	addOutput();
    void	addClock();

  private:
    void	sanityNameCheck(void) const;
    
  private:
    std::map<std::string, void(NanoTekSpice::*)()>	_action;
    bool						_continue;
    bool						_input_setted;
    nts::t_ast_node					*_tree;
    std::vector<std::pair<std::string, IComponent *> >	*_comp;
    std::vector<std::pair<std::string, cInput *> >	*_inputs;
    std::vector<std::pair<std::string, cOutput *> >	*_outputs;
    std::vector<std::pair<std::string, cClock *> >	*_clocks;

  public:
    static bool						_loop;
    static size_t					_sim_id;
  };
}

void	sigintLoop(int);

#endif /* !NANOTEKSPICE_HPP_ */
