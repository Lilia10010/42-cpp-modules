# ex01 — Deep Copy & Memory Management (Cópia Profunda)

## 🎯 O que este exercício ensina?

Este exercício evolui o ex00 adicionando **composição** (um animal possui um `Brain`) e introduz o conceito crítico de **cópia profunda** (*deep copy*) versus **cópia rasa** (*shallow copy*) — fundamental quando uma classe gerencia memória alocada dinamicamente.

---

## 📚 Conceitos abordados

### 1. Composição — "tem um" vs "é um"
`Cat` e `Dog` agora **têm um** `Brain` (composição), além de **serem** `Animal` (herança):

```cpp
class Brain {
    std::string ideas[100]; // 100 ideias armazenadas
};

class Cat : public Animal {
    Brain* brain;  // ponteiro para um Brain alocado no heap
};
```

> **Por que ponteiro?** Usar `Brain*` (ponteiro) em vez de `Brain` (valor) é intencional — força a necessidade de gerenciar memória manualmente e demonstra os problemas de cópia rasa.

---

### 2. Cópia Rasa (Shallow Copy) — o problema

A cópia rasa **copia apenas o endereço** do ponteiro, não o objeto apontado. Duas instâncias acabam compartilhando o mesmo `Brain` na memória:

```
Dog original → Brain@0xABC (ideias: "Chase cats")
Dog copy     → Brain@0xABC  ← MESMO endereço! ⚠️
```

**Consequência:**
- Modificar `copy.brain` modifica `original.brain` também
- Ao destruir ambos, o mesmo espaço de memória é liberado duas vezes (**double free** → crash)

---

### 3. Cópia Profunda (Deep Copy) — a solução ✅

A cópia profunda **aloca um novo objeto** e copia o conteúdo:

```cpp
// Construtor de cópia de Cat (ex01)
Cat::Cat(const Cat& other) : Animal(other)
{
    brain = new Brain(*other.brain); // ✅ cria um Brain novo com conteúdo copiado
}

// Operator= de Cat
Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;               // libera o antigo
        brain = new Brain(*other.brain); // aloca um novo
    }
    return (*this);
}
```

```
Dog original → Brain@0xABC (ideias: "Chase cats")
Dog copy     → Brain@0xDEF  ← endereço diferente, conteúdo copiado ✅
```

---

### 4. Destrutor responsável
Como `Brain` é alocado com `new`, **deve** ser liberado com `delete` no destrutor:

```cpp
Cat::~Cat()
{
    delete brain; // sem isso → memory leak!
}
```

---

## 🔍 Teste de Deep Copy no main

O `main` demonstra de forma clara que os objetos são independentes:

```cpp
Dog original;
original.getBrain()->setIdea(0, "Chase cats");

Dog copy = original;   // cópia profunda

copy.getBrain()->setIdea(0, "Eat food"); // modifica somente a cópia

// Resultado:
// Original idea: Chase cats  ← não mudou ✅
// Copy idea: Eat food        ← só a cópia mudou ✅
```

---

### 5. Array de Animals (teste com destruição via ponteiro base)
O `main` também cria um array de `Animal*` com Dogs e Cats:

```cpp
Animal* animals[4];
animals[0] = new Dog();
animals[2] = new Cat();
// ...
delete animals[i]; // ← destrutor virtual garante que Brain seja deletado corretamente
```

Sem destrutor virtual em `Animal`, `delete animals[i]` só chamaria `~Animal()`, **jamais `~Cat()` ou `~Dog()`** — e o `Brain` seria vazado da memória.

---

## 🧠 Diagrama de memória

```
Stack:                 Heap:
[Dog original] ──────→ [Brain@0xABC]
                         ideas[0]: "Chase cats"

[Dog copy]     ──────→ [Brain@0xDEF]  ← novo objeto
                         ideas[0]: "Eat food"
```

---

## ✅ Regra de ouro: Rule of Three

Se uma classe precisa de um **destrutor customizado** (por gerenciar memória), ela também precisa de:

| Elemento | Motivo |
|---|---|
| Destrutor | Liberar memória com `delete` |
| Construtor de cópia | Fazer deep copy do ponteiro |
| Operador `=` | Deletar antigo + fazer deep copy |

> Esta é a famosa **"Rule of Three"** do C++ (C++11 expandiu para Rule of Five com move semantics).

---

## 💡 Resumo visual

| Situação | Shallow Copy | Deep Copy |
|---|---|---|
| Ponteiros compartilhados? | ✅ Sim | ❌ Não |
| Modificar cópia afeta original? | ✅ Sim (bug!) | ❌ Não (correto) |
| Double free ao destruir? | ✅ Sim (crash!) | ❌ Não (seguro) |
