/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:42 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/15 12:52:11 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ex03: 
A par do resto já abordado no ex00 e ex01 e ex02, neste ex03 é também abordado:
1 - Fórmula de Shoelace (ou Gauss) para calcular a área de um triângulo.
2 - A fórmula determinante 2D para calcular a área de um triângulo é:
Área = | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) | / 2
3 - Neste exercício teremos que verificar se o ponto está dentro do triângulo ou não.
Como? 
3.1. - Primeiro calculando a área do triângulo formado pelos três vértices originais A, B e C (o triângulo original).
3.2. - Depois calculando a área do triângulo formado pelos vértices A, B e o ponto a ser testado P.
3.3. - Depois calculando a área do triângulo formado pelos vértices B, C e P.
3.4. - Depois calculando a área do triângulo formado pelos vértices C, A e P.
3.5. - Por fim, verificando se a soma das áreas dos três pequenos triângulos (ABP, BCP e CAP) 
é igual à área do triângulo original (ABC).
3.6. - Se a soma das áreas dos três triângulos menores for igual à área do triângulo original, 
o ponto P estará dentro do triângulo.
3.7. - Se a soma das áreas for maior ou menor do que a área do triângulo original 
(dependendo de onde P está no plano), o ponto P estará fora do triângulo.
*/

/*
Pontos do word abordados:
    Os já abordados até agora. Neste exercício não abordamos pontos novos.
*/

/*
Exercice 03: Point Inside Triangle
Objective: Create a function that checks if a point is inside a triangle.
Key Features:
Shoelace formula to calculate the area of a triangle.
Determinant 2D formula to calculate the area of a triangle.
Check if a point is inside a triangle.
---------------------------------------------
Explicação Global: 
Este exercício do Módulo 02 do CPP foca-se na criação de uma 
função que verifica se um ponto está dentro de um triângulo, 
utilizando a fórmula de Shoelace (ou Gauss) para calcular a 
área de um triângulo e a fórmula determinante 2D 
para calcular a área de um triângulo.
*/

#ifndef FIXED_HPP
 #define FIXED_HPP

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
