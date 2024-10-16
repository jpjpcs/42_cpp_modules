/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:34:15 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 16:19:04 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
CPP02ex00: 
Polimorfismo, Forma Ortodoxa Canónica, Construtor de Cópia, Operador de Atribuição de Cópia, 
Deep vs Shallow Copy, Operador de Atribuição Sobrecarregado, Auto-Atribuição, Fixed-point number class,
Floating vs Fixed Point Numbers, CONST no Getter, SetRawBits não utilizado, GetRawBits utilizado.

CPP02ex01: 
Construtores Parametrizados, Operador de Inserção Sobrecarregado, Conversões de int para fixed point e vice-versa,
Conversões de float para fixed point e vice-versa, Atribuição direta sem usar um getter no operador de atribuição.
Operador de atribuição - Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 7 do Fixed.cpp do CPP02ex01.

CPP02ex02: 
Operadores aritméticos (+, -, , /), 
Operadores de comparação (>, <, >=, <=, ==, !=), 
Operadores de incremento e decremento (++, --) e 
funções pré e pós fixadas Min e Max.

CPP02ex03: 
Fórmula de ShoeLace e verificação se ponto está dentro ou fora de triângulo.
/*

-----******________________________ex00_________________________________******-----
ex00:
1. Polimorfismo (function overload)
2. Orthodox Canonical Form 
3. Construtor de Cópia, 
    3.1. e 3.2. Operador de Atribuição de Cópia (copy assignment operator) & 
    3.3. Deep vs Shallow Copy (evitada por construtor cópia e operador atribuição) &
    3.4. Operador de Atribução de Cópia Sobrecarregado/Operator Overload ou Sobrecarga de Operador =),
4. Auto-Atribuição, 
5. Fixed-point number class & floating vs fixed point numbers (integers), 
6. CONST no Getter (static constant integer, getters /setters (member function int getRawBits(void) const
& Setter not used - member function void setRawBits(int const raw)

Pontos do word abordados:
    Módulo 2 - 19.11.29. Polymorphism 
    Módulo 2 - 19.11.29.2.1. Polimorfismo Ad-hoc
    Módulo 2 - 19.11.30. Canonical form / Regras dos 3 / Regra dos 5 ou Forma de Coplien/ Coplien form
    Módulo 2 - 19.11.31. Operadores e Construtores/Destrutores
    Módulo 2 - 19.11.31.1. Construtores e Destrutores versão 2.0 (a primeira é falada no modulo 0)
    Módulo 2 - 19.11.31.1.1. Tipos ---> Cópia 
    Módulo 0 - 19.11.8.	Construtores e Destrutores versão 1.0 (versão 2.0 abordada no módulo 2)
    Módulo 2 - 19.11.31.1.4. Construtor de Cópia (Copy Constructor)
    Módulo 2 - 19.11.31.1.4.1. Deep vs Shallow Copy 
    Módulo 2 - 19.11.31.1.6. Operador de Atribuição(=) vs Operador de Atribuição (=) Padrão vs Operador de Atribuição Sobrecarregado
    Módulo 2 - 19.11.32. Floating point numbers
    Módulo 2 - 19.11.33. Fixed point numbers
    Módulo 0 - 19.11.6.4. Constants 

Exercise 00: My First Class in Orthodox Canonical Form
Objective: Create a class in Orthodox Canonical Form that represents a fixed-point number.
Key Features:
Default constructor, copy constructor, copy assignment, destructor.
Private members: integer value, static constant for fractional bits.
Public members: getRawBits, setRawBits.
Follow Orthodox Canonical Form.
--------------------------------------------- 
Explicação Global:
Este exercício do Módulo 02 do CPP foca-se na criação de uma classe que 
representa um número de ponto fixo (fixed-point number), utilizando a 
forma canónica ortodoxa de C++. Isso significa que a classe deve implementar 
quatro funções obrigatórias: o construtor padrão, o construtor de cópia, 
o operador de atribuição de cópia e o destrutor. Além disso, a classe tem 
métodos para obter e definir o valor bruto do número de ponto fixo.

-----******________________________ex01_________________________________******-----
ex01: 
A par do resto já abordado no ex00, no ex01 também é abordado:
1. Construtores Parametrizados (int e float)     
2. Operador Inserção sobrecarregado (<<)  
3. Conversões de int para fixed point e vice-versa, e conversões de float para 
    fixed point e vice-versa. 
    Diferenças do ex00 para o ex01:
4 - No Operador de atribuição, estou a copiar o valor diretamente sem usar um getter.
    Logo, o getter não tem qualquer função no meu programa, uma vez que não é 
    chamado nem no main nem no operador de atribuição.
    As vantagens e desvantagens desta abordagem (direta vs indireta usando um getter) 
    são abordadas no ponto 12 dos comments do Fixed.cpp. 
* 1. Eles são chamados assim porque aceitam parâmetros (neste caso, um inteiro 
    e um float) que são usados para inicializar um objeto da classe Fixed. 
* 2. O operador de inserção sobrecarregado é usado para exibir o valor de um objeto 
    da classe Fixed. Ele é sobrecarregado para aceitar um objeto Fixed como argumento 
    e exibir o valor armazenado no formato de ponto fixo.

Pontos do word abordados:
    Módulo 2 - 19.11.31.1.1. Tipos ---> Parametrizado
    Módulo 2 - 19.11.31.2.2. Operador de Inserção
    Módulo 2 - 19.11.34. Fixed vs Floating Points Numbers / Aritmética ponto fixo vs flutuante?

-----******________________________ex02_________________________________******-----
ex02 -
A par do resto já abordado no ex00 e ex01, no ex02 também é abordado:
1. Operadores aritméticos (+, -, *, /).
2. Operadores de comparação (>, <, >=, <=, ==, !=).
3. Operadores de incremento e decremento (++, --).
4. Funções membro Min e Max.
Diferenças que mantive (vieram do ex00 para o ex01, e do ex01 para o ex02:
5 - No Operador de atribuição, estou a copiar o valor diretamente sem usar um getter.
    Logo, o getter não tem qualquer função no meu programa, uma vez que não é 
    chamado nem no main nem no operador de atribuição.
    As vantagens e desvantagens desta abordagem (direta vs indireta usando um getter) 
    são abordadas no ponto 12 dos comments do Fixed.cpp.
Outras diferenças:
6 - No ex02, são sobrecarregados operadores aritméticos e de comparação, bem como
    operadores de incremento e decremento.

Pontos do word abordados:
    Módulo 2 - 19.11.29.2.	Operadores
    Módulo 2 - 19.11.29.2.3.	Operadores aritméticos (+, -, , /)
    Módulo 2 - 19.11.29.2.4.	Operadores de comparação (>, <, >=, <=, ==, !=)
    Módulo 2 - 19.11.29.2.5.	Operadores de incremento e decremento (++, --)
    Módulo 2 - 19.11.30.	Funções membro min e max

Exercice 02: Fixed Point Number
Objective: Create a class that represents a fixed-point number.
Key Features:
Parametrized constructors (int and float).
Overloaded insertion operator (<<).
Conversion from int to fixed point and vice versa, and from float to fixed point and vice versa.
Arithmetic operators (+, -, *, /).
Comparison operators (>, <, >=, <=, ==, !=).
Increment and decrement operators (++, --).
Min and Max member functions.
---------------------------------------------
Explicação Global:
Este exercício do Módulo 02 do CPP foca-se na criação de uma classe que
representa um número de ponto fixo (fixed-point number), utilizando a
forma canónica ortodoxa de C++.
Neste exercício usamos construtores parametrizados para inicializar um
objeto da classe Fixed com um inteiro ou um float. Usamos conversões e
operadores de inserção. Além disso, sobrecarregamos operadores aritméticos
e de comparação, e implementamos operadores de incremento e decremento.

-----******________________________ex03_________________________________******-----
ex03 - A par do resto já abordado no ex00 e ex01 e ex02, neste ex03 é também abordado:
1 - Fórmula de Shoelace (ou Gauss) para calcular a área de um triângulo.
2 - A fórmula determinante 2D para calcular a área de um triângulo é:
Área = | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) | / 2
3 - Neste exercício teremos que verificar se o ponto está dentro do triângulo ou não.
Como? 
3.1. - Primeiro calculando a área do triângulo formado pelos três vértices originais A, B e C (o triângulo original).
3.2. - Depois calculando a área do triângulo formado pelos vértices A, B e o ponto a ser testado P.
3.3. - Depois calculando a área do triângulo formado pelos vértices B, C e P.
3.4. - Depois calculando a área do triângulo formado pelos vértices C, A e P.
3.5. - Por fim, verificando se a soma das áreas dos três pequenos triângulos (ABP, BCP e CAP) 
é igual à área do triângulo original (ABC).
3.6. - Se a soma das áreas dos três triângulos menores for igual à área do triângulo original, 
o ponto P estará dentro do triângulo.
3.7. - Se a soma das áreas for maior ou menor do que a área do triângulo original 
(dependendo de onde P está no plano), o ponto P estará fora do triângulo.

Pontos do word abordados:
    Os já abordados até agora. Neste exercício não abordamos pontos novos.

Exercice 03: Point Inside Triangle
Objective: Create a function that checks if a point is inside a triangle.
Key Features:
Shoelace formula to calculate the area of a triangle.
Determinant 2D formula to calculate the area of a triangle.
Check if a point is inside a triangle.
---------------------------------------------
Explicação Global: 
Este exercício do Módulo 02 do CPP foca-se na criação de uma 
função que verifica se um ponto está dentro de um triângulo, 
utilizando a fórmula de Shoelace (ou Gauss) para calcular a 
área de um triângulo e a fórmula determinante 2D 
para calcular a área de um triângulo.
*/

