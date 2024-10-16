/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:54:26 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/24 18:06:30 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//// Limpa a tela. c é o comando que, nesta sequência, 
// é conhecido como "Reset Terminal" ou "Full Reset".
//\033 (ou \x1b em hexadecimal) é o código de escape ANSI,
// que inicia uma sequência de controle para o terminal.
// Portanto, \033c (também conhecido como "ESC c") 
// é um comando que limpa a tela.
// Outro main que podia ter sido usado:
/* int	main(int argc, char **argv)
{
	if (argc != 3)
		usage();
	
	std::string hordName = argv[2];
    int hordNumber = atoi(argv[1]);
    
	Zombie* horde = zombieHorde(hordNumber, hordName);
   
	mainHeader();
	for (int i = 0; i < hordNumber; i++)
	{
		horde[i].announce(); // Usa o índice para percorrer o array.
	}
	delete[] horde; // Liberta corretamente a memória alocada.
	return (0);
} */

#include "Zombie.hpp"

void	mainHeader(void)
{
	std::cout << "\033c";
	std::cout << "---------------------------------" << std::endl;
	std::cout << "*        HORDE OF ZOMBIES        *" << std::endl;
	std::cout << "---------------------------------" << std::endl << std::endl;
}

void	usage(void)
{
	std::cout << "Usage: ./zombie_horde number_of_zombies>=0 name_of_the_horde" << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		usage();
	
	std::string hordName;
    int hordNumber;
    Zombie* horde;
	int i;
    
	hordNumber = atoi(argv[1]);
	hordName = argv[2];
	horde = zombieHorde(hordNumber, hordName);
   
	mainHeader();
	i = 0;
	while (hordNumber > i)
	{
		horde[i].announce();
		i++;
	}
	std::cout << std::endl;
	delete [] horde; // [] é usado a seguir ao delete para indicar que estamos a apagar um array. Se não usarmos [] o compilador não saberá que estamos a apagar um array e não apagará corretamente a memória alocada.
	// Se fosse um único objeto, não seria necessário [], ou uma string ou um inteiro ou uma variável de qualquer tipo. Mas como é um array, é necessário []. 
	std::cout << std::endl;
	return (0);
}



