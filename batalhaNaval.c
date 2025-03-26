#include <stdio.h>

// Definindo o tamanho do tabuleiro e o tamanho dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verificar se o navio cabe na linha sem ultrapassar os limites do tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
        return 0;
    }

    // Verificar se há sobreposição com outro navio
    for (int i = coluna; i < coluna + TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][i] == 3) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 0;
        }
    }

    // Posicionar o navio
    for (int i = coluna; i < coluna + TAMANHO_NAVIO; i++) {
        tabuleiro[linha][i] = 3;
    }

    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verificar se o navio cabe na coluna sem ultrapassar os limites do tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
        return 0;
    }

    // Verificar se há sobreposição com outro navio
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        if (tabuleiro[i][coluna] == 3) {
            printf("Erro: Sobreposição de navios detectada.\n");
            return 0;
        }
    }

    // Posicionar o navio
    for (int i = linha; i < linha + TAMANHO_NAVIO; i++) {
        tabuleiro[i][coluna] = 3;
    }

    return 1;
}

int main() {
    // Inicializando o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Definindo as coordenadas iniciais para os navios
    int linhaNavioHorizontal = 2, colunaNavioHorizontal = 3;  // Navio horizontal
    int linhaNavioVertical = 5, colunaNavioVertical = 6;      // Navio vertical

    // Posicionando os navios no tabuleiro
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        return 1;  // Erro ao posicionar navio horizontal
    }

    if (!posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        return 1;  // Erro ao posicionar navio vertical
    }

    // Exibindo o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
