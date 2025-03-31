#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios
    int navio_horizontal_linha = 2;
    int navio_horizontal_coluna = 3;

    int navio_vertical_linha = 6;
    int navio_vertical_coluna = 1;

    int navio_diagonal1_linha = 0;
    int navio_diagonal1_coluna = 0;

    int navio_diagonal2_linha = 0;
    int navio_diagonal2_coluna = 9;

    // Validação das coordenadas dos navios
    if (navio_horizontal_linha < 0 || navio_horizontal_linha >= TAMANHO_TABULEIRO ||
        navio_horizontal_coluna < 0 || navio_horizontal_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Coordenadas do navio horizontal inválidas.\n");
        return 1;
    }

    if (navio_vertical_linha < 0 || navio_vertical_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        navio_vertical_coluna < 0 || navio_vertical_coluna >= TAMANHO_TABULEIRO) {
        printf("Coordenadas do navio vertical inválidas.\n");
        return 1;
    }

    if (navio_diagonal1_linha < 0 || navio_diagonal1_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        navio_diagonal1_coluna < 0 || navio_diagonal1_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Coordenadas do navio diagonal 1 inválidas.\n");
        return 1;
    }

    if (navio_diagonal2_linha < 0 || navio_diagonal2_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        navio_diagonal2_coluna < 0 || navio_diagonal2_coluna - TAMANHO_NAVIO + 1 < 0) {
        printf("Coordenadas do navio diagonal 2 inválidas.\n");
        return 1;
    }

    // Posiciona os navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3;
        tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3;
        tabuleiro[navio_diagonal1_linha + i][navio_diagonal1_coluna + i] = 3;
        tabuleiro[navio_diagonal2_linha + i][navio_diagonal2_coluna - i] = 3;
    }

    // Validação de sobreposição (exemplo simples)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 3) {
                // Aqui você pode adicionar uma lógica mais robusta para verificar sobreposições
                // Por simplicidade, este exemplo não implementa uma validação completa
            }
        }
    }

    // Exibe o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
