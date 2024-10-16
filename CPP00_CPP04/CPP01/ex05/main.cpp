/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:07:24 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/25 13:52:33 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    return (0);
}
*/

#include "Harl.hpp"

void usage(void)
{
    std::cout << "Usage: ./harl [DEBUG|INFO|WARNING|ERROR]\n" << std::endl;
}

int main(int argc, char **argv)
{
    Harl harl;
    std::string level;
    
    if (argc != 2)
    {
        usage();
        return (1);
    }
    
    level = argv[1];
    harl.complain(level);
    return (0);
}