/*
Explicação Teórica dos Main Points: 
1 - Polimorfismo Ad-hoc (também chamado sobrecarga de função/FUNCTION OVERLOAD) é uma forma de polimorfismo onde a 
    escolha da função correta a ser chamada é baseada na assinatura da função (tipos e número de parâmetros) 
    e é resolvida em tempo de compilação. 
    - A SOBRECARGA DE FUNÇÕES É UM EXEMPLO CLÁSSICO deste tipo de polimorfismo. 
    Ele permite que várias funções compartilhem o mesmo nome, desde que tenham assinaturas diferentes, 
    facilitando a legibilidade e a organização do código.
    FUNCTION OVERLOAD: Dessa forma o polimorfismo ad-hoc também é conhecido como sobrecarga de função (function overload),
    e ocorre quando há múltiplas implementações de uma função ou operador, cada uma com diferentes 
    tipos de argumentos ou diferentes números de argumentos.
    Em linguagens que suportam sobrecarga de função, o compilador (ou interpretador) determina qual versão da função 
    chamar com base nos tipos ou na quantidade dos parâmetros fornecidos na chamada da função.

2 - Orthodox Canonical Form: A Orthodox Canonical Form é uma convenção de programação que define um conjunto de funções 
que devem ser implementadas em uma classe C++ para garantir que a classe seja usada de forma segura e eficiente:
    2.1 - Construtor Padrão: Inicializa o valor do ponto fixo para 0.
    2.2 - Construtor de Cópia: Cria uma nova instância copiando o valor de outra instância.
    2.3 - Operador de Atribuição de Cópia: Permite atribuir o valor de uma instância para outra.
    2.4 - Destrutor: Libera a memória alocada para o objeto.

3 - Construtor Padrão vs Construtor de cópia vs Construtor de ATRIBUIÇÃO de CÓPIA vs 
Operador de atribuição de cópia vs Operador de Atribuição de Cópia Sobrecarregado (Operator Overload):

    3.1. - Contrutor Padrão e Contrutor de cópia:
        
        No main, onde está:

        Fixed a;  // Criação de um objeto Fixed - Aqui é usado o construtor padrão
        Fixed b(a);  // Cópia de a para b - Aqui é usado o construtor de cópia
        Fixed c;  // Criação de outro objeto Fixed - Aqui é usado o construtor padrão

        Fixed::Fixed(const Fixed &copy): Cria uma nova instância copiando o valor de outra instância.

        
        Diferença prinicpal entre construtor de cópia vs Construtor de ATRIBUIÇÃO de CÓPIA 
        vs operador de atribuição de cópia vs Operador de Atribuição de Cópia Sobrecarregado (Operator Overload):
        Construtor de Cópia: Cria uma nova instância copiando o valor de outra instância.
        Operador de Atribuição de Cópia: Permite atribuir o valor de uma instância para outra.

    3.2. - Operador de Atribuição de Cópia
        
        No main, onde está:
        c = b;  // Atribuição de b para c - Aqui é usado o operador de atribuição de cópia 
        (no caso sobrecarregado com o operador de atribuição de cópia = . 
        E pqê sobrecarregado? 
        Pq estamos a atribuir o valor de um objeto a outro objeto da mesma classe.
        Caso não fosse sobrecaergado, não iria atribuir o valor de b a c. 
        Ao invés disso, iria atribuir o endereço de b a c. E isso não é o que queremos. 
        Queremos atribuir o valor de b a c.

    3.3. Operador de Atribuição de Cópia vs Operador de Atribuição Padrão 
    
        Referem-se ao mesmo conceito, mas em contextos diferentes:
        • Operador de Atribuição de Cópia: Atribui os valores de um objeto a outro já existente. 
            É o operador que permite atribuir um valor a um objeto. 
            Por exemplo, no código a = b;, o operador de atribuição (=) é utilizado para copiar o valor de b para a.
        • Operador de Atribuição de cópia Padrão: Refere-se ao operador de atribuição padrão que o compilador 
            gera automaticamente se não houver um definido pelo programador.
    
    3.4. Operador de Atribuição vs Atribuição Sobrecarregado: 
    
        3.4.1. - Fixed &operator=(const Fixed &copy);, temos um operador de atribuição sobrecarregado (que é o igual =)
        para a classe Fixed. Este operador é usado para atribuir o conteúdo de um objeto Fixed a outro. 
        
        - operator=: Este é o nome da função que sobrecarrega o operador de atribuição (=). 
        
        A sobrecarga do operador permite que se defina o que acontece quando um objeto Fixed é atribuído a outro.
        Operator Overload ou Sobrecarga do Operador de Atribuição de Cópia. 
        
       3.4.2. - E o que é isso de OPERATOR OVERLOADING? 
        
        É a capacidade de um operador, como +, -, *, /, =, etc.,
        ser usado com mais de um tipo de dados. Por exemplo, o operador + pode ser usado para adicionar
        dois números inteiros, dois números de ponto flutuante ou duas strings.
        Neste caso usamos o = para atribuir o valor de um objeto a outro objeto da mesma classe.
        - O operador de atribuição de cópia é um exemplo de sobrecarga de operador em C++.

        3.4.3. - Shallow vs Deep copy.
        
        O operador de atribuição sobrecarregado é, sim, responsável por 
        evitar a shallow copy e implementar uma deep copy, mas ele só entra em ação quando estamos a 
        lidar com a atribuição de um objeto já existente a outro (ex: obj1 = obj2;).
        No entanto, também existe o construtor de cópia, que é utilizado quando um novo objeto é criado 
        como cópia de outro (ex: Fixed obj1 = obj2; ou Fixed obj1(obj2);).
        Diferença:
        - Construtor de cópia: Evita shallow copy quando um novo objeto é criado com base em outro existente, 
        fazendo uma deep copy se necessário.
        - Operador de atribuição: Evita shallow copy quando um objeto já existente recebe valores de outro objeto, 
        implementando também uma deep copy se necessário.
        - Ambos devem ser implementados corretamente para evitar o problema de shallow copy. 
        - Se não forem sobrecarregados, tanto o construtor de cópia quanto o operador de atribuição usarão a 
        shallow copy fornecida pelo compilador por padrão.

        Definições: 
        • Shallow Copy (Cópia Superficial): A cópia superficial copia os valores dos membros 
            do objeto, incluindo os ponteiros, mas não copia os dados apontados pelos ponteiros. 
            Isso pode levar a problemas como ponteiros pendentes (dangling pointers) e 
            duplicação de liberações de memória. 
        • Deep copy - A cópia profunda cria uma cópia real dos dados apontados pelos ponteiros, 
            garantindo que o objeto copiado seja independente do original. 
        
        3.4.4. - Agora vamos ver o que está à esquerda e à direita 
        do símbolo de atribuição (=) e o que representa cada um.

        -  À esquerda do =: A função retorna uma referência para o próprio objeto (objeto atual) Fixed (this) 
        que recebe os dados e está a ser modificado (ou seja o objeto atual que está a receber a atribuição).
        O retorno por referência permite que o operador de atribuição seja encadeado (encadear atribuições), ou seja, 
        que possamos escrever expressões como a = b = c; e todas as variáveis sejam atualizadas corretamente. 
        Ao retornar uma referência, a função evita criar uma cópia adicional do objeto.

        - À direita do =: A função recebe uma referência constante para o objeto Fixed a ser copiado (copy), 
        que fornece os dados para a cópia (através do main). A referência constante evita a cópia desnecessária 
        do objeto.
        Usamos uma referência constante porque:
        Referência: Permite evitar a criação de uma cópia do objeto, melhorando a eficiência.
        Constante: Garante que o objeto passado como argumento não será modificado dentro da função.
        Como faz isso?
        A função verifica se o endereço do objeto atual é diferente do endereço do objeto a ser copiado.
        Se forem diferentes, copia o valor do objeto a ser copiado para o objeto atual.
        Se forem iguais, não faz nada, pois isso significa que o objeto está a ser atribuído a si mesmo.
        A isto chama-se auto-atribuição, e é algo que queremos evitar.

    ***----- Mais info no ponto 5 dos comments do ScavTrap.hpp do CPP03ex01. -----***
          
4 - Auto-Atribuição: Auto-atribuição é quando um objeto é atribuído a si mesmo. Ver mais info no Fixed.cpp.
                
5 - Fixed-Point Numbers: Números de ponto fixo são uma forma de representar números reais com uma parte inteira e uma parte fracionária fixa. 
    Por exemplo, 3.25 é um número de ponto fixo com 3 como parte inteira e 0.25 como parte fracionária. 
    Neste exercício, a classe Fixed representa um número de ponto fixo com 8 bits fracionários. 
    
    No nosso código temos:
    int _fixedPointValue; // Armazena o valor do ponto fixo. Corresponde à parte inteira do valor do ponto fixo.
    static const int _fractionalBits = 8; // Número de bits fracionários (sempre 8) 
    correspondentes à parte fracionária do valor do ponto fixo
    
    Essas duas variáveis fazem parte da implementação da classe de número de ponto fixo, 
    e têm funções distintas dentro da classe. Vou explicar detalhadamente cada uma delas:

    5.1. - int _fixedPointValue;
        Esta variável é um atributo privado da classe e serve para armazenar o valor real do número de ponto fixo.
        Ponto Fixo: Em vez de armazenar um número como um valor decimal (por exemplo, 3.14), ele é armazenado como um inteiro, 
        e a posição da fração é controlada por outra parte do código (neste caso, _fractionalBits). 
        O número inteiro contém a parte inteira e a parte fracionada combinadas num único valor.
        Exemplo: Se armazenamos 3.14 como um número de ponto fixo com 8 bits fracionários, podemos representá-lo como 
        um número inteiro (no caso, algo como 3.14 * 2^8 = 803). A classe trata de "interpretar" este número corretamente 
        quando precisas de converter de volta para um valor decimal.
        Portanto, _fixedPointValue é onde o número real (armazenado como inteiro) é mantido.

    5.2. - static const int _fractionalBits = 8;
        Este é um atributo constante e estático, o que significa que:
        - static: A variável pertence à classe e não a instâncias individuais da classe. Isto significa que 
        há apenas uma cópia de _fractionalBits para toda a classe, e todas as instâncias da classe partilham esse valor.
        - const: O valor é constante e não pode ser alterado durante a execução do programa.
        - 8: O valor desta variável indica que estamos a usar 8 bits da parte fracionária no número de ponto fixo.
        E o que são bits fracionários? São a parte fraccionária do número de ponto fixo.
        Números de ponto fixo utilizam uma parte do número para a parte inteira e outra parte para a parte fracionária. 
        Neste caso, como _fractionalBits = 8, isso significa que 8 bits (num total de 32 bits (4 bytes que é qt "ocupa" um int,
        por exemplo, se estás a usar int) são dedicados à parte fracionária. 
        Portanto, o número real armazenado em _fixedPointValue será interpretado como um número inteiro deslocado por 8 bits 
        para a esquerda, e a conversão de volta para decimal incluirá uma divisão ou multiplicação por 2^8.
        Exemplo: Se 3.14 fosse armazenado usando 8 bits para a fração, o valor interno seria algo como:
        803 = 3.14×256(onde 256 é 2^8) 
        Quando precisas de extrair o valor de volta para a sua forma decimal, divides por 2^8 (ou seja, 256), 
        o que resultaria em 3.14.

    Resumo:
    _fixedPointValue: É a variável que armazena o número de ponto fixo, representado como um inteiro.
    _fractionalBits: Define quantos bits são usados para a parte fracionária no número de ponto fixo (neste caso, 8 bits).
    Esses dois elementos juntos permitem representar números decimais com precisão controlada através da técnica de ponto fixo.
        
6 - Getters & Setters (not used):
    A função setRawBits só é chamada explicitamente se a invocarmos no código, tal como fazemos com a getRawbits. 
    Ela é responsável por definir o valor do atributo _fixedPointValue da classe Fixed. No exemplo de execução mostrado no main, 
    a função setRawBits não é chamada porque o código que executamos apenas utiliza o construtor padrão, o construtor de cópia,
    o operador de atribuição, e a função getRawBits.
    Embora a função setRawBits não seja usada diretamente no main.cpp, ela desempenha um papel importante no design de 
    classes com um número de ponto fixo (ou em outros tipos de classes que encapsulam dados). 
    O objetivo de incluir esta função é fornecer uma interface para definir o valor interno do objeto de forma controlada, 
    seguindo o princípio de encapsulamento.
    Aqui estão as principais razões para a existência de setRawBits na classe, mesmo que possa não ser usada imediatamente:
    6.1. - Encapsulamento:
        A função setRawBits permite controlar o acesso ao atributo privado _fixedPointValue. Isto é uma prática comum em programação 
        orientada a objetos para garantir que os dados internos não sejam acessados ou modificados diretamente por código externo. 
        Se não tivesses essa função, terias de expor o atributo _fixedPointValue, violando o encapsulamento.
    6.2. - Flexibilidade:
        A setRawBits permite que os valores internos de um objeto sejam alterados sem que o utilizador precise de mexer diretamente 
        nos membros privados da classe. Mesmo que não seja usada agora, ela torna o design da classe mais robusto e flexível para futuros usos, 
        onde poderias querer modificar o valor diretamente:
        a.setRawBits(100);
        Isto permite definir _fixedPointValue com um valor arbitrário. Em muitos casos, quando a classe começa a ser utilizada de formas 
        mais variadas, ter uma função de "set" é essencial.
    6.3. - Coerência com o Design Canónico:
        A implementação de funções getRawBits e setRawBits é uma parte fundamental do "canonical form" de classes, onde getter e setter 
        são métodos comuns para interagir com membros privados. Mesmo que não uses imediatamente setRawBits, a sua presença pode ser 
        requerida por convenção ou como uma boa prática de design.
    6.4. - Potencial para Expansão:
        Em futuras expansões da classe, podes precisar modificar _fixedPointValue diretamente, e ter setRawBits já implementada permite 
        uma adaptação mais fácil a novos requisitos. Por exemplo, podes querer calcular valores intermediários num processamento de 
        números de ponto fixo e, por isso, precisas de um setter para ajustar o valor.

    Resumindo este ponto:
    - Mesmo que setRawBits não seja chamada no exemplo atual, a sua inclusão é uma prática recomendada, especialmente para garantir 
    encapsulamento e flexibilidade no uso da classe. 
    - É um método "potencialmente necessário" para outras situações futuras, 
    onde modificar diretamente o valor _fixedPointValue de forma controlada pode ser útil.
    - E fixed point number é diferente de float, double, etc. porque float e double são tipos de ponto flutuante, ou seja, 
    eles armazenam números reais usando a representação de ponto flutuante (IEEE 754, por exemplo), sendo mais flexível e mais
    precisa e MENOS accurated do que um número de ponto fixo. Ou seja, pode representar uma ampla gama de valores com precisão, 
    mas a nível de accuracy o valor pode não ser exato /não ser bem o representado. Enquanto que um número de ponto fixo é
    mais limitado em termos de valores que pode representar sendo MENOS preciso, mas é MAIS accurated. Ou seja, 
    o valor representado é o valor real. Contudo, o valor não representará uma gama tão ampla de valores como um float ou double.
    Isto é, não será tão preciso. 
    Fixed point é mais rápido e mais eficiente do que ponto flutuante, mas menos preciso.
    Daí ser usado em aplicações onde a precisão NÃO é tão importante, mas a velocidade e eficiência são, tais como
    embedded systems/sistemas embarcados, jogos e aplicações de processamento digital de sinais (DSP) 
    onde o desempenho é crítico e o hardware é otimizado para operações inteiras.
    Os float são mais usados em aplicações onde a precisão é mais importante do que a velocidade. 
    Aplicações que requerem alta precisão e uma ampla gama de valores, como cálculos científicos,
    gráficos 3D, etc.
    Mais info no word na parte dos float e fixed-point numbers, abordados neste Módule 02 do CPP.
*/

