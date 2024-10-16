/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:51:50 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/24 18:07:05 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cria um Zombie com o nome passado como parâmetro e o faz anunciar seu nome
// Creates a Zombie with the name passed as parameter and makes it announce its name
// Creates a temporary object that is destroyed after the function
// has terminated

/*
A razão pela qual você vê a mensagem de destruição do zumbi duas vezes quando 
usa Zombie zombie; zombie = Zombie(name); em vez de 
Zombie zombie = Zombie(name); está relacionada à forma como os objetos 
são criados e destruídos em C++.

Explicação:
Declaração e Inicialização Direta:

Aqui, o objeto zombie é criado e inicializado diretamente 
com o construtor que aceita um parâmetro name.
Apenas um objeto Zombie é criado e destruído.
Declaração e Atribuição Separada:

Primeiro, um objeto zombie é criado usando o 
construtor padrão (sem parâmetros).
Em seguida, um novo objeto temporário Zombie(name) é criado.
O operador de atribuição é chamado para copiar o estado 
do objeto temporário para o objeto zombie.
Após a atribuição, o objeto temporário é destruído.
No final do escopo, o objeto zombie é destruído.
Resumo:
Zombie zombie = Zombie(name);: Cria e inicializa um único objeto Zombie.
Zombie zombie; zombie = Zombie(name);: Cria um objeto Zombie padrão, 
cria um segundo objeto temporário Zombie(name), 
copia o estado do temporário para o primeiro objeto, 
e então destrói o temporário. No final do escopo, 
o primeiro objeto é destruído.
Portanto, a destruição do objeto temporário adicional 
é a razão pela qual você vê a mensagem de destruição duas vezes.
*/

#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie = Zombie(name); // Usando o construtor parametrizado cria um Zombie com o nome passado como parâmetro
    zombie.announce(); // Anuncia o nome do Zombie
}
