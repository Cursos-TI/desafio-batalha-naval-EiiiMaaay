#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Função para criar a matriz de habilidade de cone
void criarCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (j >= TAMANHO_HABILIDADE / 2 - i && j <= TAMANHO_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

// Função para criar a matriz de habilidade de cruz
void criarCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Função para criar a matriz de habilidade de octaedro
void criarOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i + j >= TAMANHO_HABILIDADE / 2 && i + j <= TAMANHO_HABILIDADE + TAMANHO_HABILIDADE / 2 - 1 &&
                              i - j <= TAMANHO_HABILIDADE / 2 && j - i <= TAMANHO_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posiciona navios (exemplo)
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    // Matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    // Cria as habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Ponto de origem das habilidades no tabuleiro
    int cone_linha = 2;
    int cone_coluna = 4;
    int cruz_linha = 5;
    int cruz_coluna = 5;
    int octaedro_linha = 7;
    int octaedro_coluna = 5;

    // Aplica habilidades no tabuleiro
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1 && cone_linha - TAMANHO_HABILIDADE / 2 + i >= 0 && cone_linha - TAMANHO_HABILIDADE / 2 + i < TAMANHO_TABULEIRO &&
                cone_coluna - TAMANHO_HABILIDADE / 2 + j >= 0 && cone_coluna - TAMANHO_HABILIDADE / 2 + j < TAMANHO_TABULEIRO) {
                tabuleiro[cone_linha - TAMANHO_HABILIDADE / 2 + i][cone_coluna - TAMANHO_HABILIDADE / 2 + j] = 5;
            }

            if (cruz[i][j] == 1 && cruz_linha - TAMANHO_HABILIDADE / 2 + i >= 0 && cruz_linha - TAMANHO_HABILIDADE / 2 + i < TAMANHO_TABULEIRO &&
                cruz_coluna - TAMANHO_HABILIDADE / 2 + j >= 0 && cruz_coluna - TAMANHO_HABILIDADE / 2 + j < TAMANHO_TABULEIRO) {
                tabuleiro[cruz_linha - TAMANHO_HABILIDADE / 2 + i][cruz_coluna - TAMANHO_HABILIDADE / 2 + j] = 5;
            }

            if (octaedro[i][j] == 1 && octaedro_linha - TAMANHO_HABILIDADE / 2 + i >= 0 && octaedro_linha - TAMANHO_HABILIDADE / 2 + i < TAMANHO_TABULEIRO &&
                octaedro_coluna - TAMANHO_HABILIDADE / 2 + j >= 0 && octaedro_coluna - TAMANHO_HABILIDADE / 2 + j < TAMANHO_TABULEIRO) {
                tabuleiro[octaedro_linha - TAMANHO_HABILIDADE / 2 + i][octaedro_coluna - TAMANHO_HABILIDADE / 2 + j] = 5;
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro com Habilidades:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
