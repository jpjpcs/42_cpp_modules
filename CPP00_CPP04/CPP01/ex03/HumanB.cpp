/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:43:58 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:57:41 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Formas de Inicialização

Lista de Inicialização:

Comparação entre HumanA e HumanB

HumanA: A forma que estou a usar em HumanA.cpp é:

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    return;
}
Aqui, a inicialização de _name é feita através da lista de inicialização, 
que é uma prática recomendada, especialmente para tipos que podem 
ter um custo de cópia (como std::string).

Neste caso, _name é inicializado diretamente com o valor de name, 
e _weapon é inicializado com a referência do objeto weapon.
O construtor de HumanA recebe o parâmetro name como std::string name, ou seja, por valor.
No entanto, ao usar a lista de inicialização do construtor, 
estou a inicializar o membro _name diretamente:


: _name(name), _weapon(weapon)
Isso significa que _name é inicializado diretamente com a cópia de name.

HumanB: A forma que estou a usar em HumanB.cpp é diferente, 
pois aqui não uso uma lista de inicialização:

HumanB::HumanB(std::string name) {
    this->_name = name; // Atribuição no corpo do construtor.
    this->_weapon = NULL; // Inicializa _weapon como NULL.
}
Aqui, o construtor também recebe name como std::string name (ou seja, passado por valor), 
e como você não está a usar a lista de inicialização, é necessário atribuir 
o valor a _name no corpo do construtor:

this->_name = name;
Se o parâmetro name fosse passado por referência constante (const std::string &name), 
você poderia inicializar _name diretamente na lista de inicialização, 
assim como em HumanA, e evitar uma cópia desnecessária.

Aqui também estou a passar name por valor:

HumanB(std::string name);
No entanto, no HumanB, a inicialização de _name é feita no corpo do construtor, 
resultando numa cópia adicional de name.

Atribuição no Corpo do Construtor:

Tal como estou a fazer em HumanB.cpp, também poderia fazer a 
inicialização de _name dentro do corpo do construtor em HumanA:

HumanA::HumanA(std::string name, Weapon &weapon) 
{
    this->_name = name; // Atribuição no corpo
    this->_weapon = weapon; // Atribuição no corpo
    return;
}
Neste caso, _name seria atribuído após a chamada do construtor, 
o que pode levar a uma cópia desnecessária da string name.

Passagem por Valor vs. Passagem por Referência:

Passagem por Valor: No caso do HumanA, estou a passar name 
como um std::string. Isso significa que o valor de name é copiado 
para o parâmetro local no construtor. Portanto, o que recebo 
dentro do construtor é uma cópia da string, 
e isso pode ser ineficiente para strings longas.

Exemplo:

HumanA::HumanA(std::string name, Weapon &weapon);
Passagem por Referência: Se eu passasse name como uma referência constante, 
como const std::string &name, isso significa que estaria a passar o endereço 
da string original, e não uma cópia. Isso é mais eficiente.

Exemplo:

HumanA::HumanA(const std::string &name, Weapon &weapon);
Diferença na Inicialização:

Quando passo um parâmetro por valor, ele é copiado para a variável local.
Quando passo um parâmetro por referência, estou a usar o mesmo objeto na memória.
Ao usar a lista de inicialização, estou a evitar cópias extras, 
uma vez que os membros são diretamente inicializados com os valores passados. 
Ao usar a atribuição dentro do corpo do construtor, posso estar a criar uma 
cópia desnecessária (se passar por valor).

Resumo:

A Lista de Inicialização é a forma preferida para inicializar membros, 
especialmente para tipos que podem ser caros de copiar (como std::string).
Passagem por Valor cria uma cópia, enquanto Passagem por Referência usa o objeto original.
Usar const std::string &name como parâmetro é mais eficiente em 
termos de desempenho e evita cópias desnecessárias.



Diferença Entre Passar por Valor e Passar por Referência Constante:

Passagem por Valor: Tanto em HumanA quanto em HumanB, name é passado por valor, 
o que significa que, em ambos os casos, uma cópia é feita.

Passagem por Referência Constante: Se alterasse a definição do construtor de HumanA e HumanB para:

HumanA(const std::string &name, Weapon &weapon);
HumanB(const std::string &name);
Nesse caso, name não seria copiado. Em vez disso, o construtor receberia uma referência à string original, 
evitando a cópia e tornando o código mais eficiente.

Resumo Final:

A diferença que mencionei sobre passar por referência constante é sobre a eficiência. 
Quando usa uma lista de inicialização com um parâmetro passado por referência constante, 
evita cópias adicionais, o que é vantajoso para desempenho.

Se name for passado como const std::string &name, pode inicializar _name diretamente na 
lista de inicialização em ambos os construtores, minimizando cópias desnecessárias. 
Portanto, ao usar uma referência constante, melhora o desempenho e a eficiência do código.
*/

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name; // porque é que estamos a definir o nome aqui e no HumamA não? Porque no HumanA estamos a passar o nome por referência, e aqui estamos a passar por valor. Logo, temos que definir o nome aqui, caso contrário, não teríamos acesso ao nome. 
    this->_weapon = NULL;
}

HumanB::~HumanB(void)
{
    return ;
}

void	HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " attacks with their bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