/*
Explicação Funções:

1 - Construtor Padrão: Inicializa o valor do ponto fixo para 0.

2 - Construtor de Cópia: Cria uma nova instância copiando o valor de outra instância.
    Copy construtor and Operator Overloading - Copy assignment operator:
    2.1. -  Fixed(const Fixed &copy); // Copy constructor (deep copy):
    creates a new object with the same value as the original object. 
    Expects a reference to the object to be copied. 
    Returns a reference to the new object.
    
3 - Operador de Atribuição de Cópia / Operador de atribuição sobrecarregado : Permite atribuir o valor de uma instância para outra.
    3.1. - Fixed &operator=(const Fixed &copy); // Operator Overloading - Copy assignment operator (deep copy):
    assigns the value of the right-hand side object to the left-hand side object. 
    Expects a reference to the object to be copied. 
    Returns a reference to the left-hand side object.
    Fixed &operator=(const Fixed &copy); // 
    - À esquerda do operador de atribuição de cópia retorna uma referência ao objeto atual 
    (this) para permitir encadeamento de operadores.
    O this vem implícito, ou seja, não é necessário escrever this->, porque o operador de atribuição é um método 
    de membro da classe, e o this é um ponteiro para o objeto que invocou o método, ou seja, o objeto à 
    esquerda do operador de atribuição de cópia, que é o objeto atual (this). 
    - À direita do operador de atribuição de cópia, temos o objeto a ser copiado (copy), 
    que é passado por referência constante para evitar cópias desnecessárias. 
    Resumindo, o operador de atribuição de cópia retorna uma referência ao objeto à 
    esquerda do operador de atribuição de cópia (this) para permitir encadeamento de operadores.
    - O Fixed & é o tipo de retorno da função, que é uma referência ao objeto atual. 
    - O = é o operador de atribuição de cópia.
    - O const é para garantir que o objeto passado como argumento não seja modificado. 
    - O copy é o objeto a ser copiado, que é passado como argumento para a função no momento da chamada no main.cpp, 
    e é passado como uma referência constante para evitar cópias desnecessárias.
    - Existe uma verificação para evitar a auto-atribuição, ou seja, 
    se o endereço do objeto atual for igual ao endereço do objeto a ser copiado. 
    Mas ver mais info no Fixed.cpp.
    - Existe também um Operator Overload ou Sobrecarga do Operador de Atribuição de Cópia, ou seja, 
    e o que é isso de operator overloading? É a capacidade de um operador, como +, -, *, /, =, etc.,
    ser usado com mais de um tipo de dados. Por exemplo, o operador + pode ser usado para adicionar
    dois números inteiros, dois números de ponto flutuante ou duas strings.
    Neste caso usamos o = para atribuir o valor de um objeto a outro objeto da mesma classe.
    - O operador de atribuição de cópia é um exemplo de sobrecarga de operador em C++.
    
4 - Destrutor: Liberta recursos (embora, neste caso, não seja necessário).

5 - Funções getRawBits e setRawBits: Manipulam diretamente o valor bruto do número de ponto fixo.
    Getters and setters:
    5.1. - int getRawBits(void) const; // Returns the raw value of the fixed point value.
    5.2. - void setRawBits(int const raw);// Sets the raw value of the fixed point value.
 
6 - Fixed Point Numbers: 
    6.1. - int _fixedPointValue; // Armazena o valor do ponto fixo. 
    Corresponde à parte inteira do valor do ponto fixo.
    6.2. - static const int _fractionalBits = 8; // Número de bits fracionários (sempre 8) 
    correspondentes à parte fracionária do valor do ponto fixo

7 - Por que colocamos const no fim de int getRawBits(void) const?

    Resposta: 
    A palavra-chave const no final da declaração da função garante que 
    a função não altera o estado do objeto no qual é chamada. 
    Ou seja, a função não pode modificar nenhum atributo da instância da classe.
    Por outras palavras a palavra-chave const no final da declaração de um método indica 
    que o método não modificará o estado do objeto em que está sendo chamado. 
    Isso significa que o método pode ser chamado em um objeto const, ou seja, 
    um objeto que não pode ser modificado. Essa prática é importante para garantir 
    que métodos que apenas leem dados do objeto não alterem suas propriedades. 
    Portanto, a função getRawBits() é uma função constante e só pode ler (ou acessar) 
    o valor de rawBits, mas não pode modificá-lo. Se tentasses modificar o valor de 
    rawBits dentro desta função, receberias um erro de compilação.
    No mesmo sentido, no CPP02ex01, ao escrevermos float toFloat(void) const;, 
    estamos a afirmar que toFloat não vai alterar nenhuma das variáveis de membro da classe.

    Explicação da função:
    int getRawBits(void):
    A função retorna um valor do tipo int.
    O void indica que a função não recebe nenhum argumento.
    const no final da função:
    Este const significa que a função não pode modificar nenhum dos membros da classe.
    Uma função membro marcada como const pode ser chamada em instâncias da classe que também são constantes.

    Poderíamos ter colocado const em outro lugar?
    Não, a posição da palavra-chave const é específica em C++. Ela deve ser colocada após os parênteses do método, 
    indicando que é a função em si que é const, não a classe. Assim, a sintaxe correta para 
    um método const deve sempre seguir o padrão:

    Formato geral das funções:
    ReturnType MethodName(Parameters) const;
    Tentar colocar const em outro lugar, como antes do tipo de retorno ou dos parâmetros, resultará em um erro de compilação. 
    Portanto, a posição de const é fixa e deve ser mantida conforme a linguagem C++ define.

RESUMO: 
1 - Construtores e Destrutor: Estão devidamente definidos para inicializar, copiar e destruir corretamente os objetos, 
com mensagens para acompanhar a execução.
2 - Operador de Atribuição: Evita a auto-atribuição e copia os valores brutos.
3 - Métodos getRawBits e setRawBits: Manipulam o valor diretamente, sem transformar o número de ponto fixo.
*/

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{

public:
    // Constructors and Destructor
    Fixed();
    Fixed(const Fixed &copy); // Construtor de cópia
    ~Fixed();
    
    // Operador de atribuição sobrecarregado ou Copy assignment operator - Operator Overloading - deep copy
    // À esquerda retorna uma referência para o objeto atual (this) que recebe os dados e é modificado (o que permite atribuições encadeadas a=b=c), 
    // e à direita recebe uma referência constante para o objeto a ser copiado (copy), que fornece os dados para a cópia (é o molde). Ver mais detalhes no ponto 3.4.4., 3.2, 3.3. 3 e 3.4 dos comments do Fixed.hpp do CPP02ex00.
    Fixed &operator=(const Fixed &copy); 
    
    // Getters and setters para acesso ao valor bruto do número de ponto fixo
    // Const no final da função getRawBIts significa que a função não pode modificar nenhum dos membros da classe (atributos ou métodos), não alterando o estado do objeto no qual é chamada. 
    int getRawBits(void) const;
    void setRawBits(int const raw);

// Variables
private:
    int _fixedPointValue; // Armazena o valor do ponto fixo. Corresponde à parte inteira do valor do ponto fixo.
    static const int _fractionalBits = 8; // Número de bits fracionários (sempre 8) correspondentes à parte fracionária do valor do ponto fixo
};

#endif
ponto 