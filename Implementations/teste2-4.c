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
    
    if(l->tamanhoLista == 0){
        l->elemento[0].valor = num;
        l->elemento[0].prox = -1;
        l->primeiro = posicao;
        l->ultimo = posicao;
        l->posicaoLivre[0]=0;
        l->tamanhoLista++;
    }else{
        l->elemento[posicao].valor = num;
        l->elemento[l->ultimo].prox = posicao;
        l->elemento[posicao].prox = -1;
        l->ultimo = posicao;
        l->posicaoLivre[posicao] = 0;
        l->tamanhoLista++;
    }
}

// void inserirInicioDaLista(TipoLista* l, int num, int posicao){
//     if(l->tamanhoLista == 0){
//         l->elemento[0].valor = num;
//         l->elemento[0].prox = -1;
//         l->primeiro = posicao;
//         l->ultimo = posicao;
//         l->posicaoLivre[0]=0;
//         l->tamanhoLista++;
//     }else{
//         l->elemento[posicao].valor = num;
//         l->elemento[posicao].prox = l->primeiro;
//         l->primeiro = posicao;
//         l->posicaoLivre[posicao] = 0;
//         l->tamanhoLista++;
//     }
// }


// void removerElemento(TipoLista* l, int posicao, int numero){
//   int marcador=-1, i=0;
//   int aux = l->primeiro;

//   for(i=0; i<N; i++){
//     if(numero == l->elemento[aux].valor){

//       if(aux == l->primeiro){
//         l->posicaoLivre[l->primeiro] = 1; 
//         l->primeiro = l->elemento[l->primeiro].prox; 
//         l->tamanhoLista--;
//       }

//       else if(aux == l->ultimo){
//         int encontrou = 0;
//         int anterior = l->primeiro;

//         while(encontrou == 0){
//           if(l->elemento[anterior].prox == aux)
//             encontrou = 1;
//           else
//             anterior = l->elemento[anterior].prox;
//         }

//         l->elemento[anterior].prox = -1;
//         l->ultimo = anterior;
//         l -> posicaoLivre[aux] = 1;
//         l->tamanhoLista--;
//       }

//       else{
//         int encontrou=0;
//         int anterior = l->primeiro;

//         while(encontrou == 0){
//           if(l->elemento[anterior].prox == aux)
//             encontrou =1;
//           else
//             anterior = l->elemento[anterior].prox;
//         }
        
//         l->elemento[anterior].prox = l->elemento[aux].prox;
//         l->elemento[aux].prox = -1;
//         l->posicaoLivre[aux] = 1;
//         l->tamanhoLista--;
//       }
//     }
//     aux = l->elemento[aux].prox;
//   }
// }

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

// void inverteLista(TipoLista* l){
//     int i; 
//     int j = 0;
//     int k =0;
//     int posicao;
//     int vet[l->tamanhoLista];

//     for(i = l->primeiro; i!=-1; i = l->elemento[i].prox){
//         vet[j] = l->elemento[i].valor;
//         j++;
//     }

//     // for(int k = 0 ; k < l->tamanhoLista-1; k++){
//     //     printf("%d ", vet[k]);
//     // }

//     j = l->tamanhoLista-1;
//     iniciarLista(l);

//     for(j; j>=0;j--){
//         posicao = proximaPosicaoLivre(l);
//         inserirFinalDaLista(l, vet[j], posicao);
//     }
// }

int verificaOrdenacao(TipoLista* l){
  int crescente=0;
  int decrescente=0;
  int aux;
  int i;
  int igual=0;
  aux = l->primeiro;


  while(i!=-1){
    i = l->elemento[aux].prox;
    
    if(l->elemento[aux].valor == l->elemento[i].valor){
      igual ++;
      aux = i;
    }
    
    if(l->elemento[aux].valor < l->elemento[i].valor){
      crescente ++;
      aux = i;
    }
    
    if(l->elemento[aux].valor > l->elemento[i].valor){
      decrescente++;
      aux = i;
    }
    
    if(l->elemento[aux].prox == l->ultimo){
      
      if(l->elemento[aux].valor == l->elemento[l->ultimo].valor){
        igual ++;
        break;
      }
      
      if(l->elemento[aux].valor < l->elemento[l->ultimo].valor){
        crescente ++;
        break;
        }
      
      if(l->elemento[aux].valor > l->elemento[l->ultimo].valor){
        decrescente ++;
        break;
      }
    }
  }
  
  if(crescente+igual == l->tamanhoLista-1)
    printf("crescente");

  else if(decrescente+igual == l->tamanhoLista-1)
    printf("decrescente");

  else
    printf("desordenada");
}


int main(){

    int i;
    int numero;
    int posicao;
    char c;
    
    TipoLista lista;

    iniciarLista(&lista);

    while(c!='\n'){
        posicao = proximaPosicaoLivre(&lista);
        scanf("%d%c", &numero, &c);
        inserirFinalDaLista(&lista, numero, posicao);
    } 

    int ordenacao = verificaOrdenacao(&lista);
}