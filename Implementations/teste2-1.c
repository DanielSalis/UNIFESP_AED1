#include <stdio.h>
#include <stdlib.h>
#define N 100

typedef struct info{
    int valor;
    int prox;
}TipoInfo;

typedef struct lista_estatica_encadeada{
    int tamanhoLista;
    int primeiro;
    int ultimo;
    int posicaoLivre[N];
    TipoInfo elemento[N];
}TipoLista;


void iniciarLista(TipoLista* l){
    int i;
    l->tamanhoLista = 0;
    l->primeiro = -1;
    l->ultimo = -1;

    for(i = 0; i < N; i++){
        l->posicaoLivre[i] = 1;
        l->elemento[i].valor = 0;
        l->elemento[i].prox = -1;
    }   
}

int proximaPosicaoLivre(TipoLista* l){
    int i;
    for(i=0; i<N; i++){
        if(l->posicaoLivre[i] == 1){
            return i;
        }
    }
    return -1;
}

void inserirFinalDaLista(TipoLista* l, int num, int posicao){
    l->elemento[posicao].valor = num;
    l->elemento[l->ultimo].prox = posicao;
    l->elemento[posicao].prox = -1;
    l->ultimo = posicao;
    l->posicaoLivre[posicao] = 0;
    l->tamanhoLista++;
}

void inserirInicioDaLista(TipoLista* l, int num, int posicao){
    if(l->tamanhoLista == 0){
        l->elemento[0].valor = num;
        l->elemento[0].prox = -1;
        l->primeiro = posicao;
        l->ultimo = posicao;
        l->posicaoLivre[0]=0;
        l->tamanhoLista++;
    }else{
        l->elemento[posicao].valor = num;
        l->elemento[posicao].prox = l->primeiro;
        l->primeiro = posicao;
        l->posicaoLivre[posicao] = 0;
        l->tamanhoLista++;
    }
}

void imprimirLista(TipoLista* l){
    
    int posicao = l->primeiro;

    if(l->tamanhoLista !=0){
        while(posicao!=-1){
            if(l->tamanhoLista == 1){
            printf("%d ", l->elemento[l->primeiro].valor);  
            }
            else{
                printf("%d ", l->elemento[posicao].valor);
            }
            posicao = l->elemento[posicao].prox;
        }
    }
}

int main(){

    int i;
    int numero;
    int contador = 1;
    int posicao;
    char c;
    
    TipoLista lista;

    iniciarLista(&lista);

  while(c!='\n'){
    
    posicao = proximaPosicaoLivre(&lista);
    scanf("%d%c", &numero, &c);

    if(contador%2 != 0){
        inserirInicioDaLista(&lista, numero, posicao);
    }

    if(contador%2 == 0){
         inserirFinalDaLista(&lista, numero, posicao);
    }
    contador++;
  }

     imprimirLista(&lista);
}