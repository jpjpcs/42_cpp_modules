/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:31:24 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:58:06 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 Este é name da void setName(std::string name); não é o _name da std::string _name;, porque é um parâmetro e não um atributo
 Isto é, é um parâmetro que será passado para a função newZombie
 enquanto que _name é um atributo da classe Zombie. Este atributo
 será usado na função announce para anunciar o nome do Zombie
 O parâmetro name será usado na função newZombie e randomChump
 para criar um Zombie com o nome passado como parâmetro
 Zombie *newZombie(std::string name); // Função para criar um Zombie
 void randomChump(std::string name); // Função para criar um Zombie aleatório
*/

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string> // Biblioteca para usar std::string
#include <iostream> // Biblioteca para usar std::cout
# include <cstdlib> // Biblioteca para usar atoi

class Zombie
{
    public:
        Zombie(void); // Construtor
        Zombie(std::string name); // Construtor Parametrizado
        ~Zombie(); // Destrutor
        void announce(void); // Função para anunciar o nome do Zombie
        void setName(std::string name); // Função para definir o nome do Zombie

    private:
        std::string _name; // Nome do Zombie
};

Zombie	*zombieHorde(int N, std::string name); // Função para criar uma multidão de Zombies

#endif
