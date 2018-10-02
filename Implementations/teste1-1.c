// Escreva uma função para inserir elementos em uma lista de inteiros. No entanto
// a lista não pode conter elementos repetidos, dessa forma, um novo elemento só
// deve ser inserido se a lista ainda não o contém.

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
    imprimeLista(&lista);

}