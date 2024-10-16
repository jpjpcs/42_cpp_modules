/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:25 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/11 01:09:29 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Pontos 1, 2, 3 e 4 descritos no Fixed.cpp do CPP02ex00

// +++++++---------------------CPP02ex00 cima / CPP02ex01 baixo ----------------------------++++++

/*   
5. Conversão de Floating-Point para Fixed-Point (e vice-versa)
    O conceito de fixed-point implica que parte dos bits é usada para representar a 
    parte fracionária de um número. No caso do exercício, o valor das 
    "fractional bits" é 8, o que significa que os últimos 8 bits representam a fração.
    
    5.1. - Conversão de Floating-Point para Fixed-Point: Para converter um número float em um valor fixed-point:
    Multiplica-se o número float por 2^8 (256), deslocando a vírgula para a direita, 
    armazenando assim tanto a parte inteira quanto a parte fracionária nos bits.
    _fixedPointValue = roundf(value * (1 << _fractionalBits));
    em que:
    . roundf arredonda o valor float para garantir precisão.
    . (1 << 8) é equivalente a 256, que é o fator de escala.

    5.2. - Conversão de Fixed-Point para Floating-Point: Para converter um número fixed-point de volta para float:
    . Divide-se o valor em fixed-point por 2^8 (256), devolvendo a vírgula ao seu lugar original.
    return (float)_fixedPointValue / (1 << _fractionalBits);
    . A operação divide os bits representando o número por 256, restaurando a parte fracionária ao seu valor original.

    5.3. - BITWISE << e >>
        << - deslocamento de Bits para a esquerda
        >> - deslocamento de Bits para a direita
        Resumo:
        int to fixed point: _fixedPointValue = value << _fractionalBits; // Desloca os bits para a esquerda
        fixed point to int: return (_fixedPointValue >> _fractionalBits); // Desloca os bits para a direita
        float to fixed point: _fixedPointValue = roundf(value * (1 << _fractionalBits)) // Desloca os bits para a esquerda
        fixed point to float: return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits)) // Desloca os bits para a direita

        Explicação detalhada:
            5.3.1. int to fixed point: _fixedPointValue = value << _fractionalBits; // Desloca os bits para a esquerda
            Aqui está a operação:
            - << é o operador de deslocamento de bits à esquerda (bitwise left shift).
                - O que faz o deslocamento de bits à esquerda? O operador << desloca 
                    os bits para a esquerda, o que é equivalente a multiplicar o valor 
                    por uma potência de 2. Neste caso, value é multiplicado por 2^_fractionalBits.
                    - Exemplo: Se value for 10 e _fractionalBits for 8:
                        10 << 8 = 10 × 2^8 = 10 × 256 = 2560
                - Interpretação: Isto está a converter um número inteiro value 
                    para um valor de ponto fixo, multiplicando-o por 2^_fractionalBits 
                    para representar a parte fracionária no formato de ponto fixo.

            5.3.2. fixed point to int: return (_fixedPointValue >> _fractionalBits); // Desloca os bits para a direita
            - Deslocamento de Bits à Direita:
                - O operador >> desloca os bits de um número para a direita por um número específico 
                de posições, o que é equivalente a dividir o número por uma 
                potência de 2 e descartar a parte fracionária.
            - Em detalhes:
            - _fixedPointValue é o valor que está armazenado no formato de ponto fixo.
            - _fractionalBits indica o número de bits que representam a parte fracionária.
            - _fixedPointValue >> _fractionalBits desloca os bits de _fixedPointValue para a 
            direita por _fractionalBits posições, o que corresponde a dividir _fixedPointValue por 2^_fractionalBits.
            -   Exemplo:
                - Se _fractionalBits for 8, e o valor de _fixedPointValue for, por exemplo, 51200 (em ponto fixo), então:
                51200 >> 8 = 51200/2^8 = 51200/256 = 200
                - Neste caso, estás a remover a parte fracionária e a converter o valor de volta para a parte inteira correspondente.
            - Aplicação:
                - Este código é frequentemente usado para converter um valor de ponto fixo para um inteiro. 
                O deslocamento para a direita elimina a parte fracionária do valor, deixando apenas a parte inteira.
                - Portanto, _fixedPointValue >> _fractionalBits divide o valor de ponto fixo pela potência de 2 correspondente 
                ao número de bits fracionários, convertendo-o assim para o seu equivalente inteiro.
            5.3.3. float to fixed point: _fixedPointValue = roundf(value * (1 << _fractionalBits)) // Desloca os bits para a esquerda
                5.3.3.1. - Resumindo: Esta linha de código converte um número em ponto flutuante (value) para uma representação de ponto fixo, 
                    multiplicando-o por uma potência de 2 para "escalar" a parte fracionária e, em seguida, arredondando o resultado 
                    para armazenar o valor como um número inteiro.
                5.3.3.2. - Explicação detalhada:
                5.3.3.2.1. - (1 << _fractionalBits): 
                    Este é um deslocamento de bits para a esquerda, equivalente a multiplicar o número 1 por uma potência de 2. 
                    Ou seja, 1 << _fractionalBits multiplica o valor de 1 por 2^_fractionalBits. Se _fractionalBits for 8, o resultado será 256.
                5.3.3.2.2. - value * (1 << _fractionalBits): 
                    Aqui, o valor value (um número em ponto flutuante) é multiplicado por 256 
                    (ou por outra potência de 2 dependendo do valor de _fractionalBits). Isto transforma o número em ponto flutuante numa 
                    representação de ponto fixo, ampliando a parte fracionária.
                5.3.3.2.3. - roundf(...): 
                    A função roundf arredonda o resultado da multiplicação para o inteiro mais próximo. 
                    Isto é necessário porque o valor de ponto fixo (_fixedPointValue) é armazenado como um inteiro, 
                    então arredondar evita perder precisão quando a parte fracionária é convertida.
                5.3.3.2.4. - Atribuição a _fixedPointValue: 
                    O valor arredondado é então armazenado na variável _fixedPointValue, 
                    que é um número inteiro representando a versão em ponto fixo do número original.
            5.3.4. - fixed point to float: return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits)) // Desloca os bits para a direita
                5.3.4.1. - Resumindo: Esta linha de código converte um valor de ponto fixo para um número em ponto flutuante, 
                dividindo o valor de ponto fixo por uma potência de 2 para restaurar a parte fracionária e, em seguida, 
                convertendo o resultado para um float. Isso reverte o processo de conversão do ponto flutuante para ponto fixo, 
                "recuperando" a precisão.
                5.3.4.2. - Explicação detalhada:
                5.3.4.2.1. - static_cast<float>(_fixedPointValue): 
                    Conversão explícita para float: O valor de _fixedPointValue 
                    é originalmente armazenado como um número inteiro, mas como queremos devolver o valor na forma de float, 
                    o static_cast é usado para converter esse valor inteiro para um número em ponto flutuante. Isso permite 
                    manipular o número com precisão decimal, necessária para representar o valor fracionário de volta.
                5.3.4.2.2. - (1 << _fractionalBits):
                    Deslocamento de bits para a esquerda: Como no ponto 8.3.2.1, 1 << _fractionalBits multiplica 
                    o número 1 por uma potência de 2. Se _fractionalBits for 8, o resultado será 256.
                    Este valor representa o "escalamento" aplicado ao valor original durante a 
                    conversão de float para ponto fixo, que ampliou a parte fracionária. 
                    Agora, temos que desfazer essa ampliação para restaurar o valor original.
                5.3.4.2.3. - _fixedPointValue / (1 << _fractionalBits):
                    Divisão para restaurar a precisão: Agora que _fixedPointValue foi "ampliado" durante a 
                    conversão para ponto fixo (multiplicado por uma potência de 2), precisamos dividir o 
                    valor por essa mesma potência para desfazer esse efeito. 
                    Ou seja, ao dividir _fixedPointValue por 256 (ou outra potência de 2, dependendo de _fractionalBits), 
                    restauramos a parte fracionária que foi "comprimida" durante a conversão de float para ponto fixo.
                5.3.4.2.4. - Retorno do valor convertido para float:
                    Resultado: O valor resultante da divisão é um número em ponto flutuante que representa o 
                    valor original antes de ser convertido para ponto fixo. Esta é a reversão do processo 
                    descrito no ponto 8.3, onde o número foi transformado em ponto fixo para armazenamento.
                5.3.4.2.5. - Resumo Final:
                    A expressão completa converte o valor armazenado como ponto fixo de volta para um número de ponto flutuante, 
                    dividindo o valor inteiro armazenado por uma potência de 2 e restaurando a precisão decimal. 
                    O static_cast<float> assegura que o resultado da divisão seja devolvido como um 
                    número de ponto flutuante e não como um inteiro.    
    5.4. DESLOCAR OS BITS PARA A DIREITA É EQUIVALENTE A MOVER A VÍRGULA PARA A ESQUERDA e VICE-VERSA
        5.4.1. - Deslocar os bits para a direita com o operador >> é 
        equivalente a mover a vírgula para a esquerda numa representação numérica, 
        o que corresponde a dividir o valor por uma potência de 2.
        5.4.2. - Aqui está o raciocínio:
            O operador >> desloca os bits para a direita, removendo os bits menos significativos 
            (os da parte fracionária em números de ponto fixo).
            Isto é o mesmo que dividir o valor por 2 elevado ao número de posições deslocadas, 
            ou seja, dividir por uma potência de 2.
            Portanto, deslocar os bits à direita é como mover a vírgula para a esquerda, 
            porque estás a reduzir o valor ao eliminar os bits de menor significância, 
            equivalentes à parte fracionária no contexto de números de ponto fixo.
        5.4.3. -Em contraste, deslocar os bits à esquerda (com o operador <<) move a vírgula para a direita, 
            multiplicando o valor por uma potência de 2.
*/

