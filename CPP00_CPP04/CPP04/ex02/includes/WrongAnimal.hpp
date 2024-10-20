/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:22 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 11:25:14 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal 
{
    public:
        WrongAnimal(); 
        WrongAnimal(const WrongAnimal &to_copy);
        WrongAnimal& operator=(const WrongAnimal &to_copy);
        virtual ~WrongAnimal(); // destrutor virtual

        std::string getType() const;
        void makeSound() const;
        
    protected:
        std::string type;
};

#endif

