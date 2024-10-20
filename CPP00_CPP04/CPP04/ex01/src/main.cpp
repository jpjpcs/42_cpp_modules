/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:34 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 11:44:35 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iomanip>

int main() 
{
    // Teste de polimorfismo
    std::cout << std::endl;
    std::cout << "=== Testar Polimorfismo 1 ALOCANDO NA HEAP ===" << std::endl;

    const int animalCount = 4; // Número total de animais
    // Criar array de pointers para Animals, metade Dog, metade Cat
    const Animal* animals[animalCount];

    // Preencher metade do array com Dog e a outra metade com Cat
    // Criar e preencher o array de animais
    for (int i = 0; i < animalCount; i++) 
    {
        if (i % 2 == 0) 
        {
            animals[i] = new Dog(); // Criar um Dog
        } 
        else 
        {
            animals[i] = new Cat(); // Criar um Cat
        }
    }

    std::cout << std::endl;
    std::cout << "*** Sons dos animais:" << std::endl;
    // Fazer os animais emitirem sons
    for (int i = 0; i < animalCount; i++) 
    {
        animals[i]->makeSound(); // Chamar o método makeSound de cada animal
    }
    
     // Limpar a memória ao array de animais alocada
    std::cout << std::endl;
    std::cout << "=== Limpar a memória alocada ===" << std::endl;
    for (int i = 0; i < animalCount; i++) 
    {
        delete animals[i]; // Deletar cada animal
    }
    
    std::cout << "=== Testar Polimorfismo 2 - ALOCANDO NA STACK ===" << std::endl;
    // Teste de shallow copy / deep copy (Construtor de cópia)
    // Ver mais info no ponto 1 do main.cpp do CPP04ex01
    std::cout << std::endl;
    std::cout << "=== Testando Shallow/Deep Copy (Construtor de Cópia) ===" << std::endl;
    
    // Testar cópia profunda com Dog
    std::cout << "\n*** Testing deep copy with Dog:" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->showIdeas();  // Mostrar ideias originais do Dog
    std::cout << std::endl;
    Dog copiedDog = originalDog; // Testar o construtor de cópia - Cria um novo objeto Dog e copia o original
    copiedDog.getBrain()->showIdeas();    // Mostrar ideias copiadas
    
    // Testar cópia profunda com Cat
    std::cout << "\n*** Testing deep copy with Cat:" << std::endl;
    Cat originalCat;
    originalCat.getBrain()->showIdeas();  // Mostrar ideias originais do Cat
    std::cout << std::endl;
    Cat copiedCat = originalCat;  // Cópia profunda
    copiedCat.getBrain()->showIdeas();    // Mostrar ideias copiadas
    
    // Teste de clonagem (Operador de Atribuição)
    std::cout << std::endl;
    std::cout << "=== Testar Clonagem (Operador de Atribuição) ===" << std::endl;
    std::cout << "\n*** Testing clone with Dog:" << std::endl;
    Dog cloneDog;
    std::cout << std::endl;
    cloneDog = originalDog; // Testar o operador de atribuição. Neste caso assignedDog foi criado como um objeto vazio. qd fazemos = o operador de atribuição é chamado e assignedDog passa a ser uma cópia de originalDog, mas NÃO cria um novo objeto Dog.
    std::cout << std::endl;
    originalDog.getBrain()->showIdeas();  // Mostrar ideias originais do Dog
    std::cout << std::endl;
    cloneDog.getBrain()->showIdeas();  // Mostrar ideias do Dog atribuído
    std::cout << std::endl;
    std::cout << "*** Sons do cão original e do cão atribuído:" << std::endl;
    originalDog.makeSound();  // Deve latir
    cloneDog.makeSound();  // Deve latir
    
    std::cout << std::endl;
    std::cout << "*** Testing deep copy with Cat:" << std::endl;
    Cat cloneCat;
    std::cout << std::endl;
    cloneCat = originalCat;  // Testar o operador de atribuição
    std::cout << std::endl;
    originalCat.getBrain()->showIdeas();  // Mostrar ideias originais do Cat
    std::cout << std::endl;
    cloneCat.getBrain()->showIdeas();  // Mostrar ideias do Cat atribuído
    std::cout << std::endl;
    std::cout << "*** Sons do gato original e do gato atribuído:" << std::endl;
    originalCat.makeSound();  // Deve miar
    cloneCat.makeSound();      // Deve miar

    std::cout << std::endl;
    // Terminar o programa sem vazamentos de memória
    std::cout << "=== Programa a terminar ===" << std::endl;
    std::cout << "*** Program finished. Checking for leaks..." << std::endl;

    return 0;
}
