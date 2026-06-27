# Exercício 02 - HI THIS IS BRAIN

## O que o exercício propõe?
O objetivo deste exercício é consolidar a compreensão básica sobre a manipulação de strings em C++ usando referências e ponteiros, comparando a forma como armazenam e acessam valores na memória.

O programa deve:
1. Declarar uma string contendo `"HI THIS IS BRAIN"`.
2. Declarar um ponteiro (`stringPTR`) para a string.
3. Declarar uma referência (`stringREF`) para a string.
4. Exibir o endereço de memória da string original, o endereço armazenado no ponteiro e o endereço referenciado pela referência.
5. Exibir o valor da string original, o valor apontado pelo ponteiro e o valor referenciado pela referência.

---

## Conhecimentos Propostos
1. **Diferença entre Ponteiro e Referência**:
   - **Ponteiro (`Type*`)**: É uma variável independente que armazena explicitamente o endereço de memória de outra variável. Pode ser nulo (`NULL`), reatribuído para apontar para outras variáveis, e necessita do operador de desreferenciação (`*`) para acessar o valor apontado.
   - **Referência (`Type&`)**: É um apelido (alias) constante para uma variável existente. Não ocupa um espaço físico de variável própria na pilha que possa ser modificado para apontar para outro lugar após a inicialização. Não pode ser nula e é usada sintaticamente como se fosse a própria variável original (sem a necessidade de operadores especiais).
2. **Sintaxe de Referenciação (`&`) e Desreferenciação (`*`)**: Prática e visualização dos endereços e valores associados a cada representação.

---

## Como Executar

### 1. Compilação
No diretório `ex02`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `ihThisIsBrain`.

### 2. Execução
Execute o binário para ver a exibição dos endereços de memória e valores:
```bash
./ihThisIsBrain
```
Observe que todos os três endereços exibidos no console são idênticos, provando que tanto o ponteiro quanto a referência atuam sobre a mesma string na memória.
