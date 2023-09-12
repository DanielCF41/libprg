#include <libprg/libprg.h>

int enqueue(fila_t *fila, int elemento) {
    full(fila);
    fila->fila->vetor[fila->fim] = elemento;
    fila->fila->total_elementos++;
    fila->fim = (fila->fim + 1) % fila->fila->tamanho;
    return 0;

}

int dequeue(fila_t *fila) {
    empty(fila);
    fila->fila->total_elementos--;
    fila->inicio = (fila->inicio + 1) % fila->fila->tamanho;
    return 0;
}

int head (fila_t *fila){
    return fila->fila->vetor[fila->inicio];
}

int tail (fila_t *fila){
    return fila->fila->vetor[fila->fim];
}

int size (fila_t *fila){
    return fila->fila->total_elementos;
}

int empty (fila_t *fila){
    return (fila->inicio == fila->fim) ? 0 : -1;
}

int full (fila_t *fila){
    return (fila->fila->total_elementos == fila->fila->tamanho) ? 0 : -1;
}