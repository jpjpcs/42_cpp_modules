/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:58 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:53:58 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Modificações em relação ao exercício CPP04ex01:
1. No ficheiro Animal.hpp, a classe Animal passa a ser uma classe abstrata, 
com um método virtual puro makeSound(). Ou seja, makeSound() não tem implementação
na classe Animal, e as classes que herdam de Animal devem implementar esse método.
A função passou de virtual void makeSound() const para virtual void makeSound() const = 0;
*/

/*
No exercício 02 do CPP04 (Abstract class), o objetivo é impedir a criação direta de 
objetos da classe Animal, transformando-a em uma classe abstrata. Isso pode ser 
feito tornando pelo menos uma função da classe Animal puramente virtual. Normalmente, 
a função que faz sentido ser puramente virtual é a função makeSound, pois cada animal 
derivado deve ter a sua própria implementação.
*/

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
        Animal &operator=(const Animal &to_copy);
        
        // Destrutor virtual para garantir que destrutores de subclasses sejam chamados
        virtual ~Animal();
        
        // Método virtual puro, tornando Animal uma classe abstrata
        virtual void makeSound() const = 0;

        // Getter para o tipo
        std::string getType() const;
        // void setType(std::string type);

    protected:
        std::string type; // Atributo que define o tipo do animal
};

#endif
