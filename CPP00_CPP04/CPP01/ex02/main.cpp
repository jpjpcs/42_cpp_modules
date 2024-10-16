/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 00:21:31 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/20 00:33:42 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string s1 = "HI THIS IS BRAIN";
    std::string *stringPTR = &s1;
    std::string &stringREF = s1;

    std::cout << std:: endl << "Address of the string s1: " << &s1 << std::endl;
    std::cout << "Address of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of the stringREF: " << &stringREF << std::endl;
    std::cout << "The value of the string s1: " << s1 << std::endl;
    std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value of the stringREF: " << stringREF << std::endl << std::endl;

    return 0;
}

