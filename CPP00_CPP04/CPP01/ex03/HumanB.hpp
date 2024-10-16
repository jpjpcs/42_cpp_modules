/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:43:50 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/24 13:14:56 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void	attack(void);
        void	setWeapon(Weapon &weapon); // Aqui passamos como referência, pois o objeto não pode ser nulo. E é só um, não há cópias - Por isso tb n faria sentido passar por valor.

    private:
        std::string	_name;
        Weapon		*_weapon; // Aqui passamos como ponteiro e não como referência, pois o objeto pode ser nulo.
};

#endif