/* 
6 - Construtor Parametrizado de Float e FUNÇÃO toFloat
    6.1. - Por que usamos roundf no Construtor de Float?
        Fixed::Fixed(const float value)
        {
            _fixedPointValue = roundf(value * (1 << _fractionalBits)); // Converte para ponto fixo
        }
        Motivos para usar roundf:
        - Precisão: A função roundf arredonda o valor float para o inteiro mais próximo,
        garantindo que a conversão de ponto fixo para ponto flutuante seja precisa.
        - Evitar truncagem: A divisão de dois inteiros resulta num inteiro,
        o que pode levar à truncagem da parte fracionária. O roundf evita esse problema,
        garantindo que a parte fracionária seja corretamente arredondada.
        - Consistência: O uso de roundf torna o código mais consistente e legível,
        indicando claramente a intenção de arredondar o valor float.

    6.2. - Por que usamos static_cast na função toFloat?
        float Fixed::toFloat(void) const
        {
            return (static_cast<float>(_value) / (1 << _bits)); // Converte para float
        }
        Motivos para usar static_cast:
        - Conversão segura: O static_cast é uma maneira segura de realizar conversões entre tipos em C++. 
        Ele assegura que a conversão é válida em tempo de compilação e evita possíveis problemas de perda 
        de dados que poderiam ocorrer com um cast mais genérico (como um C-style cast).
        - Precisão: A variável _value é tipicamente um tipo inteiro (como int ou long), e quando a divisão é feita, 
        se ambos os operandos são inteiros, o resultado também será um inteiro. 
        Isso levaria à truncação da parte fracionária. Ao fazer static_cast<float>(_value), 
        estamos convertendo _value para um float, garantindo que a divisão resultante preserve a parte fracionária.
        - Clareza: Usar static_cast torna o código mais legível e explícito sobre a intenção do programador, 
        que é converter um valor inteiro para um valor de ponto flutuante antes da operação.
    6.3. O que quer dizer o float fixed no float Fixed::toFloat(void) const
        O float na função float Fixed::toFloat(void) const indica o tipo de retorno da função, 
        ou seja, o valor que esta função vai devolver. Neste caso, a função toFloat() 
        converte o valor de ponto fixo armazenado na classe para um número em ponto flutuante (float) 
        e o devolve como o resultado da função.
            Aqui está uma explicação mais detalhada dos componentes da assinatura:
                . float (antes do nome da função): Especifica que o tipo de retorno da função é um número em ponto flutuante de precisão simples. 
                Isso significa que, ao chamar esta função, espera-se receber um valor do tipo float.
                . Fixed::toFloat: Indica que esta função é membro da classe Fixed.
                . (void): Indica que a função não aceita nenhum parâmetro de entrada.
                . const: Declara que esta função não altera nenhum dos atributos da instância da classe. 
                Isso significa que a função toFloat() pode ser chamada em objetos constantes da classe Fixed.
                . Portanto, a função toFloat() é usada para converter o valor armazenado em ponto fixo (_fixedPointValue) 
                de volta para um valor de ponto flutuante, e o float especifica que o resultado dessa conversão será do tipo float.
    6.4. A função toFloat onde é chamada? 
        É chamada na sobrecarga do operador de inserção <<.
        // Sobrecarga do operador de inserção
        std::ostream &operator<<(std::ostream &out, Fixed const &to_copy)
        {
            out << to_copy.toFloat(); // Insere a representação em float
            return out;
        }
        Uso da função toFloat:
            A chamada to_copy.toFloat() está sendo usada na linha onde diz out << to_copy.toFloat();.
            Essa linha converte o objeto Fixed em um valor de ponto flutuante (float) 
            usando a função toFloat, permitindo que o valor do objeto Fixed seja inserido 
            no fluxo de saída (por exemplo, em um std::cout).
        - Contexto: O operador de inserção << é sobrecarregado para permitir a 
        impressão de objetos Fixed diretamente em fluxos de saída, como std::cout. 
        A chamada a to_copy.toFloat() fornece a representação em ponto flutuante do 
        valor armazenado no objeto Fixed, que é então formatado e enviado para o fluxo de saída.
        - Resumo:
        static_cast: Usado para garantir uma conversão segura 
        de um tipo inteiro para float, evitando a truncagem de valores.
        to_copy.toFloat(): Utilizado na sobrecarga do operador de inserção 
        para obter o valor em ponto flutuante do objeto Fixed, 
        permitindo sua impressão em um fluxo de saída.
*/

