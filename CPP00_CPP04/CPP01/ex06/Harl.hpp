/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:07:10 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:56:09 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise 06: Harl's Complaining

Objective: Create a class Harl that outputs different levels of complaints based on the input level.

Create a class Harl with the following member functions:
•	complain: Takes a string level as input and outputs different levels of complaints based on the input level.
•	debug: Outputs a debug message.
•	info: Outputs an info message.
•	warning: Outputs a warning message.
•	error: Outputs an error message.

The complain function should call the appropriate message function based on the input level.

The harlFilter function should call the complain function, passing the level provided by the user.

The complain function should output different messages based on the input level:
•	DEBUG: Calls the debug function.
•	INFO: Calls the info function.
•	WARNING: Calls the warning function.
•	ERROR: Calls the error function.

If the level is invalid, the complain function should output the message "[ Probably complaining about insignificant problems ]".

The usage function should output the message "Usage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]".

The main function should call the harlFilter function, passing the level provided by the user.
The main function should check if exactly one argument is passed besides the program name. If not, it should call the usage function and return with error code 1. If the argument is correct, it should call the harlFilter function, passing the level provided as an argument.



ex05 - uso de pointers to member functions.
ex06 - uso de switch case.
Diferença principal entre ex05 e ex06: switch case.
*/

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    public:
        Harl(void);
        ~Harl(void);
        void complain( std::string level);

    private: 
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif
