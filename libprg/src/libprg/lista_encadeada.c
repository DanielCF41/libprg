#include <libprg/libprg.h>

//========== LISTA ENCADEADA ==========//

bool create (int dado){
    no_t *inicio = malloc(sizeof(inicio));
    inicio->conteudo = dado;
    inicio->proximo = NULL;
    return true;
}

no_t add(no_t *no, int dado){
    no_t *novo = malloc(sizeof(novo));
    novo->conteudo = dado;
    novo->proximo = no->proximo;
    no->proximo = novo;
}

no_t add_o(no_t *no, int dado){
    no_t *novo = malloc(sizeof (novo));
    novo->conteudo = dado;
    while (novo->proximo != NULL){
        if(no->conteudo > novo->conteudo){
            novo->proximo = no->proximo;
            no->proximo = novo;
        }
    }
}

bool remove_e(no_t *no, int dado){
    no_t *lixo = malloc(sizeof(lixo));
   if(search(no, dado) == dado) {
        lixo->proximo = no->proximo;
        no->proximo = lixo;
        free(lixo);
  }
    return true;
}

bool remove_eo(no_t *no, int dado){
    no_t *lixo = malloc(sizeof(lixo));
    lixo->proximo = no->proximo;
    no->proximo = lixo;
    free(lixo);
}

bool search(no_t *no, int dado){
    no_t *novo = malloc(sizeof(novo));
    do{
        novo->proximo = no;
        no->proximo = novo;
        if(no->conteudo == dado){
            free(novo);
            return true;
        }
    }while(novo->proximo != NULL);
    free(novo);
    return false;
}

int search_o(no_t *no, int dado){

}

//========== LISTA DUPLAMENTE ENCADEADA ==========//

bool create_d(int dado){
    nod_t *inicio = malloc(sizeof (inicio));
    if(inicio == NULL){
        return false;
    }
    inicio->conteudo = dado;
    inicio->proximo = NULL;
    inicio->anterior = NULL;
    return true;
}

nod_t add_d(nod_t *nod, int dado){
    nod_t *novo = malloc(sizeof (novo));
    novo->conteudo = dado;
    nod->anterior = novo->proximo;
    novo->proximo = nod->proximo;
    nod->proximo = novo;
}

nod_t * add_do(nod_t *nod, int dado){
    nod_t *novo = malloc(sizeof (novo));
    novo->conteudo = dado;
    while (nod->proximo != NULL){
        if(dado < nod->conteudo){
            novo->proximo = nod;
            novo->anterior = nod->anterior;
            nod->anterior = novo;
        }else{
            novo->proximo = nod;
        }
    }
    return nod;
}


