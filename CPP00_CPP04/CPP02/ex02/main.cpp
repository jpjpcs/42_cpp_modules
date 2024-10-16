/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:55 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/14 23:04:34 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Resumo do Funcionamento da Saída:
    1.1. - Saída:
    joaosilvas-Air:ex02 joaosilva$ ./fixedPoint 
    Default constructor called
    Float constructor called
    Int constructor called
    Float constructor called
    Destructor called
    Destructor called
    0
    copy constructor called
    copy assignment operator called
    0.00390625
    Destructor called
    0.00390625
    copy constructor called
    copy assignment operator called
    copy constructor called
    copy assignment operator called
    Destructor called
    0.00390625
    Destructor called
    0.0078125
    10.1016
    10.1016
    Destructor called
    Destructor called
    joaosilvas-Air:ex02 joaosilva$ 
    
    1.2. - Explicação Detalhada da Saída:
        1.2.1. - Chamada do construtor por omissão (Fixed a):
        A primeira linha Fixed a; chama o construtor por omissão. Isso é indicado pela mensagem:2- 
        Default constructor called
        1.2.2. - Chamada do construtor para Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) ):
            A expressão cria dois objetos temporários:
                Fixed(5.05f) usa o construtor para float, resultando na mensagem:
                    Float constructor called
                Fixed(2) usa o construtor para int, resultando na mensagem:
                    Int constructor called
            Agora, os dois objetos temporários são multiplicados, criando um novo objeto Fixed. 
            A multiplicação provavelmente invoca o construtor de float mais uma vez, para o resultado da operação:
                    Float constructor called
            Após a multiplicação, os temporários são destruídos:
                    Destructor called
                    Destructor called
        1.2.3. - Impressão de a (std::cout << a << std::endl;):
            . O valor de a é 0 (provavelmente inicializado como zero pelo construtor por omissão), então a saída será:
                    0
        1.2.4. - Pré-incremento (std::cout << ++a << std::endl;):
        O operador de pré-incremento incrementa a e retorna uma referência para a já incrementado. 
        Dependendo de como é implementado, o valor pode ser pequeno, por exemplo, 0.00390625, resultando na saída:
                    copy constructor called
                    copy assignment operator called
                    0.00390625
                    Destructor called          
        1.2.5. - Impressão de a novamente (std::cout << a << std::endl;):
        Como a já foi incrementado, o mesmo valor 0.00390625 será impresso:
                    0.00390625
        1.2.6. - Pós-incremento (std::cout << a++ << std::endl;):
        O operador de pós-incremento retorna uma cópia de a antes de incrementá-lo. 
        Isso gera uma chamada ao construtor de cópia e ao operador de atribuição:
                    copy constructor called
                    copy assignment operator called
                    0.00390625
                    Destructor called
        1.2.7. - Impressão de a após o pós-incremento (std::cout << a << std::endl;):
        Agora, a foi incrementado novamente, então o novo valor é 0.0078125:
                    0.0078125
        1.2.8. - Impressão de b (std::cout << b << std::endl;):
        b foi inicializado com o valor Fixed(5.05f) * Fixed(2), o que resulta num valor em ponto fixo, neste caso 10.1016:
                    10.1016
        1.2.9. - Uso de Fixed::max( a, b ) (std::cout << Fixed::max( a, b ) << std::endl;):
        A função Fixed::max retorna o maior dos dois valores, que neste caso é b (10.1016). O valor de b é impresso:
                    10.1016
        1.2.10. - **Chamada dos destrutores:
        No final do programa, todos os objetos criados (incluindo os temporários e as variáveis a e b) são destruídos:
                    Destructor called
                    Destructor called
    Portanto, a sequência de destrutores e construtores está relacionada com a criação e destruição de temporários
    e objetos durante as operações (por exemplo, pós-incremento e multiplicação). Cada vez que uma cópia de um 
    objeto é feita, o construtor de cópia é chamado, seguido pelo operador de atribuição, e no final do escopo, 
    os destrutores são chamados para limpar esses objetos.
