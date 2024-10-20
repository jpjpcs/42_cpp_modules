/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:40 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:49:50 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Construtor padrão
WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00
WrongAnimal::WrongAnimal(const WrongAnimal& to_copy) : type(to_copy.type) 
{
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

// Operador de atribuição
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& to_copy) 
{
    if (this != &to_copy) 
    {
        this->type = to_copy.type; // nao chamo getType. Atribuo diretamente.
    }
    std::cout << "WrongAnimal assignment operator called." << std::endl;
    return *this;
}

// Destrutor
WrongAnimal::~WrongAnimal() 
{
    std::cout << "WrongAnimal destructor called." << std::endl;
}

// Função makeSound (errada)
void WrongAnimal::makeSound() const 
{
    std::cout << "WrongAnimal: some strange sound..." << std::endl;
}

//Getter para o tipo
std::string WrongAnimal::getType() const 
{
    return this->type;
} 

/*
void WrongAnimal::setType(std::string type) 
{
    this->type = type;
}
*/
