/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:15 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 12:47:31 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal 
{
    public:
        // Construtor padrão
        Dog();

        // Construtor de cópia
        Dog(const Dog &to_copy);

        // Operador de atribuição
        Dog& operator=(const Dog &to_copy);

        // Destrutor virtual para permitir o polimorfismo adequado
        virtual ~Dog(); // faz com que o destrutor da classe derivada seja chamado. override.
        
        // Sobrescreve a função makeSound para o som específico do cão
        virtual void makeSound() const; // Colocamos Virtual, mas não é necessário. A isto chama-se "label virtual" e é uma boa prática.
};

#endif
