/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:01:43 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 18:06:43 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
CPP03ex03 - Temas abordados
        Neste exercício usamos:
        1 - herança múltipla, 
        2 - funções virtuais
        3 - Uso do *this = copy vs this->name = copy.name
        4 - Uso de flag -Wshadow e -Wno-shadow no Makefile
    Pontos do Word Abordados:
        Módulo 3 - 19.11.43.	multiple inheritance – conceito de herança múltipla
        Módulo 0 - 19.11.9.1.7.	Virtual e no 
        Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / Função Virtual & Função membro Virtual (módulo 4).
        Módulo 0 - 19.11.16.1.	This pointer

        Pontos acima explicados com detalhe:

        1 - Herança Múltipla
            Herança Múltipla - Mais diferenças entre CPP03ex03 e os outros exercícios:
            - O nome do DiamondTrap tem de ser igual ao nome do ClapTrap.
            Isso é assegurado nas funções de construtor e de atribuição, 
            através do uso de this->ClapTrap::_name = this->_name + "_clap_name";.
            - Os atributos e funções membro serão escolhidos da classe ScavTrap ou FragTrap.
                . O nome é passado como parâmetro para o construtor.
                . ClapTrap::name (parâmetro do construtor + sufixo "_clap_name")
                . Hit points (FragTrap)
                . Energy points (ScavTrap)
                . Attack damage (FragTrap). 
                . attack() (Scavtrap)
                O ClapTrap::name (nome + "_clap_name") é assegurados nos 
                construtores (padrão e parametrizado) e no operador de atribuição.
                O nome passado como parametro é assegurado no construtor parametrizado.
                Os pontos de vida, dano de ataque serem do FragTrap são assegurados
                no construtor padrão e parametrizado, assim como os pontos de energia
                e o método attack() do ScavTrap são assegurados no construtor padrão e parametrizado.
        2 - funções virtuais
            Neste último ponto tivemos que alterar o 
            class FragTrap : public ClapTrap para 
            class FragTrap : virtual public ClapTrap e o 
            class ScavTrap : public ClapTrap para 
            class ScavTrap : virtual public ClapTrap.

            E porquê?
            Caso contrário teríamos um erro de ambiguidade, 
            evidenciando o problema de herança múltipla no C++. 
            E porquê?
            Porque tanto FragTrap quanto ScavTrap herdam de ClapTrap. 
            Isso resulta em múltiplas instâncias da classe base ClapTrap 
            dentro de DiamondTrap, tornando os membros da classe ambíguos.
            A solução aqui é usar a herança virtual para garantir que 
            haja apenas uma instância de ClapTrap em DiamondTrap, 
            mesmo que seja herdada indiretamente de FragTrap e ScavTrap.
            
            Ver mais info:
            no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01,
            no ClapTrap.hpp do CPP03ex00 ,
            no Diamond.hpp do CPP03ex03,
            no - Módulo 0 - 19.11.9.1.7.	Virtual e no 
            e no - Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / 
            Função Virtual & Função membro Virtual (módulo 4).
        
        3 - Uso do *this = copy vs this->name = copy.name
            Ver mais info no ponto 1 do DiamondTrap.cpp do CPP03ex03 e no ponto 5 
            do ScavTrap.cpp do CPP03ex01.   
        
        4 - As flags -Wshadow e -Wno-shadow são usadas no compilador 
            GCC (e outros compatíveis) para controlar os avisos relacionados 
            com variáveis que “sombras” outras variáveis no escopo.
            4.1. -Wshadow:
                . Esta flag habilita avisos para variáveis sombreadas (ou "shadowed").
                . Quando uma variável local ou parâmetro tem o mesmo nome que uma 
                    variável num escopo superior (como uma variável global ou membro de classe), 
                    ocorre uma sombreamento de variáveis (variable shadowing).
                . O sombreamento pode levar a bugs difíceis de detectar, pois uma variável do 
                    escopo local substitui (ou "sombras") uma variável global ou uma variável 
                    membro da classe.
                . Ao usar a flag -Wshadow, o compilador emitirá um aviso quando detectar esse 
                    tipo de comportamento.
                . Exemplo:
                    int x = 10;
                    void foo() 
                    {
                        int x = 5; // Variável x local "sombra" a global x
                        std::cout << x; // Imprime 5, não 10
                    }
                Com a flag -Wshadow, o compilador alertará que a variável x local está a sombrear a variável x global.
            4.2. -Wno-shadow:
                . Esta flag desabilita os avisos sobre sombreamento de variáveis.
                . Se preferires que o compilador não avise sobre variáveis sombreadas, 
                    podes usar essa flag para suprimir esses avisos.
            4.3. - Quando usar -Wshadow:
                . Código Mais Seguro: Usar essa flag pode ajudá-lo a detectar problemas de sombreamento, 
                    o que pode prevenir erros e comportamentos inesperados. Isso é especialmente 
                    importante em projetos maiores ou quando várias pessoas estão trabalhando no mesmo código.
                . Melhor Prática de Programação: Muitos programadores consideram que é uma boa prática 
                    evitar sombreamento de variáveis. A inclusão dessa flag pode promover uma 
                    mentalidade de atenção aos detalhes.
                . Aprendizagem: Se estamos a aprender C++, usar essa flag pode ajudar a entender melhor 
                    como as variáveis e escopos funcionam.
            4.4. - Quando não usar -Wshadow:
                . Simplicidade: Se estamos a escrever código pequeno ou para fins educacionais, 
                    podemos achar que não precisamos da sobrecarga de estar constantemente ciente dos avisos de sombreamento.
                . Desempenho de Compilação: Embora o impacto seja geralmente mínimo, habilitar muitos avisos pode aumentar 
                    o tempo de compilação, especialmente em projetos grandes.
            4.5. - Importância de evitar o sombreamento de variáveis
                . O sombreamento pode tornar o código mais confuso e propenso a erros, 
                    especialmente em programas maiores. Quando uma variável é sombreada, a variável "original" fica oculta, 
                    e o programador pode usar a variável errada sem perceber, levando a comportamentos inesperados.
            4.6. - Resumo:
                    -Wshadow: Ativa os avisos sobre sombreamento de variáveis.
                    -Wno-shadow: Desativa os avisos sobre sombreamento de variáveis.
                É considerado uma boa prática evitar o sombreamento para melhorar a clareza e a manutenção do código, 
                    por isso o -Wshadow pode ser útil para capturar esses problemas.             