//+++++********************** OPERADOR de INSERÇÃO << *****************************+++++
/*
7. Operador de Inserção
7.1. - MAS E ONDE ESTÁ A SER CHAMADO o OPERADOR DE INSERÇÃO <<?
    A função de sobrecarga do operador de inserção operator<< 
    está a ser chamada nas seguintes linhas do main.cpp, 
    cada vez que um objeto da classe Fixed é passado para o std::cout:
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    Essas linhas de código imprimem os valores dos objetos a, b, c, e d. 
    Quando o std::cout encontra um objeto do tipo Fixed (neste caso, as variáveis a, b, c, e d), 
    ele invoca automaticamente a sobrecarga do operador operator<< que definimos. 
    Isso faz com que a função seja chamada, convertendo o valor de ponto fixo 
    armazenado no objeto para float através da função toFloat() 
    e, em seguida, imprimindo esse valor flutuante no terminal.

    Exemplo de uma chamada:
    std::cout << "a is " << a << std::endl;
    Aqui, o std::cout << "a is " imprime a string "a is ", e quando o compilador encontra << a, ele chama a função sobrecarregada operator<< que implementámos, que, por sua vez, chama a função toFloat() no objeto a. O resultado em float é então inserido no fluxo de saída, completando a impressão.

    Fluxo detalhado:
    std::cout << a; é chamado.
    O compilador procura uma sobrecarga de operator<< que aceite um objeto do tipo Fixed.
    A função de sobrecarga operator<<(std::ostream &out, Fixed const &to_copy) é invocada.
    Dentro da função, to_copy.toFloat() é chamado para converter o valor do objeto Fixed para float.
    O valor em float é então inserido no fluxo de saída (representado pelo out).
    O resultado é exibido no terminal.
*/

