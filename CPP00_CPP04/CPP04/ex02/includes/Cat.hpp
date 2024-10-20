/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:06 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:52:02 by joaosilva        ###   ########.fr       */
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
        Cat &operator=(const Cat &to_copy);
        
        // Destrutor
        virtual ~Cat();
        
        // Sobrescreve a função makeSound para o som específico do gato
        virtual void	makeSound(void) const;

        // Getter
		Brain *getBrain(void) const;

        private:
		    Brain*	_brain;
};

#endif
