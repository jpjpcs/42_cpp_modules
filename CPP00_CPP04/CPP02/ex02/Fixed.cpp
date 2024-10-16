/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:15:25 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/11 16:57:03 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Pontos 1, 2, 3 e 4 descritos no Fixed.cpp do CPP02ex00
e pontos 5, 6, e 7 descritos no Fixed.cpp do CPP02ex01

// +++++++---------------------CPP02ex00 e CPP02ex01 cima / CPP02ex02 baixo ----------------------------++++++


Explicação Main Points:

//++++++++++++++******OPERADORES INCREMENTO/DECREMENTO SOBRECARREGADOS *****++++++++++++++
8 - Diferenças entre Pré-fixadas e Pós-fixadas
    8.1. Incremento/Pós-fixado (operator++(int) e operator--(int))
    Essas funções são chamadas pós-fixadas porque têm um parâmetro inteiro. 
    O inteiro (geralmente um valor padrão, como 0) é apenas uma maneira 
    de distinguir essa função da versão pré-fixada.

    Fixed Fixed::operator++(int) 
    {
        Fixed tmp = *this; // Cria uma cópia do objeto atual. 
        ++(*this); // Incrementa o objeto atual
        return tmp; // Retorna a cópia
    }

    Fixed Fixed::operator--(int) 
    {
        Fixed tmp = *this; // Cria uma cópia do objeto atual.
        --(*this); // Decrementa o objeto atual
        return tmp; // Retorna a cópia
    }
    a++ e a--: Chamando a++, você obtém o valor de a antes do 
    incremento ou decremento, enquanto a é atualizado para o novo valor.
    8.2. Incremento/Pré-fixado (operator++() e operator--())
    Essas funções são chamadas pré-fixadas porque não têm nenhum parâmetro. 
    Elas alteram o valor do objeto e retornam o objeto modificado.

    Fixed Fixed::operator++() 
    {
        this->_fixedPointValue++; // Incrementa o valor
        return *this; // Retorna o objeto modificado
    }

    Fixed Fixed::operator--() 
    {
        this->_fixedPointValue--; // Decrementa o valor
        return *this; // Retorna o objeto modificado
    }
    ++a e --a: Chamando ++a, o valor de a é incrementado primeiro, e o novo valor de a é retornado.

    8.3. Resumo Correto
    Pós-fixadas (operator++(int) e operator--(int)):

    Retornam uma cópia do objeto antes de ser modificado.
    Usadas com a sintaxe a++ ou a--.
    Pré-fixadas (operator++() e operator--()):

    Modificam o objeto diretamente e retornam o objeto modificado.
    Usadas com a sintaxe ++a ou --a.

9. A razão pela qual alguns colegas usaram um parâmetro como int tmp 
ou int dummy nas funções de incremento e decremento 
pós-fixado (operator++(int) e operator--(int)) e outros não, 
se deve principalmente ao padrão de programação e ao estilo de codificação. 
Vamos analisar as duas abordagens:

    9.1. Uso de um parâmetro (int tmp ou int dummy)
        Fixed Fixed::operator++(int tmp)
        {
            (void)tmp; // Ignora o parâmetro
            Fixed duplicate(*this);
            ++(*this);
            return (duplicate);
        }
        . Razão para usar o parâmetro: O operador pós-fixado operator++(int) é 
            definido para aceitar um argumento de tipo int (geralmente um parâmetro que não é usado), 
            que é uma convenção na sobrecarga de operadores em C++. O parâmetro é necessário para distinguir 
            entre a versão pré-fixada e a versão pós-fixada do operador.
            Ignorando o parâmetro: A linha (void)tmp; é uma maneira de evitar avisos de compilação 
            sobre variáveis não utilizadas. Isso é uma prática comum para indicar que você 
            intencionalmente não usou o parâmetro.
    9.2. Não usar um parâmetro (int)
        Fixed Fixed::operator++(int)
        {
            Fixed duplicate(*this);
            ++(*this);
            return duplicate;
        }
        . Razão para não usar um nome de parâmetro: Algumas pessoas podem optar por não nomear o parâmetro, 
            especialmente se não têm a intenção de usar o valor dentro da função. Isso ainda é válido, 
            pois a função espera um argumento (no entanto, o nome do parâmetro pode ser omitido se não for utilizado). 
            Isso pode simplificar a sintaxe, mas ainda respeita a necessidade de ter um parâmetro para indicar que é uma versão pós-fixada.
    9.3. Resumo
        Com parâmetro (int tmp ou int dummy): É mais explícito, permitindo que os leitores entendam que é um operador pós-fixado. 
        O uso do nome de variável (mesmo que não seja utilizado) é uma prática comum para melhorar a clareza.
        Sem parâmetro (apenas int): É uma opção válida que simplifica a função, mas pode não ser tão clara em termos de intenção. 
        O compilador ainda reconhece que é um operador pós-fixado pela assinatura, mas pode não ser tão legível quanto a outra versão.
        Ambas as abordagens são corretas, e a escolha geralmente se resume ao estilo de codificação e preferências pessoais dos programadores.
