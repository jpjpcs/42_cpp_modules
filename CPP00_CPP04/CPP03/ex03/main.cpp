/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:00:45 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 15:08:57 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Explicação da Saída do Main:

1. Diamond 1 - teste construtor padrão

    . Construtores Chamados:
            Saída: 
            ClapTrap Default Constructor called
            ScavTrap Default Constructor called
            FragTrap Default Constructor called
            DiamondTrap default constructor called
        - O objeto d1 é criado usando o construtor padrão de DiamondTrap, que herda 
        dos construtores padrão de ClapTrap, ScavTrap e FragTrap. O nome da 
        instância DiamondTrap é Default, e o nome gerado para 
        a instância ClapTrap interna é Default_clap_name.

    . Método whoAmI:
        - DiamondTrap name: Default, ClapTrap name: Default_clap_name
        Aqui, o método whoAmI() imprime o nome do DiamondTrap e o nome do ClapTrap associado.

    . Método attack:
        - ScavTrap Default_clap_name attacks Bandit, causing 30 points of damage!
        O DiamondTrap usa a função de ataque herdada de ScavTrap, e o ataque é feito no alvo "Bandit", 
        causando 30 pontos de dano.

    . Método takeDamage:
        - ScavTrap Default_clap_name takes 50 points of damage! remaining HP: 100
        ClapTrap Default_clap_name takes 50 points of damage, remaining HP: 50
        O objeto d1 leva 50 pontos de dano. A HP do ScavTrap começa em 100, e a do 
        ClapTrap (de onde a funcionalidade takeDamage foi herdada) é reduzida para 50.

    . Método beRepaired:
        - ScavTrap Default_clap_name is repaired by 25 points! remaining HP: 50
        ClapTrap Default_clap_name is repaired by 25 points, remaining HP: 75
        d1 é reparado em 25 pontos, então a HP do ClapTrap aumenta para 75.

    . Método guardGate:
        - ScavTrap Default_clap_name has entered in Gate keeper mode.
        d1 entra no modo de "Guardião", usando a funcionalidade herdada de ScavTrap.

    . Método highFivesGuys:
        - FragTrap Default_clap_name is requesting a high five!
        O DiamondTrap (por meio de FragTrap) pede um "high five".

2. Diamond 2 - teste construtor parametrizado
    . Construtores Chamados:
            Saída: 
            ClapTrap Parametrized Constructor called
            ScavTrap Parametrized Constructor called
            FragTrap Parametrized Constructor called
            DiamondTrap Parametrized constructor called
        - O objeto d2 é criado usando o construtor parametrizado com o nome "Warrior". O nome de ClapTrap associado torna-se "Warrior_clap_name".

    . Método whoAmI:
        - DiamondTrap name: Warrior, ClapTrap name: Warrior_clap_name
        Aqui, o nome da instância DiamondTrap e o nome de ClapTrap são exibidos.

    . Método attack:
        - ScavTrap Warrior_clap_name attacks Raider, causing 30 points of damage!
        O DiamondTrap ataca o alvo "Raider" causando 30 pontos de dano, herdando a função de ataque de ScavTrap.

    . Método takeDamage:
        - ScavTrap Warrior_clap_name takes 30 points of damage! remaining HP: 100
        - ClapTrap Warrior_clap_name takes 30 points of damage, remaining HP: 70
        d2 leva 30 pontos de dano, reduzindo a HP de ClapTrap para 70.

    . Método beRepaired:
        - ScavTrap Warrior_clap_name is repaired by 15 points! remaining HP: 70
        - ClapTrap Warrior_clap_name is repaired by 15 points, remaining HP: 85
        d2 é reparado por 15 pontos, subindo a HP para 85.

    . Método guardGate:
        - ScavTrap Warrior_clap_name has entered in Gate keeper mode.
        d2 entra no modo de "Guardião".

    . Método highFivesGuys:
        - FragTrap Warrior_clap_name is requesting a high five!
        O DiamondTrap pede um "high five" usando o método de FragTrap.

