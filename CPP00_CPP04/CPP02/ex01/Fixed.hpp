/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:42 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 02:06:53 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ex01: 
A par do resto já abordado no ex00, no ex01 também é abordado:
1. Construtores Parametrizados (int e float)  
2. Operador Inserção sobrecarregado (<<)
3. Conversões de int para fixed point e vice-versa, e conversões de float para 
    fixed point e vice-versa. 
Diferenças do ex00 para o ex01:
4 - No Operador de atribuição, estou a copiar o valor diretamente sem usar um getter.
    Logo, o getter não tem qualquer função no meu programa, uma vez que não é 
    chamado nem no main nem no operador de atribuição.
    As vantagens e desvantagens desta abordagem (direta vs indireta usando um getter) 
    são abordadas no ponto 12 dos comments do Fixed.cpp.
    - O operador de atribuição é usado para copiar o valor de um objeto para outro.
    - Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 7 do Fixed.cpp do CPP02ex01.
* 1. Eles são chamados assim porque aceitam parâmetros (neste caso, um inteiro 
    e um float) que são usados para inicializar um objeto da classe Fixed. 
* 2. O operador de inserção sobrecarregado é usado para exibir o valor de um objeto 
    da classe Fixed. Ele é sobrecarregado para aceitar um objeto Fixed como argumento 
    e exibir o valor armazenado no formato de ponto fixo.

Pontos do word abordados:
    Módulo 2 - 19.11.31.1.1. Tipos ---> Parametrizado
    Módulo 2 - 19.11.29.2.	Operadores
    Módulo 2 - 19.11.31.2.2. Operador de Inserção
    Módulo 2 - 19.11.34. Fixed vs Floating Points Numbers / Aritmética ponto fixo vs flutuante?
*/

/*
Exercice 01: Fixed Point Number
Objective: Create a class that represents a fixed-point number.
Key Features:
Parametrized constructors (int and float).
Overloaded insertion operator (<<).
Conversion from int to fixed point and vice versa, and from float to fixed point and vice versa.
---------------------------------------------
Explicação Global:
Este exercício do Módulo 02 do CPP foca-se na criação de uma classe que
representa um número de ponto fixo (fixed-point number), utilizando a
forma canónica ortodoxa de C++. 
Neste exercício usamos construtores parametrizados para inicializar um 
objeto da classe Fixed com um inteiro ou um float. Usamos conversões e 
operadores de inserção.
*/

/*
Explicação Main Points (mais info no Fixed.cpp do CPP02ex01):
1 - Construtores Parametrizados: Inicializam um objeto da classe Fixed com um inteiro ou um float.
    Eles são chamados assim porque aceitam parâmetros (neste caso, um inteiro 
    e um float) que são usados para inicializar um objeto da classe Fixed.    
    1.1. - Fixed(int const value); // Construtor parametrizado a partir de um inteiro:
    cria um novo objeto com base em um valor inteiro passado como argumento.
    1.2. - Fixed(float const value); // Construtor parametrizado a partir de um float:
    cria um novo objeto com base em um valor float passado como argumento.
2 - Operador de Inserção Sobrecarregado (<<): É usado para exibir o valor de um objeto da classe Fixed.
    O operador de inserção sobrecarregado é usado para exibir o valor de um objeto 
    da classe Fixed. Ele é sobrecarregado para aceitar um objeto Fixed como argumento 
    e exibir o valor armazenado no formato de ponto fixo.
3 - Conversões de int para fixed point e vice-versa, e conversões de float para fixed point e vice-versa.
    3.1. - int to fixed point: Converte um número inteiro para um valor de ponto fixo.
    3.2. - fixed point to int: Converte um valor de ponto fixo de volta para um número inteiro.
    3.3. - float to fixed point: Converte um número float para um valor de ponto fixo.
    3.4. - fixed point to float: Converte um valor de ponto fixo de volta para um número float.
    3.5. - BITWISE << e >>:
        3.5.1. - <<: Deslocamento de Bits para a Esquerda.
        3.5.2. - >>: Deslocamento de Bits para a Direita.
        Resumo:
        int to fixed point: _fixedPointValue = value << _fractionalBits; // Desloca os bits para a esquerda.
        fixed point to int: return (_fixedPointValue >> _fractionalBits); // Desloca os bits para a direita.
        float to fixed point: _fixedPointValue = roundf(value * (1 << _fractionalBits)); // Desloca os bits para a esquerda.
        fixed point to float: return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits)); // Desloca os bits para a direita. 
*/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    // Construtores e destrutor
    public:
        Fixed(); // Construtor padrão
        Fixed(int const value); // Construtor parametrizado a partir de um inteiro
        Fixed(float const value); // Construtor parametrizado a partir de um float
        Fixed(Fixed const &copy); // Construtor de cópia
        ~Fixed(); // Destrutor

        // Operador Atribuição de cópia com Sobrecarga do operador de atribuição
        Fixed &operator=(Fixed const &copy);

        // Funções Membro de Conversão
        float toFloat(void) const; // Converte o valor para float
        int toInt(void) const; // Converte o valor para inteiro
    
        // Getters and setters para acesso ao valor bruto do número de ponto fixo
        // Const no final da função getRawBIts significa que a função não pode modificar 
        // nenhum dos membros da classe (atributos ou métodos), não alterando o estado do objeto no qual é chamada. 
        int getRawBits(void) const;
        void setRawBits(int const raw);
    
    // Variables
    private:
        int _fixedPointValue; // Armazena o valor do ponto fixo. Corresponde à parte inteira do valor do ponto fixo.
        static const int _fractionalBits = 8; // Número de bits fracionários (sempre 8) correspondentes à parte fracionária do valor do ponto fixo
};

// Sobrecarga do operador de inserção para `ostream`. Está fora da classe. Mais info nos pontos 7 dos comments do Fixed.cpp CPP02ex01 e no word Módulo 2 - 19.11.31.2.2. Operador de Inserção.
std::ostream &operator<<(std::ostream &out, Fixed const &copy);

#endif
