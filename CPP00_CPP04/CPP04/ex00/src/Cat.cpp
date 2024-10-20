/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:07 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 13:35:01 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Construtor padrão
Cat::Cat() 
{
    this->type = "Cat";  // Define o tipo como "Cat"
    std::cout << "Cat default constructor called." << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00
Cat::Cat(const Cat& to_copy) : Animal(to_copy) 
{
    std::cout << "Cat copy constructor called." << std::endl;
}

// Operador de atribuição
Cat& Cat::operator=(const Cat& to_copy) 
{
    if (this != &to_copy) 
    {
        Animal::operator=(to_copy); // Chama o operador de atribuição da classe base
    }
    std::cout << "Cat assignment operator called." << std::endl;
    return *this;
}

// Destrutor
Cat::~Cat() 
{
    std::cout << "Cat destructor called." << std::endl;
}

// Sobrescreve a função makeSound para o som específico do gato
void Cat::makeSound() const 
{
    std::cout << "Cat: Miau!" << std::endl;
}
