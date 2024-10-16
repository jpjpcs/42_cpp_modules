/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:40:52 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 11:39:02 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1 - Chamar ou não chamar o operador de inserção no construtor de cópia usando 
*this = copy?

    1.1. - Por que outros programadores não usam o *this = copy 
    no construtor de cópia de ScavTrap ou FragTrap e apenas na classe ClapTrap?
        A razão principal pela qual os construtores de cópia em ScavTrap e 
        FragTrap não utilizam o *this = copy reside no facto de que ambas são 
        classes derivadas de ClapTrap. Ao copiar um objeto de uma classe 
        derivada como ScavTrap ou FragTrap, o construtor de cópia das 
        classes derivadas geralmente invoca diretamente o construtor de 
        cópia da classe base (neste caso, ClapTrap).

        Aqui está o que acontece:
        . ClapTrap (classe base): No construtor de cópia de ClapTrap, usar *this = trap; 
        faz sentido, pois o operador de atribuição foi sobrecarregado para copiar os 
        atributos diretamente (copiando valores primitivos, strings, etc.). 
        O operador de atribuição já trata de toda a lógica de cópia.
        . ScavTrap/FragTrap (classes derivadas): Quando um objeto de ScavTrap ou 
        FragTrap é copiado, a primeira parte do processo envolve a cópia da classe 
        base ClapTrap. Como ScavTrap e FragTrap são derivados de ClapTrap, 
        o uso de : ClapTrap(copy) no construtor de cópia já garante que os 
        atributos da classe base sejam copiados corretamente.

        Ou seja, invocar explicitamente o operador de atribuição via 
        *this = copy dentro do construtor de cópia de ScavTrap ou FragTrap não é necessário. 
        O construtor de cópia da classe base (ClapTrap) já é chamado e copia os atributos corretamente. 
        Depois disso, o construtor da classe derivada cuida de copiar apenas os 
        atributos específicos dessas classes, se houver.

    1.2. - Podemos/devemos usar *this = copy no construtor de cópia de ScavTrap e FragTrap?
            Tecnicamente, podemos usar *this = copy no construtor de cópia de ScavTrap e FragTrap, 
            mas não é recomendado nem necessário nesses casos específicos, por várias razões:

                . Redundância: Ao usar : ClapTrap(copy), já estamos invocando o construtor
                de cópia da classe base, o que realiza toda a cópia dos atributos da 
                classe base (ClapTrap). Usar *this = copy introduziria uma redundância desnecessária.

                . Possíveis problemas: Se o operador de atribuição for chamado explicitamente dentro 
                do construtor de cópia, isso pode resultar em chamadas duplicadas ao operador de 
                atribuição e possivelmente levar a problemas inesperados de desempenho ou lógica.

            Em resumo, invocar : ClapTrap(copy) é a maneira adequada de inicializar a parte da 
            classe base, e depois podemos lidar com os membros específicos da classe derivada 
            no corpo do construtor, se necessário.

    1.3. - Qual a abordagem mais correta?
            A abordagem mais correta é a que os outros programadores utilizam:

            No construtor de cópia da classe base (ClapTrap), usar o operador de 
            atribuição (*this = trap;) faz sentido, pois esse operador já foi projetado para 
            lidar com a cópia de todos os atributos relevantes da classe base.

            No caso das classes derivadas (ScavTrap e FragTrap), a chamada ao construtor de 
            cópia da classe base via inicialização de lista (ou seja, : ClapTrap(copy)) 
            é suficiente para copiar os atributos da base. Depois disso, o construtor da 
            classe derivada apenas copia os seus próprios atributos (caso tenha algum).

            Portanto, a abordagem mais correta e eficiente é:

            No construtor de cópia da classe base (ClapTrap), usar *this = copy 
            para reutilizar o operador de atribuição.

            No construtor de cópia das classes derivadas (ScavTrap e FragTrap), 
            chamar o construtor de cópia da classe base via lista de inicialização (: ClapTrap(copy)),
            sem necessidade de usar *this = copy.

            Essa abordagem evita duplicações desnecessárias e assegura que a hierarquia de 
            classes funcione corretamente, com os atributos sendo copiados de maneira eficiente e organizada.

2 - Então se o operador de atribuição não é chamado no construtor de cópia, para que o usamos?

A implementação do operador de atribuição nas classes derivadas como FragTrap e ScavTrap pode 
parecer redundante à primeira vista, uma vez que o operador de atribuição da classe base (ClapTrap) 
já pode lidar com a cópia de muitos atributos comuns. No entanto, há algumas boas razões para isso:

