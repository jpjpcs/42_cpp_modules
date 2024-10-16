/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:01 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 12:32:34 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1- Exercise 01: ScavTrap
1.1. - Explicação Global:
    O exercício "Serena, my love!" pede para criar uma classe ScavTrap, que deriva da 
    classe ClapTrap. Ao herdar de ClapTrap, o ScavTrap utiliza os atributos de ClapTrap, 
    mas deve personalizar os seus construtores, destrutores e método attack() para 
    exibir mensagens diferentes. Além disso, o ScavTrap tem uma função especial 
    chamada guardGate(), que ativa um "modo de guarda".

    O código deve seguir a forma canónica ortodoxa, ou seja, deve incluir um construtor 
    por defeito, um construtor de cópia, um operador de atribuição e um destrutor. 
    O objetivo é garantir que o ScavTrap é construído e destruído corretamente, 
    seguindo a ordem de herança e exibindo mensagens correspondentes.

1.2.- Explicação Detalhada:
1.2.1. - Construtor por defeito (ScavTrap()):
    Quando um objeto ScavTrap é criado sem nome, o construtor por defeito é chamado.
    Ele inicializa os pontos de vida (_hitPoints), energia (_energyPoints) e dano de ataque (_attackDamage).
    Exibe uma mensagem de construção.
1.2.2. - Construtor com nome (ScavTrap(const std::string &name)):
    Este construtor recebe um nome e inicializa o ScavTrap com ele, chamando o construtor de ClapTrap para inicializar o nome.
    Os atributos de saúde, energia e dano são ajustados para os valores específicos do ScavTrap.
    Exibe uma mensagem indicando que o ScavTrap com nome foi construído.
1.2.3. - Construtor de cópia (ScavTrap(const ScavTrap &other)):
    Realiza uma cópia dos atributos de outro objeto ScavTrap para criar um novo objeto.
    Usa o construtor de cópia da classe base ClapTrap para herdar os valores.
    Exibe uma mensagem de cópia.
1.2.4. - Destrutor (~ScavTrap()):
    Quando o objeto ScavTrap é destruído, o destrutor exibe uma mensagem.
    A destruição segue a ordem inversa de construção: primeiro o ScavTrap, depois o ClapTrap.
1.2.5. - Operador de atribuição (operator=):
    O operador de atribuição permite copiar os valores de um objeto para outro.
    O operador da classe base ClapTrap é chamado para evitar duplicação de código.
1.2.6. - Função attack(const std::string &target):
    Sobrescreve a função attack() de ClapTrap.
    Verifica se o ScavTrap tem energia e saúde para atacar.
    Se sim, diminui a energia e exibe uma mensagem de ataque.
1.2.7. - Função guardGate():
    Exibe uma mensagem informando que o ScavTrap entrou em "modo de guarda".
    É uma função exclusiva do ScavTrap.
*/

/* 
2 - Pontos do Word Abordados:
    Abordados no CPP03ex00:
        Pontos do Word Abordados:
        Módulo 3 - 19.11.38.	inheritance introduction
        Módulo 3 - 19.11.39.	Instância é Herança e Polimorifsmo?
        Módulo 3 - 19.11.40.	inheritance in classes
        outros pontos: 
        1 - unsigned int getEnergyPoints(void) const é funcionalmente o mesmo que 
        unsigned int const getEnergyPoints(void)?
        2 - colocar a sobrecarga do operador de inserção de fluxo de saída (<<) quer fora. 
    
    Aqui no CPP03ex01, também abordamos:
        Módulo 3 - 19.11.42.	Access specifier (base class & class members) 
        (ver modulo 0 e descrição dos tipos public, private and protected em módulo 0 parte da visibility)
        outros pontos:
        3 - Os atributos private da Class ClapTrap mudaram de private para protected - Módulo 3 - 19.11.42.	Access specifier (base class & class members).
        4 - class ScavTrap : public ClapTrap também é uma das diferenças. O public ClapTrap à frente - Módulo 3 - 19.11.38., 19.11.39, e 19.11.40.
        da class ScavTrap de forma a atribuir corretamente a herança. Se não o fizermos, o ScavTrap não terá acesso aos membros
        protegidos da classe base ClapTrap.
        5 - Diferença entre o Operador de Atribuição e a Cópia Direta - Módulo 2 - 19.11.31.1.6. Operador de Atribuição(=) 
        vs Operador de Atribuição (=) Padrão vs Operador de Atribuição Sobrecarregado.
        Mais info também no ponto 3.4.4., 3.2, 3.3. e 3.4 dos comments do Fixed.hpp do CPP02ex00.
        6 - No main o operador de inserção << é chamado no std::cout << scav1 << scav3 << std::endl;
            Podia ter usado virtual functions para imprimir o tipo da classe, mas não foi possível 
            pq o override é uma função do C++11 (sendo proibido na versão C++8) e o compilador não aceitou.
            Tive que fazer um override manualmente do operador << para ScavTrap. Ver mais info no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01, assim como no
        6.1. - Módulo 0 - 19.11.9.1.7.	Virtual e no 
        6.2. - Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / Função Virtual & Função membro Virtual (módulo 4).
*/

