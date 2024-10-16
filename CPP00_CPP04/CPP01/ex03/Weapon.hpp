/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:44:34 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:56:59 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Quando falamos sobre inicializar ou modificar o valor de um atributo na classe Weapon, estamos, de fato, modificando o estado do objeto. Vamos esclarecer isso em relação ao exercício que você está implementando.

1 - Contexto do Exercício e Métodos da Classe Weapon
No seu exercício, a classe Weapon deve ter um atributo privado _type, que é um std::string, e será preciso um método para definir esse tipo (setType) e um método para obter o tipo (getType).
Classe Weapon: Tem um atributo privado _type, que é um std::string. Precisamos de métodos para definir (setType) e obter (getType) esse tipo.


1.1. - Método setType
Objetivo: Modifica o valor de _type, alterando o estado do objeto.
Implementação:
void setType(const std::string &type) {
    _type = type; // Altera o valor de _type
}
Parâmetro const std::string &type: Passado por referência constante para evitar cópias desnecessárias e garantir que o valor original não seja modificado.
Nesse caso, estamos a usar uma referência constante como parâmetro. Isso é eficiente, pois evita a cópia do std::string (que pode ser custosa para strings longas) e ainda garante que você não modifique a string original que foi passada como argumento.


1.2. - Método getType
Objetivo: Retorna o valor atual de _type sem alterá-lo.
Implementação:
const std::string &getType() const {
    return _type; // Retorna uma referência constante a _type
}
const no final: Indica que o método não altera o estado do objeto. Simplesmente retorna uma referência constante para o atributo _type, permitindo que outros objetos ou funções leiam o valor sem alterá-lo:


1.3. - Resumo do Uso de const
--- No Retorno do Método:
const std::string &getType() const: O primeiro const garante que a referência retornada não pode ser modificada.
--- No Final do Método:
const: Indica que o método não altera os membros da classe.
Proibição de const Antes do Nome do Método:
--- Não pode-se colocar const antes do nome do método, pois deve preceder o tipo de retorno ou aparecer no final.
Exemplo inválido: const getType(void) const;. const


1.4. - Modificação de Estado vs. Leitura de Estado
Modificar o estado: Isso acontece quando você usa um método como setType para atribuir um novo valor a _type. Nesse caso, o estado do objeto muda. Isto é, o valor do objeto _type é alterado.
Ler o estado: Isso acontece quando você chama getType(), que retorna o valor atual de _type sem alterá-lo.
Resumo
 --- setType(const std::string &type):
Modifica o estado do objeto: altera o valor do atributo _type.
Passa a string por referência constante para evitar cópias desnecessárias, mantendo a eficiência.
const std::string &getType() const:
--- getType() const:
Não modifica o estado do objeto: apenas retorna o valor de _type.
Passa como referência constante para que não haja cópia, permitindo acesso eficiente ao valor.


1.5. - Considerações Finais
A implementação correta dos métodos setType e getType garante que estamos a modificar ou acessar os objetos.
Implementação correta dos métodos setType e getType assegura que você pode modificar e acessar o estado do objeto Weapon de maneira eficiente e segura.
Conclusão: O setType altera o estado do objeto, enquanto o getType permite a leitura desse estado sem alteração. O uso de const é crucial para garantir a integridade e eficiência dos métodos.
*/

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon(); // Contrutor padrão (sem parâmetros). Útil no caso HumanB que não tem uma arma por padrão. HumanB pode não ter uma arma, faz sentido ter a possibilidade de inicializar um Weapon vazio (usando o construtor padrão). Para HumanA, podes usar o construtor parametrizado, já que ele sempre começa com uma arma. Ter ambos os construtores é uma boa prática, principalmente no âmbito do exercício, porque permite que construtor escolher consoante o caso a aplicar. 
        Weapon(const std::string &type); // Construtor parametrizado (que inicializa o tipo da arma).
        ~Weapon(void); // Qual a diferença entre ter ~Weapon(void) e ~Weapon()? - Nenhuma. Ambas as formas são válidas. A primeira é mais explícita, indicando que o destrutor não recebe parâmetros. A segunda é mais compacta, mas igualmente válida.
        const std::string &getType(void) const; // Retorna uma referência constante para o _type, evitando cópias desnecessárias. Um getter getType() que retorna uma referência constante para o atributo type, de forma a evitar cópias desnecessárias. O const tb pode estar assim: std::string const	&getType(void); - é uma questão de estilo. // getType(const std::string &type); - Assim o parametro é que seria constante e não o retorno. 
        void setType(const std::string &type); //  Usa uma referência constante como parâmetro, garantindo que o valor passado não será copiado nem modificado.. Um setter setType() que recebe uma referência constante para definir o valor do atributo type, garantindo eficiência ao evitar cópias, mas sem modificar o valor original passado. É void pq o exercício não pede que tenha retorno. Pede apenas que DEFINA o type // setType(const std::string &type); // Mais uma vez o parametro é que seria constante e não o retorno.
    private:
        std::string _type; // Atributo privado que armazena o tipo de arma. 
};

#endif
