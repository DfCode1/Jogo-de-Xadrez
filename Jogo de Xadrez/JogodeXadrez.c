#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // Para abs()
#include <ctype.h>  // Para toupper()

#define TAMANHO_TABULEIRO 8
#define VAZIO '.'
#define PECA 'P'
#define POSSIVEL_MOVIMENTO 'X'

// Protótipos das Funções
void inicializar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
void exibir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]);
int eh_valido(int linha, int coluna);

void movimentos_torre(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);
void movimentos_bispo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);
void movimentos_rainha(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);
void movimentos_cavalo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna);

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    char escolha_peca;
    int linha_inicial, coluna_inicial;

    do {
        inicializar_tabuleiro(tabuleiro);

        printf("\nEscolha a peca para simular os movimentos:\n");
        printf("T - Torre\n");
        printf("B - Bispo\n");
        printf("R - Rainha (Queen)\n");
        printf("C - Cavalo (Knight)\n");
        printf("S - Sair\n");
        printf("Opcao: ");
        scanf(" %c", &escolha_peca);
        escolha_peca = toupper(escolha_peca);

        if (escolha_peca == 'S') {
            break;
        }

        if (escolha_peca != 'T' && escolha_peca != 'B' && escolha_peca != 'R' && escolha_peca != 'C') {
            printf("Peca invalida!\n");
            continue;
        }

        do {
            printf("Digite a linha inicial da peca (0-7): ");
            scanf("%d", &linha_inicial);
            printf("Digite a coluna inicial da peca (0-7): ");
            scanf("%d", &coluna_inicial);

            if (!eh_valido(linha_inicial, coluna_inicial)) {
                printf("Posicao inicial invalida! Tente novamente.\n");
            }
        } while (!eh_valido(linha_inicial, coluna_inicial));

        tabuleiro[linha_inicial][coluna_inicial] = PECA;

        switch (escolha_peca) {
        case 'T':
            printf("\n--- Movimentos da Torre de (%d,%d) ---\n", linha_inicial, coluna_inicial);
            movimentos_torre(tabuleiro, linha_inicial, coluna_inicial);
            break;
        case 'B':
            printf("\n--- Movimentos do Bispo de (%d,%d) ---\n", linha_inicial, coluna_inicial);
            movimentos_bispo(tabuleiro, linha_inicial, coluna_inicial);
            break;
        case 'R':
            printf("\n--- Movimentos da Rainha de (%d,%d) ---\n", linha_inicial, coluna_inicial);
            movimentos_rainha(tabuleiro, linha_inicial, coluna_inicial);
            break;
        case 'C':
            printf("\n--- Movimentos do Cavalo de (%d,%d) ---\n", linha_inicial, coluna_inicial);
            movimentos_cavalo(tabuleiro, linha_inicial, coluna_inicial);
            break;
        }
        exibir_tabuleiro(tabuleiro);

    } while (escolha_peca != 'S');

    printf("Obrigado por usar o simulador!\n");
    return 0;
}

void inicializar_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }
}

void exibir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  "); // Espaço para alinhar com as colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n'%c' = Peca, '%c' = Movimento Possivel\n", PECA, POSSIVEL_MOVIMENTO);
}

int eh_valido(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO;
}

/**
 * Simula os movimentos da Torre.
 * Utiliza loops 'for' para percorrer as direções.
 */
void movimentos_torre(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Movimento vertical para cima
    for (int i = linha - 1; i >= 0; i--) {
        tabuleiro[i][coluna] = POSSIVEL_MOVIMENTO;
    }
    // Movimento vertical para baixo
    for (int i = linha + 1; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[i][coluna] = POSSIVEL_MOVIMENTO;
    }
    // Movimento horizontal para esquerda
    for (int j = coluna - 1; j >= 0; j--) {
        tabuleiro[linha][j] = POSSIVEL_MOVIMENTO;
    }
    // Movimento horizontal para direita
    for (int j = coluna + 1; j < TAMANHO_TABULEIRO; j++) {
        tabuleiro[linha][j] = POSSIVEL_MOVIMENTO;
    }
}

