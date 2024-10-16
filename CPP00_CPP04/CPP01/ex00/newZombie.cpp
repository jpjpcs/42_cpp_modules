/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:49:18 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/24 18:06:54 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Retorna um ponteiro para um novo Zombie com o nome passado como parâmetro
// Returns a new heap allocated Zombie object with the name passed as parameter

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    return (new Zombie(name)); // Usando o construtor parametrizado cria um Zombie na heap com o nome passado como parâmetro
}
