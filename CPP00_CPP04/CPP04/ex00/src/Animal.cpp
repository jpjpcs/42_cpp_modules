/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:04:48 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 18:08:55 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1 - Resumo das Questões sobre Construtor de Cópia

    1.1. - Comparação de Implementações:
        Versão 1:
        Animal::Animal(const Animal &to_copy) : type(to_copy.type) 
        {
            std::cout << "Animal copy constructor called." << std::endl;
        }
        Versão 2:

        Animal::Animal(const Animal &to_copy) 
        {
            std::cout << "Animal copy constructor called." << std::endl;
            *this = to_copy;
        }
    Ambas as versões implementam um construtor de cópia, mas a versão 1 
    utiliza uma lista de inicialização para copiar o atributo type, 
    enquanto a versão 2 utiliza o operador de atribuição.

    1.2. - Boas Práticas:
        . Eficiência: A versão 1 é mais eficiente porque evita a 
        criação de um objeto temporário, que pode ocorrer na versão 2 
        durante a execução do operador de atribuição.
        . Consistência de Estado: A inicialização direta na versão 1 
        garante que o objeto esteja sempre em um estado válido, 
        evitando problemas que podem surgir durante a execução do 
        operador de atribuição (como vazamentos de memória ou estados inconsistentes).
        . Preferência por Inicialização Direta: Em C++, é preferível 
        inicializar membros diretamente na lista de inicialização do construtor, 
        pois isso resulta em um código mais claro e eficiente.
    1.3. - Conclusão
    Em resumo, a versão 1 é a abordagem recomendada para a implementação de construtores 
    de cópia em C++. Ela não só melhora a eficiência do código, mas também garante que o 
    objeto esteja em um estado válido durante toda a sua construção. A prática de usar 
    listas de inicialização é uma boa prática que deve ser adotada sempre que possível em C++.
*/
#include "Animal.hpp"

// Construtor parametrizado? Não. Construtor padrão. Não recebe argumentos. Inicializa o tipo como "Animal". 
Animal::Animal() : type("Animal") 
{
    std::cout << "Animal default constructor called." << std::endl;
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00 e ponto 1 do Brain.cpp do CPP04ex01
Animal::Animal(const Animal& to_copy) : type(to_copy.type) 
{
    std::cout << "Animal copy constructor called." << std::endl;
}

// Operador de atribuição
Animal& Animal::operator=(const Animal& to_copy) 
{
    if (this != &to_copy) 
    {
        this->type = to_copy.type; // nao chamo getType. Faço cópias direta de to_copy para a string type.
    }
    std::cout << "Animal assignment operator called." << std::endl;
    return *this;
}

// Destrutor
Animal::~Animal() 
{
    std::cout << "Animal destructor called." << std::endl;
}

// Função virtual que será sobrescrita
void Animal::makeSound() const 
{
    std::cout << "Animal: generic sound." << std::endl;
}

// Getter para o tipo
std::string Animal::getType() const 
{
    return this->type;
}

/*
void Animal::setType(std::string type) 
{
    this->type = type;
}*/
