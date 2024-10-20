/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:06 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/19 13:40:16 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
    public:
            // Construtor padrão
            Cat();

            // Construtor de cópia
            Cat(const Cat &to_copy);

            // Operador de atribuição
            Cat& operator=(const Cat &to_copy);

            // Destrutor virtual para permitir o polimorfismo adequado
            virtual ~Cat(); // faz com que o destrutor da classe derivada seja chamado. override.

            // Sobrescreve a função makeSound para o som específico do gato. Colocamos Virtual, mas não é necessário. A isto chama-se "label virtual" e é uma boa prática.
            virtual void makeSound() const;

            // Getter para o cérebro
            Brain* getBrain(void) const;

    private:
             Brain* _brain; // Ponteiro para o objeto Brain
};

#endif
