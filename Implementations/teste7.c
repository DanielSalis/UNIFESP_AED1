#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct elemento{
  char caractere;
  struct elemento *ant;
}tipoElemento;

typedef struct pilha {
  int tamanho;
  tipoElemento *topo;
}tipoLista;

void inicializaPilha(tipoLista *lista){
  lista->tamanho = 0;
  lista->topo = NULL;
}

void empilhar(tipoLista *lista, int caractere){
  tipoElemento *novoElemento = (tipoElemento*)malloc(sizeof(tipoElemento));
  novoElemento->caractere = caractere;

  if(lista->tamanho == 0){
    novoElemento->ant = NULL;
    lista->topo = novoElemento;
  }

  else{
    novoElemento->ant = lista->topo;
    lista->topo = novoElemento;
  }
  lista->tamanho++;
}

void remover(tipoLista* l){
    tipoElemento* aux = l->topo;

    while(aux->ant != NULL){
        aux = aux->ant;
    }

    l->topo = aux;
    aux->ant = NULL;
    l->tamanho--;
}

void imprimir(tipoLista *listaEsq, tipoLista *listaDir)
{
	int tamanhoTotal;
    int i = 0;
    
    tamanhoTotal = listaEsq->tamanho + listaDir->tamanho;

	tipoElemento *auxEsq = listaEsq->topo;
    tipoElemento *auxDir = listaDir->topo;


	for(i = 0; i < tamanhoTotal; i++){
		if(i % 2 == 0){
			printf("%c", auxEsq->caractere);
			auxEsq = auxEsq->ant;
		}
		if(i % 2 != 0){
			printf("%c", auxDir->caractere);
			auxDir = auxDir->ant;
		}
	}
}

void gerenciarCriptografia(tipoLista *listaEsq, tipoLista *listaDir, char* string, int tamanho){
    int i = tamanho;
    int j = 0;
	char caractere;

	for(j = 0; j < i; j++){
		if(j % 2 == 0){
			caractere  = string[j];
			empilhar(listaEsq, caractere);
		}
		if(j % 2 != 0){
			caractere  = string[j];
			empilhar(listaDir, caractere);
		}
	}
}
int main(){

	char string[50];
	tipoLista listaEsq;
	tipoLista listaDir;

	inicializaPilha(&listaEsq);
	inicializaPilha(&listaDir);
    scanf("%[^\n]s", string);

    int tamanho = strlen(string);

	gerenciarCriptografia(&listaEsq, &listaDir, string, tamanho);

    imprimir(&listaEsq, &listaDir);
	return 0;
}