3. Diamond 3 - teste construtor cópia

    . Construtores Chamados:
            Saída: 
            ClapTrap Copy Constructor called
            ClapTrap Assignation Operator called
            ScavTrap Copy Constructor called
            FragTrap Copy Constructor called
            DiamondTrap copy constructor called
        - O objeto d3 é criado como uma cópia de d2, usando o construtor de cópia de cada uma das classes ClapTrap, ScavTrap, FragTrap e DiamondTrap.

    . Método whoAmI:
        - DiamondTrap name: Warrior, ClapTrap name: Warrior_clap_name
        Aqui, o DiamondTrap cópia (d3) tem o mesmo nome "Warrior" e o nome de ClapTrap também é "Warrior_clap_name".

    . Método attack:
        - ScavTrap Warrior_clap_name attacks Beast, causing 30 points of damage!
        d3 ataca o alvo "Beast", causando 30 pontos de dano.

    . Método takeDamage:
        - ScavTrap Warrior_clap_name takes 45 points of damage! remaining HP: 85
        - ClapTrap Warrior_clap_name takes 45 points of damage, remaining HP: 40
        d3 leva 45 pontos de dano, reduzindo a HP de ClapTrap para 40.

    . Método beRepaired:
        - ScavTrap Warrior_clap_name is repaired by 10 points! remaining HP: 40
        - ClapTrap Warrior_clap_name is repaired by 10 points, remaining HP: 50
        d3 é reparado por 10 pontos.

    . Método highFivesGuys:
        - FragTrap Warrior_clap_name is requesting a high five!
        d3 pede um "high five" novamente.

4. Diamond 4 - teste operador atribuição
    Operador de Atribuição Chamado:
            Saída: 
            DiamondTrap assignment operator called
        - d1 é atribuído a d3, usando o operador de atribuição sobrecarregado.

    . Método whoAmI:
        - DiamondTrap name: Warrior, ClapTrap name: Warrior_clap_name
        Após a atribuição, d1 adota o nome "Warrior" e "Warrior_clap_name" de d3.

    . Método attack:
        - ScavTrap Warrior_clap_name attacks ClapTrap, causing 30 points of damage!
        d1 ataca "ClapTrap", causando 30 pontos de dano.

    . Método takeDamage:
        - ScavTrap Warrior_clap_name takes 20 points of damage! remaining HP: 50
        - ClapTrap Warrior_clap_name takes 20 points of damage, remaining HP: 30
        d1 leva 20 pontos de dano.

    . Método beRepaired:
        - ScavTrap Warrior_clap_name is repaired by 5 points! remaining HP: 30
        - ClapTrap Warrior_clap_name is repaired by 5 points, remaining HP: 35
        d1 é reparado por 5 pontos.

5. Destrutores
    . Destrutores Chamados:
        Saída: 
        DiamondTrap destructor called
        FragTrap Destructor called
        ScavTrap Destructor called
        ClapTrap Destructor called
    - Esses são chamados ao fim do programa para destruir os objetos d1, d2, d3, 
    em ordem inversa de criação, conforme a ordem de chamada dos construtores, 
    segundo o princípio da destruição em cascata.
    - Ver mais info no ponto 6 do main.cpp do CPP03ex01 e
    no ponto 5 do main.cpp do CPP03ex03.
   
*/
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << std::endl;
    
    // Testando construtor padrão
    std::cout << "Diamond 1 - teste construtor padrão" << std::endl;
    DiamondTrap d1; // Cria uma instância com o construtor padrão
    d1.whoAmI(); // Exibe os nomes de DiamondTrap e ClapTrap
    d1.attack("Bandit");
    d1.takeDamage(50);
    d1.beRepaired(25);
    d1.guardGate();
    d1.highFivesGuys();
    std::cout << std::endl;

    // Testando construtor parametrizado
    std::cout << "Diamond 2 - teste construtor parametrizado" << std::endl;
    DiamondTrap d2("Warrior");
    d2.whoAmI();
    d2.attack("Raider");
    d2.takeDamage(30);
    d2.beRepaired(15);
    d2.guardGate();
    d2.highFivesGuys();
    std::cout << std::endl;

    // Testando construtor de cópia
    std::cout << "Diamond 3 - teste contrutor cópia" << std::endl;
    DiamondTrap d3(d2);
    d3.whoAmI();
    d3.attack("Beast");
    d3.takeDamage(45);
    d3.beRepaired(10);
    d3.highFivesGuys();
    std::cout << std::endl;

    // Testando operador de atribuição
    std::cout << "Diamond 4 - teste operador atribuição" << std::endl;
    d1 = d3;
    d1.whoAmI();
    d1.attack("ClapTrap");
    d1.takeDamage(20);
    d1.beRepaired(5);
    std::cout << std::endl;

    return 0;
}
