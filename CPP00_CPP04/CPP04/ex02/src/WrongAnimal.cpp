/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:40 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:29:00 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {  // Destrutor virtual
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makes an unknown sound!" << std::endl;
}

