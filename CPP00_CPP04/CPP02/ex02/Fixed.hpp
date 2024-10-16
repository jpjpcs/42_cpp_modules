/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:42 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/11 18:15:18 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ex02: 
A par do resto já abordado no ex00 e ex01, no ex02 também é abordado:
1. Operadores aritméticos (+, -, *, /).
2. Operadores de comparação (>, <, >=, <=, ==, !=).
3. Operadores de incremento e decremento (++, --).
4. Funções membro Min e Max.
Diferenças que mantive (vieram do ex00 para o ex01, e do ex01 para o ex02:
5 - No Operador de atribuição, estou a copiar o valor diretamente sem usar um getter.
    Logo, o getter não tem qualquer função no meu programa, uma vez que não é 
    chamado nem no main nem no operador de atribuição.
    As vantagens e desvantagens desta abordagem (direta vs indireta usando um getter) 
    são abordadas no ponto 12 dos comments do Fixed.cpp.
Outras diferenças:
6 - No ex02, são sobrecarregados operadores aritméticos e de comparação, bem como
    operadores de incremento e decremento.

Pontos do word abordados:
    Módulo 2 - 19.11.29.2.	Operadores
    Módulo 2 - 19.11.29.2.3.	Operadores aritméticos (+, -, , /)
    Módulo 2 - 19.11.29.2.4.	Operadores de comparação (>, <, >=, <=, ==, !=)
    Módulo 2 - 19.11.29.2.5.	Operadores de incremento e decremento (++, --)
    Módulo 2 - 19.11.30.	Funções membro min e max
*/

/*
Exercice 02: Fixed Point Number
Objective: Create a class that represents a fixed-point number.
Key Features:
Parametrized constructors (int and float).
Overloaded insertion operator (<<).
Conversion from int to fixed point and vice versa, and from float to fixed point and vice versa.
Arithmetic operators (+, -, *, /).
Comparison operators (>, <, >=, <=, ==, !=).
Increment and decrement operators (++, --).
Min and Max member functions.
---------------------------------------------
Explicação Global:
Este exercício do Módulo 02 do CPP foca-se na criação de uma classe que
representa um número de ponto fixo (fixed-point number), utilizando a
forma canónica ortodoxa de C++.
Neste exercício usamos construtores parametrizados para inicializar um
objeto da classe Fixed com um inteiro ou um float. Usamos conversões e
operadores de inserção. Além disso, sobrecarregamos operadores aritméticos
e de comparação, e implementamos operadores de incremento e decremento.
*/

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        // Constructors and Destructor
        Fixed(); // Construtor padrão
        Fixed(int const value); // Construtor parametrizado a partir de um inteiro
        Fixed(float const value); // Construtor parametrizado a partir de um float
        Fixed(Fixed const &copy); // Construtor de cópia
        ~Fixed(); // Destrutor

        // Overload arithmetic operators
        Fixed &operator=(Fixed const &copy);   // Operador Atribuição de cópia com Sobrecarga do operador de atribuição
        Fixed operator+(Fixed const &copy) const;
		Fixed operator-(Fixed const &copy) const;
		Fixed operator*(Fixed const &copy) const;
		Fixed operator/(Fixed const &copy) const;
        
        // Overload comparison operators
		bool operator>(Fixed const &copy) const;
		bool operator>=(Fixed const &copy) const;
		bool operator<(Fixed const &copy) const;
		bool operator<=(Fixed const &copy) const;
		bool operator==(Fixed const &copy) const;
		bool operator!=(Fixed const &copy) const;
		
		// Overload increment and decrement operators
		Fixed operator++(void);
		Fixed operator--(void);
		Fixed operator++(int a);
		Fixed operator--(int a);
        
        // Min and Max member functions
		static Fixed &min(Fixed &a, Fixed &b); // ou & antes do Fixed - Fixed& Fixed::min(Fixed& a, Fixed& b) são equivalentes. Ver mais info no ponto 1, 2, e 3 dos comments do Fixed.cpp CPP02ex02.
		static Fixed &max(Fixed &a, Fixed &b);
		static Fixed const &min(Fixed const &a, Fixed const &b);
		static Fixed const &max(Fixed const &a, Fixed const &b);
        
        // Convert member functions
        float toFloat(void) const; // Converte o valor para float
        int toInt(void) const; // Converte o valor para inteiro
        
        // Getters and Setters member functions
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