//+++++**********************SOBRECARGA DE OPERADOR de INSERÇÃO << *****************************+++++
/*
7.2. - MAS PORQUE RAZÃO O COMPILADOR PROCURA UMA SOBRECARGA DE OPERADOR <<?
    O compilador procura uma sobrecarga do operador << porque 
    essa é uma característica da sintaxe padrão do C++. 
    A razão principal para isso está ligada à forma como o C++ foi projetado 
    para ser uma linguagem flexível e extensível, 
    permitindo que programadores personalizem o comportamento de operadores 
    para tipos de dados definidos pelo usuário (como classes e structs).

    Vamos explorar com maior detalhe:
        7.2.1. Uso intuitivo com tipos definidos pelo programador:
            No C++, o operador << (chamado de operador de inserção) já está 
            sobrecarregado para tipos primitivos como int, float, char, entre outros. 
            Por exemplo, quando fazemos algo como std::cout << 42;, 
            o operador << já sabe como lidar com inteiros. 
            No entanto, quando usamos o std::cout com um tipo de dado definido pelo user, 
            como uma classe (Fixed, neste caso), o compilador não sabe como imprimir 
            automaticamente um objeto dessa classe, a menos que lhe ensines.
            Por isso, o C++ permite sobrecarga de operadores: 
            para que possamos definir como o teu tipo específico deve ser impresso. 
            Ao sobrecarregar o operador <<, estamos a definir como o nosso objeto da 
            classe Fixed deve ser convertido para uma string que possa ser impressa. 
            Esta sobrecarga torna o código mais legível e intuitivo.
        7.2.2. Integração com o fluxo de saída (ostream):
            O operador << é uma maneira elegante de combinar o nosso objeto 
            com o sistema de fluxo de saída (ostream). 
            O std::ostream (e.g., std::cout) já está projetado para funcionar 
            com o operador << e suporta encadeamento de operações de saída, como:
            std::cout << "O valor de a é " << a << " e o valor de b é " << b << std::endl;
            Este comportamento de encadeamento é possível porque o operador << retorna 
            uma referência ao próprio fluxo de saída (std::ostream), 
            permitindo que outras inserções sejam feitas em sequência. 
            Se tivessemos que escrever uma função de impressão separada, 
            este tipo de fluência no código seria perdido.
        7.2.3. Razão para ser assim: Consistência e extensibilidade:
            O C++ foi projetado para fornecer uma interface consistente 
            para operações de entrada e saída. 
            Com tipos primitivos como int e float, os operadores << e >> (para entrada e saída) 
            já são usados de forma intuitiva. Ao permitir que esses operadores sejam sobrecarregados 
            para classes, o C++ estende essa mesma interface de forma coerente para 
            tipos de dados definidos pelo programador.
            - Consistência: Mantém a consistência com a sintaxe já utilizada para tipos primitivos.
            - Extensibilidade: Permite-te definir o comportamento desejado para qualquer tipo de objeto que crias, integrando-o de forma natural ao sistema de I/O do C++.

        ++++++++++++++++************ MUITO IMPORTANTE:*******************+++++++++++++++++
        7.2.4. Como o processo funciona:
            Quando o compilador encontra uma expressão como:
            std::cout << a;
            Se a for um tipo primitivo como int ou float, o operador << já sabe como manipulá-lo. 
            Mas se a for do tipo Fixed (um tipo definido pelo utilizador), o compilador vai procurar 
            uma função operator<< que aceite um std::ostream e um Fixed como parâmetros. 
            Se não houver essa função, o compilador emitirá um erro. 
            Ao fornecer a sobrecarga:
            std::ostream &operator<<(std::ostream &out, Fixed const &to_copy)
            {
                out << to_copy.toFloat(); // Converte e insere o valor em float
                return out;
            }
            Estamos a definir o comportamento de como o objeto Fixed será 
            representado quando inserido no fluxo de saída.

            VANTAGENS desta abordagem:
            - Simplicidade e Legibilidade: Usar std::cout << a; é mais simples e direto 
            do que escrever uma função de impressão separada como a.print().
            - Integração Natural com I/O: A sobrecarga do operador permite que o teu 
            tipo funcione naturalmente com o sistema de entrada e saída do C++, 
            sem ter que reinventar o processo.
            - Encadeamento de operações: Ao retornar uma referência ao std::ostream, 
            o operador << sobrecarregado permite encadear várias operações de inserção 
            numa única linha de código, como std::cout << a << b << c;.
            - Em resumo:
            O compilador procura uma sobrecarga do operador << porque faz parte da sintaxe 
            e filosofia do C++. 
            Ao sobrecarregarmos este operador para os teus tipos de dados, 
            estamos a permitir que os nossos objetos sejam impressos de forma intuitiva, 
            tal como os tipos primitivos.
            ++++++++++++++++************ MUITO IMPORTANTE:*******************+++++++++++++++++
*/

