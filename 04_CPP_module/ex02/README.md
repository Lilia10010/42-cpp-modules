# ex02 — Abstract Classes (Classes Abstratas)

## 🎯 O que este exercício ensina?

Este exercício dá um passo além do polimorfismo do ex00 ao introduzir **classes abstratas** e **funções virtuais puras** (`= 0`). O conceito central é: **`Animal` não deve existir como objeto concreto** — ele é apenas um contrato/interface que as subclasses devem implementar.

---

## 📚 Conceitos abordados

### 1. Função Virtual Pura (`= 0`)
A mudança central neste exercício é **uma única linha** no `Animal.hpp`:

```cpp
// ex00 (concreta — tem implementação)
virtual void makeSound() const;

// ex02 (pura — SEM implementação obrigatória na base)
virtual void makeSound() const = 0;
```

O `= 0` transforma `makeSound` em uma **função virtual pura**. Isso significa:
- `Animal` **não fornece** implementação de `makeSound`
- Toda subclasse **obrigatoriamente** deve fornecer sua própria implementação
- Tentar instanciar `Animal` diretamente vira **erro de compilação**

---

### 2. Classe Abstrata (Abstract Class)
Uma classe que possui **ao menos uma função virtual pura** é chamada de **classe abstrata**. Ela serve como um **contrato** ou **interface**:

```cpp
// ❌ Erro de compilação — Animal é abstrata!
Animal a;

// ✅ OK — ponteiro para Animal pode apontar para objetos concretos
Animal* dog = new Dog();
Animal* cat = new Cat();
```

No `main.cpp` do ex02, há um comentário explicativo deixado intencionalmente:
```cpp
// Animal a; ← erro: Animal é abstrata, não pode criar instância
// Animal* funfa ← OK: apenas reserva espaço para um endereço
```

---

### 3. Por que isso é útil?

Imagine um sistema real:  
Uma classe `Shape` (forma) genérica não faz sentido existir sem ser um **círculo**, **quadrado** ou **triângulo**. O método `area()` não pode ser calculado sem saber a forma concreta:

```cpp
class Shape {
    virtual double area() const = 0; // força subclasses a implementarem
};

class Circle : public Shape {
    double area() const { return 3.14 * r * r; }
};
```

Da mesma forma, **um "Animal" genérico não faz som** — somente Dogs e Cats sabem seu próprio som.

---

### 4. Diferença entre ex00, ex01 e ex02

| | ex00 | ex01 | ex02 |
|---|---|---|---|
| `makeSound` em `Animal` | `virtual` (com implementação) | `virtual` (com implementação) | `virtual` **pura** (`= 0`) |
| `Animal` instanciável? | ✅ Sim | ✅ Sim | ❌ Não |
| Classe abstrata? | ❌ Não | ❌ Não | ✅ Sim |
| `Brain` em Cats/Dogs? | ❌ Não | ✅ Sim | ✅ Sim |
| Propósito | Polimorfismo básico | Deep Copy | Interface obrigatória |

---

### 5. A implementação de `makeSound` em `Animal.cpp` foi removida

No ex02, a implementação de `makeSound` foi **comentada** (e não existe mais):

```cpp
// Animal.cpp
// void Animal::makeSound() const
// {
//     std::cout << "* generic animal sound *" << std::endl;
// }
```

Isso porque uma função virtual pura **não precisa** de implementação na classe base (pode até ter, mas raramente é necessário). As subclasses fornecem a implementação.

---

## 🔍 Fluxo de compilação

```
Tentativa de Animal a;
        ↓
Compilador: "Animal::makeSound é virtual pura"
        ↓
Animal é abstrata → ❌ ERRO: cannot declare variable 'a' to be of abstract type 'Animal'
```

```
Animal* dog = new Dog();
        ↓
Dog::makeSound() está implementado ✅
        ↓
OK — Dog é uma classe concreta
```

---

## 💡 Resumo do aprendizado

| Conceito | Descrição |
|---|---|
| `virtual f() = 0` | Função virtual pura — obriga subclasses a implementar |
| Classe Abstrata | Classe com ao menos uma função virtual pura |
| Instanciação | Classes abstratas **não** podem ser instanciadas diretamente |
| Ponteiros | Ponteiros para classe abstrata são permitidos (polimorfismo funciona normalmente) |
| Herança | Subclasse deve implementar **todas** as funções virtuais puras para ser concreta |

> **Design Pattern:** Classes abstratas são a base do **Princípio da Substituição de Liskov (LSP)** e dos **Interfaces** em C++ — fundamentais para código extensível e bem-estruturado.
