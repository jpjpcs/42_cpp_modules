/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:22 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:28:25 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal 
{
    public:
        WrongAnimal(); 
        WrongAnimal(const WrongAnimal &to_copy);
        WrongAnimal& operator=(const WrongAnimal &to_copy);
        virtual ~WrongAnimal(); // destrutor virtual

        void makeSound() const;
        std::string getType() const;
        //void setType(std::string type);
        
    protected:
        std::string type;
};

#endif
