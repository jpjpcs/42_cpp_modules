/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:27:18 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 16:21:55 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Ex00 – stdiostreams (stdout, stdendl), const char, namespace e directiva using 
probibidos

Ex01 – classes, public vs private visibility, função membro / member function, 
atributo membro /member attribute, constructor padrão, construtor parametrizado, 
destrutor, lista de inicialização / initialization list, static const int max 
contacts

Ex02 – constructor parametrizado novamente, stdiostreams (stdin), get line vs 
std::cin, this->pointer (Mais info no ponto 4 do ficheiro Account.cpp CPP00ex02 e 
no ponto 1, 2 e 4 dos comments do ScavTrap.cpp do CPP03ex01.

Ex03 – std:setfill, static functions static int
*/

#include <iostream>
#include <cctype>

void printUppercase(const char* str) 
{
    while (*str) 
    {
        std::cout << (char)std::toupper(*str);
        ++str;
    }
}

int main(int argc, char **argv) 
{
    if (argc > 1) 
    {
        for (int i = 1; i < argc; ++i) 
        {
            printUppercase(argv[i]);
        }
        std::cout << std::endl;
    } 
    else 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}
