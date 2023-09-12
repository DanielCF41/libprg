#include <libprg/libprg.h>

int cria(vetor_t *vetor, int tamanho){
    vetor->vetor = (int*) calloc(tamanho, sizeof (int));
    if(vetor->vetor == NULL){
        return -1;
    }
    return 0;
}

void nao_ordenada(vetor_t *vetor, int tamanho){
    srand((unsigned) time(NULL));

    for(int i = 0; i < vetor->total_elementos; i++){
        vetor->vetor[i] = (rand() % INT_MAX) + 1;
    }
}
void ordenada(vetor_t *vetor, int tamanho){
    int num;
    srand((unsigned) time(NULL));
    vetor->vetor = (int*) calloc(tamanho, sizeof (int));

    for(int i = 0; i < vetor->total_elementos; i++){
        do {
            num = (rand() % INT_MAX) + 1;
        }while (num <= vetor->vetor[i]);
        vetor->vetor[i] = num;
    }
}

int povoar(vetor_t * vetor, char op){
    if(op == 'O' || op == 'o'){
        ordenada(vetor, vetor->tamanho);
    }else{
        nao_ordenada(vetor, vetor->tamanho);
    }
}


int buscar_l(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] == elemento){
            return i;
        }
    }
}

int buscar_bi(vetor_t *vetor, int elemento){
    int meio;
    int inicio = 0;
    int fim = vetor->total_elementos;
    for(int i = 0; i < vetor->total_elementos; i++){
        meio = inicio + (fim - inicio) / 2;
        if(vetor->vetor[meio] == elemento){
            return meio;
        }else if(vetor->vetor[meio] < elemento){
            inicio = meio + 1;
        }else{
            fim = meio - 1;
        }
    }
    return -1;
}

int buscar_br(vetor_t *vetor, int inicio, int fim, int elemento){
    int meio;
    for(int i = 0; i < vetor->total_elementos; i++){
        meio = inicio + (fim - inicio) / 2;
        if(vetor->vetor[meio] == elemento){
            return meio;
        }else if (vetor->vetor[meio] > elemento){
            return buscar_br(vetor, meio + 1, fim, elemento);
        }else{
            return buscar_br(vetor, inicio, meio - 1, elemento);
        }
    }
    return -1;
}

void inserir_n(vetor_t *vetor, int elemento){
    if(vetor->total_elementos < vetor->tamanho) {
        vetor->vetor[vetor->total_elementos++] = elemento;
    }
}

void inserir_o(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] > elemento){
            for(int j = vetor->total_elementos++; j > i; j--){
                vetor->vetor[j] = vetor->vetor[j - 1];
            }
            vetor->vetor[i] = elemento;
            break;
        }
    }
}

int remover(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] == elemento){
            vetor->vetor[i] = vetor->vetor[vetor->total_elementos--];
        }
    }
}

int remover_o(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] == elemento){
            for(int j = i; j < vetor->total_elementos--; j++){
                vetor->vetor[j] = vetor->vetor[j + 1];
            }
        }
    }
}