/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:10:46 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/16 17:40:08 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

// Isto é um PhoneBook. Ele é uma classe que contém um array de contatos e tem métodos para adicionar e pesquisar contatos.
// Ele também tem um método privado para exibir os contatos armazenados. E porquê privado? Porque não queremos que ele seja acessado de fora da classe.
// E porquê? Porque se alguém acessar este método de fora da classe, poderia exibir os contatos sem passar pelos métodos da classe, o que poderia causar problemas.
// Assim, para garantir que os contatos sejam exibidos apenas quando queremos, colocamos o método _display() como privado, e prevenimos problemas relacionados com o acesso direto a ele.
// E que tipo de problemas seriam estes? Poderia ser um problema de segurança, por exemplo. Se alguém pudesse acessar este método de fora da classe, poderia exibir informações sensíveis sem passar pelos métodos da classe.
// Outro exemplo seria um problema de consistência. Se alguém pudesse acessar este método de fora da classe, poderia exibir os contatos em um estado inválido, o que poderia causar problemas.
// Ou ainda um problema de encapsulamento. Se alguém pudesse acessar este método de fora da classe, poderia exibir os contatos sem passar pelos métodos da classe, o que poderia quebrar o encapsulamento.
// Mais ainda um problema de manutenção. Se alguém pudesse acessar este método de fora da classe, poderia exibir os contatos sem passar pelos métodos da classe, o que poderia dificultar a manutenção.
// Estes e outros problemas podem ser evitados colocando o método _display() como privado, e prevenindo problemas relacionados com o acesso direto a ele.
// Colocamos este método como privado para que ele seja acessado apenas de dentro da classe PhoneBook. Isto é, queremos que ele seja chamado apenas de dentro da classe PhoneBook.
// Assim é impossível acessar este método de fora da classe PhoneBook como por exemplo de dentro da main, ou qualquer instância de Contact.
// Já as funções add() e search() são públicas para que possamos acessá-las de fora da classe. Isto é, podemos chamá-las de qualquer lugar do código, inclusive de dentro da main, ou qualquer instância de PhoneBook.

class PhoneBook 
{
public:
    PhoneBook(void);
    ~PhoneBook(void);

    // E porquê colocamos estas funções como públicas? Porque queremos que elas sejam acessadas de fora da classe. Isto é, queremos que elas sejam chamadas de qualquer lugar do código, inclusive de dentro da main, ou qualquer instância de PhoneBook.
    // E porque estes métodos não têm argumentos? Porque eles não precisam de argumentos para funcionar. Eles apenas executam uma ação, e não precisam de nenhum dado para funcionar.
    void add(void);
    void search(void);

private:
    int _i; // Variável de instância que armazena o número de contatos armazenados.
    static const int MAX_CONTACTS = 8; // Constante que armazena o número máximo de contatos que o telefone pode armazenar.
    Contact _contacts[MAX_CONTACTS]; // Array de contatos que armazena até 8 contatos e vem da classe Contact.

    void _display(void);
};

#endif
