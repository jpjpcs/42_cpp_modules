/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:07:24 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/08 17:05:15 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
O switch statement é uma estrutura de controle em linguagens de programação, como C++, 
usada para selecionar uma entre várias seções de código a serem executadas, 
com base no valor de uma expressão. É particularmente útil quando há múltiplos 
caminhos possíveis, dependendo do valor de uma variável, geralmente comparando um 
valor exato (como um número inteiro ou caractere).

•	expressão: A expressão ou variável que será avaliada. Deve ser de um tipo que possa ser convertido para um valor integral (tipos inteiros, caracteres ou enumeradores).
•	case valor:: Um valor constante que a expressão pode assumir. Se o valor da expressão for igual ao valor de um case, o código correspondente a esse case é executado.
•	break: Usado para sair do switch após a execução de um bloco de código de um case. Se omitido, o controle de fluxo cairá no próximo case (fall-through), executando também o código dele.
•	default: (Opcional) O bloco de código dentro do default é executado se nenhum dos case corresponder ao valor da expressão. Funciona como o else em uma estrutura if/else.
*/

/*
A diferença entre switch case e estruturas de controle if/elseif/else reside principalmente na forma como funcionam e nos casos de uso ideais para cada um. Abaixo está uma explicação detalhada:

1. Conceito e Funcionamento:
if/elseif/else:
Avalia uma condição booleana (verdadeira ou falsa). As expressões dentro de if, elseif, ou else podem ser qualquer tipo de condição lógica, desde comparações numéricas, de strings, até expressões complexas.
Cada condição é avaliada sequencialmente até que uma seja verdadeira. Quando uma é satisfeita, o bloco correspondente é executado.
Após a execução de um bloco, o controle sai da estrutura.
Exemplo:

int x = 2;
if (x == 1)
    std::cout << "One";
else if (x == 2)
    std::cout << "Two";
else
    std::cout << "Other number";
    
switch case:
É utilizado quando se tem um valor específico a ser comparado contra várias opções (casos). A comparação é feita apenas com valores inteiros, caracteres ou enums (tipos inteiros subjacentes).
Avalia o valor de uma expressão e compara-o diretamente com constantes pré-definidas nos casos (case). Quando uma correspondência é encontrada, o código associado ao case é executado.
Se não houver um break no final de um case, o switch continua a executar os blocos de código dos próximos case (funcionamento chamado de fall-through).
Exemplo:

int x = 2;
switch (x) {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    default:
        std::cout << "Other number";
}

2. Casos de Uso:
if/elseif/else:
Pode ser usado para qualquer tipo de condição, desde simples até expressões complexas.
É mais flexível, pois permite comparação de variáveis e expressões lógicas diversas.
Exemplo: quando você precisa verificar se uma variável está dentro de um intervalo (ex: x > 5 && x < 10).
switch case:
Ideal para comparação direta de uma variável contra valores constantes e quando se lida com muitas opções baseadas em valores exatos.
Utiliza-se para números inteiros, caracteres, ou enums.
Exemplo: uma boa escolha quando você tem um conjunto limitado de valores, como dias da semana, opções de menu, ou níveis de log (como no teu exercício harlFilter).

3. Performance:
if/elseif/else:
Todas as condições são verificadas sequencialmente até que uma seja verdadeira. Isso pode resultar em tempo de execução maior à medida que o número de condições aumenta.
switch case:
Pode ser mais eficiente do que if/elseif/else, especialmente quando há muitas comparações. O compilador pode otimizar o código switch usando tabelas de saltos (jump tables), 
tornando-o mais rápido para comparar valores inteiros ou enumerados.

4. Tipos Suportados:
if/elseif/else:
Suporta qualquer tipo de expressão que possa ser avaliada como verdadeira ou falsa (incluindo variáveis, expressões lógicas, chamadas de função, etc.).
switch case:
Só suporta tipos inteiros, caracteres e enum. Strings e condições mais complexas não podem ser usadas diretamente no switch.

Tabela Resumo (ver documento word):
Característica	if/elseif/else	switch case
Tipo de comparação	Qualquer expressão lógica	Comparação direta com valores inteiros, chars ou enums
Casos de uso	Condições complexas e intervalos	Comparação simples com muitos valores exatos (opções limitadas)
Flexibilidade	Muito flexível	Limitado a valores constantes inteiros/char/enum
Performance	Mais lento para grandes cadeias de comparação	Mais rápido com valores inteiros constantes (pode usar tabelas de saltos)
Tipos suportados	Qualquer tipo de expressão booleana	Inteiros, caracteres e enums
Para o teu caso específico no exercício do "Harl filter", o uso de switch é recomendado porque tens um número fixo e limitado de níveis de log (como DEBUG, INFO, etc.), 
e todos esses níveis podem ser comparados diretamente com seus primeiros caracteres.
*/


