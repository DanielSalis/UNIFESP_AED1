// Considere a lista de inteiros, sem elementos repetidos. Escreva uma função que
// faça a remoção de um elemento baseado em um valor fornecido. A função deve
// verificar se o elemento existe na lista e se sim, realizar a remoção e realocar os
// elementos da lista.


#include <stdlib.h>
#include <stdio.h>

#define N 100

typedef struct lista_estatica_sequencial{
    int tamanho;
    int ultimo;
    int lista[N];
}TipoLista;

void iniciaLista(TipoLista* l){
    l->tamanho = 0;
    int i = 0 ;
    for(i=0; i< N; i++){
        l->lista[i] = 0;
    }
}


void insereNoFim(TipoLista* l, int numero){
    int i = 0;
    int flag = 0;
    for(i=0; i< l->tamanho; i++){
        if(numero == l->lista[i]){
            flag = 1;
        }
    }

    if(flag == 0){
        l->lista[l->tamanho] = numero;
        l->ultimo = l->lista[l->tamanho];
        l->tamanho++;
    }

    
}

int existeNaLista(TipoLista* l, int numero){
    int i;
    for(i = 0; i < l->tamanho; i++){
        if(l->lista[i] == numero){
            return 1;
        }
    }
}

int BuscaPosicao(TipoLista* l, int numero){
    int i;
    for(i = 0; i < l->tamanho; i++){
        if(l->lista[i] == numero){
            return i;
        }
    }
}

void remover(TipoLista* l, int numero){

    if(l->tamanho == 0){
        //lista vazia;
        return;
    }else{
        if(existeNaLista(l, numero) == 1){
            int posicao = BuscaPosicao(l, numero);
            int j;
            for ( j = posicao; j < l->tamanho; j++) {
                l->lista[j] = l->lista[j+1];    
            }
            l->tamanho--;
            l->ultimo = l->lista[l->tamanho];
        }
    }
}

void imprimeLista(TipoLista* l){
    int i;
    for(i=0; i<l->tamanho; i++){
        printf("%d ", l->lista[i]);
    }
}

int tamanhoLista(TipoLista* l){
    return l->tamanho;
}

int main(){

    int i;
    int numero;
    char c;
    TipoLista lista;

    iniciaLista(&lista);
    
    for(i=0; i<N; i++){
        scanf("%d%c", &numero, &c);
        insereNoFim(&lista, numero);
        if(c=='\n'){
            break;
        }

    }


    scanf("%d", &numero);
    remover(&lista, numero);

    imprimeLista(&lista);

}