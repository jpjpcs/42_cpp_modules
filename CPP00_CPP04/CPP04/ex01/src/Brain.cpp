/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 08:55:54 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/19 13:44:14 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. Escolha entre chamar ou não Operador Atribuição Cópia dentro do Construtor de Cópia
    1.1.  Construtor de Cópia com Cópia Direta
        1.1.1. - Implementação: A cópia é realizada diretamente no construtor, usando um loop para copiar cada elemento.
            Brain::Brain(const Brain& to_copy) 
            {
                std::cout << "Brain copy constructor called." << std::endl;
                for (int i = 0; i < ideasCount; i++) 
                {
                    this->ideas[i] = to_copy.ideas[i]; // Cópia profunda
                }
            }
        1.1.2. - Vantagens:
        . Cópia Profunda Explícita: Garante que cada dado é copiado corretamente, evitando referências a dados destruídos.
        . Independência: Não depende de métodos externos, tornando a lógica de cópia mais clara e robusta.
        . Melhor Legibilidade: O processo de cópia é fácil de entender, pois é explicitamente descrito.

    1.2. Construtor de Cópia Chamando o Operador de Atribuição
        1.2.1. - Exemplo
            Brain::Brain(const Brain& other) 
            {
                std::cout << "Brain copy constructor called." << std::endl;
                *this = other; // Chama o operador de atribuição
            }
        1.2.2. - Vantagens de Chamar o Operador de Atribuição:
            1.2.2.1. - Reutilização de Código: Ao chamar o operador de atribuição, 
            reutilizamos a lógica de cópia que já foi implementada. Isso pode reduzir a 
            duplicação de código e garantir que ambas as operações (cópia e atribuição) 
            se comportem da mesma forma.

            1.2.2.2. - Consistência: Se o operador de atribuição é bem projetado, 
            ele deve garantir a segurança de memória e a consistência da lógica de cópia. 
            Isso pode ser especialmente útil se você adicionar lógica adicional 
            (como controle de recursos) no operador de atribuição no futuro.

            1.2.2.3. - Facilidade de Manutenção: Alterações na lógica de cópia precisam 
            ser feitas em um só lugar (no operador de atribuição), 
            o que facilita a manutenção do código.

        1.2.3. - Desvantagens de Chamar o Operador de Atribuição:
            1.2.3.1. - Dependência: Se houver um erro no operador de atribuição, 
            o construtor de cópia também poderá falhar. Isso introduz uma dependência que 
            pode ser indesejável em alguns casos.

            1.2.3.2. - Semântica de Cópia: O operador de atribuição é normalmente usado 
            para atribuições em objetos já existentes, enquanto o construtor de cópia 
            deve criar um novo objeto. Misturar essas semânticas pode causar confusão.

            1.2.3.3. - Desempenho: Chamar o operador de atribuição pode resultar em uma 
            leve sobrecarga de desempenho, especialmente se você estiver copiando 
            grandes quantidades de dados. Embora essa diferença seja frequentemente 
            negligenciável, é algo a considerar em cenários de desempenho crítico.

    1.3 - Melhor Prática
        1.3.1. - Cópia Direta: Para classes simples ou para garantir que o 
        comportamento de cópia é bem compreendido, você pode optar por copiar os 
        membros diretamente no construtor de cópia.

        1.3.2. - Chamada ao Operador de Atribuição: Para classes mais complexas 
        ou onde a lógica de cópia é extensa e precisa ser reutilizada, chamar o 
        operador de atribuição pode ser uma abordagem mais eficaz.

    1.4. - Conclusão
    Embora a prática de chamar o operador de atribuição de cópia no construtor 
    de cópia seja comum, a decisão deve ser baseada na complexidade da classe, 
    na reutilização de código desejada e na clareza do código. Em muitos casos, 
    uma implementação direta do construtor de cópia pode ser mais clara 
    e menos propensa a erros.
*/