2.1. - O operador de atribuição e o construtor de cópia têm propósitos diferentes:
    Construtor de cópia: É chamado quando um novo objeto é criado a partir de outro objeto 
    já existente (por exemplo, FragTrap fraggyCopy(fraggy)).
    Operador de atribuição: É chamado quando um objeto já existente é atribuído a outro 
    objeto também já existente (por exemplo, fraggy = fraggyCopy;).
    Logo, o operador de atribuição pode ser necessário em cenários em que não estamos a 
    inicializar um novo objeto, mas a reutilizar um objeto já existente. 
    Isso acontece, por exemplo, se em algum ponto no código quiseres fazer:
    FragTrap fraggy("Fraggy");
    FragTrap anotherFraggy;
    anotherFraggy = fraggy; // Aqui é chamado o operador de atribuição.
    Neste caso, como o objeto anotherFraggy já foi inicializado, 
    o construtor de cópia não seria chamado. Em vez disso, o operador de atribuição 
    seria chamado para "copiar" o estado de fraggy para anotherFraggy.

2.2. - Porque implementar o operador de atribuição nas classes derivadas (ScavTrap e FragTrap)?
Quando se trata de classes derivadas como ScavTrap e FragTrap, o operador de atribuição não é 
automaticamente herdado da classe base. Isso significa que, embora ClapTrap tenha um operador 
de atribuição, as classes derivadas precisam implementar o seu próprio operador de atribuição 
se tiverem membros específicos (mesmo que no momento não tenham novos atributos além dos herdados).

    Aqui está porque é necessário:

        . Polimorfismo e consistência: Mesmo que as classes derivadas como FragTrap e ScavTrap 
        não tenham novos atributos no momento, é uma boa prática implementar o operador de atribuição nelas. 
        Isso assegura que, se no futuro forem adicionados novos atributos específicos para essas classes, 
        o operador já estará lá para lidar com a cópia de forma correta.

        . Respeitar o padrão ortodoxo canónico: O C++ tem um conjunto de regras para garantir que as 
        classes tenham um comportamento previsível ao serem copiadas ou atribuídas, o chamado 
        Big Three (ou Big Five no C++11): construtor de cópia, destrutor e operador de atribuição. 
        Implementar o operador de atribuição nas classes derivadas segue essa convenção, 
        mantendo o design da classe robusto e extensível.

2.3. - O operador de atribuição é chamado na classe derivada?
    Sim, ele será chamado caso uma atribuição seja feita entre dois objetos já existentes da classe derivada. 
    Apesar de o construtor de cópia não chamar o operador de atribuição, este será utilizado em situações 
    de atribuição direta, como o exemplo anterior.

    Portanto, a implementação do operador de atribuição nas classes derivadas faz sentido para cobrir o 
    caso da atribuição entre objetos já existentes. Isso garante que as classes derivadas também possam 
    copiar seus próprios atributos e os da classe base corretamente.

2.4. - O que o operador de atribuição faz na classe derivada?
    No caso de ScavTrap e FragTrap, o operador de atribuição:

    Primeiro, verifica se não estamos a fazer auto-atribuição (se this == &copy).
    Em seguida, atribui os atributos da classe base (_name, _hitPoints, etc.), 
    normalmente reutilizando os métodos getName(), getHitPoints(), etc.
    Finalmente, retorna *this para permitir a atribuição em cadeia.
    Mesmo que não haja membros adicionais a serem copiados nas classes derivadas, 
    o operador ainda cuida da cópia dos atributos herdados da classe base.

Conclusão
    A implementação do operador de atribuição nas classes derivadas (ScavTrap e FragTrap) é 
    necessária para garantir que objetos dessas classes possam ser corretamente atribuídos uns aos outros. 
    Isso é parte do padrão ortodoxo canónico e permite que a classe seja extensível, 
    mesmo que no momento não haja atributos específicos nas classes derivadas. 
    O construtor de cópia e o operador de atribuição têm propósitos diferentes, 
    e ambos são importantes para o comportamento correto das classes.

IMPORTANTE: Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 7 do Fixed.cpp do CPP02ex01.
*/

#include "FragTrap.hpp"

// Construtor padrão: inicializa a FragTrap com valores específicos e chama o construtor de ClapTrap
FragTrap::FragTrap(void) : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

// Construtor parametrizado: inicializa com o nome passado como parâmetro e valores padrão de FragTrap
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Parametrized Constructor called" << std::endl;
}

// Construtor de cópia: copia os valores de outro FragTrap, invocando o construtor de cópia de ClapTrap
FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    //*this = copy;  // Usa o operador de atribuição
    //Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 7 do Fixed.cpp do CPP02ex01.

}

// Destrutor: imprime mensagem e segue a ordem inversa de destruição, chamando primeiro o destrutor de FragTrap
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

// Operador de atribuição: copia os valores do FragTrap passado como parâmetro
FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap Assignation Operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);  // Usa o operador de atribuição da classe base. // Invoca o operador de atribuição da classe base. Ver mais info no ponto 6 dos comments do ScavTrap.cpp do CPP03ex01. Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 6 do ScavTrap.cpp do CPP03ex01.
    }
    return *this;
}

// Função especial: pede um high five de forma positiva
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
}
