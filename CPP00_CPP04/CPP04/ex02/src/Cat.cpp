/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:07 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 13:06:38 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Construtor padrão
Cat::Cat() 
{
    std::cout << "Cat default constructor called." << std::endl;
    this->_brain = new Brain();  // Instancia o objeto Brain
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00
Cat::Cat(const Cat& to_copy) : Animal(to_copy) 
{
    std::cout << "Cat copy constructor called." << std::endl;
    this->_brain = new Brain(*to_copy._brain);  // Cria uma cópia do cérebro
}

// Operador de atribuição
Cat& Cat::operator=(const Cat& to_copy) 
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
    std::cout << "Cat assignment operator called." << std::endl;
    return *this;
}

// Destrutor
Cat::~Cat() 
{
    delete this->_brain;  // Libera a memória alocada para o cérebro
    std::cout << "Cat destructor called." << std::endl;
}

// Sobrescreve a função makeSound para o som específico do gato
void Cat::makeSound() const 
{
    std::cout << "Cat: Miau!" << std::endl;
}

// Getter para o cérebro
Brain* Cat::getBrain(void) const
{
    return this->_brain;
}