/*
Explicação detalhada:
Includes:

#include "Harl.hpp": Inclui o cabeçalho da classe Harl que contém a lógica das reclamações.
#include <iostream>: Necessário para a manipulação de entrada/saída (exibição de mensagens no terminal).
Função usage:

void usage(void): Esta função apenas exibe uma mensagem indicando o uso correto do programa. Se o usuário não fornecer o nível correto, 
a função será chamada para explicar como usar o programa.
Função harlFilter:

O argumento é uma string que contém o nível de log fornecido pelo user.
Primeiro, verificamos se o nível fornecido é válido (isto é, um dos quatro níveis: DEBUG, INFO, WARNING, ou ERROR).
Se for inválido, exibe-se uma mensagem de "problema insignificante".
O switch baseia-se no primeiro caractere do nível (por exemplo, 'D' para DEBUG, 'I' para INFO), e não interrompe 
imediatamente após o primeiro caso. Isso garante que todas as mensagens para níveis superiores também sejam exibidas.
Cada case exibe o nível correspondente e chama o método complain da classe Harl, que trata da lógica para exibir as reclamações.
Função main:

O main começa verificando se foi passado exatamente um argumento além do nome do programa. Se não, chama a função usage e termina com código de erro 1.
Se o argumento estiver correto, a função harlFilter é chamada, passando o nível fornecido como argumento.
*/

#include "Harl.hpp"

void usage(void)
{
    std::cout << "\nUsage: ./harlFilter [DEBUG|INFO|WARNING|ERROR]\n" << std::endl;
}

void harlFilter(std::string level)
{
    // Função principal que decide quais níveis de log exibir
    Harl harl;

    // Verifica se o nível fornecido é inválido
    if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n" << std::endl;
        return;
    }

    // Usa switch para filtrar e exibir as mensagens a partir do nível fornecido
    switch (level[0]) // O switch é baseado no primeiro caractere do nível. 
    {
        case 'D': // Se o nível for "DEBUG"
            std::cout << "[ DEBUG ]\n";
            harl.complain("DEBUG"); // Chama o método que lida com este nível
            break;// Sem break; a execução continua para o próximo nível (ou seja, fall-through)
        case 'I': // Se o nível for "INFO"
            std::cout << "[ INFO ]\n";
            harl.complain("INFO"); // Exibe mensagens de INFO e níveis superiores
            break;
        case 'W': // Se o nível for "WARNING"
            std::cout << "[ WARNING ]\n";
            harl.complain("WARNING"); // Exibe mensagens de WARNING e superiores
            break;
        case 'E': // Se o nível for "ERROR"
            std::cout << "[ ERROR ]\n";
            harl.complain("ERROR"); // Exibe mensagens de ERROR
            break; // Aqui paramos, pois ERROR é o último nível
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        usage();
        return (1);
    }

    // Chama a função principal, passando o nível fornecido pelo usuário
    harlFilter(argv[1]);

    return (0);
}
