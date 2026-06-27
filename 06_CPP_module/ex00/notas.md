# Exercício 00 - Scalar Converter

## O que o exercício propõe?
O objetivo deste exercício é criar uma classe estática `ScalarConverter` que converte uma string representando um literal de tipo escalar (caractere, inteiro, número de ponto flutuante de precisão simples `float` ou precisão dupla `double`) para seus respectivos tipos e os exibe no terminal.

O programa deve detectar o tipo do literal inserido, convertê-lo apropriadamente para o tipo real e, em seguida, convertê-lo explicitamente (usando `static_cast`) para os outros três tipos. Se uma conversão for impossível ou estourar os limites do tipo (overflow/underflow), deve exibir `impossible`.

### Exemplos de Literais Suportados:
- **char**: `'a'`, `'*'`
- **int**: `0`, `-42`, `42`
- **float**: `0.0f`, `-4.2f`, `4.2f`, `nanf`, `+inff`, `-inff`
- **double**: `0.0`, `-4.2`, `4.2`, `nan`, `+inf`, `-inf`

---

## Conhecimentos Propostos
1. **Casts em C++**: Foco principal no uso de `static_cast` para conversões seguras e explícitas de tipos primitivos (de `double` para `char`, `int`, `float`).
2. **Classes Estáticas**: Criação de uma classe que não pode ser instanciada (construtores, destrutor e operador de atribuição privados).
3. **Tratamento de Limites e Pseudo-literais**: Lidar com valores especiais do padrão IEEE 754 como `NaN` (Not a Number) e `inf` (Infinity), e gerenciar limites numéricos usando `<climits>`, `<cfloat>` e `<limits>`.
4. **Parsing de Strings**: Validação e análise de strings para correspondência exata dos formatos literais de C++.

---

## Como Executar

### 1. Compilação
No diretório `ex00`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `convert`.

### 2. Execução
Execute o programa passando o literal desejado como argumento:
```bash
./convert <literal>
```

#### Exemplos de Teste:
```bash
# Teste com caractere
./convert 'a'

# Teste com inteiro
./convert 42

# Teste com float
./convert 4.2f

# Teste com double
./convert 42.42

# Teste com pseudo-literais
./convert nan
./convert -inff

# Teste com valor fora dos limites
./convert 2147483648
```
