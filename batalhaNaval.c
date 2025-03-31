#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
  // Inicializa o tabuleiro com água (0)
  int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

  // Coordenadas do navio horizontal
  int navio_horizontal_linha = 2;
  int navio_horizontal_coluna = 3;

  // Coordenadas do navio vertical
  int navio_vertical_linha = 6;
  int navio_vertical_coluna = 1;

  // Validação das coordenadas do navio horizontal
  if (navio_horizontal_linha < 0 || navio_horizontal_linha >= TAMANHO_TABULEIRO ||
      navio_horizontal_coluna < 0 || navio_horizontal_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
    printf("Coordenadas do navio horizontal inválidas.\n");
    return 1; // Encerra o programa com código de erro
  }

  // Validação das coordenadas do navio vertical
  if (navio_vertical_linha < 0 || navio_vertical_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
      navio_vertical_coluna < 0 || navio_vertical_coluna >= TAMANHO_TABULEIRO) {
    printf("Coordenadas do navio vertical inválidas.\n");
    return 1; // Encerra o programa com código de erro
  }

  // Posiciona o navio horizontal
  for (int i = 0; i < TAMANHO_NAVIO; i++) {
    tabuleiro[navio_horizontal_linha][navio_horizontal_coluna + i] = 3;
  }

  // Posiciona o navio vertical
  for (int i = 0; i < TAMANHO_NAVIO; i++) {
    tabuleiro[navio_vertical_linha + i][navio_vertical_coluna] = 3;
  }

  // Exibe o tabuleiro
  printf("Tabuleiro:\n");
  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0; // Encerra o programa com sucesso
}
