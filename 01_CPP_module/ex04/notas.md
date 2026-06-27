# Exercício 04 - Sed is for losers

## O que o exercício propõe?
O objetivo deste exercício é criar um utilitário de substituição de strings em arquivos texto. O programa deve receber três argumentos: um nome de arquivo, e duas strings `s1` e `s2`. Ele deve abrir o arquivo, ler seu conteúdo, e criar um novo arquivo com a extensão `.replace` contendo o mesmo conteúdo do arquivo original, mas com todas as ocorrências de `s1` substituídas por `s2`.

O uso de funções de manipulação direta de regex ou comandos externos (como o próprio utilitário `sed`) é proibido. Toda a lógica de leitura, substituição e escrita deve ser feita em C++.

---

## Conhecimentos Propostos
1. **Manipulação de Arquivos e Streams (`std::ifstream` e `std::ofstream`)**: Abertura, leitura linha a linha ou em bloco, verificação de erros na abertura e escrita segura.
2. **Manipulação Avançada de `std::string`**:
   - Uso de `std::string::find` para localizar substrings sequencialmente.
   - Uso de `std::string::erase`, `std::string::insert` ou concatenação para realizar a substituição eficiente.
3. **Gerenciamento de Erros e Casos Extremos**:
   - Tratamento de arquivos inexistentes ou sem permissões de leitura/escrita.
   - Tratamento de argumentos inválidos na chamada do programa.
   - Lidar com strings de busca vazias (como `s1` vazia) para evitar loops infinitos.

---

## Como Executar

### 1. Compilação
No diretório `ex04`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `replace`.

### 2. Execução
Execute o programa passando os argumentos exigidos:
```bash
./replace <nome_do_arquivo> <string_a_ser_substituida> <nova_string>
```

#### Exemplo de Teste:
```bash
# Crie um arquivo de teste
echo "Olá Mundo! O mundo é maravilhoso." > teste.txt

# Execute a substituição
./replace teste.txt "mundo" "universo"

# Verifique o arquivo gerado
cat teste.txt.replace
# Saída esperada: "Olá Mundo! O universo é maravilhoso."
```
O Makefile também disponibiliza um comando de teste automatizado:
```bash
make test
```
