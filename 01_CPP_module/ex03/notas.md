# Exercício 03 - Violence and-a-half

## O que o exercício propõe?
O objetivo deste exercício é aplicar a distinção entre referências e ponteiros em um caso prático de design de classes.

São criadas duas classes de personagens, `HumanA` e `HumanB`, que compartilham o uso de um mesmo objeto de arma (`Weapon`). A forma como cada um armazena a arma é diferente:
- **`HumanA`**: Sempre tem uma arma desde o momento de sua criação. A arma nunca é alterada para `NULL`.
- **`HumanB`**: Pode ou não possuir uma arma no momento da criação (inicia desarmado) e pode receber/alterar a arma durante o tempo de execução por um método `setWeapon`.

O desafio é decidir qual classe usará uma **referência** e qual usará um **ponteiro** para manter o vínculo com o objeto `Weapon`.

---

## Conhecimentos Propostos
1. **Escolha de Design (Ponteiros vs. Referências)**:
   - **Referências**: Usadas quando a associação a um objeto externo é obrigatória e permanente ao longo do tempo de vida do objeto contentor (caso do `HumanA`). Exige a inicialização obrigatória na lista de inicialização do construtor.
   - **Ponteiros**: Usados quando a associação é opcional, pode iniciar vazia (`NULL`) ou ser modificada em tempo de execução (caso do `HumanB`).
2. **Listas de Inicialização do Construtor**: Como inicializar atributos do tipo referência em C++ (pois referências não podem ser declaradas sem inicialização).
3. **Modificações por Efeito Colateral**: Garantir que as alterações no objeto `Weapon` original (usando `setType`) se reflitam automaticamente nos ataques de `HumanA` e `HumanB`, comprovando que as classes não guardaram uma cópia do valor da arma, mas sim uma referência direta/ponteiro ao objeto original.

---

## Como Executar

### 1. Compilação
No diretório `ex03`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `weapon`.

### 2. Execução
Execute o binário para observar os ataques dos humanos:
```bash
./weapon
```
Verifique no console que quando o tipo da arma é modificado na função `main`, o próximo ataque do humano reflete instantaneamente o novo tipo da arma.
