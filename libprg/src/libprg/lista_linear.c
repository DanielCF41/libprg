#include <libprg/libprg.h>
//------------- CRIA -------------
int cria(vetor_t *vetor, int tamanho){
    vetor->vetor = (int*) calloc(tamanho, sizeof (int));
    if(vetor->vetor == NULL){
        return -1;
    }
    return 0;
}

//------------- NÃO ORDENADA -------------
void nao_ordenada(vetor_t *vetor, int tamanho){
    int num;
    srand((unsigned) time(NULL));

    for(int i = 0; i < vetor->tamanho; i++){
        num = (rand() % 100) + 1;
        if(buscar_l(vetor, num) == -1){
            vetor->vetor[i] = num;
        }
    }
}

//------------- ORDENADA -------------
void ordenada(vetor_t *vetor, int tamanho){
    int num;

    srand((unsigned) time(NULL));
    cria(vetor, tamanho);

    for(int i = 0; i < vetor->total_elementos; i++){
        num = (rand() % 100) + 1;
        if(num > vetor->vetor[i - 1] && buscar_bi(vetor, num) == -1){
            vetor->vetor[i] = num;
        }
    }
}

//------------- POVOAR -------------
int povoar(vetor_t * vetor, char op){
    if(op == 1){
        ordenada(vetor, vetor->tamanho);
    }else if(op == 2){
        nao_ordenada(vetor, vetor->tamanho);
    }
}

//------------- BUSCA LINEAR -------------
int buscar_l(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] == elemento){
            return i;
        }
    }
    return -1;
}

//------------- BUSCA BINÁRIA -------------
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

//------------- BUSCA BINÁRIA RECURSIVA -------------
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

//------------- INSERIR NÃO ORDENADA -------------
void inserir_n(vetor_t *vetor, int elemento){
    if(vetor->total_elementos < vetor->tamanho) {
        vetor->vetor[vetor->total_elementos++] = elemento;
    }
}

//------------- INSERIR ORDENADA -------------
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

//------------- REMOVER -------------
int remover(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] == elemento){
            vetor->vetor[i] = vetor->vetor[vetor->total_elementos--];
        }
    }
}

//------------- REMOVER ORDENADA -------------
int remover_o(vetor_t *vetor, int elemento){
    for(int i = 0; i < vetor->total_elementos; i++){
        if(vetor->vetor[i] == elemento){
            for(int j = i; j < vetor->total_elementos--; j++){
                vetor->vetor[j] = vetor->vetor[j + 1];
            }
        }
    }
}