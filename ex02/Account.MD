//recriar o arquivo Account.cpp de forma que a execução do tests.cpp gere exatamente o mesmo output do arquivo .log (exceto o timestamp).

/_ [19920104_091532] index:0;amount:42;created
imprime um timestamp
imprime index:X;amount:Y;created
incrementa \_nbAccounts
soma no \_totalAmount _/

/_ static
construtores / destrutores
métodos const
organização
precisão de output _/

/\* 1 = {
int Account::\_nbAccounts = 0;
int Account::\_totalAmount = 0;
int Account::\_totalNbDeposits = 0;
int Account::\_totalNbWithdrawals = 0;

}
2 = [19920104_091532] index:X;amount:Y;created
3 = {
\_accountIndex = \_nbAccounts
\_amount = initial_deposit
\_nbDeposits = 0
\_nbWithdrawals = 0
incrementa \_nbAccounts
soma em \_totalAmount
}
4 = Destrutor ~Account()
log: index:X;amount:Y;closed

5 = displayAccountsInfos()
accounts:8;total:20049;deposits:0;withdrawals:0

6 = displayStatus() const
index:0;amount:42;deposits:0;withdrawals:0

7 = makeDeposit(int)
index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
componente {
guarda valor antigo
soma no \_amount
incrementa \_nbDeposits
atualiza \_totalAmount
incrementa \_totalNbDeposits
}

8 = makeWithdrawal(int)
recusado: index:0;p_amount:47;withdrawal:refused
aceito: index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
atualiza
{
\_amount
\_nbWithdrawals
\_totalAmount
\_totalNbWithdrawals

}
9 = checkAmount() const
Retorna \_amount \*/

O que é cobrado nesse exercício

static NÃO pertence ao objeto
➤ static pertence à classe inteira

| Atributo static       | Significado                         |
| --------------------- | ----------------------------------- |
| `_nbAccounts`         | Quantas contas existem              |
| `_totalAmount`        | Soma do dinheiro de TODAS as contas |
| `_totalNbDeposits`    | Quantos depósitos já foram feitos   |
| `_totalNbWithdrawals` | Quantos saques já foram feitos      |

REGRA:
Se a informação é do SISTEMA → static
Se a informação é da CONTA → atributo normal

| Arquivo       | Função                                     |
| ------------- | ------------------------------------------ |
| `Account.hpp` | **Contrato** (o que a classe promete)      |
| `Account.cpp` | **Implementação** (como a classe funciona) |
| `tests.cpp`   | **Cliente** (quem usa a classe)            |

./account > my.log
