/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:19:50 by joaosilva         #+#    #+#             */
/*   Updated: 2024/10/16 11:39:34 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
1. Diferenças Inicialização:

    ScavTrap::ScavTrap(void) : ClapTrap()
    {
        std::cout << "ScavTrap Default Constructor called" << std::endl;
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        return;
    }

    VS

    ScavTrap::ScavTrap() : ClapTrap("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20) 
    {
        std::cout << "ScavTrap Default Constructor called" << std::endl;
    }

    VS 

    ScavTrap::ScavTrap() : ClapTrap("ScavTrap", 100, 50, 20)
    {
        std::cout << "ScavTrap Default Constructor called" << std::endl;
    }

       1.1. - Diferenças entre formas:
            A diferença entre as 3 formas de inicialização é a forma como os membros 
            da classe ScavTrap são inicializados.
            
            1.1.1. - Na primeira forma, o construtor padrão de ScavTrap chama o construtor padrão de ClapTrap,
            e depois inicializa os membros específicos de ScavTrap.
            
            Quer na segunda, quer na terceira forma, o construtor padrão de ScavTrap chama o 
            construtor de ClapTrap com o nome "ScavTrap",
            e depois inicializa os membros específicos de ScavTrap.
            
            1.1.2. - Na segunda forma, os atributos da classe derivada são inicializados após a 
            chamada do construtor da classe base, e os valores definidos podem não estar 
            conectados à lógica da classe base.
            Ou seja, primeiro chamamos o construtor da classe base e depois inicializamos os atributos da classe derivada.
            
            E em que é diferente da primeira forma?
            
            A diferença entre a primeira e a segunda forma é que, na primeira, os atributos
            da classe derivada são inicializados após a chamada do construtor da classe base,
            enquanto na segunda, os atributos da classe derivada são inicializados diretamente
            no construtor da classe base usando a lista de inicialização.
            
            1.1.3. - Na terceira foram, todos os valores são passados para o construtor da classe base, 
            permitindo que a lógica de inicialização da classe base seja utilizada de forma mais coesa.
            Ou seja, passamos os valores para a class ClapTrap e ela trata de inicializar os atributos
                . Encapsulamento:
                A terceira forma é geralmente preferível se o construtor da classe base estiver preparado 
                para receber todos os parâmetros que você deseja inicializar, pois encapsula a lógica de inicialização em um único local.
                Para estar preparado precisa de ter a possibilidade de passar todos os parâmetros necessários para a classe base:
        exemplo: ClapTrap::ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
                . Consideração:
                A escolha entre os dois estilos depende do design desejado e da necessidade de controle sobre a inicialização dos membros. Se você precisa de lógica adicional para inicializar atributos ou se os valores padrão da classe base não são suficientes, você pode preferir a primeira opção. Se todos os atributos devem ser definidos de maneira consistente e centralizada, a segunda opção é mais adequada.

            1.1.4. - A diferença entre a segunda e a terceia forma dos construtores de ScavTrap está na forma 
            como o construtor da classe base ClapTrap é chamado e como os atributos da classe 
            derivada são inicializados:
            1.1.4.1. - Construtor com Inicialização de Membros Separada
                    ScavTrap::ScavTrap() : ClapTrap("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20) 
                    {
                        std::cout << "ScavTrap Default Constructor called" << std::endl;
                    }
                    Chamada do Construtor da Classe Base: Aqui, o construtor da classe base 
                    ClapTrap é chamado com o argumento "ScavTrap".
                        . Inicialização de Membros: Os atributos _hitPoints, _energyPoints e _attackDamage 
                        são inicializados diretamente após a chamada ao construtor da classe base.
                        . Valores de Inicialização: Os valores de _hitPoints, _energyPoints e _attackDamage 
                        são definidos independentemente e não afetam a inicialização que ocorre na classe base.
            1.1.4.2. - Construtor com Todos os Parâmetros na Classe Base
                ScavTrap::ScavTrap() : ClapTrap("ScavTrap", 100, 50, 20)
                {
                    std::cout << "ScavTrap Default Constructor called" << std::endl;
                }
                Chamada do Construtor da Classe Base: Neste caso, o construtor da classe base ClapTrap 
                é chamado com três argumentos: "ScavTrap", 100, 50 e 20.
                    . Inicialização de Membros: Aqui, a inicialização de _hitPoints, _energyPoints e _attackDamage 
                    é feita diretamente no construtor da classe base, permitindo que ClapTrap manipule esses 
                    valores no próprio contexto da classe.
                    . Atributos na Classe Base: O que é passado para o construtor de ClapTrap se reflete 
                    diretamente nos membros que pertencem à classe base.
            
       1.2. - Que forma será mais correto usar:
       As 3 formas não são exatamente iguais. Embora ambas façam essencialmente a mesma coisa, 
        a primeira forma é preferível, e porquê?
            Mantendo o construtor padrão de ClapTrap apenas com o construtor default (ou seja, sem o construtor parametrizado), 
            o construtor de ScavTrap terá que usar esse construtor default e, portanto, não poderá passar parâmetros adicionais 
            diretamente para ClapTrap. Nesse caso, teremos que definir os valores desejados para _hitPoints, _energyPoints, 
            e _attackDamage no construtor de ScavTrap após chamar o construtor default de ClapTrap. 
            Caso contrário, o programa não compilará, dando erro de:
            "error: no instance of constructor 'ClapTrap::ClapTrap' matches the argument list".     
*/