*/

/*
10 - Diferença entre usar & e não usar & no retorno das funções:
exemplo: 
Fixed Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}

nas quais optei por NÃO usar & no retorno das funções, como está aqui:
    Fixed operator++(void);
    Fixed operator--(void);
e não como está aqui:
    Fixed &operator++(int a);
    Fixed &operator--(int a);

    E Quais as diferenças?
     Resumo Geral:
    - Retornar por Referência (&):
    . Mais eficiente (evita cópia desnecessária).
    . Permite modificar o objeto original fora da função.
    . Permite encadear operações.
    . Deve ser usado apenas quando é seguro, ou seja, quando o objeto que está sendo retornado vai sobreviver 
        após o término da função (não é uma variável local).
    - Retornar por Valor:
    . Garante segurança, pois retorna uma cópia que não pode modificar o original.
    . Útil quando você precisa de um resultado isolado ou um objeto temporário.
    . Menos eficiente, especialmente para objetos grandes, devido à criação de cópias.
    . Dependendo da situação, pode-se priorizar a eficiência (retorno por referência) ou a segurança (retorno por valor).
    A escolha entre retornar por referência ou por valor em C++ depende do contexto 
    e das necessidades da função. Aqui estão as principais vantagens de cada abordagem:
        10.1. Retornar por Referência (Fixed&)
        Quando você retorna por referência, está retornando um endereço que aponta diretamente 
        para o objeto original, em vez de uma cópia. Isso traz algumas vantagens importantes:
            . Eficiência: Como não é criada uma cópia do objeto, o retorno por referência é 
                muito mais eficiente, especialmente quando se lida com objetos grandes. 
                Evita o custo adicional de alocação de memória e cópia de dados.
            . Modificação do Objeto Original: Se a função retorna uma referência, 
                você pode modificar diretamente o objeto original fora da função. 
                Isso é útil em cenários onde você deseja manipular o mesmo objeto
                em várias operações, sem criar cópias desnecessárias.
                Exemplo:
                    Fixed a, b;
                    Fixed& min = Fixed::min(a, b);  // min é uma referência a 'a' ou 'b'
                    min.setRawBits(10);             // modifica o objeto original
            . Encadeamento de Operações: Quando a função retorna uma referência, 
                permite encadear múltiplas operações em sequência, como no caso de 
                operadores de incremento (++), sem perder o contexto do objeto original.
                Exemplo:
                    Fixed a;
                    (++a)++;  // Funciona porque (++a) retorna uma referência para `a`
            10.1.1. - Quando não retornar por referência:
            Não faz sentido retornar por referência quando o objeto sendo retornado é uma 
            variável local da função, porque a variável local será destruída quando a 
            função terminar. Nesse caso, retornar por referência causaria 
            um erro de dangling reference (referência inválida).
        10.2. Retornar por Valor (Fixed)
        Quando você retorna por valor, a função cria uma cópia do objeto e a retorna. 
        Isso também pode ter suas vantagens dependendo da situação:
            . Segurança: O retorno por valor garante que o objeto retornado seja uma cópia do original, 
                o que evita modificações acidentais no objeto original. Se o objetivo da função é fornecer 
                um resultado calculado sem que o chamador modifique o objeto, retornar por valor é uma boa escolha.
                Exemplo:
                    Fixed a, b;
                    Fixed result = a + b;  // `result` é uma cópia, não afeta `a` nem `b`
            . Isolamento de Escopo: Retornar por valor permite que o chamador da função trabalhe com uma cópia 
                que não tem qualquer ligação ao objeto original. Isso é útil quando você quer isolar o 
                resultado de uma função do estado dos objetos originais.
                Exemplo:
                    Fixed a;
                    Fixed b = a++;  // b recebe a cópia do valor antigo de `a`, antes do incremento
            . Objeto Temporário: Retornar por valor é útil quando a função precisa criar e retornar 
                um objeto temporário que não existia previamente, como no caso de cálculos ou combinações de dados.
            10.2.1. - Quando não retornar por valor:
                . Retornar por valor pode ser ineficiente se o objeto a ser retornado for grande, pois envolve a criação 
                    de uma cópia. Esse custo de performance pode ser significativo se for feito repetidamente, 
                    como em loops ou em funções chamadas frequentemente.
*/

#include "Fixed.hpp"

//++++++++++++*********** CONTRUTORES E DESTRUTOR ***********++++++++++++

// Construtor padrão inicializa o valor como 0
Fixed::Fixed() : _fixedPointValue(0) // ou this->_fixedPointValue = 0;
{
    //std::cout << "Default constructor called" << std::endl;
}

// Construtor que converte de inteiro para ponto fixo
Fixed::Fixed(int const value)
{
    //std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits; // << é o operador de deslocamento de bits à esquerda (bitwise left shift). Converte para o formato de ponto fixo, deslocando a vírgula para a direita através de uma multiplicação por 2^8 (256). Ver mais info no ponto 5 dos comments acima.
}

