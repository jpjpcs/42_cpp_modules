/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:08:49 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 18:04:16 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ex00 - 
    Herança, Polimorfismo e Encapsulamento, const, operador de inserção fora ou
    dentro da classe, friend.

    Pontos do Word Abordados:
    Módulo 3 - 19.11.38.	inheritance introduction
    Módulo 3 - 19.11.39.	Instância é Herança e Polimorifsmo?
    Módulo 3 - 19.11.40.	inheritance in classes
    outros pontos: 
    1 - unsigned int getEnergyPoints(void) const é funcionalmente o mesmo que 
    unsigned int const getEnergyPoints(void)?
    2 - colocar a sobrecarga do operador de inserção de fluxo de saída (<<) quer fora. 

ex01 - 
    1 - acesso a membros protegidos (access specifier) - passar de private a protected,
    2 - herança em classes (class  ScavTrap : public ClapTrap), 
    3 - diferença entre operador de atribuição e cópia direta,
        Mais info no ponto 5 do ScavTrap.cpp do CPP03ex01,
    4 - sobrecarga do operador de inserção de fluxo de saída (<<) no main com 
        std::cout << scav1 << scav3 << std::endl; e override manual do operador << para ScavTrap.
        Mais info no ponto 6 do ScavTrap.cpp do CPP03ex01.
    5 -  Função Amiga - Mais info em ScravTrap.cpp do CPP03ex01, no 
         Módulo 02 - 19.11.27.2.1.1.2.1. Definição de sobrecarga de operadores, 
            assim como no ClapTrap.cpp do CPP03ex00.
    6 - Operador de inserção numa classe derivada - Ver mais info no ponto 1 e ponto 2 do 
        FragTrap.cpp do CPP03ex02 e no ponto 6 do ScavTrap.cpp do CPP03ex01.
    7 - Princípio da destruição em cascata - Ver mais info no ponto 6 do main.cpp do CPP03ex01 e
        no ponto 5 do main.cpp do CPP03ex03.
    
    Pontos word abordados:
    Módulo 0 - 19.11.16.1.	This pointer
    Módulo 3 - 19.11.42.	Access specifier (base class & class members)
    Módulo 02 - 19.11.27.2.1.1.2.1. Definição de sobrecarga de operadores
        (ver modulo 0 e descrição dos tipos public, private and protected em módulo 0 parte da visibility)
        outros pontos:
        1 - Os atributos private da Class ClapTrap mudaram de private para protected - Módulo 3 - 19.11.42.	Access specifier (base class & class members).
        3 - Diferença entre o Operador de Atribuição e a Cópia Direta - Módulo 2 - 19.11.31.1.6. Operador de Atribuição(=) 
        vs Operador de Atribuição (=) Padrão vs Operador de Atribuição Sobrecarregado.
        Mais info também no ponto 3.4.4., 3.2, 3.3. e 3.4 dos comments do Fixed.hpp do CPP02ex00.
        4 - class ScavTrap : public ClapTrap também é uma das diferenças. O public ClapTrap à frente - Módulo 3 - 19.11.38., 19.11.39, e 19.11.40.
        da class ScavTrap de forma a atribuir corretamente a herança. Se não o fizermos, o ScavTrap não terá acesso aos membros
        protegidos da classe base ClapTrap.
        5 - Função Amiga - Funções amigas são declaradas dentro de uma classe, mas NÃO são métodos da classe. 
            Uma função amiga é uma função regular que tem o privilégio de acessar membros privados nos objetos dos parâmetros.
            Mais info em ScravTrap.cpp do CPP03ex01, no Módulo 02 - 19.11.27.2.1.1.2.1. Definição de sobrecarga de operadores, 
            assim como no ClapTrap.cpp do CPP03ex00.
        6 - No main o operador de inserção << é chamado no std::cout << scav1 << scav3 << std::endl;
            Podia ter usado virtual functions para imprimir o tipo da classe, mas não foi possível 
            pq o override é uma função do C++11 (sendo proibido na versão C++8) e o compilador não aceitou.
            Tive que fazer um override manualmente do operador << para ScavTrap. 
            Ver mais info:
            no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01,
            no ClapTrap.hpp do CPP03ex00 ,
            no Diamond.hpp do CPP03ex03,
            no - Módulo 0 - 19.11.9.1.7.	Virtual e no 
            e no - Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / Função Virtual & Função membro Virtual (módulo 4).
        
ex02 - 
    Semelhante ao exercício 01, mas com a classe FragTrap. Neste exercício optei por 
    não fazer override manual do operador << para FragTrap. Logo, o operador << para FragTrap
    é o mesmo que o operador << para ClapTrap, o que na saída do terminal resulta na mensagem
    usada pelo operador << de ClapTrap.

    Outro tema IMPORTANTE abordado: 
    Porque devemos implementar o operador de inserção se na realidade não o chamamos no copy constructor?
    2as questões:
        1 - Chamar ou não chamar o operador de inserção no construtor de cópia usando *this = copy?
        2 - Então se o operador de atribuição não é chamado no construtor de cópia, para que o usamos?
    Ver mais info no ponto 1 e ponto 2 do 
    FragTrap.cpp do CPP03ex02 e no ponto 6 do ScavTrap.cpp do CPP03ex01.

    Pontos do Word Abordados:
    Os mesmos pontos que no CPP03ex01, mas com a classe FragTrap, e algumas exceções:
        1 - No CPP03ex02, não fiz override manual do operador << para FragTrap. Logo, o operador << para FragTrap
        é o mesmo que o operador << para ClapTrap, o que na saída do terminal resulta na mensagem
        usada pelo operador << de ClapTrap.
        2 - Não criei a função takeDamage ou beRepaired para a nova classe FragTrap (como tinha feito para ScavTrap).
    
