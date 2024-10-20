/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:19 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 13:35:51 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Construtor padrão
Dog::Dog() 
{
    this->type = "Dog";  // Define o tipo como "Dog"
    std::cout << "Dog default constructor called." << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00
Dog::Dog(const Dog &to_copy) : Animal(to_copy) 
{
    std::cout << "Dog copy constructor called." << std::endl;
}

// Operador de atribuição
Dog& Dog::operator=(const Dog& to_copy) 
{
    if (this != &to_copy) 
    {
        Animal::operator=(to_copy); // Chama o operador de atribuição da classe base
    }
    std::cout << "Dog assignment operator called." << std::endl;
    return *this;
}

// Destrutor
Dog::~Dog() 
{
    std::cout << "Dog destructor called." << std::endl;
}

// Sobrescreve a função makeSound para o som específico do cão
void Dog::makeSound() const 
{
    std::cout << "Dog: Woof!" << std::endl;
}
