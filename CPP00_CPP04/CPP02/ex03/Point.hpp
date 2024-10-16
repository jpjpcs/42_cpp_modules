/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:02:07 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/14 22:53:32 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
    public:
        Point(void);
        Point(float const x, float const y);
        Point(Point const &copy);
        ~Point(void);

        Point &operator=(Point const &copy);
        
        // GETTERS & SETTERS
        // Member functions to get the coordinates of the point
        Fixed getX(void) const;
        Fixed getY(void) const;
        // Member functions to define the coordinates of the point
        //void setX(float const x); not used. 
        //void setY(float const y); not used. 
        // setters não fazem sentido, já que não podemos alterar os valores após a inicialização.
        
    // Variables to store the coordinates of the point
    private:
        Fixed const _x;
        Fixed const _y;
};

// Sobrecarga do operador de inserção para `ostream`. Está fora da classe. Mais info nos pontos 7 dos comments do Fixed.cpp CPP02ex01 e no word Módulo 2 - 19.11.31.2.2. Operador de Inserção.
// std::ostream &operator<<(std::ostream &out, Point const &point);

// Função para verificar se um ponto está dentro de um triângulo ou não (usando a regra de Barycentric Coordinates). Está fora da classe. Mais info no ponto 7 dos comments do Fixed.cpp CPP02ex01.
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
