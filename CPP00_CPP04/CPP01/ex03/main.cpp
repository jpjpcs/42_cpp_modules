/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:43:41 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:57:24 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
int main()
{
    Weapon club = Weapon("crude spiked club");
    
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    
    Weapon club2 = Weapon("crude spiked club");
    HumanB jim("Jim", club2);
    jim.attack();
    club2.setType("some other type of club");
    jim.attack();
    return (0);
} 
*/

/* 
Qual a diferença entre utilizar o main acima e o main que está comentado?
R: A diferença está no uso das {} para criar um escopo. 
No main que está a ser executado, club está em escopos diferentes. 
Logo é como se fossem 2 objetos diferentes. Já no main comentado, 
club estaria no mesmo escopo, logo é necessário criar 
um novo objeto club2 para que o objeto club não seja alterado.
Qual dele está correto? E porquê?
R: Ambos estão corretos. O que está a ser executado é mais eficiente, 
pois não é necessário criar um novo objeto club2. No entanto, ambos estão corretos.
*/

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int		main(void)
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim("Jim");

		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