/*
2 - Chamada de ClapTrap dentro de ClapTrap::ClapTrap(void) está errado.
    2.1. - Exemplo: ClapTrap::ClapTrap(void) : ClapTrap() _name("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
    Porquê?
    2.2. Problemas com a abordagem:
    ClapTrap::ClapTrap(void) : ClapTrap():

        . A chamada ClapTrap() dentro de ClapTrap::ClapTrap() está a tentar invocar o próprio 
        construtor de forma recursiva, o que é inválido. Não podemos invocar diretamente o 
        construtor dessa maneira dentro da lista de inicializadores.
    2.3. - Inicialização de membros:
        . A inicialização de _name("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20) deve ocorrer 
        diretamente na lista de inicializadores, mas precisa ser chamada no construtor derivado (neste caso, no ScavTrap), 
        e não no próprio ClapTrap.
    2.4. - Forma correta de inicializar membros:
        Quando criamos um objeto ScavTrap, os membros herdados da classe ClapTrap devem ser inicializados 
        chamando explicitamente o construtor da classe base na lista de inicialização. 
        
        ScavTrap::ScavTrap() : ClapTrap("ScavTrap"), _hitPoints(100), _energyPoints(50), _attackDamage(20) 
        {
            std::cout << "ScavTrap Default Constructor called" << std::endl;
        }
        
        Explicação:
        2.4.1. - ClapTrap("ScavTrap"):
            . Este chama o construtor de ClapTrap, que recebe o nome do ScavTrap como argumento e 
            inicializa o membro _name herdado.
        2.4.2. - Inicialização de _hitPoints, _energyPoints e _attackDamage:
            . Esses membros são específicos do ScavTrap e podem ser inicializados 
            diretamente na lista de inicializadores.
        2.4.3. - Mensagem de debug:
            O std::cout está dentro do corpo do construtor para indicar que o construtor foi chamado.
*/

/*
3 - Cópia direta vs Indireta:

    3.1. Porque é que a cópia direta pode resultar em duplicação de código?
        A cópia direta pode resultar em duplicação de código porque, quando usamos 
        a atribuição direta de membros no corpo de um construtor ou de uma função, 
        tens de fazer essa atribuição manualmente em todos os lugares onde precisas copiar os dados. 
        Isto leva a situações onde o mesmo código de atribuição se repete em várias partes do programa.
        Exemplo:
            Imaginemos que temos uma classe ClapTrap e uma derivada ScavTrap, e precisamos copiar os 
            membros de uma instância para outra.
            Se fizermos a cópia diretamente no corpo de funções (manualmente):
                ScavTrap& ScavTrap::operator=(const ScavTrap& other) 
                {
                    this->_name = other._name;
                    this->_hitPoints = other._hitPoints;
                    this->_energyPoints = other._energyPoints;
                    this->_attackDamage = other._attackDamage;
                    return *this;
                }
            Agora, se tivermos outro construtor de cópia, poderemos precisar repetir o mesmo código lá:
                ScavTrap::ScavTrap(const ScavTrap& other) 
                {
                    this->_name = other._name;
                    this->_hitPoints = other._hitPoints;
                    this->_energyPoints = other._energyPoints;
                    this->_attackDamage = other._attackDamage;
                }
            Esse código está a ser duplicado. Sempre que adicionamos novos membros à classe, 
            vamos precisar lembrar-nos de modificar todos esses lugares onde fizemos a cópia manual. 
            Com muitos membros ou classes derivadas, essa abordagem torna-se propensa a erros e difícil de manter.
    Já o operador de atribuição bem implementado resolve esse problema. O código de cópia fica centralizado 
    no operador de atribuição (operator=), e podemos reutilizá-lo de forma segura, evitando duplicação e inconsistências.
    Além disso, o operador de atribuição costuma tratar adequadamente a auto-atribuição (quando atribuis um objeto a ele mesmo) 
    e garante que a classe base é também copiada corretamente.
*/

