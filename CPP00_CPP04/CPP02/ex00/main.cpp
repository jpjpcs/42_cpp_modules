/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:34:02 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/08 19:12:42 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Output no terminal:
joaosilvas-Air:ex00 joaosilva$ ./fixedPoint 
Default constructor called
Copy constructor called
Copy assignment operator called
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
joaosilvas-Air:ex00 joaosilva$ 

----------------------------------------------------------------------------------------------------------------------------

Explicação Detalhada da Saída:
1. Linha: Default constructor called
Causa: O objeto a é criado usando o construtor padrão. 
É a primeira linha no main.cpp, onde Fixed a; inicializa o objeto a com 
o valor _fixedPointValue como 0.

2. Linha: Copy constructor called - CONSTRUTOR de Cópia (e não de ATRIBUIÇÃO)
Causa: O objeto b é criado como uma cópia de a usando o construtor de cópia. 
Isto ocorre quando escrevemos Fixed b(a);. O valor de b é copiado a partir de a, 
usando o operador de atribuição por cópia.

3. Linha: Copy assignment operator called - Construtor de ATRIBUIÇÃO de Cópia
Causa: O operador de atribuição de cópia é chamado dentro do próprio construtor de cópia. 
Como o construtor de cópia utiliza *this = other;, a operação de atribuição por cópia 
é invocada para definir o valor de _fixedPointValue de b para ser igual ao de a.

4. Linha: getRawBits member function called
Causa: A função getRawBits é chamada no operador de atribuição para obter o valor 
de a e atribuí-lo ao novo objeto b.

5. Linha: Default constructor called
Causa: O objeto c é criado usando o construtor padrão. Isto ocorre 
quando escreves Fixed c; no main.cpp.

6. Linha:Copy assignment operator called
Causa: O operador de atribuição de cópia é chamado quando fazes c = b;, 
copiando o valor de b para c.

7. Linha: getRawBits member function called
Causa: O operador de atribuição de cópia chama a função getRawBits 
para obter o valor de b e copiá-lo para c.

8. Linha: getRawBits member function called
Causa: A função getRawBits é chamada explicitamente em 
std::cout << a.getRawBits();, para mostrar o valor do objeto a no terminal. 
O valor é 0, pois a foi inicializado pelo construtor padrão.

9. Linha: 0
Causa: O valor obtido de a.getRawBits() é 0 e é impresso no terminal.

10. Linha: getRawBits member function called
Causa: O método getRawBits é chamado para o objeto b em 
std::cout << b.getRawBits();, também resultando em 0.

11. Linha: 0
Causa: O valor obtido de b.getRawBits() é impresso no terminal, que também é 0.

12. Linha: getRawBits member function called
Causa: O método getRawBits é chamado para o objeto c em std::cout << c.getRawBits();, resultando novamente em 0.

13. Linha: 0
Causa: O valor obtido de c.getRawBits() é impresso no terminal, que é 0, 
pois o valor de b (copiado para c) também era 0.

14-16. Linhas:
Destructor called
Destructor called
Destructor called
Causa: Os objetos a, b, e c são destruídos à medida que o programa termina, 
chamando o destrutor para cada um, nesta ordem, de acordo com as suas criações no main.

Conclusão:
A ordem da saída ocorre porque o fluxo segue a sequência natural de criação e destruição de objetos no programa. 
O construtor padrão é chamado primeiro, seguido pelo construtor de cópia e o operador de atribuição quando necessário. 
Durante as atribuições, o método getRawBits é chamado para acessar os valores dos objetos e copiar para outros.

Resumidamente:

A criação de objetos (a, b, c) segue a ordem escrita no main.
O destrutor é chamado em ordem inversa à criação, como esperado, uma vez que o escopo é saído.

*/

#include "Fixed.hpp"

int main(void) 
{
    Fixed a;  // Criação de um objeto Fixed usando 
    Fixed b(a);  // Cópia de a para b usando o construtor de cópia
    Fixed c;  // Criação de outro objeto Fixed usando o construtor padrão

    c = b;  // Atribuição de b para c usando o operador de atribuição de cópia (não é um construtor).

    std::cout << a.getRawBits() << std::endl;  // Exibir valor bruto de a
    std::cout << b.getRawBits() << std::endl;  // Exibir valor bruto de b
    std::cout << c.getRawBits() << std::endl;  // Exibir valor bruto de c

    return 0;
}
