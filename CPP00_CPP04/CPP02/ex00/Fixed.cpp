/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:34:25 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/11 01:09:05 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1 - No construtor de cópia optamos por copiar o valor indiretamente 
(usando o atribuidor de cópia) e não fazê-lo de forma direta. 

Fixed::Fixed(Fixed const &to_copy)
{
    std::cout << "to_copy constructor called" << std::endl;
    *this = to_copy; // Copia indiretamente chamando o operador de atribuição. Ver mais info nos comments acima.   
}

    1.1. - Usar *this = to_copy; em vez de this->_fixedPointValue = to_copy._fixedPointValue; 
    no constutor de cópia. Porquê?

    Fixed::Fixed(Fixed const &to_copy)
    {
        1.1.1. - Optamos por usar o *this = to_copy; em vez de this->_fixedPointValue = to_copy._fixedPointValue;
        *this = to_copy; indica que o operador de atribuição está a ser chamado no corpo do construtor de cópia 
        (ou seja, está a ser chamado explicitamente para copiar o valor). Neste caso, o construtor de cópia 
        criaria o novo objeto, mas em vez de simplesmente copiar os dados diretamente, ele chamaria o 
        operador de atribuição, levando à saída "to_copy assignment operator called" imediatamente após o 
        "to_copy constructor called". Isto cria uma duplicação de operações: primeiro o construtor de cópia e 
        logo de seguida o operador de atribuição. Por isso é que no output aparece o "to_copy assignment operator called" 
        após o "to_copy constructor called" e antes do "Float constructor called" na linha 5 da saída.
        - E pq é que *this = to_copy é considerado indireto? Porque o operador de atribuição é chamado para copiar 
        o valor de to_copy para o objeto atual, em vez de copiar diretamente o valor de to_copy para o objeto atual. 
        
        1.1.2. - Podíamos também ter optado por esta abordagem this->_fixedPointValue = to_copy._fixedPointValue; 
        em vez de *this = to_copy;
        - this->_fixedPointValue = to_copy._fixedPointValue; seria usado para evitar o 
        problema mencionado acima (duplicação de operações).
        Para tal devemos assegurar que o construtor de cópia faz uma cópia direta dos membros, 
        sem envolver o operador de atribuição.
        - E pq é que this->_fixedPointValue é considerado direto? Porque o valor do ponto fixo é copiado 
        diretamente de to_copy para o objeto atual, sem envolver o operador de atribuição.
    }
    1.2. - PORQUE É QUE FIZEMOS ISSO? E VANTAGENS VS DESVANTAGENS:
            1.2.1. - PORQUE É QUE FIZEMOS ISSO? 
            Fizemos isso porque o subject do exercício assim o pedia. No output do terminal 
            apresentado no subject do exercício é apresentada a impressão do 
            "to_copy assignment operator called" após o "to_copy constructor called".
            Logo, seguimos o mesmo raciocínio. 
            MAS PORQUE RAZÃO O SUBJECT DO EXERCÍCIO PEDE ISTO?
            Possivelmente porque quer que o aluno aprenda a diferença entre copiar diretamente 
            ou através do operador de atribuição, e as vantagens e desvantagens de cada abordagem. 
            Assim como espera que o aluno aprenda a utilizar quer o construtor de cópia, 
            quer o operador de atribuição de cópia juntos e de forma correta.
            Aprendemos assim que se quisermos reutilizar o código do operador de 
            atribuição no construtor de cópia, evitamos duplicação de lógica. 
            Contudo, existem mais vantagens e desvantagens que passo a explicar seguidamente.

            1.2.2. Vantagens/Desvantagens de Usar o Operador de Atribuição no Construtor de Cópia
            Vantagens:
                - Reutilização de código: Usar o operador de atribuição no construtor de cópia 
                evita duplicação de lógica, já que ambos (construtor de cópia e operador de atribuição) 
                envolvem a cópia de dados.
                - Facilidade de manutenção: Se o operador de atribuição for atualizado, 
                o construtor de cópia automaticamente aproveita essa modificação.
            Desvantagens:
                - Overhead desnecessário: O operador de atribuição pressupõe que o objeto 
                já existe, por isso pode haver mais trabalho do que o necessário para um objeto novo, 
                como tentar "libertar" memória ou recursos que ainda não foram alocados.
                - Comportamento inesperado: Como observaste, pode introduzir resultados 
                inesperados na ordem das saídas, o que complica a depuração.
                - Performance: Pode haver uma penalidade de desempenho ao utilizar o 
                operador de atribuição em vez de copiar os membros diretamente,
                uma vez que há verificações e possíveis desalocações de recursos antigos.
