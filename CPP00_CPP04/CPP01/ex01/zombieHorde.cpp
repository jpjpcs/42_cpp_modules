/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:56:40 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:58:17 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int i; // Variável para iterar sobre o array de Zombies.

Zombie *horde = new Zombie[N]; // Cria um array de N Zombies na heap. 
    // E porquê na heap?Porque se fosse na stack, o array seria destruído
    // quando a função terminasse. E como queremos que o array sobreviva
    // à função, ele deve ser alocado na heap. E pq queremos que ele sobreviva?
    // Porque o queremos usar na função main, que é a função principal do programa
    // e que só termina quando o programa termina. Portanto, o array de Zombies
    // deve sobreviver à função zombieHorde. E para isso, ele deve ser alocado na heap.
    // Caso contrário não poderíamos usá-lo na função main, uma vez que ele seria destruído
    // no âmbito da função zombieHorde. 
*/

/* 
outra opção:
Zombie	*zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N]; // Cria o array de N Zombies na heap.
    for (int i = 0; i < N; i++) {
        horde[i].setName(name); // Define o nome de cada Zombie.
    }
    return horde; // Retorna o ponteiro para o início do array.
} 
*/

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
    int i; // Variável para iterar sobre o array de Zombies.
    Zombie *horde = new Zombie[N]; 

    i = 0; 
    while (i < N) 
    {
        horde[i].setName(name); // Define o nome de cada Zombie.
        i++;
    }
    return horde; // Retorna o ponteiro para o início do array.
}




