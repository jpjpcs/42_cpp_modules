/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:22 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 13:50:00 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal 
{   
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &to_copy);
        WrongAnimal& operator=(const WrongAnimal &to_copy);
        virtual ~WrongAnimal(); // Destrutor virtual para permitir o polimorfismo adequado

        void makeSound() const;
        std::string getType() const;
        //void setType(std::string type);
        
    protected:
        std::string type;
};

#endif
