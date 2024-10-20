/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:47 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:50:32 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Construtor padrão
WrongCat::WrongCat() 
{
    this->type = "WrongCat";  // Define o tipo como "WrongCat"
    std::cout << "WrongCat default constructor called." << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00
WrongCat::WrongCat(const WrongCat& to_copy) : WrongAnimal(to_copy) 
{
    std::cout << "WrongCat copy constructor called." << std::endl;
}

// Operador de atribuição
WrongCat& WrongCat::operator=(const WrongCat& to_copy) 
{
    if (this != &to_copy) 
    {
        WrongAnimal::operator=(to_copy); // Chama o operador de atribuição da classe base
    }
    std::cout << "WrongCat assignment operator called." << std::endl;
    return *this;
}

// Destrutor
WrongCat::~WrongCat() 
{
    std::cout << "WrongCat destructor called." << std::endl;
}
