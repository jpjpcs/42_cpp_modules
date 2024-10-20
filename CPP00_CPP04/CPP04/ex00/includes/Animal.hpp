/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:58 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 13:49:11 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal 
{
    public:
        // Construtor padrão
        Animal();
        
        // Construtor de cópia
        Animal(const Animal &to_copy);

        // Operador de atribuição
        Animal& operator=(const Animal &to_copy);
        
        // Destrutor virtual para permitir o polimorfismo adequado
        virtual ~Animal();

        // Função virtual que será sobrescrita nas classes derivadas.
        virtual void makeSound() const;

        // Getter e setter para o tipo do animal
        std::string getType() const;
        //void setType(std::string type);
    
    protected:
        std::string type;  // Atributo que define o tipo do animal
};

#endif