/*
7.3. - E PORQUE RAZÃO A SOBRECARGA ESTÁ FORA DA CLASSE?
    A razão pela qual a sobrecarga do operador << está fora da classe 
    está ligada ao conceito de funções globais e à forma como 
    o operador << precisa interagir com dois tipos de objetos: 
    um fluxo de saída (std::ostream) e o objeto da classe (Fixed). 
    Vamos explorar detalhadamente por que isto é necessário:
        7.3.1. Operador << precisa ser uma função não-membro:
            O operador << é um operador binário que opera em dois operandos:
            O primeiro operando é o fluxo de saída (std::ostream &), 
            como std::cout.
            O segundo operando é o objeto que está a ser inserido, 
            neste caso, uma instância da classe Fixed.
            Se o operador << fosse definido dentro da classe Fixed, 
            ele teria acesso ao segundo operando (o objeto Fixed), 
            mas não teria acesso direto ao primeiro operando (o std::ostream). 
            A sobrecarga do operador de inserção tem de ser capaz de interagir 
            tanto com o objeto de fluxo quanto com o objeto da classe.
            Exemplo:
            std::ostream &operator<<(std::ostream &out, Fixed const &to_copy);
            Aqui, o out é o fluxo de saída (como std::cout), e o to_copy é o objeto Fixed. 
            Ao definir esta função fora da classe, consegues lidar com ambos 
            os tipos de parâmetros, tornando a função mais geral.
        7.3.2. Operador << como uma função global (não-membro):
            Ao definir a sobrecarga do operador << fora da classe, estamos a torná-la 
            uma função global, o que significa que ela não faz parte diretamente da 
            classe Fixed, mas pode aceder aos seus membros públicos. 
            Além disso, como o std::ostream pertence à biblioteca std, 
            a função não pode ser definida dentro da classe Fixed, 
            porque isso implicaria que o operador deveria ser um método de membro da 
            classe std::ostream, o que não é permitido ou possível, 
            uma vez que não podemos modificar classes da biblioteca padrão C++.
        7.3.3. Integração fluente com o sistema de fluxos de saída:
            Ao manter a sobrecarga do operador << como uma função externa à classe, 
            estás a seguir o padrão utilizado pelo C++ para garantir que o operador 
            pode ser usado de forma fluente com objetos de qualquer classe, como std::cout. 
            Por exemplo:
            std::cout << "O valor de a é: " << a << std::endl;
            Aqui, a é um objeto da classe Fixed, e o operador << que escrevemos 
            permite que este objeto seja corretamente convertido e exibido como um 
            valor no fluxo de saída. 
            O operador << funciona da mesma forma que para os tipos primitivos, 
            como int e float, mantendo a consistência da sintaxe C++.
        7.3.4. Vantagens de ser uma função global:
            Flexibilidade: O operador pode ser utilizado por qualquer 
            fluxo de saída (std::cout, std::ofstream, etc.) para qualquer instância de Fixed. 
            Definir o operador fora da classe permite que ele seja reutilizado de maneira flexível.
            Consistência: Segue o padrão de sobrecarga de operadores já implementado na 
            biblioteca C++ para tipos nativos.
            Encadeamento de operações: A função devolve uma referência ao fluxo de saída, 
            permitindo o encadeamento de múltiplas operações de inserção, como std::cout << a << b << c;.
        7.3.5. Por que não fazer dentro da classe?
            Se a sobrecarga fosse definida dentro da classe Fixed, o primeiro operando (std::ostream) 
            não seria automaticamente acessível. Além disso, a função não teria a generalidade necessária 
            para funcionar com qualquer tipo de fluxo de saída, 
            limitando o seu uso a instâncias específicas da classe Fixed.
            Exemplo de Sobrecarga Fora da Classe:
            std::ostream &operator<<(std::ostream &out, Fixed const &to_copy)
            {
                out << to_copy.toFloat(); // Converte e insere a representação em float
                return out;
            }
            Aqui, o fluxo de saída out é o primeiro operando, e to_copy (um Fixed) é o segundo. 
            Este operador permite imprimir objetos Fixed diretamente para qualquer fluxo de saída.

- Resumo:
O operador << está fora da classe Fixed porque precisa de acesso ao tipo std::ostream, 
que não pertence à classe Fixed.
Definir a sobrecarga do operador como uma função global permite a 
interação entre o fluxo de saída e o objeto da classe.
Mantém a consistência da linguagem C++ e permite o uso fluente do operador de inserção 
para objetos da classe Fixed, tal como para tipos primitivos.
Desta forma, garantimos que a função é flexível, reutilizável e segue o 
padrão idiomático da linguagem C++.
*/

