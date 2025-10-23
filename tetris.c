#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_FILA 5

typedef struct {
    char nome;  
    int id;     
} Peca;

Peca gerarPeca(int id) {
    Peca nova;
    char tipos[] = {'I', 'O', 'T', 'L'};
    nova.nome = tipos[rand() % 4]; 
    nova.id = id;
    return nova;
}

void exibirFila(Peca fila[], int frente, int tras, int quantidade) {
    printf("\nFila de peças:\n[ ");
    for (int i = 0; i < quantidade; i++) {
        int index = (frente + i) % TAMANHO_FILA;
        printf("%c %d ", fila[index].nome, fila[index].id);
    }
    printf("]\n");
}

int main() {
    Peca fila[TAMANHO_FILA];
    int frente = 0;         // Início da fila
    int tras = 0;           // Fim da fila
    int quantidade = 0;     // Número de elementos atuais
    int idAtual = 0;
    int opcao;

    srand(time(NULL)); 

    // Inicializa a fila com 5 peças
    for (int i = 0; i < TAMANHO_FILA; i++) {
        fila[i] = gerarPeca(idAtual++);
        quantidade++;
        tras = (tras + 1) % TAMANHO_FILA;
    }

    printf("=== Tetris Stack - Fila de Peças Futuras ===\n");
    exibirFila(fila, frente, tras, quantidade);

    do {
        printf("\nOpções:\n");
        printf("1 - Jogar peça (dequeue)\n");
        printf("2 - Inserir nova peça (enqueue)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (quantidade > 0) {
                    printf("\nPeça jogada: %c %d\n", fila[frente].nome, fila[frente].id);
                    frente = (frente + 1) % TAMANHO_FILA;
                    quantidade--;
                } else {
                    printf("\nA fila está vazia!\n");
                }
                exibirFila(fila, frente, tras, quantidade);
                break;

            case 2:
                if (quantidade < TAMANHO_FILA) {
                    fila[tras] = gerarPeca(idAtual++);
                    tras = (tras + 1) % TAMANHO_FILA;
                    quantidade++;
                } else {
                    printf("\nA fila está cheia!\n");
                }
                exibirFila(fila, frente, tras, quantidade);
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
