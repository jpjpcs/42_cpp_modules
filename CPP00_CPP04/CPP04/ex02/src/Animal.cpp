/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:04:48 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:15:59 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Construtor padrão
Animal::Animal() : type("Animal") {
    std::cout << "Animal criado!" << std::endl;
}

// Construtor de cópia
Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copiado!" << std::endl;
}

// Operador de atribuição
Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Animal atribuído!" << std::endl;
    return *this;
}

// Destrutor
Animal::~Animal() {
    std::cout << "Animal destruído!" << std::endl;
}

// Getter do tipo
std::string Animal::getType() const {
    return this->type;
}