/* 
4. ScavTrap::ScavTrap(void) : ClapTrap() vs ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
& uso de THIS->POINTER OU REFERÊNCIA DIRETA NO CONSTRUTOR:

    4.1. - Se colocar:
        ScavTrap::ScavTrap() : ClapTrap() 
                            OU
        ScavTrap::ScavTrap() : ClapTrap(void) 
                        ao invés de
        ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap"),
        
        4.1.1. O que acontece?
        O construtor parametrizado é chamado, e não o construtor padrão.
    
    4.1.2. Logo, NO TERMINAL APARECE:
        "ClapTrap Parametrized Constructor called"
        seguido por 
        "ScavTrap Default Constructor called".
                        ao invés 
        de "ClapTrap Default Constructor called".
        seguido por 
        "ScavTrap Default Constructor called".
    
    4.2. - Uso de this->pointer ou referência direta no construtor?
        4.2.1. - Uso no construtor padrão ou parametrizado:
            4.2.1.1. - Há essa necessidade?
                Não. Não é necessário uma vez que não há ambiguidade entre um argumento de função e um membro da classe com o mesmo nome.
                Isto é, não há possibilidade de confusão entre os atributos da classe (no caso _hitPoints, _energyPoints, e _attackDamage) e
                os argumentos do construtor (no caso _hitPoints, _energyPoints, e _attackDamage) porque nada é passado como parametro para o construtor.
                
                    . Não há Ambiguidade: Em ambos os casos, não existe um parâmetro com o mesmo nome que os membros da classe. 
                    Portanto, podemos usar os membros da classe diretamente com _hitPoints, _energyPoints, e _attackDamage sem a necessidade de this->.
                    . Se houvesse um parâmetro: Se, por exemplo, o construtor de ScavTrap tivesse um parâmetro chamado _hitPoints, 
                    aí sim teríamos que usar this->_hitPoints para deixar claro que estava se referindo ao membro da classe.
            4.2.1.2. -  Pode haver confusão entre o atributo e o parâmetro _name no construtor parametrizado?
                Não, porque o nome do parâmetro é diferente do nome do atributo da classe.
                O nome do parametro é name e o nome do atributo da classe é _name.
            4.2.1.3. - É redundante usar this->_hitPoints = 100; após chamar a classe ClapTrap no construtor padrão ou no construtor parametrizado?
                Não, não é redundante. Tal como referido anteriormente o Não é necessário usar o this-> explicitamente para referir-se aos membros 
                da classe se não houver conflito de nomes entre variáveis locais (ou parâmetros) e membros da classe. O uso de this-> é apenas uma 
                forma de deixar claro que estamos a referir-nos a um membro da classe atual.
                Se não houver conflito de nomes, podemos usar os membros diretamente sem this->.
                Mais digo que a chamada explícita do construtor base não influencia a necessidade ou não de usar o this-> para acessar os 
                membros da classe. O uso de this-> é determinado unicamente pela necessidade de diferenciar membros da classe de variáveis ou parâmetros locais.
                O uso de this-> depende apenas de evitar ambiguidades, ou seja, de diferenciar os membros da classe de possíveis parâmetros ou variáveis locais 
                com o mesmo nome. Se não houver esse conflito, pode omitir o this->.
            4.2.1.4. - Pq razão é útil usarmos a chamada à classe ClapTrap no construtor da classe ScavTrap?
                A chamada à classe base ClapTrap no construtor da classe derivada ScavTrap é útil para inicializar os membros herdados da classe base.
                Isso garante que os membros da classe base sejam inicializados corretamente antes de inicializar os membros específicos da classe derivada.
                A chamada ao construtor da classe base é feita na lista de inicialização do construtor da classe derivada, 
                permitindo que os membros da classe base sejam inicializados antes dos membros da classe derivada.
                Isso é importante para garantir que a inicialização ocorra na ordem correta e que os membros da classe base sejam configurados adequadamente.
                Além disso, a chamada ao construtor da classe base permite que os parâmetros necessários sejam passados para a classe base, 
                permitindo uma inicialização personalizada dos membros da classe base.
                A chamada ao construtor da classe base é uma prática comum em herança de classes para garantir que os membros da classe base 
                sejam inicializados corretamente antes de inicializar os membros da classe derivada.
               
****----+++++ Mais info no ponto 4 do ficheiro Account.cpp CPP00ex02 e no ponto 1, 2 e 4 dos comments do ScavTrap.cpp do CPP03ex01. ++++----****
*/

