/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:39:20 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/17 20:15:48 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Construtor padrão
Zombie::Zombie(void)
{
    return ;
}

// Construtor parametrizado
Zombie::Zombie(std::string name)
{
    this->_name = name;
}

// Destrutor
Zombie::~Zombie()
{
    std::cout << this->_name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}





