# Exercício 01 - Moar brainz deeead

## O que o exercício propõe?
O objetivo deste exercício é criar um exército de zombies alocados em lote usando uma única instrução de alocação de memória em C++.

Deve ser implementada a seguinte função:
- **`Zombie* zombieHorde(int N, std::string name)`**: Aloca dinamicamente na heap um array de `N` zombies de uma única vez. A função deve configurar o nome de cada zombie com o nome fornecido no argumento e retornar um ponteiro para o primeiro elemento do array. O chamador da função deve destruir corretamente todos os zombies em um único comando no final de sua execução.

---

## Conhecimentos Propostos
1. **Alocação de Arrays Dinâmicos (`new[]`)**: Compreender como funciona a alocação de múltiplos objetos sequenciais na memória heap usando o operador `new[]`.
2. **Destruição de Arrays Dinâmicos (`delete[]`)**: Entender que para desalocar múltiplos elementos criados com `new[]`, é obrigatório o uso do operador `delete[]` (com colchetes). A não utilização dos colchetes causará comportamento indefinido e vazamentos de memória de todos os elementos subsequentes ao primeiro.
3. **Inicialização em Lote**: Técnicas para inicializar dados em membros de um array de objetos após a alocação (visto que o construtor padrão não recebe argumentos ao ser chamado por `new[]`).

---

## Como Executar

### 1. Compilação
No diretório `ex01`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `zombieHorde`.

### 2. Execução
Execute o binário para observar a horda sendo instanciada, anunciada e devidamente destruída:
```bash
./zombieHorde
```