/*
5 - No construtor de cópia, devemos usar *this=copy ou não?

5.1. Diferença entre os construtores de cópia
5.1.1. - Primeira implementação:
    ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) // Chama o construtor de cópia de ClapTrap
    {
        std::cout << "ScavTrap Copy Constructor called" << std::endl;
    }
    Esta implementação chama o construtor de cópia de ClapTrap ao inicializar um objeto ScavTrap.
    A parte ClapTrap do objeto ScavTrap é inicializada com os valores copiados de copy.
    Contudo, os membros de ScavTrap que são diferentes da classe base (se houver) não são copiados explicitamente no corpo do construtor. 
    Se esses membros já forem inicializados de maneira adequada no construtor de ClapTrap, isso pode não ser um problema.
5.1.2. - Segunda implementação:
    ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
        std::cout << "ScavTrap copy constructor called" << std::endl;
        *this = other;
    }
    Esta implementação chama o construtor de cópia da classe base (ClapTrap) e depois faz uma atribuição com *this = other, 
    invocando assim o operador de atribuição de ScavTrap.
    Isto resulta em uma cópia duplicada: primeiro pelo construtor de cópia da classe base, e depois pelo operador de atribuição.
    Esta abordagem é menos eficiente, pois faz a cópia duas vezes, primeiro no construtor de cópia e depois no operador de atribuição.
5.1.3. - Qual das implementações está mais correta?
    A primeira implementação é a mais correta e eficiente, pois não faz uma cópia duplicada. Ela utiliza o construtor de cópia da classe 
    base para garantir que a parte da classe base é copiada corretamente, sem precisar chamar explicitamente o operador de atribuição depois.
    No subject do exercício, a expectativa é que o construtor de cópia siga o padrão usual de chamar o construtor da classe base 
    e evitar duplicação de cópia desnecessária. Portanto, a primeira abordagem está mais alinhada com essas expectativas
*/

/*
6 - No operador de atribuição, qual a diferença entre usar:
    6.1. Esta abordagem (a que estou a usar): 
        ScavTrap &ScavTrap::operator=(const ScavTrap &other) 
        {
            if (this != &other) 
            {
                ClapTrap::operator=(other); // Invoca o operador de atribuição da classe base
            }
        return *this;
        }

    Nesta implementação, o operador de atribuição de ScavTrap invoca explicitamente o 
    operador de atribuição da classe base (ClapTrap::operator=), garantindo que todos 
    os membros da classe base são corretamente copiados.
    Esta implementação delega a lógica de cópia dos atributos de ClapTrap para o operador 
    de atribuição da própria classe base.
    Isso é importante caso ClapTrap tenha atributos adicionais (não presentes em ScavTrap) 
    ou uma lógica especial no seu operador de atribuição.

    6.2. Ou esta abordagem (que colegas meus estão a usar):
        ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
        {
            std::cout << "ScavTrap Assignation Operator called" << std::endl;
            if (this != &copy)
            {
                _name = copy._name;
                _hitPoints = copy._hitPoints;
                _energyPoints = copy._energyPoints;
                _attackDamage = copy._attackDamage;
            }
            return *this;
        }
    
    Nesta implementação, o operador de atribuição está a copiar diretamente os 
    atributos do objeto copy para o objeto atual.
    Não invoca explicitamente o operador de atribuição da classe base (ClapTrap), 
    então apenas os atributos diretamente definidos em ScavTrap estão a ser copiados.
    Se ClapTrap tiver lógica adicional ou atributos que precisem ser copiados 
    durante a atribuição, essa lógica será ignorada, o que pode levar a problemas 
    se ClapTrap não for corretamente copiada.

6.3. - Qual das implementações está mais correta?

    A primeira implementação está mais correta e é mais robusta, porque invoca o 
    operador de atribuição da classe base (ClapTrap). Isto garante que todos os 
    membros da classe base também são corretamente copiados, o que é particularmente 
    importante se ClapTrap tiver mais atributos ou lógica no seu operador de atribuição.

De acordo com os princípios de herança e boas práticas, a primeira implementação é preferida. 
O subject do exercício geralmente espera que, em caso de herança, a inicialização e a cópia 
sejam feitas corretamente, incluindo os atributos da classe base.
*/