*/

/*
Exercise 03: DiamondTrap
Create a class DiamondTrap that inherits from ScavTrap and FragTrap.
The DiamondTrap class should have the following attributes:
- A string name.
The DiamondTrap class should have the following methods:
- A constructor that takes a string as a parameter and initializes the 
    name attribute and the attributes of the ScavTrap and FragTrap classes.
- A constructor that takes no parameters and initializes the name attribute 
    and the attributes of the ScavTrap and FragTrap classes.
- A copy constructor.
- An assignment operator overload.
- A whoAmI method that displays the name of the DiamondTrap and the name of the ClapTrap.
- An attack method that takes a string as a parameter and calls the attack method of the ScavTrap class.
*/

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Classe DiamondTrap, herda de ScavTrap e FragTrap
class DiamondTrap : public ScavTrap, public FragTrap // Mais info ponto 2 dos comments do ScavTrap.hpp do CPP03ex01
{
    public:
        // Construtor padrão
        DiamondTrap(void);

        // Construtor com parâmetro (nome)
        DiamondTrap(std::string name);

        // Construtor de cópia
        DiamondTrap(const DiamondTrap &copy);

        // Destrutor
        ~DiamondTrap(void);

        // Operador de atribuição
        DiamondTrap &operator=(const DiamondTrap &copy);

        // Member functions
        // Função especial para identificar o DiamondTrap e seu nome ClapTrap
        void whoAmI(void);
        // Usar o método attack da classe ScavTrap
        using ScavTrap::attack;
        
    private:
        std::string _name; // Atributo privado para o nome do DiamondTrap
};

#endif
