/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:55:54 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:29:46 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

// Construtor padrão
Brain::Brain() 
{
    std::cout << "Brain created." << std::endl;
}

// Construtor de cópia
Brain::Brain(const Brain& to_copy) 
{
    std::cout << "Brain copied." << std::endl;
    for (int i = 0; i < ideasCount; i++) 
    {
        ideas[i] = to_copy.ideas[i]; // Cópia profunda
    }
}

// Operador de atribuição
Brain& Brain::operator=(const Brain& to_copy) 
{
    if (this != &to_copy) 
    {
        std::cout << "Brain assigned." << std::endl;
        for (int i = 0; i < ideasCount; i++) 
        {
            ideas[i] = to_copy.ideas[i]; // Cópia profunda
        }
    }
    return *this;
}

// Destrutor
Brain::~Brain() 
{
    std::cout << "Brain destroyed." << std::endl;
}

// Método para definir uma ideia
void Brain::setIdea(int index, const std::string& idea) 
{
    if (index >= 0 && index < ideasCount) 
    {
        ideas[index] = idea;
    }
}

// Método para obter uma ideia
std::string Brain::getIdea(int index) const 
{
    if (index >= 0 && index < ideasCount) 
    {
        return ideas[index];
    }
    return "";
}
