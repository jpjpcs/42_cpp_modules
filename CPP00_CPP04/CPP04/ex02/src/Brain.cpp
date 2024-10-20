/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:55:54 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:40:14 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Construtor padrão
Brain::Brain() 
{
    std::cout << "Brain default constructor called." << std::endl;
    const std::string ideas_list [] = 
    {
        "I am hungry",
        "I want to play",
        "I need to pee",
        "I feel sleepy",
        "I want to explore the world",
        "I need a cozy nap",
        "I wish for a treat",
        "I want to chase squirrels",
        "I need some belly rubs",
        "I want to climb a tree",
        "I feel like scratching something",
        "I want to investigate that box",
        "I need to groom myself",
        "I wish I could catch that bird",
        "I want to find a sunny spot",
        "I feel playful today",
        "I need some fresh air",
        "I miss my human",
        "I want to dig a hole",
        "I want to smell the flowers"
    };

    for (int i = 0; i < ideasCount; i++) 
    {
        this->ideas[i] = ideas_list[rand()%20]; // Cópia profunda que copia o conteúdo de cada uma das ideias.
    } 
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00 e ponto 1 do Brain.cpp do CPP04ex01
Brain::Brain(const Brain& to_copy) 
{
    std::cout << "Brain copy constructor called." << std::endl;
    for (int i = 0; i < ideasCount; i++) 
    {
        this->ideas[i] = to_copy.ideas[i]; // Cópia profunda que copia o conteúdo de cada uma das ideias.
    }
}

// Operador de atribuição
Brain& Brain::operator=(const Brain& to_copy) 
{
    std::cout << "Brain assignment operator called." << std::endl;
    if (this != &to_copy) 
    {
        for (int i = 0; i < ideasCount; i++) 
        {
            this->ideas[i] = to_copy.ideas[i]; // Cópia profunda que copia o conteúdo de cada uma das ideias.
        }
    }
    return *this;
}

// Destrutor

Brain::~Brain() 
{
    std::cout << "Brain destructor called." << std::endl;
}

// Método para apresentar as ideias

void Brain::showIdeas() const 
{
    for (int i = 0; i < 3; i++) 
    {
        std::cout << "Idea #" << i + 1 << ": " << this->ideas[i] << std::endl;
    }
}
