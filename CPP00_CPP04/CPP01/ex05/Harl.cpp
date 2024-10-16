/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:06:57 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:56:32 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Para o exercício 05 (Harl 2.0), a solução envolve o uso de pointers to member functions 
para evitar uma série de condicionais (if/else). A ideia é mapear as diferentes funções 
privadas da classe Harl (debug, info, warning, error) para um conjunto de ponteiros de 
função e invocá-los com base no nível passado para a função pública complain.
*/

/*
Explicação Teórica:
Pointers to Member Functions: São ponteiros que referenciam funções membro de uma classe. 
São ponteiros que armazenam o endereço de uma função membro de uma classe.
Diferente dos ponteiros para funções normais, eles precisam de um contexto 
(um objeto específico da classe) para serem usados. 
Ou seja, Diferem de ponteiros de funções normais, pois são usados dentro do contexto 
de um objeto específico da classe (precisam de um "this"). 
A sintaxe para chamá-los é (*objPtr).*funcPtr(args) ou, mais comumente, 
objPtr->*funcPtr(args), onde objPtr é o ponteiro para o objeto e funcPtr 
é o ponteiro para a função membro.
Ou seja, Para invocar uma função membro através de um ponteiro, 
usa-se a sintaxe (obj->*ptr)() ou (this->*ptr)().

Uso na solução: No método complain, armazenamos quatro ponteiros para as 
funções debug, info, warning e error num array de ponteiros de funções membro.
Para tal, no referido método complain, criei um array de ponteiros 
para as funções debug, info, warning e error. 
Dependendo do valor do argumento level, escolhemos e invocamos o ponteiro correspondente.
Ou seja, Com base no parâmetro level, o array de strings correspondente aos níveis é verificado e, 
quando o nível coincide, o ponteiro para a função apropriada é invocado. 
Isso elimina a necessidade de várias instruções if/else, como no exemplo abaixo:
void Harl::complain(std::string level)
{
    if (level == "debug")
        debug();
    else if (level == "info")
        info();
    else if (level == "warning")
        warning();
    else if (level == "error")
        error();
    else
        std::cout << "Invalid level" << std::endl;
}
*/

#include "Harl.hpp"

Harl::Harl(void) 
{
    std::cout << "\nHarl is ready to complain! \n" << std::endl;
}

Harl::~Harl(void) 
{
    std::cout << "Harl has stopped complaining.\n" << std::endl;
}

void Harl::complain(std::string level) 
{
    // Definir um array de ponteiros para as funções membro
    void (Harl::*funcPtr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    // Definir um array de strings correspondentes aos níveis
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    // Percorrer os níveis para encontrar uma correspondência
    for (int i = 0; i < 4; i++) 
    {
        if (levels[i] == level) 
        {
            // Chamar a função correspondente usando o ponteiro de função
            (this->*funcPtr[i])();
            return;
        }
    }
    std::cout << "Invalid level!\n" << std::endl;
}

void Harl::debug(void)
{
    std::cout << "DEBUG - This is a debug message: " << std::endl;
    std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO - This is an info message: " << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING - This is a warning message: " << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working ";
	std::cout << "here since last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR - This is an error message: " << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}