// Construtor que converte de float para ponto fixo
Fixed::Fixed(float const value)
{
    //std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(value * (1 << _fractionalBits)); // 1 << _fractionalBits: Este é o operador de deslocamento de bits à esquerda (bitwise left shift). Converte e arredonda para o formato de ponto fixo, deslocando a vírgula para a direita através da multiplicação por 2^8 (256). Ver mais info no ponto 5 e 6 dos comments acima.
}

// Construtor de cópia
Fixed::Fixed(Fixed const &to_copy)
{
    //std::cout << "copy constructor called" << std::endl;
    *this = to_copy; // Copia indiretamente chamando o operador de atribuição. Diretamente seria this->_fixedPointValue = to_copy.getRawBits(); Ver mais info no ponto 1 do Fixed.cpp CPP02ex01.  
}

// Destrutor
Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

//++++++++++++++*************** OPERADORES ARITMÉTICOS SOBRECARREGADOS ***************++++++++++++++
// Operador de atribuição de cópia sobrecarregado
Fixed &Fixed::operator=(Fixed const &to_copy)
{
    //std::cout << "copy assignment operator called" << std::endl;
    if (this != &to_copy) // Verifica se não há auto-atribuição
        _fixedPointValue = to_copy._fixedPointValue; // _fixedPointValue = to_copy._fixedPointValue; mais direto ou this->_fixedPointValue = to_copy.getRawBits(); mais indireto, mas opcional(indica q nos referimos a um membro da classe). Ou seja, a diferença reside na forma de acesso ao valor do atributo, mas ambos copiam o valor. Ver mais info pontos 3 (3.4. sobre to_copy) dos comments do CPP02ex00.
    return *this; // Retorna o valor copiado como referência para o objeto atual (this) que recebe os dados e é modificado.
}

// Operadores aritméticos somam, subtraem, multiplicam e dividem dois objetos Fixed
Fixed Fixed::operator+(const Fixed &to_copy) const 
{
    return Fixed(this->toFloat() + to_copy.toFloat());
}

Fixed Fixed::operator-(const Fixed &to_copy) const 
{
    return Fixed(this->toFloat() - to_copy.toFloat());
}

Fixed Fixed::operator*(const Fixed &to_copy) const 
{
    return Fixed(this->toFloat() * to_copy.toFloat());
}

Fixed Fixed::operator/(const Fixed &to_copy) const 
{
    return Fixed(this->toFloat() / to_copy.toFloat());
}

//++++++++++++++*************** OPERADORES COMPARAÇÃO SOBRECARREGADOS ***************++++++++++++++
// Operadores de comparação
bool Fixed::operator>(const Fixed &to_copy) const 
{
    return this->_fixedPointValue > to_copy._fixedPointValue;
}

bool Fixed::operator<(const Fixed &to_copy) const 
{
    return this->_fixedPointValue < to_copy._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &to_copy) const 
{
    return this->_fixedPointValue >= to_copy._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &to_copy) const 
{
    return this->_fixedPointValue <= to_copy._fixedPointValue;
}

bool Fixed::operator==(const Fixed &to_copy) const 
{
    return this->_fixedPointValue == to_copy._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &to_copy) const 
{
    return this->_fixedPointValue != to_copy._fixedPointValue;
}

//++++++++++++++******OPERADORES INCREMENTO/DECREMENTO SOBRECARREGADOS *****++++++++++++++

// Funções PRÉ-FIXADAS de incremento e decremento. ver info no ponto 1, 2, e 3 dos comments do Fixed.cpp CPP02ex02.
Fixed Fixed::operator++() 
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator--() 
{
    this->_fixedPointValue--;
    return *this;
}

// Funções PÓS-FIXADAS de incremento e decremento. ver info no ponto 1, 2, e 3 dos comments do Fixed.cpp CPP02ex02.
Fixed Fixed::operator++(int)
{
    Fixed tmp = *this; // Cria uma cópia do objeto atual. E pq cria uma cópia? 
    ++(*this); // Incrementa o objeto atual
    return tmp; // Retorna a cópia
}

Fixed Fixed::operator--(int) 
{
    Fixed tmp = *this;
    --(*this);
    return tmp;
}

//++++++++++++++*************** FUNÇÕES MIN E MAX ***************++++++++++++++
// Funções estáticas min e max
Fixed &Fixed::min(Fixed &a, Fixed &b) // ou o & antes do min - static Fixed &min(Fixed& a, Fixed& b) são equivalentes. Ver mais info no ponto 3 dos comments do Fixed.cpp CPP02ex01.
{
    return (a < b) ? a : b; // Se a < b, retorna a, senão retorna b. O ? significa "se" e o : significa "senão". ? : é um operador ternário.
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) 
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) 
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) 
{
    return (a > b) ? a : b;
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
