#ifndef TEMP_LIBPRG_H
#define TEMP_LIBPRG_H

#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stdbool.h>

/**
 * @param elemento = elemento que o usuário deseja remover ou incluir no vetor
 * @param vetor  = vetor de tamanho escolhido pelo usuário;
 * @param inserir = inseri elemento no vetor;
 * @param remover = remove elemento no vetor;
 *
 */
// ------------------------- LISTA LINEAR ------------------------- //
typedef struct {
    int *vetor;
    int tamanho;
    int total_elementos;
}vetor_t;

int cria(vetor_t *vetor, int tamanho); // CRIA VETOR
int povoar(vetor_t * vetor, char op); // POVOA VETOR

void nao_ordenada(vetor_t *vetor, int tamanho); // POVOA VETOR NÃO ORDENADO
void ordenada(vetor_t *vetor, int tamanho); // POVOA VETOR ORDENADO

int buscar_l(vetor_t *vetor, int elemento); // BUSCA LINEAR
int buscar_bi(vetor_t *vetor, int elemento); // BUSCA BINÁRIA ITERATIVA
int buscar_br(vetor_t *vetor, int inicio, int fim, int elemento); // BUSCA BINÁRIA RECURSIVA

int inserir_n(vetor_t *vetor, int elemento); // INSERÇÃO NÃO ORDENADA
int inserir_o(vetor_t *vetor, int elemento); // INSERÇÃO ORDENADA

int remover(vetor_t *vetor, int elemento); // REMOVE NÃO ORDENADA
int remover_o(vetor_t *vetor, int elemento); // REMOVE ORDENADA

void libera(vetor_t *vetor); // LIBERA ESPAÇO

// ------------------------- FILA ------------------------- //

typedef struct {
    vetor_t *fila;
    int inicio;
    int fim;
}fila_t;

int enqueue (fila_t *fila, int elemento); // ADICIONA UM ELEMENTO NO FINAL DA FILA
int dequeue (fila_t *fila); // REMOVE O ELEMENTO QUE ESTÁ NO INÍCIO DA FILA

int head (fila_t *fila); // RETORNA O ELEMENTO QUE ESTÁ NO INÍCIO DA FILA
int tail (fila_t *fila); // RETORNA O ELEMENTO QUE ESTÁ NO FIM DA FILA

int size (fila_t *fila); // RETORNA O TOTAL DE ELEMENTOS NA FILA

int empty (fila_t *fila); // INDICA SE A FILA ESTÁ VAZIA OU NÃO
int full (fila_t *fila); // INDICA SE A FILA ESTÁ CHEIA OU NÃO

#endif //TEMP_LIBPRG_H