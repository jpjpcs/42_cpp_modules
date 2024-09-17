/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:13:02 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/16 17:37:43 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

// Construtor padrão
PhoneBook::PhoneBook(void) : _i(0) 
{
    
}

// Destrutor
PhoneBook::~PhoneBook(void) 
{
    
}

// Adiciona um contato ao telefone
void PhoneBook::add(void) 
{
    std::string fn, ln, nn, pn, ds;

    std::cout << "First Name (type 'exit' to finish): ";
    std::getline(std::cin, fn);
    if (fn == "exit") return;
    
    std::cout << "Last Name: ";
    std::getline(std::cin, ln);
    if (ln == "exit") return;

    std::cout << "Nickname: ";
    std::getline(std::cin, nn);
    if (nn == "exit") return;

    std::cout << "Phone number: ";
    std::getline(std::cin, pn);
    if (pn == "exit") return;

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, ds);
    if (ds == "exit") return;

    if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty()) 
    {
        std::cout << "\n\t-- A CONTACT CAN'T HAVE EMPTY FIELDS --\n" << std::endl;
        return;
    }

    this->_contacts[this->_i % MAX_CONTACTS] = Contact(fn, ln, nn, pn, ds);
    this->_i++;
    std::cout << "\n\t---- CONTACT SAVED ----\n" << std::endl;
}

// Exibe os contatos armazenados
void PhoneBook::_display(void) 
{
    std::string field;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < MAX_CONTACTS; ++i) 
    {
        std::cout << "|" << std::setw(10) << i << "|";
        field = this->_contacts[i].getFirstName();
        std::cout << std::setw(10) << Contact::formatField(field) << "|";
        field = this->_contacts[i].getLastName();
        std::cout << std::setw(10) << Contact::formatField(field) << "|";
        field = this->_contacts[i].getNickName();
        std::cout << std::setw(10) << Contact::formatField(field) << "|" << std::endl;
    }
}

// Procura e exibe um contato específico pelo ID
void PhoneBook::search(void) 
{
    int id;
    int maxId = (this->_i > MAX_CONTACTS - 1) ? MAX_CONTACTS - 1 : this->_i - 1;

    _display();
    std::cout << "Entry id > ";
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::cin.fail()) 
    {
        std::cout << "\n\t--- INVALID INPUT ---\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } 
    else if (id < 0 || id > maxId) 
    {
        std::cout << "\n\t--- NO CONTACT AT " << id << " ---\n" << std::endl;
    } 
    else 
    {
        this->_contacts[id].display();
    }
}
