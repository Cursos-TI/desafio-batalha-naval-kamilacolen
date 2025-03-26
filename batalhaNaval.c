#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5  // Tamanho das matrizes de habilidade (5x5)

#define CONE 1
#define CRUZ 2
#define OCTAEDRO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 ");  // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 ");  // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("5 ");  // Área de Efeito
            }
        }
        printf("\n");
    }
}

// Função para aplicar a área de efeito do Cone
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // A habilidade do Cone se expande de cima para baixo
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicando a habilidade no tabuleiro, centrando na posição dada
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cone[i][j] == 1) {
                int novaLinha = linha + i - 2;  // Ajuste para centrar a habilidade
                int novaColuna = coluna + j - 2; // Ajuste para centrar a habilidade
                if (novaLinha >= 0 && novaLinha < TAMANHO_TABULEIRO && novaColuna >= 0 && novaColuna < TAMANHO_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = 5;  // Marca a área de efeito
                }
            }
        }
    }
}

// Função para aplicar a área de efeito da Cruz
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // A habilidade Cruz afeta as células acima, abaixo, à esquerda e à direita do centro
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicando a habilidade no tabuleiro, centrando na posição dada
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (cruz[i][j] == 1) {
                int novaLinha = linha + i - 2;  // Ajuste para centrar a habilidade
                int novaColuna = coluna + j - 2; // Ajuste para centrar a habilidade
                if (novaLinha >= 0 && novaLinha < TAMANHO_TABULEIRO && novaColuna >= 0 && novaColuna < TAMANHO_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = 5;  // Marca a área de efeito
                }
            }
        }
    }
}

// Função para aplicar a área de efeito do Octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // A habilidade Octaedro se expande em forma de losango
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // Aplicando a habilidade no tabuleiro, centrando na posição dada
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (octaedro[i][j] == 1) {
                int novaLinha = linha + i - 2;  // Ajuste para centrar a habilidade
                int novaColuna = coluna + j - 2; // Ajuste para centrar a habilidade
                if (novaLinha >= 0 && novaLinha < TAMANHO_TABULEIRO && novaColuna >= 0 && novaColuna < TAMANHO_TABULEIRO) {
                    tabuleiro[novaLinha][novaColuna] = 5;  // Marca a área de efeito
                }
            }
        }
    }
}

int main() {
    // Inicializando o tabuleiro com 0 (água) e colocando 3 para os navios
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo as posições dos navios (coordenadas fixas)
    tabuleiro[2][3] = 3;  // Navio horizontal
    tabuleiro[3][3] = 3;
    tabuleiro[4][3] = 3;
    tabuleiro[5][6] = 3;  // Navio vertical
    tabuleiro[6][6] = 3;
    tabuleiro[7][6] = 3;

    // Definindo o ponto de origem para as habilidades (centro de cada habilidade)
    int linhaCone = 3, colunaCone = 3;
    int linhaCruz = 6, colunaCruz = 6;
    int linhaOctaedro = 4, colunaOctaedro = 4;

    // Aplicando as habilidades no tabuleiro
    aplicarHabilidadeCone(tabuleiro, linhaCone, colunaCone);
    aplicarHabilidadeCruz(tabuleiro, linhaCruz, colunaCruz);
    aplicarHabilidadeOctaedro(tabuleiro, linhaOctaedro, colunaOctaedro);

    // Exibindo o tabuleiro após aplicar as habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}
