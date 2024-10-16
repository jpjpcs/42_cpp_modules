/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:31:24 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/08 16:59:34 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
CPP01Ex00 e Ex01 memory: new & delete. Heap vs stack

CPP01Ex02 references and heap vs stack

CPP01Ex03 references vs pointers and heap vs stack

CPP01Ex04 file streams - Manipulação ficheiros

CPP01Ex05 Pointers to member functions

CPP01Ex06 swith case statement
*/

// Este é name da Zombie *newZombie(std::string name); ou 
// da void randomChump(std::string name); não é 
// o _name da std::string _name;, porque um é um parâmetro 
// e o outro é um atributo, respetivamente.
// Isto é, é um parâmetro que será passado para a função newZombie
// enquanto que _name é um atributo da classe Zombie. Este atributo
// será usado na função announce para anunciar o nome do Zombie
// O parâmetro name será usado na função newZombie e randomChump
// para criar um Zombie com o nome passado como parâmetro. 

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string> // Biblioteca para usar std::string
#include <iostream> // Biblioteca para usar std::cout

class Zombie
{
    public:
        Zombie(void); // Construtor
        Zombie(std::string name); // Construtor Parametrizado
        ~Zombie(); // Destrutor
        void announce(void); // Função para anunciar o nome do Zombie

    private:
        std::string _name; // Nome do Zombie
};

Zombie *newZombie(std::string name); // Função para criar um Zombie
void randomChump(std::string name); // Função para criar um Zombie aleatório

#endif
