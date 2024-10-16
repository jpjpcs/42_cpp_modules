/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:44:07 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/24 18:04:25 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Weapon e _weapon são iguais? 
// Não, weapon e _weapon são diferentes. 
// weapon é o parâmetro do construtor HumanA, que é usado para inicializar o atributo _weapon. 
// _weapon é o atributo da classe HumanA que armazena a arma do HumanA. 
// weapon é uma variável temporária que é usada para inicializar _weapon. 
// Uma vez que _weapon é uma referência, ela deve ser inicializada no construtor, e não pode ser alterada depois. 
// Portanto, weapon é usado para inicializar _weapon, mas não é armazenado em _weapon. 
// _weapon é armazenado em _weapon. 
// O mesmo acontece com name e _name. 
// name é o parâmetro do construtor HumanA, que é usado para inicializar o atributo _name.
// _name é o atributo da classe HumanA que armazena o nome do HumanA.

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon); // Weapon passa por referencia para evitar cópias desnecessárias. E porque não são precisas cópias? Porque o HumanA não vai ter várias armas, ele vai ter uma arma só. Então, não faz sentido copiar a arma, porque só vai haver uma arma. Se passares por valor, estás a copiar a arma, o que é desnecessário. Se passares por referência, estás a passar o endereço da arma, o que é mais eficiente. Tb podia passar por ponteiro. Teria era que dereferenciar o ponteiro para aceder ao objeto. Além disso a referência é mais segura, porque não pode ser nula. O nome pode ser passado por valor/cópia, porque o HumanA pode ter vários nomes. Portanto, faz sentido copiar o nome.
        ~HumanA(void); 
        void	attack(void); // Função para atacar. Não recebe parâmetros, porque o ataque é feito com a arma que o HumanA tem. E o HumanA tem a arma no atributo _weapon. Portanto, não é preciso passar a arma como parâmetro.

    private:
        std::string	_name; // É privada porque só o HumanA deve ter acesso. Caso contrário, qualquer um poderia mudar o nome do HumanA, nomeadamente fora da classe HumanA. E isso não é desejável. O nome do HumanA deve ser definido no construtor e não deve ser alterado fora da classe HumanA.
        Weapon		&_weapon; // É uma referência porque o HumanA não vai ter várias armas, ele vai ter uma arma só. Portanto, não faz sentido copiar a arma, porque só vai haver uma arma. Se passares por valor, estás a copiar a arma, o que é desnecessário. Se passares por referência, estás a passar o endereço da arma, o que é mais eficiente. Tb podia passar por ponteiro. Teria era que dereferenciar o ponteiro para aceder ao objeto. Além disso a referência é mais segura, porque não pode ser nula.
};


#endif
