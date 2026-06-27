# Exercício 00 - Start with a few functions

## O que o exercício propõe?
O objetivo deste exercício é familiarizar-se com a escrita de funções genéricas (templates de funções) em C++.
Devem ser desenvolvidos três templates:
1. **`swap`**: Troca os valores de duas variáveis passadas por referência. Não retorna nada.
2. **`min`**: Compara os dois argumentos passados e retorna o menor deles. Se forem iguais em valor, deve obrigatoriamente retornar o segundo argumento.
3. **`max`**: Compara os dois argumentos passados e retorna o maior deles. Se forem iguais em valor, deve obrigatoriamente retornar o segundo argumento.

---

## Conhecimentos Propostos
1. **Templates de Funções (Programação Genérica)**: Escrita de código independente de tipo usando a palavra-chave `template <typename T>`. O compilador gerará a versão apropriada da função em tempo de compilação para cada tipo diferente utilizado.
2. **Passagem por Referência constante (`T const &` ou `const T &`)**: Uso de referências constantes para receber os parâmetros sem realizar cópias adicionais (otimizando a performance), ao mesmo tempo em que garante a imutabilidade dos parâmetros de entrada nas funções `min` e `max`.
3. **Requisitos de Operadores**: Compreensão de que qualquer tipo genérico `T` passado a esses templates precisa ter os operadores correspondentes sobrecarregados (como `<` ou `>` para comparação, e o construtor de cópia/atribuição para o `swap`).

---

## Como Executar

### 1. Compilação
No diretório `ex00`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `whatever`.

### 2. Execução
Execute o programa diretamente:
```bash
./whatever
```

Os testes cobrem:
- Valores inteiros simples.
- Strings.
- Números em ponto flutuante (`double`).
- Teste de igualdade de valores para comprovar que o segundo argumento é retornado (comprovado pela comparação de endereços de memória).
- Uso com uma classe customizada `Awesome` que sobrecarrega os operadores de comparação.
