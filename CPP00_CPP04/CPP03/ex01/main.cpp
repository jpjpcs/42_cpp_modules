/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:08:12 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 15:19:46 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Explicação detalhada da saída do Main:
1. Criação dos objetos ScavTrap e ClapTrap
    Quatro instâncias de ScavTrap são criadas no início do programa:
     - scav1 com o construtor por omissão,
     - scav2("Manel") com o construtor parametrizado,
     - scav3("Roberto") com o construtor parametrizado,
     - scav4("Mariana") com o construtor parametrizado.
    Saída: 
                ClapTrap Default Constructor called
                ScavTrap Default Constructor called
                ClapTrap Parametrized Constructor called
                ScavTrap Parametrized Constructor called
                ClapTrap Parametrized Constructor called
                ScavTrap Parametrized Constructor called
                ClapTrap Parametrized Constructor called
                ScavTrap Parametrized Constructor called
2. Ataques e interações entre ScavTrap
    - A função de ataque é chamada para Roberto, Mariana e Manel, e o método attack de ScavTrap mostra as mensagens de ataque.
	- O método takeDamage é chamado para subtrair o HP dos ClapTraps atacados.
	- O método beRepaired repara os ClapTraps afetados, restaurando HP.
    Saída:
        aparecia:
                            -------- Testing Roberto vs Afonso --------
                ScavTrap Roberto attacks Afonso, causing 20 points of damage!
                ClapTrap Roberto takes 20 points of damage, remaining HP: 80
                ClapTrap Roberto is repaired by 15 points, remaining HP: 95

                -------- Testing Roberto ataca Mariana --------
                ScavTrap Roberto attacks Mariana, causing 20 points of damage!
                ClapTrap Mariana takes 25 points of damage, remaining HP: 75
                ClapTrap Roberto is repaired by 10 points, remaining HP: 105

                -------- Testing Mariana ataca Roberto --------
                ScavTrap Mariana attacks Roberto, causing 20 points of damage!
                ClapTrap Roberto takes 10 points of damage, remaining HP: 95
                ClapTrap Mariana is repaired by 5 points, remaining HP: 80

                -------- Testing Manel ataca Roberto --------
                ScavTrap Manel attacks Roberto, causing 20 points of damage!
                ClapTrap Roberto takes 10 points of damage, remaining HP: 85
                ClapTrap Manel is repaired by 5 points, remaining HP: 105
         depois da implementação das funções takeDamage e beRepaired, quer no ScavTrap.cpp, 
         quer no ScavTrap.hpp,
         aparece: 
                -------- Testing Roberto vs Afonso --------
                ScavTrap Roberto attacks Afonso, causing 20 points of damage!
                ScavTrap Roberto takes 20 points of damage! remaining HP: 100
                ClapTrap Roberto takes 20 points of damage, remaining HP: 80
                ScavTrap Roberto is repaired by 15 points! remaining HP: 80
                ClapTrap Roberto is repaired by 15 points, remaining HP: 95

                -------- Testing Roberto ataca Mariana --------
                ScavTrap Roberto attacks Mariana, causing 20 points of damage!
                ScavTrap Mariana takes 25 points of damage! remaining HP: 100
                ClapTrap Mariana takes 25 points of damage, remaining HP: 75
                ScavTrap Roberto is repaired by 10 points! remaining HP: 95
                ClapTrap Roberto is repaired by 10 points, remaining HP: 105

                -------- Testing Mariana ataca Roberto --------
                ScavTrap Mariana attacks Roberto, causing 20 points of damage!
                ScavTrap Roberto takes 10 points of damage! remaining HP: 105
                ClapTrap Roberto takes 10 points of damage, remaining HP: 95
                ScavTrap Mariana is repaired by 5 points! remaining HP: 75
                ClapTrap Mariana is repaired by 5 points, remaining HP: 80

                -------- Testing manel ataca Roberto --------
                ScavTrap manel attacks Roberto, causing 20 points of damage!
                ScavTrap Roberto takes 10 points of damage! remaining HP: 95
                ClapTrap Roberto takes 10 points of damage, remaining HP: 85
                ScavTrap manel is repaired by 5 points! remaining HP: 100
                ClapTrap manel is repaired by 5 points, remaining HP: 105
        e porquê?
            O problema de estar a aparecer tanto "ScavTrap" como "ClapTrap" é porque, 
            ao sobrescrevermos as funções takeDamage e beRepaired em ScavTrap, estamos a 
            chamar as versões da classe base ClapTrap após a mensagem personalizada. 
            O que acontece é que primeiro imprimimos a mensagem de ScavTrap 
            e depois a lógica de ClapTrap é executada, que imprime também a sua própria mensagem.
