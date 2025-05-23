#include <stdio.h>
#include <stdlib.h>

// Define a quantidade de linhas / colunas do tabuleiro.
#define linhas 5
#define colunas 5

// Declara a matriz do tabuleiro do jogo. Tamanho 5 x 5.
char tabuleiro[linhas][colunas];

void iniciaTabuleiro(){
    // Varre as linhas / colunas do tabuleiro
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            // Preenche as posições vazias ' ' nas linhas[i] e colunas[j]
            if(i % 2 == 0 && j % 2 ==0){
                tabuleiro[i][j] = ' ';
                // Preenche a posição[i][j] com | quando i vale 2 e 4.
            }else if (i % 2 == 0){
                tabuleiro[i][j] = '|';
                // Preenche a posição[i][j] com - quando j vale 2 e 4.
            }else if (j % 2 == 0){
                tabuleiro[i][j] = '-';
            }else{
                tabuleiro[i][j] = '+';
            }
        }
    }
}


void imprimeTabuleiro(){

    // Varre as linhas / colunas do tabuleiro
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%c",tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se posição esta vazia e se esta dentro dos limites da matriz.
int ehValida(int x, int y) {
    // Verifica se a posição é inválida.
    if (x < 0 || x >= linhas || y < 0 || y >= colunas) {
        return 0;
    }

    // Verifica se a posição está vazia
    if (tabuleiro[x][y] == ' ') {
        return 1;
    }

    return 0;
}

// Marca a jogada no tabuleiro
int jogarNaPosicao(int x, int y, char jogador) {
    if (ehValida(x, y)) {
        tabuleiro[x][y] = jogador;
        return 1;
    }
    return 0;
}

// Troca o jogador atual
char alternarJogador(char jogadorAtual) {
    return (jogadorAtual == 'X') ? 'O' : 'X';
}

// Verifica se o jogador ganhou. 
int verificarVencedor() {
    char jogo[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jogo[i][j] = tabuleiro[i * 2][j * 2];
        }
    }

    // Verifica se o jogador ganhou nas linhas.
    for (int i = 0; i < 3; i++) {
        if (jogo[i][0] != ' ' &&
            jogo[i][0] == jogo[i][1] &&
            jogo[i][1] == jogo[i][2]) {
            return 1;
        }
    }

    // Verifica se o jogador ganhou nas colunas.
    for (int j = 0; j < 3; j++) {
        if (jogo[0][j] != ' ' &&
            jogo[0][j] == jogo[1][j] &&
            jogo[1][j] == jogo[2][j]) {
            return 1;
        }
    }

    // Verifica se o jogador ganhou na diagonal da esquerda para direita.
    if (jogo[0][0] != ' ' &&
        jogo[0][0] == jogo[1][1] &&
        jogo[1][1] == jogo[2][2]) {
        return 1;
    }

    // Verifica se o jogador ganhou na diagonal da direita para esquerda.
    if (jogo[0][2] != ' ' &&
        jogo[0][2] == jogo[1][1] &&
        jogo[1][1] == jogo[2][0]) {
        return 1;
    }

    return 0; // Ainda nenhum jogador venceu.
}

int main() {
    iniciaTabuleiro();

    int jogadas = 0;
    char jogador = 'X';

    while (jogadas < 9) {
        imprimeTabuleiro();

        int linha, coluna;
        printf("Jogador %c - Digite a linha e coluna (0 a 2): ", jogador);
        scanf("%d %d", &linha, &coluna);

        // Converte para coordenadas do tabuleiro gráfico
        int x = linha * 2;
        int y = coluna * 2;

        if (ehValida(x, y)) {
            tabuleiro[x][y] = jogador;
            jogadas++;

            if (verificarVencedor()) {
                imprimeTabuleiro();
                printf("Jogador %c venceu!\n", jogador);
                break;
            }

            jogador = alternarJogador(jogador);
        } else {
            printf("Posição inválida ou ocupada! Tente novamente.\n");
        }
    }

    if (jogadas == 9 && !verificarVencedor()) {
        imprimeTabuleiro();
        printf("Empate!\n");
    }

    return 0;
}