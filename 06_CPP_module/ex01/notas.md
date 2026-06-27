# Exercício 01 - Serializer

## O que o exercício propõe?
O objetivo deste exercício é criar uma classe `Serializer` estática com dois métodos:
- `uintptr_t serialize(Data* ptr)`: Recebe um ponteiro para a estrutura `Data` e o converte para um tipo inteiro sem sinal `uintptr_t`.
- `Data* deserialize(uintptr_t raw)`: Recebe o valor inteiro sem sinal `uintptr_t` e o converte de volta para um ponteiro de `Data`.

Ao final, deve ser verificado se o ponteiro retornado por `deserialize` é exatamente igual ao ponteiro original passado para `serialize`, e se os dados originais permanecem intactos.

---

## Conhecimentos Propostos
1. **Reinterpretação de Tipos (`reinterpret_cast`)**: Foco no uso de `reinterpret_cast`, utilizado para conversões entre tipos de ponteiros não relacionados ou conversões entre ponteiros e tipos inteiros. É o cast mais permissivo e de mais baixo nível no C++.
2. **Endereçamento de Memória e Inteiros**: Compreensão de que ponteiros são simplesmente números representando endereços de memória.
3. **Tipo `uintptr_t`**: Introdução ao tipo inteiro `uintptr_t` (definido em `<stdint.h>`), que possui tamanho garantido para armazenar um ponteiro sem perda de dados/truncamento, independentemente da arquitetura do processador (32-bit ou 64-bit).

---

## Como Executar

### 1. Compilação
No diretório `ex01`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `serialize`.

### 2. Execução
Execute o programa diretamente para ver os testes automatizados rodando:
```bash
./serialize
```

O programa executará três testes principais:
1. **Stack Allocated**: Objeto alocado na pilha.
2. **Heap Allocated**: Objeto alocado dinamicamente na memória heap.
3. **Null Pointer**: Garante que o comportamento com ponteiros nulos seja preservado.

Para cada teste, a saída mostrará o endereço do ponteiro original, o valor serializado (em formato decimal e hexadecimal), e o ponteiro desserializado, confirmando que os dados e endereços coincidem perfeitamente.