#include "Fixed.hpp"
//++++++++++++*********** CONTRUTORES E DESTRUTOR ***********++++++++++++

// Construtor padrão inicializa o valor como 0
Fixed::Fixed() : _fixedPointValue(0) // ou this->_fixedPointValue = 0;
{
    std::cout << "Default constructor called" << std::endl;
}

// Construtor que converte de inteiro para ponto fixo
Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits; // << é o operador de deslocamento de bits à esquerda (bitwise left shift). Converte para o formato de ponto fixo, deslocando a vírgula para a direita através de uma multiplicação por 2^8 (256). Ver mais info no ponto 5 dos comments acima.
}

// Construtor que converte de float para ponto fixo
Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits)); // 1 << _fractionalBits: Este é o operador de deslocamento de bits à esquerda (bitwise left shift). Converte e arredonda para o formato de ponto fixo, deslocando a vírgula para a direita através da multiplicação por 2^8 (256). Ver mais info no ponto 5 e 6 dos comments acima.
}

// Construtor de cópia
Fixed::Fixed(Fixed const &to_copy)
{
    std::cout << "copy constructor called" << std::endl;
    *this = to_copy; // Copia indiretamente chamando o operador de atribuição. Diretamente seria this->_fixedPointValue = to_copy.getRawBits(); Ver mais info no ponto 1 do Fixed.cpp CPP02ex01.  
}

