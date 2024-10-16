/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:54:26 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/08 16:55:12 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* 
Limpa a tela. c é o comando que, nesta sequência, 
 é conhecido como "Reset Terminal" ou "Full Reset".
\033 (ou \x1b em hexadecimal) é o código de escape ANSI,
 que inicia uma sequência de controle para o terminal.
 Portanto, \033c (também conhecido como "ESC c") 
 é um comando que limpa a tela.
*/

void	mainHeader(void)
{
	std::cout << "\033c";
	std::cout << "---------------------------------" << std::endl;
	std::cout << "*   BraiiiiiiinnnzzzZ ZOMBIES   *" << std::endl;
	std::cout << "---------------------------------" << std::endl << std::endl;
}

void	usage(void)
{
	std::cout << "Usage: ./zombie name_of_random_chump name_of_new_zombie" << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	std::string newZombieName;
    std::string randomName;
    Zombie* zombie;
    
    if (argc != 3)
		usage();

    newZombieName = argv[1];
    randomName = argv[2];
    
	mainHeader();
    
    // Cria um novo Zombie na heap com o nome passado como parâmetro e anuncia o seu nome
	std::cout << "\n\t**** New Zombie ****\n\n";
	zombie = newZombie(newZombieName);
	zombie->announce(); // Usa o this pointer para acessar à função announce da classe Zombie
	delete zombie;

    // Cria um Zombie com o nome passado como parâmetro e anuncia o seu nome
	std::cout << "\n\t**** Random Chump ****\n\n";
	randomChump(randomName);
    std::cout << "\n\n";
	return 0;
}
