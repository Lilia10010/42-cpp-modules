# Exercício 02 - Array

## O que o exercício propõe?
O objetivo deste exercício é desenvolver um template de classe `Array` que simula um array dinâmico, fornecendo comportamento seguro em relação ao gerenciamento de memória e acesso a índices em C++.

A classe deve possuir:
1. Construtor padrão (sem argumentos): cria um array vazio.
2. Construtor parametrizado `Array(unsigned int n)`: aloca um array de `n` elementos, inicializando cada elemento com o seu valor padrão (por exemplo, 0 para inteiros).
3. Construtor de cópia e operador de atribuição sobrecarregado: que implementem obrigatoriamente a **cópia profunda (deep copy)**, garantindo que a modificação de uma cópia não altere o array original.
4. Operador de indexação sobrecarregado `operator[]` para acesso de leitura/escrita, e uma versão `const` para acesso somente leitura. Ambos devem lançar uma exceção do tipo `std::exception` se o índice estiver fora dos limites do array.
5. Função membro `size()` que retorna a quantidade de elementos no array (sem modificar o estado da classe).

---

## Conhecimentos Propostos
1. **Templates de Classes**: Criação de tipos compostos genéricos (`template <typename T> class Array`).
2. **Definições e Implementações de Templates (`.tpp` / `.hpp`)**: Compreensão de que, por serem resolvidos em tempo de compilação, a implementação dos métodos de templates deve estar acessível no cabeçalho. O uso de arquivos `.tpp` incluídos ao final do `.hpp` ajuda a organizar a separação de declaração e implementação.
3. **Gerenciamento Seguro de Memória (Alocação Dinâmica)**: Uso correto de `new[]` e `delete[]` nos construtores, operadores de atribuição e destrutor para evitar vazamentos de memória (memory leaks) e ponteiros órfãos (dangling pointers).
4. **Sobrecarga de Operadores (`operator[]`)**: Implementação de dois operadores de indexação (um mutável e um constante) para garantir const-correctness.
5. **Tratamento de Exceções (`try-catch`)**: Lançar e capturar exceções customizadas derivadas de `std::exception` para impedir acessos inválidos de memória (impedindo Segmentation Faults e promovendo estabilidade ao código).

---

## Como Executar

### 1. Compilação
No diretório `ex02`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `array`.

### 2. Execução
Execute o binário para iniciar a bateria de testes automatizados:
```bash
./array
```

Os testes automatizados cobrem:
- **Test 1**: Criação e acesso a um array vazio (espera-se que lance exceção ao tentar acessar).
- **Test 2**: Criação de um array constante e acesso somente leitura aos seus elementos inicializados.
- **Test 3**: Verificação de cópia profunda (deep copy) em cópias por atribuição e por construtor de cópia, verificando se a alteração das cópias não interfere no original.
- **Test 4**: Compatibilidade do template com tipos complexos (como `std::string`).
- **Test 5**: Teste original do assunto (Mirror Test) onde 750 elementos aleatórios são clonados, seus valores são comparados sequencialmente e testes de estouro de limites (índices negativos e acima do tamanho máximo) são executados e tratados de forma segura.