#include "ScavTrap.hpp"

// Mais info no ponto 4 do ficheiro Account.cpp CPP00ex02 e no ponto 1, 2 e 4 dos comments do ScavTrap.cpp do CPP03ex01.
ScavTrap::ScavTrap() : ClapTrap() // Se usar ScavTrap::ScavTrap() : ClapTrap()  ou ScavTrap::ScavTrap() : ClapTrap(void) chama o construtor padrão de ClapTrap, Se colocar ScavTrap::ScavTrap() : ClapTrap("ScavTrap") chama o construtor parametrizado de ClapTrap.
{
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    // Inicializa os atributos da classe ScavTrap
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

// Mais info no ponto 4 do ficheiro Account.cpp CPP00ex02 e no ponto 1, 2 e 4 dos comments do ScavTrap.cpp do CPP03ex01.
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Parametrized Constructor called" << std::endl;
    // Inicializa os atributos da classe ScavTrap
    _hitPoints = 100; // A diferença entre meter _hitPoints e this->_hitPoints é que o this->_hitPoints indica que estamos a referir a um membro da classe, enquanto o _hitPoints indica que estamos a referir a um argumento do construtor. E quando devemos usar um ou outro? (Mais info no ponto 4 do ficheiro Account.cpp CPP00ex02 e no ficheiro ScavTrap.cpp do CPP03ex01).
    _energyPoints = 50;
    _attackDamage = 20;
}

// ver mais info no ponto 5 dos comments do ScavTrap.cpp do CPP03ex01.
ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) // Chama o construtor de cópia de ClapTrap
{
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    //*this = copy;  // Usa o operador de atribuição
    //Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 7 do Fixed.cpp do CPP02ex01.
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

// Operador de atribuição: copia os valores do ScavTrap passado como parâmetro

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
    std::cout << "ScavTrap Assignation Operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy); // Invoca o operador de atribuição da classe base. Ver mais info no ponto 6 dos comments do ScavTrap.cpp do CPP03ex01. Ver mais info no ponto 1 e ponto 2 do FragTrap.cpp do CPP02ex02 e no ponto 6 do ScavTrap.cpp do CPP03ex01.
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints > 0  && _energyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--; // Energy points are reduced by 1 after each attack
    }
    else 
    {
        std::cout << "ScavTrap " << _name << " can't attack " << target << " because it has no health or energy points!" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    std::cout << "ScavTrap " << this->getName() << " takes " << amount << " points of damage!" << " remaining HP: " << this->getHitPoints() << std::endl;
    ClapTrap::takeDamage(amount);  // Mantém a lógica da função base
}

void ScavTrap::beRepaired(unsigned int amount)
{
    std::cout << "ScavTrap " << this->getName() << " is repaired by " << amount << " points!" << " remaining HP: " << this->getHitPoints() << std::endl;
    ClapTrap::beRepaired(amount);  // Mantém a lógica da função base
} 

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode." << std::endl;
}

std::ostream &operator<<(std::ostream &os, const ScavTrap &scavTrap)
{
    os << "ScavTrap " << scavTrap.getName() << " has " << scavTrap.getHitPoints()
       << " HP, " << scavTrap.getEnergyPoints() << " energy points and "
       << scavTrap.getAttackDamage() << " attack damage." << std::endl;
    return os;
}

/* // Virtual getter function // não pode ser usada. 
// Ver mais info no ponto 6 dos comments do ScavTrap.hpp do CPP03ex01, assim como no ponto 5 do main.cpp do CPP03ex01, 
// e no word nos:
//        Módulo 0 - 19.11.9.1.7.	Virtual e no 
//        Módulo 0 - 19.11.9.1.7.1.	Virtual Function & Virtual Member Function / Função Virtual & Função membro Virtual (módulo 4).
std::string ScavTrap::getClassType() const
{
    return "ScavTrap";
} */