/*
3 - Os atributos private da Class ClapTrap mudaram de private para protected:
    3.1. - Porquê?
        . Os atributos private da classe base ClapTrap foram alterados para protected na classe derivada ScavTrap.
        . Isso permite que os atributos sejam acessados diretamente pela classe derivada, sem a necessidade de métodos de acesso.
        . A mudança de private para protected permite que os atributos sejam herdados pela classe derivada e acessados diretamente.
    3.2. - Qual é a diferença entre private e protected?
        . private: Os membros privados são acessíveis apenas pela própria classe e não pelas classes derivadas.
        . protected: Os membros protegidos são acessíveis pela própria classe e pelas classes derivadas.
        . Ao alterar os atributos de private para protected, os atributos da classe base ClapTrap podem ser 
        acessados diretamente pela classe derivada ScavTrap.
    3.3. - Por que usar protected em vez de private?
        . O uso de protected em vez de private permite que os atributos sejam acessados diretamente pela classe derivada.
        . Isso simplifica o acesso aos atributos e evita a necessidade de métodos de acesso.
        . A mudança de private para protected é útil quando os atributos precisam ser acessados por classes derivadas.
    3.4. - Qual é a diferença entre protected e public?
        . protected: Os membros protegidos são acessíveis pela própria classe e pelas classes derivadas.
        . public: Os membros públicos são acessíveis por qualquer classe.
        . A diferença entre protected e public é a visibilidade dos membros: protected é acessível pela classe derivada, 
        enquanto public é acessível por qualquer classe.
        . Ao usar protected, os atributos podem ser acessados diretamente pela classe derivada, mas não por outras classes.

    3.5. - erro que pode acontecer no construtor no ScavTrap.cpp caso os membros sejam privados: 
    "member 'ClapTrap::_hitPoints' is inaccessible"
        3.5.1. - Porque se dá este erro: ocorre porque os membros da classe base ClapTrap 
        (como _hitPoints, _energyPoints, e _attackDamage) estão provavelmente declarados como private. 
        Isso significa que a classe derivada ScavTrap não pode aceder diretamente a esses membros, resultando nesse erro.
        3.5.2. - Como corrigir?
            3.5.2.1. - Alterar os membros da classe base ClapTrap de private para protected.
            3.5.2.2. - Manter os membros private mas adicionar métodos de acesso 
            (getters e setters -  para definir ou modificar os valores de _hitPoints, _energyPoints, e _attackDamage) 
            públicos na classe base ClapTrap para permitir que a classe derivada ScavTrap acesse os membros.
*/

/*
4. Temos de colocar : public ClapTrap à frente da class ScavTrap de forma a atribuir
    corretamente a herança. Se não o fizermos, o ScavTrap não terá acesso aos membros
    protegidos da classe base ClapTrap. A herança é uma relação entre classes que permite
    que uma classe derivada (ScavTrap) herde membros e funções de uma classe base (ClapTrap).
    A herança é definida pela palavra-chave public, que indica que os membros protegidos
    da classe base são acessíveis pela classe derivada. Se não especificarmos public,
    a herança será privada por padrão, o que significa que os membros protegidos da classe
    base não serão acessíveis pela classe derivada.
    Desta forma, a palavra-chave public especifica que ScavTrap herda publicamente de ClapTrap.
    Se não definirmos de forma correta a herança, acontecerá no ScavTrap.cpp o erro:
        error: "ClapTrap is not a nonstatic data member or base class of class ScavTrap" 
*/

/*
5 - Diferença entre o Operador de Atribuição e a Cópia Direta:
    O operador de atribuição (operator=) copia os membros de um objeto para outro, 
    verificando se não estamos a atribuir o objeto a si mesmo (self-assignment). 
    É importante em herança para assegurar que a parte da classe base também seja copiada corretamente.
    A cópia direta (simples atribuição de membros) pode resultar em duplicação de código 
    e não garante que as partes da classe base sejam manipuladas adequadamente, 
    especialmente em classes derivadas.
    
    ***----- Mais info no ponto 3.4.4., 3.2, 
    3.3. e 3.4 dos comments do Fixed.hpp do CPP02ex00. -----***
*/

