/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:55 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/09 12:56:20 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Resumo do Funcionamento da Saída

1 - Fixed a;
Chama o construtor padrão, que inicializa _fixedPointValue a 0.
Saída: Default constructor called

2 - Fixed const b(10);
Chama o construtor parametrizado com inteiro. O número 10 é convertido para fixed-point (10 << 8 = 2560). 10 << 8 = 2560 desconstruído é 10 * 2^8 = 2560.
Saída: Int constructor called

3 - Fixed const c(42.42f);
Chama o construtor parametrizado com float. O valor 42.42 é multiplicado por 256 e arredondado para o valor em fixed-point.
Saída: Float constructor called

4 - Fixed const d(b);
Chama o construtor de cópia para criar d com base em b.
Internamente, o operador de atribuição é chamado no construtor de cópia, gerando a saída do operador de atribuição.
Saída: Copy constructor called, seguida por Copy assignment operator called

5 - a = Fixed(1234.4321f);
Primeiro, chama-se o construtor parametrizado com float, criando um objeto temporário.
Em seguida, o operador de atribuição copia o valor do objeto temporário para a.
Saída: Float constructor called, seguida por Copy assignment operator called e 
Destructor called.
Aqui, temos dois passos:
- Um novo objeto Fixed temporário é criado usando o construtor parametrizado que aceita um float (1234.4321f).
Saída: "Float constructor called"
- O operador de atribuição é chamado para copiar os dados deste objeto temporário para o objeto a.
Saída: "Copy assignment operator called"
- Após a atribuição, o objeto temporário é destruído.
Saída: "Destructor called"

6 - Saída dos valores armazenados e Conversão para inteiros:
A seguir, o programa imprime os valores armazenados nos objetos criados até aqui:
a is 1234.43 — Aqui, o objeto a (inicializado com 1234.43f) tem o valor 1234.43 em ponto fixo.
b is 10 — O objeto b (inicializado com o inteiro 10) exibe o valor 10.
c is 42.4219 — O objeto c foi uma cópia do objeto a e exibe o valor copiado, que é uma aproximação de 42.4219 em ponto fixo.
d is 10 — O objeto d recebeu o valor de b através do operador de atribuição e exibe 10.

Depois, o programa converte os valores armazenados para inteiros e imprime os resultados:
a is 1234 as integer — O valor em ponto fixo de a foi convertido para int, resultando em 1234.
b is 10 as integer — O valor em ponto fixo de b foi convertido para int, resultando em 10.
c is 42 as integer — O valor em ponto fixo de c (uma cópia de a) foi convertido para int, resultando em 42.
d is 10 as integer — O valor de d, também copiado de b, foi convertido para int, resultando em 10.

Impressão dos valores (conversões implícitas para float):
1. std::cout << "a is " << a << std::endl;
.Exibe o valor de a, que foi atribuído com 1234.4321f convertido para ponto fixo.
.Saída: a is 1234.43
2. std::cout << "b is " << b << std::endl;
.Exibe o valor de b, que foi inicializado com 10 (via construtor int).
.Saída: b is 10
3. std::cout << "c is " << c << std::endl;
.Exibe o valor de c, que foi inicializado com 42.42f.
.Saída: c is 42.4219
4 - std::cout << "d is " << d << std::endl;
.Exibe o valor de d, que é uma cópia de b, portanto também exibe 10.
.Saída: d is 10

Impressão dos valores convertidos para int:
1 - std::cout << "a is " << a.toInt() << " as integer" << std::endl;
.Converte o valor de a para int e exibe-o.
-Saída: a is 1234 as integer
2 - std::cout << "b is " << b.toInt() << " as integer" << std::endl;
.Converte o valor de b para int e exibe-o.
.Saída: b is 10 as integer
3 - std::cout << "c is " << c.toInt() << " as integer" << std::endl;
.Converte o valor de c para int e exibe-o.
.Saída: c is 42 as integer
4 - std::cout << "d is " << d.toInt() << " as integer" << std::endl;
.Converte o valor de d para int e exibe-o (como é uma cópia de b, o resultado será 10).
. Saída: d is 10 as integer

7 - Destrutores:
Quando os objetos temporários e os demais objetos saem de escopo, o destrutor é chamado para cada um, na ordem inversa de criação.
Saída: Destructor called (quatro vezes):
Destructor de 'a' called — Destrói a.
Destructor de 'b' called — Destrói b.
Destructor de 'c' called — Destrói c.
Destructor de 'd' called — Destrói d.

Resumo final:
Construtores: Foram usados construtores padrão, parametrizados (para int e float), de cópia e o operador de atribuição.
Operador de atribuição: Foi utilizado para copiar valores de um objeto para outro já existente.
Destruidores: Foram chamados automaticamente à medida que os objetos deixaram de ser necessários.
Essa ordem de saída reflete a sequência de criação, manipulação e destruição de objetos de ponto fixo.
Ordem detalhada e precisa da saída:
    "Default constructor called" — Objeto a é criado.
    "Int constructor called" — Objeto b é criado.
    "Float constructor called" — Objeto c é criado.
    "Copy constructor called" — Objeto d é criado a partir de b.
    "Copy assignment operator called" - O valor de b é atribuído a d.
    "Float constructor called" — Objeto temporário é criado para atribuição a a.
    "Copy assignment operator called" — O valor do temporário é atribuído a a.
    "Destructor called" — Objeto temporário é destruído.
    Impressão dos valores de a, b, c e d.
    Impressão dos valores convertidos para int.
    "Destructor called" — Destrói a.
    "Destructor called" — Destrói b.
    "Destructor called" — Destrói c.
    "Destructor called" — Destrói d.
*/

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;                             // Cria um objeto Fixed 'a' usando o construtor padrão
    Fixed const b(10);                   // Cria um objeto Fixed 'b' a partir de um inteiro usando o construtor parametrizado
    Fixed const c(42.42f);               // Cria um objeto Fixed 'c' a partir de um float usando o construtor parametrizado
    Fixed const d(b);                    // Cria um objeto Fixed 'd' usando o construtor de cópia

    a = Fixed(1234.4321f);               // Cria um objeto temporário com o construtor parametrizado (float) e atribui a 'a' usando o operador de atribuição

    // Exibe os valores como float
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // Exibe os valores convertidos para inteiro
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
