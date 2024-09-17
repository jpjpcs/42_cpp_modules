/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:00:11 by joaosilva         #+#    #+#             */
/*   Updated: 2024/09/17 16:19:36 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Explicação Geral:
// 1. Construtor: Inicializa um objeto Account com um depósito inicial 
// e exibe uma mensagem de criação no formato dos logs.
// 2. Destrutor: Exibe uma mensagem de fechamento de conta.
// 3. Funções estáticas: Gerenciam contadores globais para o número 
// total de contas, depósitos e retiradas, e o valor total.
// 4. Função _displayTimestamp: Gera o timestamp necessário 
// para as mensagens de log, similar ao formato dos logs fornecidos.
// 5. Funções membro: Controlam depósitos, retiradas e exibem o status da conta.

// Explicação Detalhada Step-by-Step:
/*
Passo 1: Compreender o problema
O exercício pede que reconstruamos o ficheiro Account.cpp, que foi perdido. 
Temos à disposição três recursos principais:
1 - Ficheiro Account.hpp: Este define a interface (declaração da classe Account e seus métodos).
2 - Ficheiro tests.cpp: Contém testes para verificar o comportamento da classe Account. 
Isso nos dá pistas sobre como as funções devem ser implementadas e como os objetos devem se comportar.
3 - Logs de execução: Mostram os resultados de execuções anteriores da classe, 
indicando a estrutura de saída esperada para as funções.

Passo 2: Análise do ficheiro Account.hpp
O ficheiro Account.hpp contém a declaração da classe Account e todos os métodos que precisamos implementar. 
Aqui estão as partes mais importantes:
1 - Atributos estáticos:
_nbAccounts: Contagem total de contas.
_totalAmount: Montante total depositado em todas as contas.
_totalNbDeposits e _totalNbWithdrawals: Contagem total de depósitos e retiradas.
Esses atributos são estáticos, o que significa que eles são compartilhados 
por todas as instâncias da classe Account.
2 - Atributos não estáticos:
_accountIndex, _amount, _nbDeposits, _nbWithdrawals: Esses atributos são específicos de cada conta.
3 - Funções estáticas:
Funções como getNbAccounts, getTotalAmount, displayAccountsInfos são funções estáticas, ou seja, 
pertencem à classe em si e podem ser chamadas sem instanciar um objeto.
4 - Funções de instância:
Funções como makeDeposit, makeWithdrawal, e displayStatus são chamadas em 
instâncias da classe e trabalham nos dados específicos de cada conta.
5 - Função privada _displayTimestamp:
Vai ser usada para gerar a data e hora nos logs.

Passo 3: Análise dos logs
Os logs fornecidos são cruciais para entender o 
comportamento e a saída esperada de cada função. Por exemplo:
O log mostra que, ao criar uma conta, é exibida uma mensagem do tipo:
[19920104_091532] index:0;amount:42;created
Isso nos dá a dica de que ao instanciar uma conta, o seu índice e o 
depósito inicial devem ser mostrados.
Quando um depósito é feito, aparece algo assim:
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
Ou seja, o depósito deve atualizar o saldo e incrementar o número de depósitos, 
exibindo a informação no formato correto.

Passo 4: Implementação do ficheiro Account.cpp
Agora que temos a interface, o comportamento esperado e os logs,
podemos começar a implementar as funções. 
Aqui estão os detalhes de como cada uma foi implementada:
1- Construtor Account::Account
Quando uma nova conta é criada, o construtor é chamado. Ele deve:
1.1. -Inicializar a conta com um depósito inicial e atribuir o índice da conta 
1.2. - usando o contador estático _nbAccounts.
1.3. - Incrementar o total de contas e o valor total dos depósitos.
1.4. - Exibir uma mensagem de criação no formato:
[timestamp] index:X;amount:Y;created
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}
Aqui, _nbAccounts++ é usado para garantir que cada nova conta tenha um índice único. 
Também incrementamos o valor total depositado (_totalAmount += initial_deposit).
2 - Destrutor Account::~Account
Quando uma conta é destruída, a função exibe uma mensagem de encerramento:
Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}
Isso corresponde à saída dos logs ao fechar a conta.
3 - Funções estáticas
As funções estáticas acessam e retornam as variáveis estáticas 
que gerenciam o estado de todas as contas:

3.1. - getNbAccounts(): Retorna o número de contas.
3.2. - getTotalAmount(): Retorna o montante total.
3.3. - getNbDeposits(): Retorna o número total de depósitos.
3.4. getNbWithdrawals(): Retorna o número total de retiradas.
3.5. - displayAccountsInfos(): Mostra o estado geral das contas.
Exemplo da função displayAccountsInfos:
void Account::displayAccountsInfos(void) 
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
3.6. - Função _displayTimestamp
Essa função gera o timestamp no formato [YYYYMMDD_HHMMSS]:
void Account::_displayTimestamp(void) 
{
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << (1900 + ltm->tm_year);
    if (ltm->tm_mon < 9)
        std::cout << "0";
    std::cout << (1 + ltm->tm_mon);
    if (ltm->tm_mday < 10)
        std::cout << "0";
    std::cout << ltm->tm_mday << "_";
    if (ltm->tm_hour < 10)
        std::cout << "0";
    std::cout << ltm->tm_hour;
    if (ltm->tm_min < 10)
        std::cout << "0";
    std::cout << ltm->tm_min;
    if (ltm->tm_sec < 10)
        std::cout << "0";
    std::cout << ltm->tm_sec << "] ";
}
3.7. - Função makeDeposit
Essa função:
3.7.1. - Adiciona o depósito ao saldo da conta.
3.7.2. - Atualiza o número de depósitos da conta e o número total de depósitos.
3.7.3. -Exibe uma mensagem no formato:
[timestamp] index:X;p_amount:old_amount;deposit:Y;amount:new_amount;nb_deposits:Z
void Account::makeDeposit(int deposit) 
{
    _displayTimestamp();
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}
3.8. - Função makeWithdrawal
A função tenta retirar um valor da conta. 
Se o saldo for suficiente, atualiza o saldo, 
caso contrário, recusa a retirada:
bool Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}
3.9. - Função checkAmount e displayStatus 
Essas funções retornam o saldo da conta e exibem o status da conta, respectivamente:
int Account::checkAmount(void) const 
{
    return _amount;
}
void Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

Passo 5: Testes
Ao compilar este código em conjunto com tests.cpp, 
ele irá gerar a mesma saída dos logs fornecidos 
(com diferentes timestamps como é óbvio), 
o que indica que a implementação está correta.

*/


