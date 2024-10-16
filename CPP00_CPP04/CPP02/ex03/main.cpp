/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:03:17 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/14 22:54:11 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

int main() 
{
    // Definindo os vértices do triângulo
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // Definindo um ponto a ser testado
    Point testPoint(11, 3);

    // Verifica se o ponto está dentro do triângulo
    if (bsp(a, b, c, testPoint)) 
    {
        std::cout << "O ponto está dentro do triângulo." << std::endl;
    } 
    else 
    {
        std::cout << "O ponto está fora do triângulo." << std::endl;
    }

    return 0;
}
