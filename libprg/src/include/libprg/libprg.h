#ifndef TEMP_LIBPRG_H
#define TEMP_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>
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
} vetor_t;

int cria(vetor_t *vetor, int tamanho); // CRIA VETOR
void libera(vetor_t *vetor); // LIBERA MEMÓRIA
int povoar(vetor_t *vetor, char op); // POVOA VETOR

void nao_ordenada(vetor_t *vetor, int tamanho); // POVOA VETOR NÃO ORDENADO
void ordenada(vetor_t *vetor, int tamanho); // POVOA VETOR ORDENADO

int buscar_l(vetor_t *vetor, int elemento); // BUSCA LINEAR
int buscar_bi(vetor_t *vetor, int elemento); // BUSCA BINÁRIA ITERATIVA
int buscar_br(vetor_t *vetor, int inicio, int fim, int elemento); // BUSCA BINÁRIA RECURSIVA

int inserir_n(vetor_t *vetor, int elemento); // INSERÇÃO NÃO ORDENADA
int inserir_o(vetor_t *vetor, int elemento); // INSERÇÃO ORDENADA

int remover(vetor_t *vetor, int elemento); // REMOVE NÃO ORDENADA
int remover_o(vetor_t *vetor, int elemento); // REMOVE ORDENADA

// ------------------------- FILA ------------------------- //

typedef struct {
    vetor_t *fila;
    int inicio;
    int fim;
} fila_t;

int enqueue(fila_t *fila, int elemento); // ADICIONA UM ELEMENTO NO FINAL DA FILA
int dequeue(fila_t *fila); // REMOVE O ELEMENTO QUE ESTÁ NO INÍCIO DA FILA

int head(fila_t *fila); // RETORNA O ELEMENTO QUE ESTÁ NO INÍCIO DA FILA
int tail(fila_t *fila); // RETORNA O ELEMENTO QUE ESTÁ NO FIM DA FILA

int size(fila_t *fila); // RETORNA O TOTAL DE ELEMENTOS NA FILA

int empty(fila_t *fila); // INDICA SE A FILA ESTÁ VAZIA OU NÃO
int full(fila_t *fila); // INDICA SE A FILA ESTÁ CHEIA OU NÃO

// ------------------- TOMADA DE TEMPO ------------------- //


void inicio(struct timeval *inicio_t);
double finaliza(struct timeval *inicio_t);

double finaliza_cpu(clock_t start);


// ------------------------ PILHA ------------------------ //

typedef struct{
    vetor_t *pilha;
    int topo;
}pilha_t;

int cria_pilha(pilha_t *pilha, int tamanho);
int push(pilha_t *pilha, int elemento, int tamanho);
int pop(pilha_t *pilha);
int size_p(pilha_t pilha);
int empty_p(pilha_t *pilha);

// --------- LISTA ENCADEADA ----------- //

typedef struct no {
    int conteudo;
    struct no *proximo;
}no_t;

bool create (int dado);

no_t add(no_t *no, int dado);
no_t add_o(no_t *no, int dado);

bool remove_e(no_t *no, int dado);
bool remove_eo(no_t *no, int dado);

bool search(no_t *no, int dado);
int search_o(no_t *no, int dado);

//========== LISTA DUPLAMENTE ENCADEADA ==========//

typedef struct nod {
    int conteudo;
    struct nod *proximo;
    struct nod *anterior;
}nod_t;

bool create_d(int dado);

nod_t add_d(nod_t *nod, int dado);
nod_t * add_do(nod_t *nod, int dado);

//========== ALGORITMO DE ORDENAÇÃO ==========//
typedef struct{
    int *array;
    int n;
} sort_t;
bool troca_posicao(sort_t *sort, int i, int j);
bool create_S(sort_t *sort, int n);
void povoar_S(sort_t *sort, int n);

void bubble_sort(sort_t *sort, bool crescente); // MÉTODO BOLHA
void insertion_sort(sort_t *sort); // MÉTODO INSERÇÃO
void selection_sort(sort_t *sort, bool crescente); // MÉTODO SELEÇÃO

int particiona(sort_t *sort, int start, int end);
void merge(sort_t *sort, int mid, int left, int right);
void merge_sort(sort_t *sort, int left, int right);
void quick_sort(sort_t *sort, int start, int end);

// ========== BINARY TREE =========== //

typedef struct node {
    int value;
    struct node *left;
    struct node * right;
} node_t;

node_t * create_node (int value);
void destroy (node_t *node);
node_t * insert_node (node_t *root, int value);
node_t *  search_tree (node_t * root, int value, int * level);
int maxValue(node_t * root);
int minValue(node_t * root);
void printTree(node_t *root);
node_t * printTreeSoons(node_t * root, int value, int level);
node_t * removeNumber (node_t *root, int value);

#endif //TEMP_LIBPRG_H