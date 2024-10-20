/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:19 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:16:33 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Construtor padrão
Dog::Dog() {
    this->type = "Dog";
    std::cout << "Cão criado!" << std::endl;
}

// Construtor de cópia
Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Cão copiado!" << std::endl;
}

// Operador de atribuição
Dog &Dog::operator=(const Dog &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << "Cão atribuído!" << std::endl;
    return *this;
}

// Destrutor
Dog::~Dog() {
    std::cout << "Cão destruído!" << std::endl;
}

// Implementação de makeSound
void Dog::makeSound() const {
    std::cout << "Woof Woof!" << std::endl;
}
