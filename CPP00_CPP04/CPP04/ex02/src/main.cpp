/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:34 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:45:06 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    // Teste com Dog e Cat
    std::cout << "=== Testando Dog e Cat ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    // Mostrar tipos
    std::cout << "Dog é: " << dog->getType() << std::endl;
    std::cout << "Cat é: " << cat->getType() << std::endl;
    
    // Fazer sons
    dog->makeSound();
    cat->makeSound();

    // Limpando memória
    delete dog;
    delete cat;

    return 0;
}
