# Exercício 02 - Real Type Detection

## O que o exercício propõe?
O objetivo deste exercício é identificar o tipo real de um objeto em tempo de execução sem utilizar o operador `typeid` nem a biblioteca `<typeinfo>`.

Para isso, é criada uma classe base `Base` (com um destrutor virtual para torná-la polimórfica) e três classes derivadas vazias: `A`, `B` e `C`.
Devem ser implementadas as seguintes funções:
1. **`Base* generate(void)`**: Instancia aleatoriamente `A`, `B` ou `C` e retorna o ponteiro correspondente como um tipo `Base*`.
2. **`void identify(Base* p)`**: Imprime a classe real do objeto (`A`, `B` ou `C`) utilizando conversão por ponteiro. Se a conversão falhar, ela simplesmente não faz nada (ou neste projeto melhorado, trata com segurança).
3. **`void identify(Base& p)`**: Imprime a classe real do objeto utilizando conversão por referência. É proibido usar ponteiros aqui, portanto a falha de conversão deve ser capturada através de exceções (`std::exception`).

---

## Conhecimentos Propostos
1. **Polimorfismo em Tempo de Execução (RTTI)**: Entendimento de como o compilador C++ armazena informações de tipo em tempo de execução para classes polimórficas (classes que possuem pelo menos uma função virtual, como o destrutor virtual de `Base`).
2. **Cast Dinâmico (`dynamic_cast`)**: Uso de `dynamic_cast` para realizar downcasting seguro (conversão de uma classe base para uma classe derivada na hierarquia).
3. **Diferença de Comportamento do Cast**:
   - **Ponteiros (`Base*`)**: Se o cast dinâmico falhar (ou se o ponteiro for nulo), o operador retorna `NULL`.
   - **Referências (`Base&`)**: Como referências não podem ser nulas em C++, uma falha no cast dinâmico lança uma exceção `std::bad_cast` (que herda de `std::exception`). Assim, é obrigatório o uso de blocos `try-catch`.

---

## Como Executar

### 1. Compilação
No diretório `ex02`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `identify`.

### 2. Execução
Execute o programa diretamente para ver os testes de identificação:
```bash
./identify
```

O programa executará:
1. **Parte 1 (Identificação de Instâncias Aleatórias)**: Gera 5 instâncias aleatórias de classes derivadas (`A`, `B` ou `C`), identificando cada uma delas tanto usando a função de ponteiros quanto a de referências.
2. **Parte 2 (Casos Extremos)**:
   - **Ponteiro Nulo**: Demonstra o tratamento correto de ponteiros `NULL` sem gerar falhas de segmentação.
   - **Instância Pura de Base**: Demonstra o comportamento quando um objeto é do tipo `Base` (nem `A`, nem `B`, nem `C`). O cast dinâmico para as subclasses falhará tanto via ponteiro quanto via referência, exibindo a mensagem apropriada.