*/

/*
2 - O Porquê do valor de 10,1016 vs 10,10?:

    O valor de b está a ser impresso como 10.1016 em vez de 10.10 porque estamos a lidar com aritmética de 
    ponto fixo e possíveis erros de precisão ao converter entre representações de ponto flutuante e ponto fixo.

    2.1. - O que está a acontecer:
        2.1.1. - Conversão para ponto fixo:
            . O valor 5.05f é passado ao construtor que recebe um float, que provavelmente multiplica 
            este valor por uma potência de 2 (por exemplo, 256) para armazenar a parte inteira como número fixo.
            . Algo semelhante acontece com Fixed(2), convertendo o número 2 para o formato de ponto fixo.
        2.1.2. - Multiplicação:
            . Quando os dois valores Fixed(5.05f) e Fixed(2) são multiplicados, ocorre a multiplicação no 
            formato de ponto fixo. Dependendo da implementaste da multiplicação, pode ser necessário 
            "corrigir a escala" (dividir o resultado pela potência de 2 usada na conversão original) 
            para obter o valor correto no resultado.
        2.1.3. - Erro de precisão:
            . A conversão entre ponto flutuante e ponto fixo pode introduzir pequenos erros de arredondamento, 
            devido à forma como os números de ponto flutuante são representados internamente (padrão IEEE 754).
            . Este erro resulta numa ligeira diferença em relação ao valor exato esperado de 10.10. 
            Neste caso específico do código, o valor resultante é 10.1016.
    2.2. - Resolução:
        2.2.1. - Multiplicação de ponto fixo:
        Teremos que nos certificar que a multiplicação de dois números de ponto fixo está a "ajustar a escala" corretamente.
        Por exemplo, se estivermos a usar uma base de 256 para a conversão, após a multiplicação de dois valores de ponto fixo, 
        devemos dividir o resultado por 256 para compensar o facto de a multiplicação em ponto fixo introduzir um fator extra de 256.
            Exemplo de ajuste ao realizar a multiplicação:
            Fixed Fixed::operator*(Fixed const &other) const 
            {
                return Fixed((this->_value * other._value) / (1 << this->_fractionalBits));
            }
            Neste caso, this->_value e other._value representam os valores internos em ponto fixo, e this->_fractionalBits refere-se 
            ao número de bits utilizados para representar a parte fracionária (por exemplo, 8 bits, que corresponde a um fator de escala de 256).
        2.2.2. - Arredondamento:
            . Se precisarmos de maior precisão na saída, podemos implementar uma função que arredonda o número resultante para o número de 
            casas decimais desejado, como 10.10, em vez de 10.1016.
    
    2.3. - Conclusão:
    O valor de b é 10.1016 por causa de pequenos erros de arredondamento durante a multiplicação e a conversão de ponto flutuante para ponto fixo. 
    Devemos certificarmo-nos de ajustar corretamente a escala durante a multiplicação de valores de ponto fixo, e devemos considerar uma estratégia de 
    arredondamento se quisermos limitar o número de casas decimais no output.

*/

#include "Fixed.hpp"

