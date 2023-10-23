#include <libprg/libprg.h>

bool bubble_sort_c(sort_t *sort){
    int aux;
    for(int i = 0; i < sort->n; i++){
        for(int j = 0; j < sort->n - i; j++){
            if(sort->array[j] > sort->array[j + 1]) {
                aux = sort->array[j];
                sort->array[j] = sort->array[j + 1];
                sort->array[j + 1] = aux;
            }
        }
    }
}

bool bubble_sort_d(sort_t *sort){
    int aux;
    for(int i = 0; i < sort->n; i++){
        for(int j = 0; j < sort->n - i; j++){
            if(sort->array[j] < sort->array[j + 1]) {
                aux = sort->array[j];
                sort->array[j] = sort->array[j + 1];
                sort->array[j + 1] = aux;
            }
        }
    }
}



bool insertion_sort(sort_t *sort){
    for(int i = 0; i < sort->n; i++){
        int chave = sort->array[i];
        int j = i - 1;
        while(j >= 0 && sort->array[j] > chave){
            sort->array[j + 1] = sort->array[j];
            j = j - 1;
        }
        sort->array[j + 1] = chave;
    }
}

bool selection_sort(sort_t *sort){
    int indice;
    for(int i = 0; i < sort->n; i++){
        indice = i;
        for(int j = i + 1; j < sort->n; j++){
            if(sort->array[j] < sort->array[indice]) {
                indice = j;
            }
        }
        if(i != indice){
            int aux = sort->array[i];
            sort->array[i] = sort->array[indice];
            sort->array[indice] = aux;
        }
    }
}

bool selection_sort_d(sort_t *sort){
    int indice;
    for(int i = 0; i < sort->n; i++){
        indice = i;
        for(int j = i + 1; j < sort->n; j++){
            if(sort->array[j] > sort->array[indice]) {
                indice = j;
            }
        }
        if(i != indice){
            int aux = sort->array[i];
            sort->array[i] = sort->array[indice];
            sort->array[indice] = aux;
        }
    }
}