3. Operador de atribuição
	- O operador de atribuição de ScavTrap é chamado: "ScavTrap Assignation Operator called".
	 - Em seguida, o operador de atribuição de ClapTrap é chamado para garantir que os atributos 
	 herdados de ClapTrap sejam corretamente copiados: "ClapTrap Assignation Operator called".
	Saída:
                -------- Testing scav1 = scav3 (Roberto) --------
                ScavTrap Assignation Operator called
                ClapTrap Assignation Operator called
4. Modo Guardião - GuardGate
	- A função especial guardGate é chamada em scav1 (agora com os atributos de scav3 devido à atribuição).
	- A função guardGate exibe uma mensagem indicando que scav1 (com os atributos de scav3, ou seja, "Roberto") entrou no modo de guardião.
	Saída:
		        ScavTrap Roberto has entered in Gate keeper mode.
5. Relatório do estado do ScavTrap
	- Após a ativação do modo Guardião, o estado atual de scav1 (copiado de scav3) é mostrado.
	- Esta mensagem indica o estado atual de Roberto (agora também de scav1), exibindo o HP, pontos de energia e dano de ataque.
	Saída:
    esta a ser:
		ClapTrap Roberto has 85 HP, 46 energy points and 20 attack damage.
		ClapTrap Roberto has 85 HP, 46 energy points and 20 attack damage.
    passou a ser:
                ScavTrap Roberto has 85 HP, 46 energy points and 20 attack damage.
                ScavTrap Roberto has 85 HP, 46 energy points and 20 attack damage.
    e porquê?
        Porque o operador de inserção << foi chamado no std::cout << scav1 << scav3 << std::endl; 
        e o operador de inserção << foi sobrecarregado para a classe ScavTrap, 
        permitindo que os atributos privados da classe ScavTrap sejam acessados e exibidos.
    Soluções: 
        Tinha 2 soluções possíveis para implementar:
            1. Fazer "override manualmente" do operador << para ScavTrap.
            2. Fazer "override automático", adicionar um método getClassType() que retorna o nome da classe.
    Não pude usar a solução 2 para imprimir ScavTrap em vez de ClapTrap na saída do operador <<, 
    pq override é uma função do C++11 (sendo proibido na versão C++8) e o compilador não aceitou. 

IMPORTANTE: Ver mais info no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01, assim como no ponto 5 do main.cpp do CPP03ex01, 
 e no word nos:
        Módulo 0 - 19.11.9.1.7.	Virtual e no 
        Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / Função Virtual & Função membro Virtual (módulo 4).

6. Destruidores- Fim do programa
    - O programa termina após a impressão do estado atual de scav1 e scav3.
    - os destruidores são chamados para cada instância de ScavTrap. A destruição segue a ordem inversa de criação dos objetos: 
    primeiro, a classe derivada ScavTrap é destruída, seguida pela destruição da classe base ClapTrap.
    - Para cada ScavTrap destruído, o destruidor de ScavTrap é chamado primeiro: "ScavTrap Destructor called".
    - Em seguida, o destruidor da classe base ClapTrap é chamado: "ClapTrap Destructor called".

