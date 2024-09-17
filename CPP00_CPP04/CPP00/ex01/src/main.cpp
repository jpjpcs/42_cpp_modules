/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:26:27 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/16 17:11:30 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) 
{
    PhoneBook pb;
    std::string input;

    while (true) 
    {
        std::cout << "Phonebook > ";
        std::getline(std::cin, input); // Get the input from the user. It takes 2 arguments: the first is the stream to get the input from, and the second is the string where the input will be stored.

        if (input.empty())
        {
            std::cout << "Please enter a command: ADD, SEARCH, or EXIT." << std::endl;
            std::cout << "Empty inputs will not do anything." << std::endl;
            continue;
        }
        if (input == "ADD")
            pb.add();
        else if (input == "SEARCH")
            pb.search();
        else if (input == "EXIT")
            break;
        else
		{
			std::cout << "Command not Valid." << std::endl;
            std::cout << "Please enter a valid command: ADD, SEARCH, or EXIT." << std::endl;
            std::cout << "Otherwise, the program will continue to request a valid command." << std::endl;
			continue ;
		}
    }
    return 0;
}
