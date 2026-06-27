# Exercício 05 - Harl 2.0

## O que o exercício propõe?
O objetivo deste exercício é implementar uma classe `Harl` que reclama sobre diferentes situações com base em quatro níveis de gravidade: `DEBUG`, `INFO`, `WARNING` e `ERROR`.

Para resolver isso, o programa **não deve usar** uma grande quantidade de estruturas `if/else if/else`. Em vez disso, deve ser implementado o uso de **ponteiros para funções membro** (pointers to member functions) da própria classe `Harl`, mapeando a string do nível diretamente para o método correspondente.

---

## Conhecimentos Propostos
1. **Ponteiros para Funções Membro em C++**: Compreender a sintaxe especial de definição e chamada de ponteiros para funções membro de uma classe. Ao contrário de ponteiros para funções globais simples, eles dependem do escopo de um objeto específico para serem chamados (`(this->*fptr)()`).
2. **Mapeamento de Ações por String**: Criação de arrays de correspondência contendo as chaves (ex: `"DEBUG"`) e os ponteiros para os métodos (`&Harl::debug`). Isso permite despachar chamadas dinamicamente sem poluir o código com condicionais.
3. **Encapsulamento**: Manter as funções de nível de reclamação (`debug`, `info`, `warning`, `error`) privadas e expor apenas a interface pública `complain(std::string level)`.

---

## Como Executar

### 1. Compilação
No diretório `ex05`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `harl`.

### 2. Execução
Execute o executável diretamente. Ele rodará os testes básicos de reclamações configurados na função `main`:
```bash
./harl
```
Você verá as mensagens de log correspondentes a cada nível de reclamação exibidas no terminal.
