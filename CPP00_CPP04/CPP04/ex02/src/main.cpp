/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:05:34 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:28:07 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
tanto a classe Brain quanto as classes WrongAnimal e WrongCat devem ter destrutores virtuais, ou pelo menos o destrutor da classe base (WrongAnimal) deve ser virtual. Vamos ver o porquê em dois contextos diferentes:

1. Por que o destrutor da classe base (WrongAnimal) deve ser virtual?
Quando uma classe é usada para herança, o destrutor da classe base deve ser virtual para garantir que, quando objetos derivados forem destruídos através de um ponteiro para a classe base, o destrutor correto (da classe derivada) seja chamado.

Exemplo sem destrutor virtual:
cpp
Copiar código
WrongAnimal* animal = new WrongCat();
delete animal;  // Apenas o destrutor de WrongAnimal é chamado, não o de WrongCat
Se o destrutor de WrongAnimal não for virtual, o comportamento acima causará vazamento de memória (memory leak), porque o destrutor de WrongCat não será invocado. Somente o destrutor de WrongAnimal seria chamado, deixando qualquer recurso alocado pela classe derivada (WrongCat) sem ser liberado.

Exemplo com destrutor virtual:
cpp
Copiar código
WrongAnimal* animal = new WrongCat();
delete animal;  // Agora o destrutor de WrongCat é chamado, seguido pelo de WrongAnimal
Neste caso, o destrutor virtual garante que o destrutor de WrongCat será chamado primeiro, e depois o destrutor de WrongAnimal. Isso garante a limpeza adequada dos recursos.

2. Por que o Brain também pode ter um destrutor virtual?
A classe Brain em si não foi projetada para ser uma classe base, mas se houver a possibilidade de ela ser usada como base para outras classes no futuro, o destrutor deveria ser virtual. Isso protege o código contra possíveis problemas com herança no futuro.

Mesmo que a classe não tenha a intenção de ser herdada, adicionar um destrutor virtual não prejudica o desempenho em grande parte dos casos. No entanto, se houver certeza de que Brain nunca será usada como base, o destrutor não precisa ser virtual.

Resumo:
WrongAnimal: Deve ter um destrutor virtual porque é uma classe base para WrongCat (ou qualquer outra subclasse).
Brain: Ter um destrutor virtual não é obrigatório, a menos que seja planejado que Brain seja usada como classe base. Mas como prática defensiva, poderia ser uma boa ideia fazer o destrutor virtual.
*/
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
