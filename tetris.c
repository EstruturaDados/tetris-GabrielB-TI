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

