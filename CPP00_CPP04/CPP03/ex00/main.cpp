/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:08:12 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/15 21:59:08 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void usage(void)
{
	std::cout << "Usage: ./program trap_name" << std::endl;
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		usage();

	// Criar ClapTraps
	ClapTrap t1;             // ClapTrap sem nome definido. Construtor default chamado.
	ClapTrap t2(argv[1]);     // ClapTrap com nome passado como argumento
	ClapTrap t3("João");
	ClapTrap t4("Maria");

	// Testar ClapTraps criados
	std::cout << "\n-------- Testing João vs Afonso --------\n";
	t3.attack("Afonso");
	t3.takeDamage(9);
	t3.beRepaired(5);

	std::cout << "\n-------- Testing João ataca Maria --------\n";
	t3.attack("Maria");
	t4.takeDamage(5); 
	t3.beRepaired(2);

    std::cout << "\n-------- Testing Maria ataca João --------\n";
    t4.attack("João");
    t3.takeDamage(5);
    t4.beRepaired(2);
    
    std::cout << "\n-------- Testing Manel ataca João --------\n";
    t2.attack("João");
    t3.takeDamage(5);
    t2.beRepaired(2);
    
	std::cout << "\n-------- Testing t1 = t3 (João) --------\n";
	t1 = t3; // Atribuir t3 para t1
    std::cout << "\n";
    std::cout << t1;
    std::cout << t3 << std::endl;

	return 0;
}
