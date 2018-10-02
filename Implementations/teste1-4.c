// 4. A NALISANDO A L ISTA
// Escreva uma função que dada uma lista de inteiros, analise se os elementos
// estão em ordem crescente, decrescente ou desordenados.
// Entrada
// • Sequência de inteiros que compõe a lista.
// Saída
// • Imprimir o estado da lista ("crescente", "decrescente" ou "desordenada").
 
// 4. A NALISANDO A L ISTA
// Escreva uma função que dada uma lista de inteiros, analise se os elementos
// estão em ordem crescente, decrescente ou desordenados.
// Entrada
// • Sequência de inteiros que compõe a lista.
// Saída
// • Imprimir o estado da lista ("crescente", "decrescente" ou "desordenada").
 
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
    
    l->lista[l->tamanho] = numero;
    l->ultimo = l->lista[l->tamanho];
    l->tamanho++;
    
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
 
int verificaOrdenacao(TipoLista* l){
   int crescente = 1;
   int decrescente = 1;
   int desordenada = 1;
    int i;
    for(i = 0 ; i < l->tamanho-1; i++){
        if(l->lista[i] < l->lista[i+1]){
            decrescente = 0;
            if(l->lista[i] == l->lista[i+1] - 1){
                desordenada = 0;
            }
        }

        if(l->lista[i] > l->lista[i+1]){
            crescente = 0;
            if(l->lista[i] == l->lista[i+1] -+1){
                desordenada = 0;
            }
        }

        if(l->lista[i] == l->lista[i+1]){
            crescente = 0;
            decrescente = 0;
        }

    }
 
    if (crescente == 1){
        return 0;
    }
 
    if(decrescente == 1){
        return 1;
    }
 
    if (desordenada == 1 ){
        return 2;
    }
 
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
 
    int ordenacao = verificaOrdenacao(&lista);
    // printf("\n%d\n", ordenacao);
 
    if(ordenacao == 0){
        printf("crescente");
    }
 
    if(ordenacao == 1){
        printf("decrescente");
    }
 
    if(ordenacao == 2){
        printf("nao");
    }
}