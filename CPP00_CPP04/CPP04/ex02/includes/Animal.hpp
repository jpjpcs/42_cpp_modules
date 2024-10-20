/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:58 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:37:05 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal 
{
    public:
        // Construtor padrão
        Animal();
        
        // Construtor de cópia
        Animal(const Animal &to_copy);
        
        // Operador de atribuição
        Animal &operator=(const Animal &to_copy);
        
        // Destrutor virtual para garantir que destrutores de subclasses sejam chamados
        virtual ~Animal();
        
        // Método virtual puro, tornando Animal uma classe abstrata
        virtual void makeSound() const = 0;

        // Getter para o tipo
        std::string getType() const;

    protected:
        std::string type;  // Tipo do animal
};

#endif
