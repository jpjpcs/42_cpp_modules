/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:27:18 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/16 16:27:54 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void printUppercase(const char* str) {
    while (*str) {
        std::cout << (char)std::toupper(*str);
        ++str;
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            printUppercase(argv[i]);
        }
        std::cout << std::endl;
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}
