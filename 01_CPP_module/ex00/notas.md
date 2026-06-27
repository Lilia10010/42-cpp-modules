# Exercício 00 - BraiiiiiiinnnzzzZ

## O que o exercício propõe?
O objetivo deste exercício é criar uma classe `Zombie` básica e implementar duas formas distintas de criar e gerenciar o ciclo de vida dessas instâncias, comparando a alocação de memória na pilha (stack) e no monte (heap).

Devem ser implementadas as seguintes funções:
1. **`Zombie* newZombie(std::string name)`**: Cria um zombie, aloca-o dinamicamente na heap, inicializa seu nome e retorna o ponteiro correspondente. O ciclo de vida do zombie fica sob responsabilidade do chamador da função, que deve deletá-lo manualmente.
2. **`void randomChump(std::string name)`**: Cria um zombie alocado localmente na stack, faz com que ele se anuncie e, ao fim do escopo da função, o objeto é automaticamente destruído pelo compilador.

---

## Conhecimentos Propostos
1. **Alocação na Stack vs. Heap**:
   - **Stack (Pilha)**: Alocação automática e extremamente rápida de variáveis locais. A memória é liberada assim que o escopo de execução (`{}`) termina. Ideal para objetos temporários de curta duração.
   - **Heap (Monte)**: Alocação dinâmica de memória que persiste além do escopo de criação. O programador tem total controle de quando o objeto nasce (`new`) e quando ele morre (`delete`).
2. **Ciclo de vida do Objeto (Construtores e Destrutores)**: Compreender o papel do destrutor (`~Zombie()`) na liberação de recursos adicionais e a importância de sempre chamar `delete` para evitar vazamentos de memória (memory leaks).

---

## Como Executar

### 1. Compilação
No diretório `ex00`, utilize o Makefile para compilar o código:
```bash
make
```
Isso gerará o executável `zombie`.

### 2. Execução
Execute o binário para observar o comportamento de alocação e destruição automática (stack) vs manual (heap):
```bash
./zombie
```
Observe nas mensagens do terminal a ordem de execução do anúncio e da destruição de cada zombie.
