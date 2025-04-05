#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função para exibir uma matriz 5x5 (usada nas habilidades)
void mostrarHabilidade(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Nível Novato – Tabuleiro 5x5 com dois navios
void nivelNovato() {
    int tabuleiro[5][5] = {0};

    // Navio horizontal na linha 1
    for (int j = 0; j < 3; j++) {
        tabuleiro[1][j] = 3;
        printf("Navio horizontal em: (%d, %d)\n", 1, j);
    }

    // Navio vertical na coluna 3
    for (int i = 2; i < 5; i++) {
        tabuleiro[i][3] = 3;
        printf("Navio vertical em: (%d, %d)\n", i, 3);
    }
}

// Nível Aventureiro – Tabuleiro 10x10 com quatro navios
void nivelAventureiro() {
    int tabuleiro[10][10] = {0};

    // Navio horizontal
    for (int j = 2; j < 6; j++) {
        tabuleiro[0][j] = 3;
    }

    // Navio vertical
    for (int i = 5; i < 9; i++) {
        tabuleiro[i][7] = 3;
    }

    // Navio diagonal descendo
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio diagonal subindo
    for (int i = 0; i < 4; i++) {
        tabuleiro[9 - i][i] = 3;
    }

    printf("\nTabuleiro 10x10:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Nível Mestre – Exibição das habilidades especiais
void nivelMestre() {
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Cone
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            cone[i][j] = 1;
        }
    }

    // Cruz
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1;
        cruz[i][2] = 1;
    }

    // Octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    printf("Habilidade em Cone:\n");
    mostrarHabilidade(cone);

    printf("Habilidade em Cruz:\n");
    mostrarHabilidade(cruz);

    printf("Habilidade em Octaedro:\n");
    mostrarHabilidade(octaedro);
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU DE NÍVEIS ---\n");
        printf("1 - Nível Novato (5x5)\n");
        printf("2 - Nível Aventureiro (10x10)\n");
        printf("3 - Nível Mestre (Habilidades)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                nivelNovato();
                break;
            case 2:
                nivelAventureiro();
                break;
            case 3:
                nivelMestre();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}

