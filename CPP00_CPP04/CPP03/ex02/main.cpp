/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:41:30 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 01:16:22 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A saída do main() reflete a criação, cópia, utilização e destruição de objetos 
da classe FragTrap, que herda de ClapTrap. Vamos detalhar cada parte da saída 
e o que ocorre em termos de construção, cópia e destruição de objetos, 
além das interações com os métodos das classes:

1. Criação do objeto fraggy
    - FragTrap fraggy("Fraggy");
    A criação de um objeto FragTrap com o nome "Fraggy" chama os construtores 
    das classes base (ClapTrap) e derivada (FragTrap).
        . ClapTrap Parametrized Constructor called: Primeiro, o construtor 
        parametrizado da classe base ClapTrap é chamado, pois FragTrap 
        herda de ClapTrap. Isso inicializa os atributos de ClapTrap para o objeto fraggy.
        . FragTrap Parametrized Constructor called: Em seguida, o construtor parametrizado 
        de FragTrap é chamado, que pode inicializar ou modificar atributos específicos de 
        FragTrap (como energia adicional, capacidades extras, etc.).

2. Interações de combate
Aqui, o objeto fraggy executa ações de combate:
    - fraggy.attack("Bandit");
    - fraggy.takeDamage(30);
    - fraggy.beRepaired(20);
        . ClapTrap Fraggy attacks Bandit, causing 30 points of damage!: 
        O método attack() de ClapTrap (herdado por FragTrap) é chamado, 
        exibindo que Fraggy ataca o alvo "Bandit" com 30 pontos de dano.
        . ClapTrap Fraggy takes 30 points of damage, remaining HP: 70: 
        O método takeDamage() de ClapTrap é chamado, reduzindo os pontos 
        de vida de Fraggy em 30 (assumindo que ele começou com 100 pontos de vida).
        . ClapTrap Fraggy is repaired by 20 points, remaining HP: 90: 
        O método beRepaired() de ClapTrap restaura 20 pontos de vida de Fraggy, 
        elevando sua saúde para 90.

3. FragTrap pedindo um high-five
    - fraggy.highFivesGuys();
        . FragTrap Fraggy is requesting a high five!: O método específico de FragTrap, 
        highFivesGuys(), é chamado. Este método não está presente em ClapTrap, 
        e é uma funcionalidade especial de FragTrap, indicando que Fraggy está a pedir um "high-five".

4. Criação do objeto fraggyCopy via construtor de cópia
    - FragTrap fraggyCopy(fraggy);
    Quando um novo objeto fraggyCopy é criado a partir de fraggy, o construtor de cópia é chamado. 
    Aqui temos várias chamadas:
        . ClapTrap Copy Constructor called: O construtor de cópia de ClapTrap é chamado primeiro, 
        copiando os atributos de ClapTrap de fraggy para fraggyCopy.
        . ClapTrap Assignation Operator called: O operador de atribuição de ClapTrap pode ser 
        chamado se, ao copiar, a classe estiver a usar o operador de atribuição sobrecarregado, 
        que normalmente copia os valores dos atributos.
        . FragTrap Copy Constructor called: Após copiar a parte de ClapTrap, 
        o construtor de cópia de FragTrap é chamado, completando a cópia de qualquer 
        atributo ou funcionalidade específica de FragTrap.

5. Interações de combate com fraggyCopy
    - fraggyCopy.attack("Raider");
    - fraggyCopy.takeDamage(40);
        . ClapTrap Fraggy attacks Raider, causing 30 points of damage!: O fraggyCopy ataca "Raider", 
        usando o método attack() herdado de ClapTrap.
        . ClapTrap Fraggy takes 40 points of damage, remaining HP: 50: fraggyCopy sofre 40 pontos de dano, 
        resultando em 50 pontos de vida restantes (assumindo que começou com 90).
6. Reparando fraggyCopy
    - fraggyCopy.beRepaired(25);
        . ClapTrap Fraggy is repaired by 25 points, remaining HP: 75: O método beRepaired() é 
        chamado para fraggyCopy, restaurando 25 pontos de vida, totalizando 75 pontos de saúde.
7. Fraggy original pedindo um high-five novamente
    - fraggy.highFivesGuys();
        . FragTrap Fraggy is requesting a high five!: O objeto original fraggy pede novamente um high-five, 
        mostrando que tanto o original quanto a cópia ainda estão em funcionamento.
8. Destruição dos objetos
    - Quando o programa termina, os objetos fraggy e fraggyCopy são destruídos:
        . FragTrap Destructor called: O destrutor de FragTrap é chamado para o objeto fraggyCopy (a cópia), 
        que por sua vez chama o destrutor de ClapTrap.
        . ClapTrap Destructor called: O destrutor de ClapTrap é chamado após o destrutor de FragTrap, 
        para limpar os recursos de ClapTrap da cópia.
        . FragTrap Destructor called: O destrutor de FragTrap é chamado para o objeto original fraggy.
        . ClapTrap Destructor called: Finalmente, o destrutor de ClapTrap é chamado para fraggy, 
        completando a destruição do objeto.

Conclusão
A sequência de eventos reflete o ciclo completo de vida de objetos em C++, desde a criação, cópia, 
utilização e destruição. Os construtores são chamados na ordem de herança (primeiro ClapTrap, depois FragTrap), 
e o mesmo ocorre para os destrutores. A cópia de objetos envolve os construtores de cópia e 
operadores de atribuição para garantir que o novo objeto seja uma cópia fiel.
*/

#include "FragTrap.hpp"

int main(void)
{
    std::cout << std::endl;
    // Criação de um FragTrap
    FragTrap fraggy("Fraggy");
    std::cout << std::endl;

    // Exibindo interações de combate
    fraggy.attack("Bandit");
    fraggy.takeDamage(30);
    fraggy.beRepaired(20);
    std::cout << std::endl;
    
    // FragTrap a pedir um high-five
    fraggy.highFivesGuys();
    std::cout << std::endl;
    
    // Outro FragTrap a partir de cópia
    FragTrap fraggyCopy(fraggy);
    std::cout << std::endl;
    
    // Cópia a atacar e sofrer dano
    fraggyCopy.attack("Raider");
    fraggyCopy.takeDamage(40);
    std::cout << std::endl;
    
    // Reparando a cópia
    fraggyCopy.beRepaired(25);
    std::cout << std::endl;
    
    // Fraggy original ainda a pedir um high-five!
    fraggy.highFivesGuys();
    std::cout << std::endl;
    
    return 0;
}
