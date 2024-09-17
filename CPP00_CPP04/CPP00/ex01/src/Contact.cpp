/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:26:16 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/16 17:42:32 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Construtor padrão que inicializa as variáveis de instância com valores padrão.
Contact::Contact(void) {}

Contact::~Contact(void) {}

// Construtor Parametrizado que inicializa as variáveis de instância com os valores passados como argumento.
Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
    : _firstName(fn), _lastName(ln), _nickName(nn), _phoneNumber(pn), _darkestSecret(ds) {} // Inicializa as variáveis de instância com os valores passados como argumento.

void Contact::display(void) 
{
    std::cout << std::endl;
    std::cout << "First name: \"" << this->_firstName << "\"" << std::endl;
    std::cout << "Last name: \"" << this->_lastName << "\"" << std::endl;
    std::cout << "Nickname: \"" << this->_nickName << "\"" << std::endl;
    std::cout << "Phone Number: \"" << this->_phoneNumber << "\"" << std::endl;
    std::cout << "Darkest Secret: \"" << this->_darkestSecret << "\"" << std::endl;
    std::cout << std::endl;
}

// Formata um campo de texto. Se o campo de texto tiver mais de 10 caracteres, ele é truncado para 9 caracteres e um ponto é adicionado ao final.
std::string Contact::formatField(std::string field) 
{
    if (field.length() > 10)
        return (field.substr(0, 9) + ".");
    return field;
}

// Retorna o primeiro nome do contato. Primeiro nome é uma variável de instância, e por isso, é acessada com o operador de seta. 
// O operador de seta é usado para acessar membros de um objeto que é apontado por um ponteiro.
// Mas donde vem este valor de _firstName? Este valor de firstName vem do construtor de Contact, que inicializa a variável de instância _firstName com o valor passado como argumento.
// E donde vem esse valor? Este valor vem do método add() de PhoneBook, que pede ao usuário para digitar o primeiro nome, e armazena o valor digitado na variável fn.

std::string Contact::getFirstName(void)
{
    return this->_firstName;
}

std::string Contact::getLastName(void) 
{
    return this->_lastName;
}

std::string Contact::getNickName(void) 
{
    return this->_nickName;
}
