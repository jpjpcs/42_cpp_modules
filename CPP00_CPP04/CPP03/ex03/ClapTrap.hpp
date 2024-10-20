/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:08:49 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 18:04:46 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exercise 01: ScavTrap
ver mais info em ScavTrap.hpp do CPP03ex01 para mais detalhes.
*/

/* 
Pontos do Word Abordados:
ver mais info em ScavTrap.hpp do CPP03ex01 para mais detalhes.
*/

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &copy);
        ~ClapTrap(void);
        
        // Atribution Operator Overload
        ClapTrap &operator=(const ClapTrap &copy);
        
        // Sobrecarga do operador <<
	    friend std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap); // Declarado como friend para poder aceder aos atributos privados da classe. Ver mais info no ponto 2 dos comments do ClapTrap.hpp do CPP03ex00.

        // Member functions
        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
     
        // GETTERS
        std::string getName(void) const;
        int getHitPoints(void) const;
        int getEnergyPoints(void) const; // ver mais info no ponto 1 dos comments do ClapTrap.hpp do CPP03ex00.
        int getAttackDamage(void) const;
        
        // Virtual getter function
        // virtual std::string getClassType() const; // Não pode ser usada. 
        //Ver mais info no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01, assim como no ponto 5 do main.cpp do CPP03ex01, 
        // e no word nos:
        //        Módulo 0 - 19.11.9.1.7.	Virtual e no 
        //        Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / Função Virtual & Função membro Virtual (módulo 4).

        // Setters - not used cause we are not changing the values of the attributes

    protected: // IMPORTANTE: Ver mais info no ponto 1 dos comments do ScavTrap.cpp do CPP03ex01.
        std::string _name; // Nome do ClapTrap
        int _hitPoints; // Pontos de vida (HP)
        int _energyPoints; // Pontos de energia (para realizar ações)
        int _attackDamage; // Dano de ataque
};
// Podia ter declarado a função std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap); aqui fora da classe. Seria outra abordagem. Ver mais info no ponto 2 dos comments do ClapTrap.hpp do CPP03ex00.
#endif
