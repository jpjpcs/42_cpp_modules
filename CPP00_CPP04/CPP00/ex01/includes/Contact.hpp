/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:25:55 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/16 17:27:32 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip> // std::setw e std::setfill. O primeiro é para definir a largura do campo, e o segundo é para preencher o campo com um caractere específico.

// Isto é um contato. Um contato é constituído por um primeiro nome, um último nome, um apelido, um número de telefone e um segredo obscuro.
// Um contato ten métodos para exibir suas informações e formatar um campo de texto.
// a função do campo texto é estática por 1a simples razão: ela não vai mudar de acordo com o objeto que a chama, além de que ela não precisa de nenhum dado do objeto para funcionar.
// Portanto, ela é uma função que pertence à classe, e não ao objeto.
// Quer a função display() seja estática ou não, depende do que você quer fazer com ela. Se você quiser que ela seja chamada sem um objeto, então ela deve ser estática.
// Se você quiser que ela seja chamada com um objeto, então ela não deve ser estática.
// Neste caso, quer a função display(), quer a função getFirstName(), getLastName() e getNickName() não são estáticas, porque elas precisam de um objeto para funcionar.
// Colocamos estas funções como públicas para que possamos acessá-las de fora da classe. Isto é, podemos chamar estas funções de qualquer lugar do código, inclusive de dentro da main, ou qualquer instância de PhoneBook.
// Colocamos privadas as variáveis de instância, porque não queremos que elas sejam acessadas de fora da classe. Isto é, não queremos que elas sejam acessadas de fora da classe Contact. 
// E porquê? Porque se alguém pudesse acessar estas variáveis de fora da classe, poderia mudar o estado do objeto sem passar pelos métodos da classe, o que poderia causar problemas.
// Assim, para garantir que o objeto esteja sempre em um estado válido, colocamos as variáveis de instância como privadas, e prevenimos problemas relacionados com o acesso direto a elas.

class Contact 
{
public:
    Contact(void);
    ~Contact(void);

    Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
    void display(void);
    
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickName(void);

    static std::string formatField(std::string field);

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;
};

#endif