/*
6 - No main o operador de inserção << é chamado no std::cout << scav1 << scav3 << std::endl;
No terminal a saída estava a ser ClapTrap Roberto has 85 HP, 46 energy points and 20 attack damage, 
ao invés de ScavTrap Roberto has 85 HP, 46 energy points and 20 attack damage.
    6.1. - Porquê?
        . A saída do operador de inserção << exibe "ClapTrap" em vez de "ScavTrap" deve-se à função 
        de impressão não ter sido sobrescrita na classe ScavTrap, ela na realidade foi herdada da classe base ClapTrap. 
        . Assim, a razão pela qual aparece "ClapTrap Roberto" em vez de "ScavTrap Roberto" está relacionada com o facto 
        de a sobrecarga do operador << estar a ser definida para a classe base, ClapTrap, e não para a classe derivada, ScavTrap.
        . Quando fazemos std::cout << scav1;, o compilador chama a sobrecarga do operador << que está definida para o tipo ClapTrap, 
        porque ScavTrap herda de ClapTrap. O operador sobrecarregado para ClapTrap imprime o nome da classe base, e não da derivada.
        . Aqui está o que está a acontecer, passo a passo:
            - O operator<< está sobrecarregado para a classe ClapTrap, e imprime "ClapTrap [nome] has [HP] HP, [energy points] 
            energy points and [attack damage] attack damage".
            - Como ScavTrap herda de ClapTrap, a sobrecarga do operator<< que foi definida para ClapTrap é utilizada, 
            mesmo que o objeto seja um ScavTrap. Não há uma distinção implícita entre ClapTrap e ScavTrap nesse contexto, 
            a menos que definas especificamente uma versão diferente para ScavTrap.
    6.2. - Como corrigir?
        Há 2 formas (uma pude usar, outra que usava virtual function, no caso um
        virtual getter function e override não pude usar pq override é uma função do C++11 
        (sendo proibido na versão C++8) e o compilador não aceitou):
        6.2.1. - Sobrescrever a função de impressão na classe ScavTrap para exibir "ScavTrap" em vez de "ClapTrap".
        6.2.2. - Usar uma função virtual na classe base ClapTrap para retornar o tipo da classe e sobrescrevê-la na classe derivada ScavTrap.
        
        Explicação detalhada
        Solução 6.2.1. - Uma maneira de resolver isso seria fazer "override" do operador << especificamente para a classe ScavTrap. 
            Podemos adicionar uma nova versão do operador << para ScavTrap no ficheiro ScavTrap.cpp, de forma a que, quando for usado 
            um objeto ScavTrap, a sobrecarga correta seja chamada:
                - No ScavTrap.hpp:
                friend std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);
                - No ScavTrap.cpp:
                std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap)
                {
                    os << "ScavTrap " << scavTrap.getName() << " has " << scavTrap.getHitPoints()
                    << " HP, " << scavTrap.getEnergyPoints() << " energy points and "
                    << scavTrap.getAttackDamage() << " attack damage." << std::endl;
                    return os;
                }
            Dessa forma, quando fizermos std::cout << scav1; com um objeto ScavTrap, será chamado o operador sobrecarregado 
       específico para ScavTrap, e veremos a mensagem "ScavTrap Roberto..." em vez de "ClapTrap Roberto...".

        Solução 6.2.2. - Alternativa: Adicionar um método getClassType()
            Outra abordagem seria modificar a função existente para imprimir o tipo de classe dinamicamente, por exemplo, através de um método virtual getClassType() que retorna o nome da classe:

                - No ClapTrap.hpp, adicionávamos:
                virtual std::string getClassType() const;
                - No ClapTrap.cpp, definíamos o método:
                std::string ClapTrap::getClassType() const
                {
                    return "ClapTrap";
                }
                - No ScavTrap.hpp, override do método:
                std::string getClassType() const override;
                - No ScavTrap.cpp, definíamos o override:
                std::string ScavTrap::getClassType() const
                {
                    return "ScavTrap";
                }
                - Atualizamos o operador << no ClapTrap para usar getClassType():
                std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap)
                {
                    os << clapTrap.getClassType() << " " << clapTrap.getName() << " has " 
                    << clapTrap.getHitPoints() << " HP, " << clapTrap.getEnergyPoints()
                    << " energy points and " << clapTrap.getAttackDamage() 
                    << " attack damage." << std::endl;
                    return os;
                }
                Assim, o operador << adaptará automaticamente a mensagem conforme o tipo real do objeto (ClapTrap ou ScavTrap).
*/

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public virtual ClapTrap // ver mais info no ponto 4 dos comments do ScavTrap.cpp do CPP03ex01.
{
    public:
        ScavTrap(void); // Construtor Padrão
        ScavTrap(std::string name); // Construtor Parametrizado
        ScavTrap(ScavTrap const &copy); // Construtor de Cópia
        ~ScavTrap(void); // Destrutor
        
        // Atribution Operator Overload - Ver mais info no ponto 5 dos comments do ScavTrap.hpp do CPP03ex01.
        ScavTrap &operator=(ScavTrap const &copy); // Operador de Atribuição
        
        // Operador de inserção de fluxo de saída (<<) - Ver mais info no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01.
        friend std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);
        
        // ao invés de usar a solução acima (friend std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap);),
        // podia ter usado esta:
        // Virtual getter function
        //std::string getClassType() const override; // Não pude usar esta solução para imprimir ScavTrap em vez de ClapTrap 
        // na saída do operador <<, pq override é uma função do C++11 (sendo proibido na versão C++8) e o compilador não aceitou. 
        // Ver mais info no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01.
        
        // Member Functions
        void attack(const std::string &target); // Ataca um alvo - Função de ataque (sobrescreve a do ClapTrap)
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // Guarda a porta - Função especial de modo de guarda 
        void guardGate(void);     
};

#endif