// Destrutor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

//++++++++++++++*************** OPERADORES ARITMÉTICOS SOBRECARREGADOS ***************++++++++++++++
// Operador de atribuição de cópia sobrecarregado
Fixed &Fixed::operator=(Fixed const &to_copy)
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &to_copy) // Verifica se não há auto-atribuição
        _fixedPointValue = to_copy._fixedPointValue; // _fixedPointValue = to_copy._fixedPointValue; mais direto ou this->_fixedPointValue = to_copy.getRawBits(); mais indireto, mas opcional(indica q nos referimos a um membro da classe). Ou seja, a diferença reside na forma de acesso ao valor do atributo, mas ambos copiam o valor. Ver mais info pontos 3 (3.4. sobre to_copy) dos comments do CPP02ex00.
    return *this; // Retorna o valor copiado como referência para o objeto atual (this) que recebe os dados e é modificado.
}

//++++++++++++++*************** CONVERTORES ***************++++++++++++++
// Converte o valor fixo para float
float Fixed::toFloat(void) const
{
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits)); // 1 << _fractionalBits: Este é o operador de deslocamento de bits à esquerda (bitwise left shift). Converte para float dividindo por 2^8 (256). Ou seja, restaura a parte fracionária, deslocando a vírgula para a direita. Ver mais info no ponto 5 e 6 dos comments acima.
}

