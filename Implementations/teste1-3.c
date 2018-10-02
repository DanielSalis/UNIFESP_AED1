// 3. M ANIPULANDO A L ISTA
// Escreva uma função que inverta a ordem dos elementos de uma lista de inteiros.
// Note que os elementos devem ser alterados dentro da lista!! Apenas percorrer
// e imprimir na ordem inversa não é válido.
// Entrada
// • Sequência de inteiros que compõe a lista.
// Saída
// • Imprimir os elementos da lista após a inversão, em uma única linha sep-
// arados por espaço.

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
    l->tamanho--;
    l->ultimo = l->lista[l->tamanho];
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

void inverteLista(TipoLista* l){
    int i; 
    int j;
    int tamanhoListaAnterior = l->tamanho-1;
    int removido;

    TipoLista novaLista;
    iniciaLista(&novaLista);

    for(i = tamanhoListaAnterior; i >= 0; i--){
        removido = l->lista[i];
        remover(l, removido);
        insereNoFim(&novaLista, removido);
    }
    imprimeLista(&novaLista);
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


    inverteLista(&lista);

}