*/

/* 
2- Auto-Atribuição: Auto-atribuição é quando um objeto é atribuído a si mesmo.
    Ou seja, é quando o endereço do objeto atual é igual ao endereço do objeto a ser copiado.
    Por exemplo, se tivermos Fixed a; e fizermos a = a;, isso é auto-atribuição.
    E o que acontece se houver auto-atribuição no operador de atribuição de cópia? 
    Se houver auto-atribuição, o valor do objeto atual será igual ao valor do objeto a ser copiado.
    E é isso que queremos evitar, pois não faz sentido copiar o valor de um objeto para ele mesmo.
    Portanto, para evitar auto-atribuição, verificamos se o endereço do objeto atual é diferente
    do endereço do objeto a ser copiado. Se forem diferentes, copiamos o valor do objeto a ser copiado
    para o objeto atual.
    No entanto, se o endereço do objeto atual for igual ao endereço do objeto a ser copiado,
    não fazemos nada, pois isso significa que o objeto está a ser atribuído a si mesmo.
    Isto está a ser feito no operador de atribuição de cópia, onde verificamos se o endereço do objeto atual
    é diferente do endereço do objeto a ser copiado, na parte do código onde está a ser feita a verificação:
    if (this != &to_copy).
*/

/*
No OPERADOR DE ATRIBUIÇÃO:
3. Atribuição direta (_fixedPointValue - CPP02ex01) vs Atribuição indireta (com getRawBits() - CPP02ex00):
    ex00 - atribuição indireta (usando getRawBits())
    Fixed &Fixed::operator=(Fixed const &to_copy)
    {
        std::cout << "to_copy assignment operator called" << std::endl;
        if (this != &to_copy) // Verifica se não há auto-atribuição
            _fixedPointValue = to_copy.getRawBits(); // Atribuição indireta usando um getter
        return *this;
    }
    ex01 - atribuição direta (_fixedPointValue)
    Fixed &Fixed::operator=(Fixed const &to_copy)
    {
        std::cout << "to_copy assignment operator called" << std::endl;
        if (this != &to_copy) // Verifica se não há auto-atribuição
            _fixedPointValue = to_copy._fixedPointValue; // Atribuição direta do valor
        return *this;
    }
    3.1. Atribuição indireta (CPP02ex00)
        - Acesso por método de acesso: Nesta abordagem, o valor de _fixedPointValue 
        é obtido através de um método público de acesso getRawBits(). Este método é parte da interface pública 
        da classe e fornece uma forma controlada de acessar o valor do ponto fixo, o que pode ser útil em certas situações.
        - Isso fornece uma camada de abstração, permitindo que a classe controle como o valor é obtido e manipulado.
        - Vantagem: Oferece mais flexibilidade, pois permite que a classe adicione lógica adicional ao método getRawBits() 
        sem precisar alterar o operador de atribuição. Isso pode ser útil se precisarmos de validar 
        ou modificar o valor antes de atribuí-lo. A abstração pode ser útil se o comportamento de acesso ao valor mudar no 
        futuro (por exemplo, se houver validação adicional ou algum processamento antes de retornar _fixedPointValue).
        - Desvantagem: Adiciona uma chamada de função extra, o que pode ter um impacto/custo ligeiro no desempenho.
        Além disso, a abstração adicional pode tornar o código mais complexo e difícil de entender em comparação 
        com a atribuição direta, especialmente se a função getRawBits() for complexa ou se o código for executado muitas vezes. 
        - Diferenças principais:
            . Abstração vs. Eficiência:
                O uso de getRawBits() (opção 1) oferece mais abstração, permitindo mudanças no comportamento 
                de como o valor é acessado sem precisar alterar o operador de atribuição. 
                A atribuição direta (opção 2) é mais eficiente, pois elimina a necessidade de uma chamada de função, 
                mas torna o código menos flexível a alterações futuras.
            . Legibilidade:
                Ambas as abordagens são claras, mas o uso de this-> pode ajudar a destacar membros da classe, 
                o que melhora a legibilidade.    
    3.2. Atribuição direta (CPP02ex01)
        - Acesso direto ao membro privado: Nesta abordagem, o valor de _fixedPointValue é copiado diretamente, 
        sem passar por um método de acesso. O código é mais simples e direto, o que pode melhorar o desempenho 
        ligeiramente, já que elimina a sobrecarga de uma chamada de função.
        - Vantagem: É mais eficiente e direto, pois não há chamada extra de função. 
        É útil quando tens certeza de que não precisas de controle extra sobre como o valor é obtido.
        - Desvantagem: Perde a abstração fornecida pelo getRawBits(), tornando o código menos flexível 
        a alterações futuras (por exemplo, se quiseres adicionar lógica ao método getRawBits() mais tarde).
        - Diferenças principais:
            . Abstração vs. Eficiência:
                O uso de getRawBits() (opção 1) oferece mais abstração, permitindo mudanças no comportamento 
                de como o valor é acessado sem precisar alterar o operador de atribuição. 
                A atribuição direta (opção 2) é mais eficiente, pois elimina a necessidade de uma chamada de função,
                mas torna o código menos flexível a alterações futuras.
            .Legibilidade:
                Ambas as abordagens são claras, mas o uso de this-> pode ajudar a destacar membros da classe, 
                o que melhora a legibilidade.
    3.3. Quando escolher uma abordagem:
            . Se esperamos que a forma como o valor é obtido ou manipulado possa mudar no futuro: 
            Devemos usar a versão com getRawBits(), pois ela oferece maior flexibilidade.
            . Se a performance for uma prioridade e não esperas mudanças no acesso ao valor: 
            Usa a versão com atribuição direta de _fixedPointValue.
    3.4. O to_copy no _fixedPointValue = to_copy._fixedPointValue; ?
        Desmontando a frase: _fixedPointValue = to_copy._fixedPointValue;:, temos no lado esquerdo da atribuição
        o membro privado da classe Fixed, _fixedPointValue, e no lado direito da atribuição, o membro privado
        da classe Fixed que está a ser copiado, to_copy._fixedPointValue. Ou seja, estamos a copiar o valor do
        membro privado da classe Fixed que está a ser copiado para o membro privado da classe Fixed que está a
        a receber a cópia. to_copy é o objeto que está a ser copiado.
*/

