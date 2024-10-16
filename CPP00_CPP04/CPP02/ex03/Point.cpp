/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:02:57 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/14 22:52:58 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Construtor Padrão
Point::Point(void) : _x(0), _y(0)
{
    return;
}

// Construtor Parametrizado
Point::Point(float const x, float const y) : _x(x), _y(y)
{
    return;
}

// Construtor de Cópia
Point::Point(Point const &copy) : _x(copy._x), _y(copy._y)
{
    return;
}

// Destrutor
Point::~Point(void)
{
    return;
}

// Operador de Atribuição de Cópia
Point &Point::operator=(Point const &copy)
{
    if (this != &copy)
    {
        (Fixed) this->_x = copy._x;
        (Fixed) this->_y = copy._y;
    }
    return *this;
}
// GETTERS & SETTERS
// Member functions to get the coordinates of the point
Fixed Point::getX(void) const
{
    return this->_x;
}

Fixed Point::getY(void) const
{
    return this->_y;
}

// Member functions to define the coordinates of the point

/* void Point::setX(float const x)
{
    this->_x = x;
}

void Point::setY(float const y)
{
    this->_y = y;
} */
