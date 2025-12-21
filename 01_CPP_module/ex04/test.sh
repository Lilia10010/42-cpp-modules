#!/bin/bash

# Criamos um arquivo de teste
echo "hello world hello" > test.txt

# Executamos o programa
./replace test.txt hello 42

# Mostramos o resultado
echo "Conteúdo do arquivo gerado:"
cat test.txt.replace

# Verificação simples
if grep -q "42 world 42" test.txt.replace; then
	echo "✅ Teste passou!"
else
	echo "❌ Teste falhou!"
fi

echo "===== TESTE 1: Arquivo inexistente ====="
./replace arquivo_que_nao_existe.txt hello 42

echo
echo "===== TESTE 2: s1 vazia ====="
echo "hello world" > test.txt
./replace test.txt "" 42

echo
echo "===== TESTE 3: Permissão negada ====="
echo "hello world" > locked.txt
chmod 000 locked.txt
./replace locked.txt hello 42
chmod 644 locked.txt