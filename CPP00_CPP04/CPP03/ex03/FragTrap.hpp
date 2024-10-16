/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:41:10 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 12:32:43 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public virtual ClapTrap
{
    public:
        // Construtores
        FragTrap(void);                            // Construtor padrão
        FragTrap(std::string name);                // Construtor parametrizado
        FragTrap(const FragTrap &copy);            // Construtor de cópia
        ~FragTrap(void);                           // Destrutor

        FragTrap &operator=(const FragTrap &copy); // Operador de atribuição

        void highFivesGuys(void);                  // Função especial de FragTrap
};

#endif
