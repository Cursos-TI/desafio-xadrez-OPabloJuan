#include <stdio.h>

// Função recursiva para mover a Torre para a Direita
void moverTorre(int casas, int atual) {
    if (atual > casas) return;
    printf("Casa %d: Direita\n", atual);
    moverTorre(casas, atual + 1);
}

// Função recursiva que chama loops aninhados para simular o Bispo na diagonal (Cima Direita)
void moverBispo(int casas, int atual) {
    if (atual > casas) return;

    // Para cada movimento vertical, também há um passo horizontal (diagonal)
    for (int v = 0; v < 1; v++) {
        for (int h = 0; h < 1; h++) {
            printf("Casa %d: Cima Direita\n", atual);
        }
    }

    moverBispo(casas, atual + 1);
}

// Função recursiva para mover a Rainha para a Esquerda
void moverRainha(int casas, int atual) {
    if (atual > casas) return;
    printf("Casa %d: Esquerda\n", atual);
    moverRainha(casas, atual + 1);
}

// Função que move o Cavalo: 2 casas para cima e 1 para a direita, com loops aninhados
void moverCavalo() {
    int movCima = 2;
    int movDireita = 1;
    int casa = 1;

    printf("Movimento do Cavalo:\n");

    // Loop externo para representar os movimentos totais
    for (int i = 0; i < movCima + movDireita; i++) {
        // Loop interno para controlar a lógica da direção
        for (int j = 0; j < 2; j++) {
            if (i < movCima && j == 0) {
                printf("Casa %d: Cima\n", casa++);
                break; // sai do loop interno após imprimir "Cima"
            } else if (i >= movCima && j == 1) {
                printf("Casa %d: Direita\n", casa++);
                continue; // continua o loop externo
            }
        }
    }
}

// Função principal com menu de seleção
int main() {
    int opcao;
    int casas = 5; // número de casas para Torre, Bispo e Rainha

    printf("=== Super Desafio Xadrez - Nível Mestre ===\n");
    printf("Escolha a peça para mover:\n");
    printf("1 - Torre (horizontal - Direita)\n");
    printf("2 - Bispo (diagonal - Cima Direita)\n");
    printf("3 - Rainha (horizontal - Esquerda)\n");
    printf("4 - Cavalo (movimento em L - Cima e Direita)\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\n");

    switch (opcao) {
        case 1:
            printf("Movimento da Torre:\n");
            moverTorre(casas, 1);
            break;

        case 2:
            printf("Movimento do Bispo:\n");
            moverBispo(casas, 1);
            break;

        case 3:
            printf("Movimento da Rainha:\n");
            moverRainha(casas, 1);
            break;

        case 4:
            moverCavalo();
            break;

        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