/*
2 - Usar getter no construtor de cópia vs não usar
    2.1. - Fazer uma cópia profunda sem invocar o getter pode ser uma questão de estilo 
    e implementação, mas não é necessariamente uma má prática, desde tenhamos a certeza de que 
    estamos a acessar os dados de forma segura. 
    2.2. - Prós e Contras
    exemplo:
    Brain::Brain(const Brain& other) 
    {
        std::cout << "Brain copy constructor called." << std::endl;
        for (int i = 0; i < ideasCount; i++) {
            ideas[i] = other.getIdea(i); // Usando getter para obter a ideia
    }
    Prós: 
        . aproveitamos qualquer lógica que esteja no getter, o que pode garantir que as 
        operações sejam consistentes e seguras. 
        . Isso é especialmente útil se temos alguma lógica de validação ou transformação dos dados.
    Contras:
        . Pode adicionar uma leve sobrecarga, dependendo do que o getter faz.
        . A legibilidade pode ser prejudicada se o getter estiver muito longe do código que realiza a cópia.
    2.3. - Melhor Prática
    Escolher entre os dois métodos depende do contexto: 
        . Se os getters não têm lógica adicional e simplesmente retornam o valor, podemos optar por não usá-los, 
            como no primeiro exemplo. Isso pode ser preferível por simplicidade e eficiência.
        . Se houver lógica adicional que precisa ser executada ao acessar os dados (por exemplo, garantir 
        que um índice esteja dentro dos limites), é uma boa prática usar os getters.
    2.4. - Recomendação
        2.4.1. - Consistência: Temos q decidir por um estilo e mantê-lo em todo o código. Se usamos getters 
            numa parte, devemos usá-los em todas as partes relevantes.
        2.4.2. - Se os dados requerem manipulação ou validação: Usamos getters para garantir que essa lógica seja sempre aplicada.
        2.4.3. - Se não houver lógica nos getters: podemos acessar diretamente os membros privados, mas certificando-nos
         de que isso não compromete a integridade dos dados ou a encapsulação.
Portanto, a escolha de usar ou não os getters depende do design e das necessidades do seu código. 
Ambos os métodos são válidos, mas devem ser usados com consideração para garantir a clareza e a segurança do programa.
}

*/

#include "Brain.hpp"

// Construtor padrão
Brain::Brain() 
{
    std::cout << "Brain default constructor called." << std::endl;
    const std::string ideas_list [] = 
    {
        "I am hungry",
        "I want to play",
        "I need to pee",
        "I feel sleepy",
        "I want to explore the world",
        "I need a cozy nap",
        "I wish for a treat",
        "I want to chase squirrels",
        "I need some belly rubs",
        "I want to climb a tree",
        "I feel like scratching something",
        "I want to investigate that box",
        "I need to groom myself",
        "I wish I could catch that bird",
        "I want to find a sunny spot",
        "I feel playful today",
        "I need some fresh air",
        "I miss my human",
        "I want to dig a hole",
        "I want to smell the flowers"
    };

    for (int i = 0; i < ideasCount; i++) 
    {
        this->ideas[i] = ideas_list[rand()%20]; // Cópia profunda que copia o conteúdo de cada uma das ideias.
    } 
}

// Construtor de cópia
// Ver mais info no ponto 1 do Animal.cpp do CPP04ex00 e ponto 1 do Brain.cpp do CPP04ex01
Brain::Brain(const Brain& to_copy) 
{
    std::cout << "Brain copy constructor called." << std::endl;
    for (int i = 0; i < ideasCount; i++) 
    {
        this->ideas[i] = to_copy.ideas[i]; // Cópia profunda que copia o conteúdo de cada uma das ideias.
    }
}

// Operador de atribuição
Brain& Brain::operator=(const Brain& to_copy) 
{
    std::cout << "Brain assignment operator called." << std::endl;
    if (this != &to_copy) 
    {
        for (int i = 0; i < ideasCount; i++) 
        {
            this->ideas[i] = to_copy.ideas[i]; // Cópia profunda que copia o conteúdo de cada uma das ideias.
        }
    }
    return *this;
}

// Destrutor

Brain::~Brain() 
{
    std::cout << "Brain destructor called." << std::endl;
}

// Método para apresentar as ideias

void Brain::showIdeas() const 
{
    for (int i = 0; i < 3; i++) 
    {
        std::cout << "Idea #" << i + 1 << ": " << this->ideas[i] << std::endl;
    }
}
