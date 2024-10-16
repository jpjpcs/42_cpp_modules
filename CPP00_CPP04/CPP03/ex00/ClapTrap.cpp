/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:08:58 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/15 13:51:50 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default Constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Parametrized Constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
    *this = copy;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
    std::cout << "ClapTrap Assignation Operator called" << std::endl;
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_hitPoints = copy._hitPoints;
        this->_energyPoints = copy._energyPoints;
        this->_attackDamage = copy._attackDamage;
    }
    return *this;
}

// Método attack: Ataca um alvo, se houver energia e vida suficientes
void ClapTrap::attack(std::string const &target)
{
    if (_hitPoints > 0  && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        _energyPoints--; // Energy points are reduced by 1 after each attack
    }
    else 
    {
        std::cout << "ClapTrap " << this->_name << " can't attack " << target << " because it has no health or energy points!" << std::endl;
    }
    return;
}

// Método takeDamage: Reduz os pontos de vida com base no dano recebido
void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount; // Reduz HP pelo valor do dano
    
    if (this->_hitPoints < 0)
        this->_hitPoints = 0; // Garante que não temos valores negativos
    
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage, remaining HP: " << this->_hitPoints << std::endl;
    return;
}

// Método beRepaired: Repara o ClapTrap, se tiver energia e vida
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        this->_hitPoints += amount;
        std::cout << "ClapTrap " << this->_name << " is repaired by " << amount << " points, remaining HP: " << this->_hitPoints << std::endl;
        _energyPoints--; // Energy points are reduced by 1 after each repair
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " can't be repaired because it has no health or energy points!" << std::endl;
    }
    return;
}

// Getters

std::string ClapTrap::getName(void) const
{
    return this->_name;
}

int ClapTrap::getHitPoints(void) const
{
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->_attackDamage;
}

// Sobrecarga do operador <<
std::ostream &operator<<(std::ostream &os, const ClapTrap &clapTrap)
{
    os << "ClapTrap " << clapTrap.getName() << " has " << clapTrap.getHitPoints() << " HP, " << clapTrap.getEnergyPoints() << " energy points and " << clapTrap.getAttackDamage() << " attack damage." << std::endl;
    return os;
}
