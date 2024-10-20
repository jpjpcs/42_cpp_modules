/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:04:48 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 13:11:27 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Construtor parametrizado? Não. Construtor padrão. Não recebe argumentos. Inicializa o tipo como "Animal". 
Animal::Animal() : type("Animal") 
{
    std::cout << "Animal default constructor called." << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00 e ponto 1 do Brain.cpp do CPP04ex01
Animal::Animal(const Animal& to_copy) : type(to_copy.type) 
{
    std::cout << "Animal copy constructor called." << std::endl;
}

// Operador de atribuição
Animal& Animal::operator=(const Animal& to_copy) 
{
    if (this != &to_copy) 
    {
        this->type = to_copy.type; // nao chamo getType. Faço cópias direta de to_copy para a string type.
    }
    std::cout << "Animal assignment operator called." << std::endl;
    return *this;
}

// Destrutor
Animal::~Animal() 
{
    std::cout << "Animal destructor called." << std::endl;
}

// Função virtual que será sobrescrita
void Animal::makeSound() const 
{
    std::cout << "Animal: generic sound." << std::endl;
}

// Getter para o tipo
std::string Animal::getType() const 
{
    return this->type;
}

/*
void Animal::setType(std::string type) 
{
    this->type = type;
}*/
