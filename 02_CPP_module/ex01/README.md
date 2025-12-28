### OPERADOR BITWISE SHIFT LEFT (<<)

O operador de shift left (<<) desloca os bits de um número para a esquerda, inserindo zeros nas posições mais à direita.

Cada shift para a esquerda = multiplicar por 2.

value << 1 = value \* 2

value << 8 = value _ 2⁸ = value _ 256

value = 10

10 << 8 = 10 \* 256 = 2560

não é guardado o 10, mas sim a representação fixa em bits do 10.

return static_cast<float>(\_rawBits) / (1 << \_fractionalBits);

- converte o inteiro para float
  10860.0 / 256 = 42.421875

### Operador BITWISE SHIFT RIGHT (>>)

O operador de shift right (>>) desloca os bits de um número para a direita, descartando os bits mais à direita.
Cada shift para a direita = dividir por 2.

10860 >> 8 = 10860 / 256 = 42
parte fracionária é descartada

### Operator de inserção em fluxo (<<)

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
“Uma função chamada operator<< que recebe
um fluxo de saída (std::ostream)
e um Fixed,
e devolve o mesmo fluxo.”

o que é std::ostream?
é a classe base para todos os fluxos de saída em C++.
std::cout é um objeto da classe std::ostream.

```
std::cout << 10;
std::cout << 3.14f;
std::cout << a;
```

O compilador escolhe qual versão de operator<< usar:

int

float

Fixed

👉 Mesmo nome
👉 Parâmetros diferentes
👉 Implementações diferentes

📌 Isso é polimorfismo ad-hoc.

Você não armazena números.
Você armazena representações.
