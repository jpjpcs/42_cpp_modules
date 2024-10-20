/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:19 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:41:45 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Construtor padrão
Dog::Dog() 
{
     std::cout << "Dog default constructor called." << std::endl;
    this->_brain = new Brain();  // Instancia o objeto Brain
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00
Dog::Dog(const Dog &to_copy) : Animal(to_copy) 
{
    std::cout << "Dog copy constructor called." << std::endl;
    this->_brain = new Brain(*to_copy._brain);  // Cria uma cópia do cérebro
}

// Operador de atribuição
Dog& Dog::operator=(const Dog& to_copy) 
{
    if (this != &to_copy) 
    {
        Animal::operator=(to_copy); // Chama o operador de atribuição da classe base
        if (this->_brain) 
        {
            delete this->_brain;  // Libera a memória alocada para o cérebro
        }
        this->_brain = new Brain(*to_copy.getBrain());  // Cria uma cópia do cérebro
    }
    std::cout << "Dog assignment operator called." << std::endl;
    return *this;
}

// Destrutor
Dog::~Dog() 
{
    delete this->_brain;  // Libera a memória alocada para o cérebro
    std::cout << "Dog destructor called." << std::endl;
}

// Sobrescreve a função makeSound para o som específico do cão
void Dog::makeSound() const 
{
    std::cout << "Dog: Woof!" << std::endl;
}

// Getter para o cérebro
Brain* Dog::getBrain(void) const 
{
    return this->_brain;
}
