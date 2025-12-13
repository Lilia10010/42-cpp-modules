## Conceitos Fundamentais

### Atributos Static

- `static` não pertence ao objeto
- `static` pertence à classe inteira

### Regra de Uso

- Se a informação é do **SISTEMA** → `static`
- Se a informação é da **CONTA** → atributo normal

### Variáveis Estáticas da Classe

```cpp
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
```

```

| Atributo static | Significado |
|----------------|-------------|
| `_nbAccounts` | Quantas contas existem |
| `_totalAmount` | Soma do dinheiro de TODAS as contas |
| `_totalNbDeposits` | Quantos depósitos já foram feitos |
| `_totalNbWithdrawals` | Quantos saques já foram feitos |

---

## Implementação dos Métodos

### Construtor — `Account(int initial_deposit)`

**Atribuições:**
- `_accountIndex = _nbAccounts`
- `_amount = initial_deposit`
- `_nbDeposits = 0`
- `_nbWithdrawals = 0`

**Atualizações globais:**
- Incrementa `_nbAccounts`
- Soma `initial_deposit` em `_totalAmount`

**Log:**
```

[19920104_091532] index:X;amount:Y;created

```

### Destrutor — `~Account()`

**Log:**
```

[timestamp] index:X;amount:Y;closed

```

### `displayAccountsInfos()`

Exibe informações globais do sistema.

**Log:**
```

[timestamp] accounts:8;total:20049;deposits:0;withdrawals:0

```

### `displayStatus() const`

Exibe informações da conta individual.

**Log:**
```

[timestamp] index:0;amount:42;deposits:0;withdrawals:0

```

### `makeDeposit(int deposit)`

**Operações:**
- Guarda valor antigo
- Soma `deposit` no `_amount`
- Incrementa `_nbDeposits`
- Atualiza `_totalAmount`
- Incrementa `_totalNbDeposits`

**Log:**
```

[timestamp] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

```

### `makeWithdrawal(int withdrawal)`

#### Caso recusado
**Condição:** `_amount < withdrawal`

**Log:**
```

[timestamp] index:0;p_amount:47;withdrawal:refused

```

#### Caso aceito

**Atualizações:**
- `_amount` (subtrai o valor)
- `_nbWithdrawals` (incrementa)
- `_totalAmount` (atualiza)
- `_totalNbWithdrawals` (incrementa)

**Log:**
```

[timestamp] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

Organização dos Arquivos:

| Arquivo       | Função                         |
| ------------- | ------------------------------ |
| `Account.hpp` | Contrato da classe (interface) |
| `Account.cpp` | Implementação da classe        |
| `tests.cpp`   | Cliente que utiliza a classe   |

### Geração de Log

```
./account > my.log
diff my.log 19920104_091532.log
```

por conta do timestamp o diff sempre mostrará diferenças, mas o restante do conteúdo deve ser idêntico.

```
diff my.log 19920104_091532.log
```
