# Exercício 01 - Iter

## O que o exercício propõe?
O objetivo deste exercício é criar um template de função global `iter` que itera sobre todos os elementos de um array e aplica uma função passada como parâmetro a cada um desses elementos.

A função `iter` deve receber três parâmetros:
1. O endereço do array a ser percorrido.
2. O comprimento (tamanho) do array (do tipo `size_t`).
3. Uma função (ou ponteiro de função) a ser chamada para cada elemento. Essa função parâmetro pode opcionalmente aceitar o elemento por referência para modificá-lo ou por referência constante para apenas realizar operações de leitura.

---

## Conhecimentos Propostos
1. **Iteração Genérica (Templates de Ordem Superior)**: Desenvolvimento de um template que aceita outra função como argumento.
2. **Funções e Ponteiros para Funções**: Compreensão de como ponteiros para funções normais ou instâncias de templates de funções podem ser passados como parâmetros para outras funções.
3. **Assinaturas Constantes e Modificadoras**:
   - Se o array for de elementos constantes (`const T *`), a função chamada por `iter` deve receber o parâmetro como `const T &`.
   - Se o array for modificável (`T *`), a função pode receber o parâmetro como `T &` para realizar alterações nos elementos originais do array.

---

## Como Executar

### 1. Compilação
No diretório `ex01`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `iter`. (Nota: O Makefile utiliza a regra `all` para compilar).

### 2. Execução
Execute o binário diretamente:
```bash
./iter
```

Os testes cobrem:
- Iteração e mutação em um array de inteiros (incremento).
- Iteração e mutação em um array de caracteres (conversão para maiúsculo).
- Iteração em modo somente leitura (exibindo valores de string).
- Compatibilidade de leitura com arrays de dados constantes (`const int`).
- Compatibilidade com arrays de objetos de classe customizada (`Awesome`).