#include "Fixed.hpp"

//++++++++++++*********** CONTRUTORES E DESTRUTOR ***********++++++++++++
// Construtor padrão 
Fixed::Fixed() : _fixedPointValue(0) // ou this->_value = 0;
{
    std::cout << "Default constructor called" << std::endl;
}

// Construtor de cópia para ser usado no main: Fixed b(a); Cópia de a para b
Fixed::Fixed(const Fixed &to_copy) 
{
    std::cout << "copy constructor called" << std::endl;
    *this = to_copy; // Copia indiretamente chamando o operador de atribuição. Diretamente seria this->_fixedPointValue = to_copy.getRawBits(); Ver mais info no ponto 1 do Fixed.cpp do CPP02ex00 ou CPP02ex01.
}

// Destrutor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

//++++++++++++++*************** OPERADORES ARITMÉTICOS SOBRECARREGADOS ***************++++++++++++++
// Chama/usa o OPERADOR de ATRIBUIÇÃO de cópia para ser usado no main: c = b;  // Atribuição de b para c
// Operador de Atribuição sobrecarregado e to_copy construtor evitam shallow copies (fazem deep to_copy). Mais info ponto 
Fixed &Fixed::operator=(const Fixed &to_copy) 
{
    std::cout << "copy assignment operator called" << std::endl;
    if (this != &to_copy) // Evita auto-atribuição. E o que é a auto-atribuição? Ver acima.
    {
        this->_fixedPointValue = to_copy.getRawBits();  // _fixedPointValue = to_copy._fixedPointValue; mais direto ou this->_fixedPointValue = to_copy.getRawBits(); mais indireto, mas opcional(indica q nos referimos a um membro da classe). Ou seja, a diferença reside na forma de acesso ao valor do atributo, mas ambos copiam o valor. Ver mais info pontos 3 (3.4. sobre to_copy) dos comments do CPP02ex00.
    }
    return *this; // Retorna o valor copiado como referência para o objeto atual (this) que recebe os dados e é modificado.
}

//++++++++++++++*************** GETTERS & SETTERS ***************++++++++++++++
// Retorna o valor bruto do ponto fixo
int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl; // Esta msg é impressa pq getter é chamado no main.
    return this->_fixedPointValue;
}

// Define o valor bruto do ponto fixo
void Fixed::setRawBits(int const raw) // Aqui é const pq não queremos modificar o valor do objeto, apenas queremos acessá-lo e retorná-lo.
{
    std::cout << "setRawBits member function called" << std::endl; // Nunca é chamado no main.cpp, logo nunca é impresso no terminal. mais info no ponto  6 do Fixed.hpp do CPP02ex00.
    this->_fixedPointValue = raw; // Define o valor bruto do ponto fixo como o valor passado como argumento para a função no momento da chamada no main.cpp
}
