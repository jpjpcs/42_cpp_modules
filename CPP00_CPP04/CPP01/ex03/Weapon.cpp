/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:44:28 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/07 18:57:10 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. A versão correta e recomendada:
const std::string &Weapon::getType(void) const;
Aqui, temos:

const std::string &: Indica que a função retorna uma referência constante para um objeto std::string.
Referência (&): Significa que a função não retorna uma cópia do std::string, mas sim uma referência para o atributo da classe (neste caso, o atributo type).
const antes de std::string: Indica que a referência retornada é constante, ou seja, quem chamar essa função não poderá modificar o objeto std::string retornado.
const após os parênteses (() const): Indica que a função getType não modifica o objeto da classe Weapon ao qual pertence. Portanto, é uma função "constante", garantindo que ela apenas lê os dados e não altera o estado do objeto.
Em resumo, esta assinatura é recomendada porque:

Evita cópia de strings, já que retorna uma referência.
Garante que o valor retornado não pode ser modificado, mantendo a integridade do atributo.
Garante que a função não altera o objeto da classe, o que é essencial para funções de acesso como getType.
2. Explicação do outro formato mencionado:
const std::string Weapon::getType(void) const;
Aqui, temos:

const std::string: Isso indica que a função retorna um objeto constante do tipo std::string.
A função retorna uma cópia do objeto std::string (não uma referência), mas essa cópia é constante e não pode ser modificada.
const após os parênteses (() const): Como antes, isso garante que a função não modifica o objeto Weapon.
Diferenças importantes:
Retorno de uma cópia: Neste caso, estamos a retornar uma cópia do std::string, o que significa que o valor do atributo será duplicado, o que pode ser ineficiente, especialmente para strings grandes.
Objeto constante: A cópia retornada é constante, o que significa que quem chamar a função não poderá modificar a cópia, mas ainda assim é uma cópia, não a referência original.
3. Conclusão: Qual a diferença e qual o correto?
Referência constante (const std::string &):
Retorna uma referência para o std::string existente.
O chamador não pode modificar o valor porque a referência é constante.
Evita cópias desnecessárias e é mais eficiente.
Objeto constante (const std::string):
Retorna uma cópia do std::string, mas a cópia é constante.
Embora o chamador não possa modificar a cópia, o ato de copiar pode ser ineficiente se a string for grande ou se a função for chamada muitas vezes.
Portanto, no contexto do exercício e em boas práticas de C++, o correto é usar a referência constante (const std::string &), pois:

Evita cópias desnecessárias, tornando o código mais eficiente.
Garante que o chamador não pode modificar o valor retornado.
A função não modifica o objeto da classe, mantendo o estado imutável.
Recapitulando a sintaxe:
const std::string &: Retorna uma referência constante, evitando cópia.
() const: Garante que a função não modifica o objeto Weapon.
A combinação dos dois faz com que a função seja eficiente e mantenha a integridade do objeto da classe.
*/

/* 
Qual a diferença entre const std::string Weapon::&getType(void) const e const std::string &Weapon::getType(void) const? 
R. 1. const std::string &Weapon::getType(void) const
Significado:
const std::string &: Retorna uma referência constante a um objeto do tipo std::string. Isso significa que você pode acessar o objeto, mas não pode modificá-lo.
Weapon::getType(void): Esta parte especifica que getType é um método da classe Weapon.
const: Após os parênteses, indica que o método getType não modifica o estado do objeto da classe Weapon.
Esta é a declaração correta para o método getType.
2. const std::string Weapon::&getType(void) const
Significado:
const std::string: Indica que a função retornará um objeto do tipo std::string, que é constante.
Weapon::&: Esta parte é incorreta porque a referência & deve aparecer antes do tipo de retorno, não após o nome da classe.
**Esta declaração está incorreta e não é válida em C++.
3. const std::string &Weapon::&getType(void) const
Significado:

Esta combinação é inválida, pois contém duas referências (&), o que não faz sentido na sintaxe C++. Não é permitido usar dois & assim.
**Esta declaração está incorreta e não é válida em C++.

Resumindo:
A única declaração correta é:
const std::string &Weapon::getType(void) const;
As outras duas declarações estão incorretas e não podem ser utilizadas. Se você usar a declaração correta, não deverá encontrar problemas de compilação ao definir o método getType em sua classe Weapon.
*/

#include "Weapon.hpp"

// é o mesmo que não colocar nada aqui? R. Sim, é o mesmo. O compilador coloca um return; implicitamente no final de cada função que retorna void.
Weapon::Weapon(void)
{
    return ;
}

// Porque usamos o this pointer? Para apontar para o membro da classe, e não para a variável local. Se apontassemos para a variável local, a variável local seria alterada, e não o membro da classe. E como faríamos? Simplesmente colocando o mesmo nome para a variável local e para o membro da classe. Exemplo: type = type; Contudo, queremos diferenciar a variável local _type da variável membro _type pelas razões aqui já apontadas.
Weapon::Weapon(const std::string &type)
{
      this->_type = type;
}

// return; é o mesmo que não colocar nada aqui? R. Sim, é o mesmo. O compilador coloca um return; implicitamente no final de cada função que retorna void.
Weapon::~Weapon(void)
{
    return ;
}

// this->_type = type; // Modifica o valor de _type. Usar this->_type não é estritamente necessário, mas é uma prática comum para deixar claro que você está acessando um membro da classe. A linha return _type; também funcionaria, pois o compilador saberia que você está se referindo ao membro da classe.
// Porque usamos o this pointer? Para apontar para o membro da classe, e não para a variável local. Se apontassemos para a variável local, a variável local seria alterada, e não o membro da classe. E como faríamos? Simplesmente colocando o mesmo nome para a variável local e para o membro da classe. 
// Exemplo: type = type; Contudo, queremos diferenciar a variável local _type da variável membro _type pelas razões aqui já apontadas.
void Weapon::setType(const std::string &type)
{
    this->_type = type; 
}

// return (this->_type); // Acesso ao membro da classe. Retorna uma referência constante. Porque usamos o this pointer? Para apontar para o membro da classe, e não para a variável local. Se apontassemos para a variável local, a variável local seria alterada, e não o membro da classe. E como faríamos? Simplesmente colocando o mesmo nome para a variável local e para o membro da classe. Exemplo: type = type; Contudo, queremos diferenciar a variável local _type da variável membro _type pelas razões aqui já apontadas.
const std::string &Weapon::getType() const // 
{
    return (this->_type);
}