/**
 * Simula os movimentos do Bispo.
 * Utiliza loops 'while' para percorrer as diagonais.
 * Os loops têm múltiplas condições para verificar os limites do tabuleiro.
 */
void movimentos_bispo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int i, j;

    // Diagonal superior esquerda
    i = linha - 1;
    j = coluna - 1;
    while (eh_valido(i, j)) {
        tabuleiro[i][j] = POSSIVEL_MOVIMENTO;
        i--;
        j--;
    }

    // Diagonal superior direita
    i = linha - 1;
    j = coluna + 1;
    while (eh_valido(i, j)) {
        tabuleiro[i][j] = POSSIVEL_MOVIMENTO;
        i--;
        j++;
    }

    // Diagonal inferior esquerda
    i = linha + 1;
    j = coluna - 1;
    while (eh_valido(i, j)) {
        tabuleiro[i][j] = POSSIVEL_MOVIMENTO;
        i++;
        j--;
    }

    // Diagonal inferior direita
    i = linha + 1;
    j = coluna + 1;
    while (eh_valido(i, j)) {
        tabuleiro[i][j] = POSSIVEL_MOVIMENTO;
        i++;
        j++;
    }
}

/**
 * Simula os movimentos da Rainha.
 * A Rainha combina os movimentos da Torre e do Bispo.
 * Reutiliza a lógica, demonstrando como combinar funcionalidades baseadas em loops.
 */
void movimentos_rainha(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Movimentos da Torre
    movimentos_torre(tabuleiro, linha, coluna);
    // Movimentos do Bispo
    movimentos_bispo(tabuleiro, linha, coluna);
}

/**
 * Simula os movimentos do Cavalo.
 * Utiliza um loop 'for' simples com arrays de deslocamentos para os 8 movimentos em "L".
 * Para atender ao requisito de "loops aninhados" de forma mais explícita para o Cavalo,
 * poderíamos iterar sobre possíveis deltas, mas a abordagem com arrays de deslocamento é
 * mais comum e clara para os 8 movimentos fixos.
 * Aqui, usamos um loop simples para os 8 movimentos e a checagem de validade dentro dele.
 * A "complexidade" do movimento em L é representada pelos pares de deslocamento.
 */
void movimentos_cavalo(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Deslocamentos possíveis para o cavalo (dx, dy)
    // Estes 8 pares representam os movimentos em "L"
    int dx[] = { -2, -2, -1, -1,  1,  1,  2,  2 };
    int dy[] = { -1,  1, -2,  2, -2,  2, -1,  1 };

    // Loop para testar cada um dos 8 movimentos possíveis
    for (int k = 0; k < 8; k++) {
        int nova_linha = linha + dx[k];
        int nova_coluna = coluna + dy[k];

        // Loop interno implícito (verificação de validade) para cada movimento
        // Este 'if' representa uma condição dentro do loop 'for'
        if (eh_valido(nova_linha, nova_coluna)) {
            tabuleiro[nova_linha][nova_coluna] = POSSIVEL_MOVIMENTO;
        }
    }
    /*
    // Abordagem alternativa para "loops aninhados" mais explícitos para o Cavalo (menos usual):
    // Percorre um quadrado 5x5 ao redor do cavalo e verifica se o movimento é em L.
    // (startX - 2, startY - 2) to (startX + 2, startY + 2)
    for (int i_offset = -2; i_offset <= 2; i_offset++) {
        for (int j_offset = -2; j_offset <= 2; j_offset++) {
            // Condição para movimento em "L": |i_offset * j_offset| == 2
            // Isso significa que um offset é +/-1 e o outro é +/-2.
            if (abs(i_offset * j_offset) == 2) {
                int nova_linha = linha + i_offset;
                int nova_coluna = coluna + j_offset;
                if (eh_valido(nova_linha, nova_coluna)) {
                    tabuleiro[nova_linha][nova_coluna] = POSSIVEL_MOVIMENTO;
                }
            }
        }
    }
    */
}