ex03 - 
    CPP03ex03 - Temas abordados
        Neste exercício usamos:
        1 - herança múltipla, 
        2 - funções virtuais
        3 - Uso do *this = copy vs this->name = copy.name
        4 - Uso de flag -Wshadow e -Wno-shadow no Makefile
        5 - Função Amiga (Friend Function)
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
            e no - Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual 
            Member Function / Função Virtual & Função membro Virtual (módulo 4).
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
Exercise 00: ClapTrap
Objective: Create a class ClapTrap with the following member functions:
•	public: 
    - void attack(std::string const & target);
    - void takeDamage(unsigned int amount);
    - void beRepaired(unsigned int amount);
    getters:
    - std::string getName(void) const;
    - int getHitPoints(void) const;
    - int getEnergyPoints(void) const;
    - int getAttackDamage(void) const;
.   private:
    - std::string _name;
    - int _hitPoints;
    - int _energyPoints;
    - int _attackDamage;
*/

/*
1 - Questão - unsigned int getEnergyPoints(void) const é funcionalmente o mesmo que 
unsigned int const getEnergyPoints(void)?

    1.1. - Resposta: Sim. A única diferença está na posição da palavra-chave const em 
    relação ao tipo retornado, mas em ambos os casos, ela se refere ao fato de que o 
    valor retornado é um unsigned int constante (não pode ser modificado após ser retornado). 
    Essa é apenas uma questão de estilo de escrita, mas o comportamento é o mesmo.

    O que realmente importa é o const ao final, que qualifica o método como um método 
    constante, garantindo que ele não modifica o estado interno do objeto.

    Portanto:
    unsigned int getEnergyPoints(void) const
    unsigned int const getEnergyPoints(void) const
    Ambas garantem que o método não alterará o estado do objeto e que o valor 
    retornado é um const unsigned int.

    1.2. - Já as declarações const unsigned int getEnergyPoints(void) e 
    unsigned int getEnergyPoints(void) const têm significados diferentes em C++.
    
        1.2.1. - const unsigned int getEnergyPoints(void):

            Declara que a função retorna um valor do tipo const unsigned int. 
            Isso significa que o valor retornado não pode ser modificado após 
            ser retornado. No entanto, essa forma de uso de const no retorno é 
            raramente usada, porque o valor retornado é uma cópia, então geralmente 
            não há necessidade de marcá-lo como const.
        
        1.2.2. - unsigned int getEnergyPoints(void) const:

            Declara que a função getEnergyPoints não altera nenhum dos atributos do 
            objeto ao qual pertence. Ou seja, a palavra-chave const após a declaração 
            do método garante que o estado do objeto permanece inalterado dentro desta 
            função. Esse tipo de qualificador const é muito mais comum para métodos de 
            acesso que não devem modificar o objeto (como getters).
            Portanto, a segunda versão (unsigned int getEnergyPoints(void) const) é usada 
            para marcar o método como não modificador e é a abordagem correta quando você 
            deseja garantir que a função não altere o estado do objeto.
*/

/*
2 -  Posso colocar a sobrecarga do operador de inserção de fluxo de saída (<<) quer fora, quer
dentro da classe (como coloquei). Mas quais as diferenças?
    2.1. - Função fora da classe: 
        A função operator<< não precisa ser uma friend, pois usa os métodos públicos getName(), getHealth(), 
        getEnergy(), e getDamage() para acessar os atributos da instância ClapTrap. 
        Isso permite que a função tenha acesso a informações sobre o objeto sem violar o encapsulamento.
    2.2. - Função dentro da classe: 
        A função operator<< precisa ser declarada como friend para ter acesso aos atributos privados da classe. 
        Se tentassemos declará-la fora da classe sem a palavra-chave friend, ficariamos com um erro, 
        pois o compilador não saberia como acessar os membros privados.
        Isso permite que a função acesse diretamente os atributos privados da instância ClapTrap, 
        sem precisar chamar métodos públicos para obter informações sobre o objeto.
    2.3. - Qual é a melhor prática?
        A melhor prática é declarar a função operator<< como friend apenas se for necessário 
        acessar atributos privados da classe. Se a função puder acessar as informações necessárias 
        usando métodos públicos, é preferível não declará-la como friend, pois isso mantém o encapsulamento 
        e a coesão da classe.
*/

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap(void);
        
        ClapTrap &operator=(const ClapTrap &copy);

        // Member functions
        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // Sobrecarga do operador <<
	    friend std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap); // Declarado como friend para poder aceder aos atributos privados da classe. Ver mais info no ponto 2 dos comments do ClapTrap.hpp do CPP03ex00.
     
        // GETTERS
        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const; // ver mais info no ponto 3 dos comments do ClapTrap.hpp do CPP03ex00.
        int getAttackDamage(void) const;
        // Setters - not used cause we are not changing the values of the attributes

    private:
        std::string _name; // Nome do ClapTrap
        int _hitPoints; // Pontos de vida (HP)
        int _energyPoints; // Pontos de energia (para realizar ações)
        int _attackDamage; // Dano de ataque
};
// Podia ter declarado a função std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap); aqui fora da classe. Seria outra abordagem. Ver mais info no ponto 2 dos comments do ClapTrap.hpp do CPP03ex00.
#endif
