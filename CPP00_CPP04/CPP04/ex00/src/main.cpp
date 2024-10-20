/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:34 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 15:12:37 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    // Teste com Animal, Dog e Cat
    std::cout << std::endl;
    std::cout << "=== Testar a classe Animal, Dog e Cat ===" << std::endl;
    const Animal* meta = new Animal();        // Criar um Animal genérico
    const Animal* dog = new Dog();            // Criar um Dog, que herda de Animal
    const Animal* cat = new Cat();            // Criar um Cat, que herda de Animal
    
    // Mostrar os tipos
    std::cout << std::endl;
    std::cout << "       *** Mostrar os tipos dos animais:" << std::endl;
    std::cout << "Animal tipo: " << dog->getType() << std::endl; // Deve exibir "Dog"
    std::cout << "Animal tipo: " << cat->getType() << std::endl; // Deve exibir "Cat"
    
    // Mostrar os sons - Testar o Polimorfismo com o Método makeSound()
    std::cout << std::endl;
    std::cout << "       *** Mostrar os sons dos animais:" << std::endl;
    meta->makeSound(); // Som genérico de Animal
    dog->makeSound(); // Deve latir
    cat->makeSound(); // Deve miar
    
    // Testar a cópia - copy construtor e operador de atribuição (q não está a ser usado)
    std::cout << std::endl;
    std::cout << "       *** Testar a cópia dos animais:" << std::endl;
    const Animal* dog2 = new Dog();
	const Animal* copy = dog2;
    std::cout << "Copy type: " << copy->getType() << std::endl;
	copy->makeSound();
 
    // Limpando a memória alocada
    std::cout << std::endl;
    std::cout << "=== Limpar a memória alocada ===" << std::endl;
    std::cout << "       *** Eliminar Animal" << std::endl;
    delete meta;
    std::cout << "       *** Eliminar Dog" << std::endl;
    delete dog;
    std::cout << "       *** Eliminar Cat" << std::endl;
    delete cat;
    std::cout << "       *** Eliminar Dog2" << std::endl;
    delete dog2;
    
    // Teste com WrongAnimal e WrongCat
    std::cout << std::endl;
    std::cout << "=== Testar a classe WrongAnimal e WrongCat ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal(); // Criar um WrongAnimal genérico
    const WrongAnimal* wrongCat = new WrongCat();     // Criar um WrongCat, que herda de WrongAnimal

    // Mostrar o tipo de WrongCat
    std::cout << std::endl;
    std::cout << "       *** Mostrar os tipos dos animais errados:" << std::endl;
    std::cout << "WrongAnimal tipo: " << wrongCat->getType() << std::endl; // Deve exibir "WrongCat"
    
    // Mostrar o som de WrongCat - Testar o Polimorfismo com o Método makeSound()
    std::cout << std::endl;
    std::cout << "       *** Mostrar os sons dos animais errados:" << std::endl;
    wrongCat->makeSound();   // Deve emitir o som de WrongAnimal (não de gato)
    wrongMeta->makeSound();  // Som genérico de WrongAnimal

    // Limpando a memória alocada
    std::cout << std::endl;
    std::cout << "=== Limpar a memória alocada ===" << std::endl;
    std::cout << "       *** Eliminar WrongAnimal" << std::endl;
    delete wrongMeta;
    std::cout << "       *** Eliminar WrongCat" << std::endl;
    delete wrongCat;

    return 0;
}
