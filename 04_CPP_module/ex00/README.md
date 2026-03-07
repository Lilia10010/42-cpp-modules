# ex00 — Polymorphism (Polimorfismo)

## 🎯 O que este exercício ensina?

Este exercício introduz um dos conceitos mais fundamentais da Programação Orientada a Objetos (POO): o **polimorfismo em tempo de execução**, usando **funções virtuais** (`virtual`) em C++.

---

## 📚 Conceitos abordados

### 1. Herança (`public` inheritance)
`Cat` e `Dog` herdam de `Animal`. Isso significa que eles **são** animais e podem ser tratados como tal:

```cpp
class Cat : public Animal { ... };
class Dog : public Animal { ... };
```

### 2. Funções Virtuais (`virtual`)
Quando um método é marcado como `virtual` na classe base, o C++ garante que a versão correta do método será chamada **em tempo de execução**, mesmo quando acessado por um ponteiro da classe base.

```cpp
// Animal.hpp
virtual void makeSound() const;
```

Sem `virtual`, o compilador decide qual função chamar **em tempo de compilação** (dispatch estático), baseado no tipo do ponteiro — não do objeto real. Com `virtual`, o dispatch é **dinâmico**.

### 3. Destrutor Virtual (`virtual ~Animal()`)
**Crítico para evitar vazamento de memória!** Quando deletamos um objeto `Cat` por um ponteiro `Animal*`, o destrutor da classe derivada (`Cat`) precisa ser chamado corretamente. Sem `virtual` no destrutor, somente o destrutor de `Animal` seria chamado, causando **undefined behavior** (comportamento indefinido).

```cpp
virtual ~Animal();  // garante que ~Cat() e ~Dog() sejam chamados corretamente
```

### 4. "Wrong" Polymorphism — o contraexemplo
O exercício inclui `WrongAnimal` e `WrongCat` **intencionalmente** para demonstrar o que acontece sem `virtual`:

```cpp
// WrongAnimal: makeSound() NÃO é virtual
void makeSound() const;

// No main:
const WrongAnimal* wrongCat = new WrongCat();
wrongCat->makeSound(); // ⚠️ Chama o makeSound() de WrongAnimal, NÃO de WrongCat!
```

**Resultado:** mesmo que o objeto real seja um `WrongCat` (que faz "Miaauu???"), o programa exibe o som genérico de `WrongAnimal` — o polimorfismo **não** funciona sem `virtual`.

---

## 🔍 Como funciona na prática

```cpp
const Animal* dog = new Dog();   // ponteiro Animal, objeto Dog
const Animal* cat = new Cat();   // ponteiro Animal, objeto Cat

dog->makeSound();   // chama Dog::makeSound()  → "Woof! 🐶"
cat->makeSound();   // chama Cat::makeSound()  → "Miaaaaaaaauu 🙀"
meta->makeSound();  // chama Animal::makeSound() → "* generic animal sound *"
```

O C++ consulta a **vtable** (tabela virtual) do objeto para descobrir qual implementação chamar.

---

## 🏗️ Estrutura de Classes

```
        Animal
       /      \
     Cat      Dog
   
   WrongAnimal
       |
    WrongCat
```

---

## ✅ Regra da Forma Ortodoxa Canônica (OCF)
Todas as classes implementam os 4 elementos obrigatórios:
| Elemento | Função |
|---|---|
| Construtor padrão | Inicializa o objeto |
| Construtor de cópia | Copia todos os atributos |
| Operador de atribuição `=` | Copia com verificação `this != &other` |
| Destrutor | Libera recursos |

---

## 💡 Resumo do aprendizado

| Conceito | Com `virtual` | Sem `virtual` |
|---|---|---|
| Dispatch de método | Dinâmico (runtime) | Estático (compile-time) |
| Método chamado | Do objeto real | Do tipo do ponteiro |
| Destrutor seguro | ✅ Sim | ❌ Não |
| Comportamento | Polimorfismo real | Falso polimorfismo |

> **Regra de ouro:** sempre que uma classe for usada como base para herança e você precisar de polimorfismo, marque os métodos relevantes (especialmente o destrutor) com `virtual`.
