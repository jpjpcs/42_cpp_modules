/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:55:32 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/20 12:22:28 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain 
{
    public:
        // Construtor padrão
        Brain();
        // Construtor de cópia
        Brain(const Brain& to_copy);
        // Operador de atribuição
        Brain& operator=(const Brain& to_copy);
        // Destrutor virtual para garantir que destrutores de subclasses sejam chamados
        virtual ~Brain();

        // Método para apresentar as ideias
        void showIdeas() const;

        /* // Método para definir uma ideia
        void setIdea(int index, const std::string& idea);
        // Método para obter uma ideia
        std::string getIdea(int index) const; */

    private:
        static const int ideasCount = 100; // Número de ideias
        std::string ideas[ideasCount];      // Array de ideias
};

#endif // BRAIN_HPP
