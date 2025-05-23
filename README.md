# 🧩 Jogo da Velha em C 

Este projeto consiste na implementação de um **jogo da velha (tic-tac-toe)** em linguagem C, com uma interface em modo texto utilizando uma matriz 5x5 para simular o tabuleiro de 3x3 com divisórias visuais.  

> 🎓 Trabalho desenvolvido como parte da disciplina **Algoritmos e Estruturas de Dados I**, no curso de Ciência da Computação.

## 📋 Objetivo

Criar um jogo interativo que permita a dois jogadores alternarem turnos, verificando jogadas válidas, atualizando o tabuleiro, identificando o vencedor ou detectando empate, utilizando conceitos fundamentais de programação como:

- Matrizes bidimensionais
- Estruturas de repetição e condição
- Funções
- Manipulação de entrada/saída no terminal

## 🧠 Lógica do Jogo

- O tabuleiro é representado por uma matriz 5x5, onde os índices pares contêm os espaços jogáveis e os ímpares contêm divisores visuais (`|`, `-`, `+`).
- Os jogadores alternam entre `X` e `O`.
- Após cada jogada válida, o sistema verifica:
  - Linhas
  - Colunas
  - Diagonais
- O jogo termina quando um jogador vence ou quando 9 jogadas válidas são feitas (empate).

## ▶️ Como jogar

1. Compile o código com um compilador C, como o `gcc`:

```bash
gcc jogo_da_velha.c -o jogo_da_velha
```

2. Execute o jogo:

```bash
./jogo_da_velha
```

3. Digite as coordenadas da sua jogada (linha e coluna de 0 a 2) quando solicitado.

## 🧱 Estrutura do Código

- `iniciaTabuleiro()`: inicializa o tabuleiro com divisores e espaços em branco.
- `imprimeTabuleiro()`: imprime o tabuleiro na tela.
- `ehValida()`: verifica se a jogada é válida.
- `jogarNaPosicao()`: marca a jogada no tabuleiro.
- `alternarJogador()`: troca o jogador da rodada.
- `verificarVencedor()`: verifica se algum jogador venceu.
- `main()`: gerencia o loop principal do jogo.

## 📌 Requisitos

- Compilador C (como `gcc`)
- Terminal ou prompt de comando

## 📚 Créditos

Desenvolvido por Breno Ruggeri Ristic e Miguel Durães Bueno  
Curso de Ciência da Computação – Universidade Municipal de São Caetano do Sul (USCS)  
Disciplina: Algoritmos e Estruturas de Dados I