int main(void) 
{
    // Criação de objetos Fixed para testes
    Fixed a; // Cria um objeto a (o valor será 0 do construtor padrão)
    Fixed const b(Fixed( 5.05f) * Fixed(2)); // Cria um objeto b com o valor 10.1016
    Fixed c(10.0f); // Cria um objeto c com o valor de 10
    Fixed const d(3.14f);  // Um novo Fixed constante
    Fixed const e(42.42f); // Outro Fixed constante
    
    // Testes simples do subject: incremento pré e pós-fixados.
    std::cout << "\n";
    std::cout << "Simple Tests:" << std::endl;
    std::cout << a << std::endl; // 0
    std::cout << ++a << std::endl; // valor resultante é 0,00390625. É o valor de 1 dividido por 256 (2^8).
    std::cout << a << std::endl; // 0,00390625. É o valor de 1 dividido por 256 (2^8).
    std::cout << a++ << std::endl; // 0,00390625. É o valor de 1 dividido por 256 (2^8).
    std::cout << a << std::endl; // 0,0078125. É o valor de 2 (incrementado anteriormente) dividido por 256 (2^8).
    
    std::cout << b << std::endl;// B é 10,1. Os 0,0016 no valor 10,1016 provêm de arredondamentos devido à conversão de float para fixed-point number, que é feita através de uma multiplicação por 2^8 (256). Ver mais info ponto 2 do main.cpp CPP02ex02.
    
    std::cout << Fixed::max( a, b ) << std::endl; // Entre a e b, b é o maior valor, então a saída é 10,1.
    
    std::cout << "\n";
    
    // Testes aritméticos
    std::cout << "Arithmetic Operations:" << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl; // Soma a e b
    std::cout << "b - a = " << (b - a) << std::endl; // Subtrai a de b
    std::cout << "a * c = " << (a * c) << std::endl; // Multiplica a por c
    std::cout << "b / a = " << (b / a) << std::endl; // Divide b por a
    std::cout << "\n";

    // Testes de comparação
    std::cout << "Comparisons:" << std::endl;
    std::cout << "a (" << a << ") == c (" << c << "): " << (a == c) << std::endl; // Verifica se a é igual a c
    std::cout << "a (" << a << ") != b (" << b << "): " << (a != b) << std::endl; // Verifica se a é diferente de b
    std::cout << "a (" << a << ") < b (" << b << "): " << (a < b) << std::endl;   // Verifica se a é menor que b
    std::cout << "a (" << a << ") > b (" << b << "): " << (a > b) << std::endl;   // Verifica se a é maior que b
    std::cout << "b (" << b << ") >= a (" << a << "): " << (b >= a) << std::endl; // Verifica se b é maior ou igual a a
    std::cout << "b (" << b << ") <= c (" << c << "): " << (b <= c) << std::endl; // Verifica se b é menor ou igual a c
    std::cout << "\n";
    
    // Testes de incrementos e decrementos
    std::cout << "Increment and Decrement Operations:" << std::endl;
    std::cout << "++a = " << ++a << std::endl; // Pré-incrementa a, que passa a 1 que dps é dividido por 256 (2^8) e dá 0.00390625
    std::cout << "a++ = " << a++ << std::endl; // Pós-incrementa a, logo a ainda é 1, q tal como acima é dividido por 256 (2^8) e dá 0.00390625
    std::cout << "After a++: " << a << std::endl; // Mostra o valor de a após os incrementos, que é 0.0078125, correspondente a 2 dividido por 256 (2^8).
    std::cout << "--c = " << --c << std::endl; // Pré-decrementa c, que passa ser 9.99609, que corresponde a 2559 dividido por 256 (2^8). E de onde vem o 2559? Vem do valor de c que é 10 e que é multiplicado por 256 (2^8) e dá 2560, que é decrementado em 1 e dá 2559.
    std::cout << "c-- = " << c-- << std::endl; // Pós-decrementa c, q continua a ser 9.99609.
    std::cout << "After c--: " << c << std::endl; // Mostra o valor de c após o pós-decremento, que é 9.99219, que corresponde a 2558 dividido por 256 (2^8).
    std::cout << "\n";
    
    // Testes de min e max
    std::cout << "Minimum and Maximum:" << std::endl;
    // Testa as versões não-constantes
    std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl; // Mostra o menor entre a e b, no caso a, q é 0.0078125.
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl; // Mostra o maior entre a e b, no caso b, q é 10.1016.
    // Testa as versões constantes
    std::cout << "Testing const versions:" << std::endl;
    std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl; // Testa a versão constante de min, que é d, q é 3.14.
    std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl; // Testa a versão constante de max, que é c, q é 9.99219.
    std::cout << "\n";
    
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
