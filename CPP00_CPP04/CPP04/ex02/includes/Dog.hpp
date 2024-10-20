/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:15 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:16:14 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    // Construtor padrão
    Dog();
    
    // Construtor de cópia
    Dog(const Dog &other);
    
    // Operador de atribuição
    Dog &operator=(const Dog &other);
    
    // Destrutor
    ~Dog();
    
    // Implementação de makeSound
    void makeSound() const;
};

#endif