IMPORTANTE: Os destruidores são chamados na ordem inversa à criação dos objetos, seguindo o princípio da destruição em cascata.
- Ver mais info no ponto 6 do main.cpp do CPP03ex01 e
    no ponto 5 do main.cpp do CPP03ex03.

                Saída: 
                ScavTrap Destructor called
                ClapTrap Destructor called
                ScavTrap Destructor called
                ClapTrap Destructor called
                ScavTrap Destructor called
                ClapTrap Destructor called
                ScavTrap Destructor called
                ClapTrap Destructor called
    
    6.1. O princípio da destruição em cascata refere-se justamente a essa ordem inversa de destruição de objetos em 
        uma hierarquia de classes. Em C++, esse processo ocorre automaticamente para garantir que os objetos sejam destruídos 
        de maneira correta e segura, seguindo a lógica de dependência entre as classes.
        6.1.1. - Por que os destrutores são chamados por ordem inversa?
            . Em C++, os destrutores são chamados em ordem inversa à de criação devido à relação de dependência entre 
                as classes derivadas e as suas classes base. Quando um objeto de uma classe derivada é destruído, 
                primeiro é necessário destruir os membros específicos da classe derivada (que foram criados mais recentemente), 
                antes de destruir os membros herdados da classe base. Isso é importante para garantir que os recursos sejam liberados corretamente.
            . Por exemplo, no caso de herança em classes como DiamondTrap, que herda de FragTrap, ScavTrap, e ClapTrap:
                - Quando o objeto DiamondTrap é criado, o construtor de ClapTrap é chamado primeiro (base), seguido por ScavTrap e FragTrap, 
                    e por fim, o construtor de DiamondTrap.
                - Quando o objeto DiamondTrap é destruído, a ordem é invertida: primeiro o destrutor de DiamondTrap, depois os destrutores 
                    de FragTrap, ScavTrap, e por último, o destrutor de ClapTrap.
            . Essa ordem inversa de destruição ocorre porque cada classe derivada pode depender de recursos da classe base. 
                Logo, ao destruir o objeto, os membros da classe derivada devem ser liberados antes de destruir os da classe base, 
                já que a classe derivada pode estar a usar recursos da base.
        6.1.2. - É para respeitar alguma regra ou boa prática em C++?
            . Sim, essa ordem inversa de chamada dos destrutores segue as regras da linguagem C++ para garantir o correto 
                gerenciamento de recursos, especialmente em casos de herança e polimorfismo. A razão para essa prática é 
                evitar problemas de dependência circular, garantindo que os recursos sejam liberados de forma segura e ordenada. 
                Se o destrutor da classe base fosse chamado antes, a classe derivada poderia tentar acessar recursos que já 
                foram destruídos, o que causaria erros de execução ou comportamento indefinido.
            . Essa abordagem é uma boa prática em linguagens orientadas a objetos, onde o gerenciamento de memória e a 
                libertação de recursos são críticos para evitar memory leaks e outros problemas. C++ automatiza esse processo, 
                chamando destrutores na ordem inversa para garantir a destruição correta de objetos complexos.
            . Resumo:
                - Ordem inversa de destrutores: Destrutores são chamados de cima para baixo na hierarquia de herança.
                - Motivo: As classes derivadas podem depender de recursos das classes base, então é necessário 
                destruir as partes mais derivadas primeiro.
                - Boa prática: Garantir a liberação de recursos na ordem correta, prevenindo erros e comportamento indefinido.
        6.1.3. -Como funciona a destruição em cascata:
            . Construção em cascata (ou ordem direta): Quando um objeto de uma classe derivada é criado, o construtor 
            da classe base é chamado primeiro, depois o construtor das classes intermediárias (caso existam), 
            até chegar ao construtor da classe derivada.
            . Destruição em cascata (ou ordem inversa): Ao destruir o objeto, o processo é feito na ordem inversa. 
            O destrutor da classe derivada é chamado primeiro, seguido pelos destrutores das classes intermediárias (se houver), 
            até que o destrutor da classe base seja chamado por último.
        6.1.4. - Por que é que isso é importante?
            . Essa destruição em cascata garante que, ao destruir um objeto de uma classe derivada, 
            os recursos e membros mais específicos dessa classe sejam liberados primeiro, 
            para depois destruir os membros da classe base, que podem ser utilizados pela derivada. 
            . Isso previne que um destrutor da base seja chamado quando a classe derivada ainda não 
            foi completamente destruída, evitando potenciais erros.
    Portanto, o princípio de destruição em cascata é uma regra fundamental de C++, que garante que a hierarquia de objetos e recursos seja desmontada de forma segura e previsível.
*/

#include "ScavTrap.hpp"

void usage(void)
{
    std::cout << "Usage: ./program scav_name" << std::endl;
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        usage();

    // Criar ScavTraps
    ScavTrap scav1;             // ScavTrap sem nome definido. Construtor default chamado.
    ScavTrap scav2(argv[1]);     // ScavTrap com nome passado como argumento. Construtor parametrizado chamado.
    ScavTrap scav3("Roberto");
    ScavTrap scav4("Mariana");

    // Testar ScavTraps criados
    std::cout << "\n-------- Testing Roberto vs Afonso --------\n";
    scav3.attack("Afonso");
    scav3.takeDamage(20);
    scav3.beRepaired(15);

    std::cout << "\n-------- Testing Roberto ataca Mariana --------\n";
    scav3.attack("Mariana");
    scav4.takeDamage(25); 
    scav3.beRepaired(10);

    std::cout << "\n-------- Testing Mariana ataca Roberto --------\n";
    scav4.attack("Roberto");
    scav3.takeDamage(10);
    scav4.beRepaired(5);

    std::cout << "\n-------- Testing " << argv[1] << " ataca Roberto --------\n";
    scav2.attack("Roberto");
    scav3.takeDamage(10);
    scav2.beRepaired(5);

    std::cout << "\n-------- Testing scav1 = scav3 (Roberto) --------\n";
    scav1 = scav3; // Atribuir scav3 para scav1
    std::cout << "\n";
    scav1.guardGate(); // Testar a função especial
    std::cout << scav1 << scav3 << std::endl;

    return 0;
}
