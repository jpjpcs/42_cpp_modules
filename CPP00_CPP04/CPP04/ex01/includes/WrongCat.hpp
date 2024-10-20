/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:06:32 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/18 12:51:09 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
    public:
        WrongCat();
        WrongCat(const WrongCat& to_copy);
        WrongCat& operator=(const WrongCat& to_copy);
        virtual ~WrongCat(); // Destrutor virtual para permitir o polimorfismo adequado

        void makeSound() const;
};

#endif
