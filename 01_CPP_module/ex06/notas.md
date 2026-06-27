# Exercício 06 - Harl filter

## O que o exercício propõe?
O objetivo deste exercício é estender a classe `Harl` desenvolvida no exercício anterior, adicionando uma funcionalidade de filtragem de logs.

O programa deve aceitar um único argumento de linha de comando que representa o nível mínimo de reclamação que o usuário deseja exibir. A partir desse nível inicial informado, o programa deve exibir essa reclamação e todas as outras de nível superior (por exemplo, ao escolher `WARNING`, serão exibidos `WARNING` e `ERROR`).

Caso o argumento passado não seja um nível válido, deve ser exibido uma mensagem padrão engraçada: `[ Probably complaining about insignificant problems ]`.

---

## Conhecimentos Propostos
1. **Controle de Fluxo com `switch`**: Uso de instruções `switch` em C++ para direcionar a execução de acordo com o nível numérico correspondente da string de entrada.
2. **Queda de Fluxo (`Fallthrough`)**: Compreensão de como o fluxo de um `switch` continua executando as declarações subsequentes (`case` abaixo) quando a instrução `break` é intencionalmente omitida. É o recurso chave que possibilita a exibição acumulativa dos logs de níveis superiores.
3. **Conversão de Strings para Enumeradores**: Mapear uma string dinâmica de linha de comando para valores de um `enum` para que possa ser usada na condição de um `switch`.

---

## Como Executar

### 1. Compilação
No diretório `ex06`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `harlFilter`.

### 2. Execução
Execute o programa passando o nível inicial desejado como parâmetro:
```bash
./harlFilter <NIVEL>
```

#### Exemplos de Execução:
```bash
# Filtrando a partir de WARNING (exibe WARNING e ERROR)
./harlFilter WARNING

# Filtrando a partir de DEBUG (exibe todos os logs)
./harlFilter DEBUG

# Nível inválido ou irrelevante
./harlFilter "SALADA"
```