#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Inicializando variáveis estáticas
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Função auxiliar para exibir o timestamp atual
// void Account::_displayTimestamp(void) {
//    std::time_t now = std::time(nullptr);
//    std::tm* ltm = std::localtime(&now);
//    std::cout << "[" << (1900 + ltm->tm_year);
//    std::cout << std::setfill('0') << std::setw(2) << (1 + ltm->tm_mon);
//    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday << "_";
//    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
//    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
//    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec << "] ";
//}
void Account::_displayTimestamp()
{
    std::time_t time_in_sec = std::time(nullptr);
    std::tm* timemark = std::localtime(&time_in_sec);

    std::cout << "[" << (timemark->tm_year + 1900);
    std::cout << std::setfill('0') << std::setw(2) << (timemark->tm_mon + 1);
    std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << timemark->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << timemark->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << timemark->tm_sec << "] ";
}

// Construtor
// Account::Account(int initial_deposit) 
//    : _accountIndex(_nbAccounts++), 
//      _amount(initial_deposit), 
//      _nbDeposits(0), 
//      _nbWithdrawals(0) 
//{
//    _totalAmount += initial_deposit;
//    _displayTimestamp();
//    std::cout << "index:" << _accountIndex << ";
//amount:" << _amount << ";created" << std::endl;
//}
Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

// Destrutor
//Account::~Account()
//{
//    _displayTimestamp();
//    std::cout << "index:" << this->_accountIndex << ";";
//    std::cout << "amount:" << this->_amount << ";";
//    std::cout << "closed" << std::endl;
//}
Account::~Account(void) 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Funções estáticas
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// void Account::displayAccountsInfos()
//{
//    _displayTimestamp();
//    std::cout << "accounts:" << _nbAccounts << ";";
//    std::cout << "total:" << _totalAmount << ";";
//    std::cout << "deposits:" << _totalNbDeposits << ";";
//    std::cout << "withdrawals:" << _totalNbWithdrawals 
// << std::endl;
//}
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Funções membro
//void Account::makeDeposit(int deposit)
//{
//    int p_amount = this->_amount;
//    this->_amount += deposit;
//    this->_nbDeposits++;
//    _totalAmount += deposit;
//    _totalNbDeposits++;
//
//    _displayTimestamp();
//    std::cout << "index:" << this->_accountIndex << ";";
//    std::cout << "p_amount:" << p_amount << ";";
//    std::cout << "deposit:" << deposit << ";";
//    std::cout << "amount:" << this->_amount << ";";
//    std::cout << "nb_deposits:" << this->_nbDeposits << 
// std::endl;
// }
void Account::makeDeposit(int deposit) 
{
    _displayTimestamp();
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

//bool Account::makeWithdrawal(int withdrawal)
//{
//    _displayTimestamp();
//    std::cout << "index:" << this->_accountIndex << ";";
//    std::cout << "p_amount:" << this->_amount << ";";
//
//    if (this->_amount < withdrawal)
//    {
//        std::cout << "withdrawal:refused" << std::endl;
//        return false;
//    }
//
//    this->_amount -= withdrawal;
//    this->_nbWithdrawals++;
//    _totalAmount -= withdrawal;
//    _totalNbWithdrawals++;
//
//    std::cout << "withdrawal:" << withdrawal << ";";
//    std::cout << "amount:" << this->_amount << ";";
//    std::cout << "nb_withdrawals:" << 
// this->_nbWithdrawals << std::endl;
//
//    return true;
//}
bool Account::makeWithdrawal(int withdrawal) 
{
    _displayTimestamp();
    int p_amount = _amount;
    if (withdrawal > _amount) {
        std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount(void) const 
{
    return _amount;
}

//void Account::displayStatus() const
//{
//    _displayTimestamp();
//    std::cout << "index:" << this->_accountIndex << ";";
//    std::cout << "amount:" << this->_amount << ";";
//    std::cout << "deposits:" << this->_nbDeposits << "";
//    std::cout << "withdrawals:" << this->_nbWithdrawals 
// << std::endl;
// }
void Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