// Converte o valor fixo para inteiro
int Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits); // ou return (this->_fixedPointValue >> Fixed::_fractionalBits); >> é o operador de deslocamento de bits à direita (bitwise right shift). Converte um fixed point para inteiro dividindo por 2^8 (256). Ou seja, remove a parte fracionária através de uma divisão inteira deslocando a vírgula para a esquerda. Ver mais info no ponto 5 dos comments acima.
}

//++++++++++++++*************** GETTERS & SETTERS ***************++++++++++++++
// Retorna o valor bruto do ponto fixo, mas não está a ser chamada nem no main.cpp nem no operador de atribuição sobrecarregado (uma vez que estou a copiar o valor diretamente e não através de um getter). Mais info no ponto 3 do Fixed.cpp CPP02ex00: atribuição direta vs indireta usando um getter.
int Fixed::getRawBits(void) const // Aqui é const pq não queremos modificar o valor do objeto, apenas queremos acessá-lo e retorná-lo.
{
    std::cout << "getRawBits member function called" << std::endl; // Esta msg nunca é impressa pq o getter nunca é chamado nem no main nem no operador de atribuição sobrecarregado.
    return this->_fixedPointValue;
}

// Define o valor bruto do ponto fixo
void Fixed::setRawBits(int const raw) // Aqui é const pq não queremos modificar o valor do objeto, apenas queremos acessá-lo e retorná-lo.
{
    std::cout << "setRawBits member function called" << std::endl; // Continua a não ser chamado no main.cpp, logo nunca é impresso no terminal. mais info no ponto 6 do Fixed.hpp do CPP02ex00.
    this->_fixedPointValue = raw; // Define o valor bruto do ponto fixo como o valor passado como argumento para a função no momento da chamada no main.cpp
}

//++++++++++++++*************** OPERADOR INSERÇÃO ***************++++++++++++++
// Sobrecarga do operador de inserção
// Neste caso std::cout << "a is " << a << std::endl; 
// recebe à esquerda o std::cout e à direita o objeto da classe Fixed que é o a. 
// O "a is " é apenas uma string passada como argumento 
// para o std::cout e que serve para imprimir.
// Ver mais info no ponto 7 dos comments do Fixed.cpp CPP02ex01.
std::ostream &operator<<(std::ostream &out, Fixed const &to_copy)
{
    out << to_copy.toFloat(); // Insere a representação em float. << neste caso significa inserir o valor convertido para float no fluxo de saída (std::cout) e não deslocar a vírgula para a esquerda ou deslocar os bits para a direita. Ver mais info no ponto 5 e 7 dos comments do Fixed.cpp CPP02ex01.
    return out;
}