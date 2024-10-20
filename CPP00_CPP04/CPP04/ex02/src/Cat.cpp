/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:07 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:16:56 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Construtor padrão
Cat::Cat() {
    this->type = "Cat";
    std::cout << "Gato criado!" << std::endl;
}

// Construtor de cópia
Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Gato copiado!" << std::endl;
}

// Operador de atribuição
Cat &Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Gato atribuído!" << std::endl;
    return *this;
}

// Destrutor
Cat::~Cat() {
    std::cout << "Gato destruído!" << std::endl;
}

// Implementação de makeSound
void Cat::makeSound() const {
    std::cout << "Meow Meow!" << std::endl;
}
