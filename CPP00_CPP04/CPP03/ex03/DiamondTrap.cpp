/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:01:10 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 14:37:56 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1 - Uso de *this = copy ou this->_name = copy._name; no construtor de cópia de DiamondTrap:
    1.1. - No construtor de cópia, e no âmbito da herança multipla, é mais correto usar:
        DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) 
        {
            this->_name = copy._name; // Copia o nome
            std::cout << "DiamondTrap copy constructor called" << std::endl;
        }

                                OU

        DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) 
        {
            *this = copy;
            std::cout << "DiamondTrap copy constructor called" << std::endl;
        }
    1.2. - quais as diferenças?
    1.3. - Qual a abordagem mais correta?

***RESPOSTAS: *************************************************

    1.1. - Diferença entre as duas abordagens:
    - Primeira abordagem:

        DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
            this->_name = copy._name; // Copia o nome
            std::cout << "DiamondTrap copy constructor called" << std::endl;
        }
        . Nesta versão, o construtor de cópia chama explicitamente os construtores de cópia de ClapTrap, ScavTrap e FragTrap. 
        . Após isso, ele copia diretamente o atributo _name de copy.

    - Segunda abordagem:
        DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) 
        {
            *this = copy;
            std::cout << "DiamondTrap copy constructor called" << std::endl;
        }
        . Aqui, o construtor de cópia também chama os construtores de cópia das classes base, mas depois usa o operador 
        de atribuição (operator=) para copiar os membros de copy. Isso faz com que todo o estado de copy seja transferido 
        para this, incluindo os atributos de todas as classes base.

    1.2. Diferenças:
        - A primeira abordagem copia diretamente o valor do atributo _name da instância copy. Ela não depende do operador de 
        atribuição e lida apenas com o atributo específico de DiamondTrap.

        - A segunda abordagem faz uma cópia de toda a instância copy usando o operador de atribuição (operator=), 
        o que copia não só os membros de DiamondTrap, mas também os atributos herdados de ClapTrap, ScavTrap e FragTrap. 
        Isso implica que o operador de atribuição seja invocado após os construtores de cópia, o que pode parecer redundante, 
        uma vez que os construtores já foram chamados para cada base.

    1.3. Qual a abordagem mais correta?
        - A primeira abordagem é geralmente mais correta e eficiente em termos de cópia de objetos, porque:
            . Evita duplicidade: O uso do operador de atribuição na segunda abordagem causa redundância. 
            Primeiro, os construtores de cópia das classes base são chamados, e depois o operador de atribuição faz a cópia novamente. 
            Isso pode ser desnecessário e ineficiente.
            . Mais claro: Na primeira abordagem, sabemos exatamente o que está a ser copiado no construtor de cópia. 
            No exemplo, o atributo _name é copiado diretamente, e temos o controlo sobre o que é copiado, o que pode evitar surpresas.
            . Evita possíveis efeitos colaterais: O uso do operador de atribuição pode envolver mais lógica, 
            e se houver efeitos colaterais no operador de atribuição (por exemplo, alocações de memória 
            ou lógica extra), eles serão invocados sem necessidade.

Conclusão: Portanto, a primeira abordagem é preferível porque é mais clara, eficiente, e evita duplicação de esforços de cópia.

Ver mais info no ponto 1 do DiamondTrap.cpp do CPP03ex03 e no ponto 5 
        do ScavTrap.cpp do CPP03ex01.
*/

#include "DiamondTrap.hpp"

// Construtor padrão
DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
    this->_name = "Default"; // Atribui um nome padrão
    this->_hitPoints = FragTrap::_hitPoints; // Usa os pontos de vida do FragTrap
    this->_energyPoints = ScavTrap::_energyPoints; // Usa a energia do ScavTrap
    this->_attackDamage = FragTrap::_attackDamage; // Usa o dano de ataque do FragTrap
    this->ClapTrap::_name = this->_name + "_clap_name"; // Define o nome ClapTrap
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Construtor com parâmetro
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    this->_name = name; // Atribui o nome passado como parâmetro
    this->_hitPoints = FragTrap::_hitPoints; // Usa os pontos de vida do FragTrap
    this->_energyPoints = ScavTrap::_energyPoints; // Usa a energia do ScavTrap
    this->_attackDamage = FragTrap::_attackDamage; // Usa o dano de ataque do FragTrap
    //this->ClapTrap::_name = this->_name + "_clap_name"; // Define o nome ClapTrap. Coloquei na definição da função.
    std::cout << "DiamondTrap Parametrized constructor called" << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do DiamondTrap.cpp do CPP03ex03 e no ponto 5 
//        do ScavTrap.cpp do CPP03ex01.
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) 
{
    this->_name = copy._name; // Copia o nome
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Destrutor
DiamondTrap::~DiamondTrap(void) 
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

// Operador de atribuição
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) 
{
    if (this != &copy) 
    {
        this->_name = copy._name; // Copia o nome
        this->_hitPoints = copy._hitPoints; // Copia os pontos de vida
        this->_energyPoints = copy._energyPoints; // Copia a energia
        this->_attackDamage = copy._attackDamage; // Copia o dano de ataque
        this->ClapTrap::_name = copy.ClapTrap::_name; // Copia o nome ClapTrap
    }
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

// Função whoAmI para exibir os nomes
void DiamondTrap::whoAmI(void) 
{
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << this->ClapTrap::_name << std::endl;
}
