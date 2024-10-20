/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:58 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:47:51 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Modificações em relação ao exercício 00
1. Nos ficheiros Dog.hpp e Cat.hpp e Dog.cpp e Cat.cpp:
    1.1. - introduzi função para obter o cérebro - getBrain para o cat e para o dog. Retorna um ponteiro para o cérebro.
    1.2. - alterei o construtor colocando a inicialização do ponteiro _brain para um novo objeto Brain.
    1.3. - alterei o destrutor para deletar o ponteiro _brain.
    1.4. - alterei o construtor de cópia para criar uma cópia do cérebro do objeto a ser copiado, usando o getBrain para 
    obter o ponteiro para o cérebro e passando-o para o construtor de cópia do Brain, e usando o delete para 
    libertar a memória alocada para o cérebro do objeto a ser copiado.
*/

/*
1 - Deep Copy vs Shallow Copy

    A deep copy copies all fields, and makes copies of dynamically allocated memory 
    pointed to by the fields. 

    To make a deep copy, you must write a copy constructor and overload the assignment operator, 
    otherwise the copy will point to the original, with disasterous consequences. 

    If an object has pointers to dynamically allocated memory, 
    and the dynamically allocated memory needs to be copied when the original object is copied, 
    then a deep copy is required.
    A class that requires deep copies generally needs: - A constructor to either make an 
    initial allocation or set the pointer to NULL. - A destructor to delete the dynamically 
    allocated memory. - A copy constructor to make a copy of the dynamically allocated 
    memory. - An overloaded assignment operator to make a copy of the dynamically allocated memory.
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
