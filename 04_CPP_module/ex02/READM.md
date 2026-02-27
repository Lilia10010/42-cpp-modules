| Código                    | Funciona? | Por quê?            |
| ------------------------- | --------- | ------------------- |
| `Animal a;`               | ❌        | Classe é abstrata   |
| `Animal* a;`              | ✅        | É só ponteiro       |
| `new Animal()`            | ❌        | Não pode instanciar |
| `new Dog()` via `Animal*` | ✅        | Dog implementa tudo |

🎯 Resumo Final Mental

Classe abstrata:

Modelo conceitual que não pode existir sozinho.

Método virtual:

Permite decisão em tempo de execução.

Método virtual puro:

Obriga implementação e torna classe abstrata.

Contrato:

Regras obrigatórias para classes filhas.

Polimorfismo básico:

Permite sobrescrever comportamento.

Polimorfismo avançado:

Define arquitetura e obriga comportamento.

vtable:

Tabela interna usada para decidir qual função chamar dinamicamente.

🎯 Diferença entre virtual e virtual puro
| Tipo | Pode instanciar? | Tem implementação? | Obriga a sobrescrever? |
| ------------ | ---------------- | ------------------ | ---------------------- |
| virtual | ✅ sim | ✅ pode ter | ❌ não |
| virtual puro | ❌ não | ❌ não | ✅ sim |

O que é Método Virtual Puro?

É um método virtual com = 0.

virtual void makeSound() const = 0;

ignifica:

Não há implementação na classe base

A classe vira abstrata

As subclasses são obrigadas a implementar

O que é Método Virtual?
🔹 Problema que ele resolve

Sem virtual, C++ decide qual função chamar em tempo de compilação.

Com virtual, C++ decide qual função chamar em tempo de execução.

🧠 Definição técnica

Uma classe abstrata é:

Uma classe que possui pelo menos um método virtual puro.

Ela:

❌ não pode ser instanciada

✅ pode ser usada como classe base

✅ define um contrato

📌 Quando usar classe abstrata?

Use quando:

Você quer definir uma interface comum

Você quer impedir instanciamento direto

Você quer forçar subclasses a implementar algo

Você está modelando um conceito genérico

Exemplos reais:

Shape (forma geométrica)

Vehicle

Character em jogo

Logger

File
