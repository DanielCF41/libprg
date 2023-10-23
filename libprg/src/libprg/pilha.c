#include <libprg/libprg.h>

int push(pilha_t *pilha, int elemento, int tamanho){

    if(tamanho == pilha->pilha->total_elementos){
        return -1;
    }
    pilha->pilha->total_elementos++;
    pilha->topo++;
    pilha->pilha->vetor[pilha->topo] = elemento;
}

int pop(pilha_t *pilha){
    if(empty_p(pilha)){
        return -1;
    }
    pilha->pilha->total_elementos--;
    pilha->topo--;
    return pilha->pilha->vetor[pilha->topo + 1];
}

int size_p(pilha_t pilha){
    return pilha.pilha->total_elementos;
}

int empty_p(pilha_t *pilha){
    return (pilha->topo == -1);
}



