/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:34 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 13:09:15 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Explicação do código:
1. Instanciando Dog e Cat: Como Dog e Cat são classes derivadas de Animal, 
que agora é abstrata, elas devem implementar o método makeSound, permitindo 
que as instâncias de Dog e Cat sejam criadas e seus sons específicos sejam exibidos.

2. Tentativa de instanciar Animal: A linha comentada Animal* animal = new Animal(); 
serve para mostrar que não é possível instanciar a classe Animal, pois ela é agora uma classe abstrata.

3. Uso do polimorfismo: As instâncias de Dog e Cat são criadas e armazenadas 
como ponteiros de Animal, mostrando o uso do polimorfismo. Quando chamamos makeSound() 
nos ponteiros dog e cat, o método correto de cada classe derivada é chamado.

4. Testando a hierarquia errada (WrongAnimal e WrongCat): A classe WrongCat 
é derivada de WrongAnimal, mas pode ter uma implementação diferente. Isso serve 
para demonstrar que, sem polimorfismo adequado, o comportamento pode não ser o esperado. 
*/

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() 
{
    // Tentar criar uma instância de Animal deve falhar, pois Animal é uma classe abstrata.
    // Animal* animal = new Animal();  // Isto deveria dar erro de compilação

    // Criar instâncias de Dog e Cat, que são classes concretas derivadas de Animal.
    std::cout << "=== Testando Dog e Cat ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;

    // Fazer sons
    std::cout << "=== Som Dog e Cat ===" << std::endl;
    std::cout << "Dog sound: ";
    dog->makeSound();  // Deve exibir o som do cão
    std::cout << "Cat sound: ";
    cat->makeSound();  // Deve exibir o som do gato
    std::cout << std::endl;
    
    // Mostrar tipos
    std::cout << "=== Tipos ===" << std::endl;
    std::cout << "Dog é: " << dog->getType() << std::endl;
    std::cout << "Cat é: " << cat->getType() << std::endl;
    std::cout << std::endl;
    
    // Limpar memória
    std::cout << "=== Limpar memória ===" << std::endl;
    delete dog;
    delete cat;
    std::cout << std::endl;

    // Testando a WrongAnimal e WrongCat
    std::cout << "=== Testando WrongAnimal e WrongCat ===" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "WrongCat sound: ";
    wrongCat->makeSound();  // Deve exibir o som do WrongCat, que não é o som correto de um gato
    delete wrongCat;
    std::cout << std::endl;

    return 0;
}
