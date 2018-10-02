#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct elemento{
    int valor;
    int id;
    int chave;
    int chaveAnterior;
    struct elemento* prox;
}TipoElemento;

typedef struct lista_dinamica{
    TipoElemento* primeiro;
    TipoElemento* ultimo;
    int tamanho;
}TipoLista;

void iniciarLista(TipoLista* l){
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->tamanho = 0;
}

int FuncHashInserir(TipoLista* l){
    int mod;
    TipoElemento* aux = l->ultimo;
    mod = (aux->valor % aux->id);
    int novaChave = mod +  aux->chaveAnterior;
    return novaChave;
}

void FuncHash(TipoLista* l, TipoElemento* elemento){
    TipoElemento* aux = l->primeiro;

    if(elemento->id == l->primeiro->id){
        elemento->chaveAnterior = 0;
        int mod = (elemento->valor % elemento->id);
        int novaChave = mod + elemento->chaveAnterior;
        elemento->chave = novaChave;
    }
    else{
        while(aux->prox!= elemento){
            aux = aux->prox;
        }
        elemento->chaveAnterior = aux->chave;
        int mod = (elemento->valor % elemento->id);
        int novaChave = mod + aux->chave;
        elemento->chave = novaChave;
    }
}

void atualizaHash(TipoLista* l){
    TipoElemento* aux;
    aux=l->primeiro;
    while(aux!=NULL){
        FuncHash(l, aux);
        aux = aux->prox;
    }
}

void inserirFim(TipoLista* l, int id, int valor){
    
    TipoElemento* aux = l->primeiro;
    while(aux!=NULL){
        if(aux->id == id){
            return;
        }
        aux = aux->prox;
    }

    TipoElemento* novoElemento = (TipoElemento*)malloc(sizeof(TipoElemento));
    novoElemento->id = id;
    novoElemento->valor = valor;

    if(l->tamanho == 0){
        l->primeiro = novoElemento;
        l->ultimo = novoElemento;
        novoElemento->chaveAnterior = 0;
        novoElemento->chave = FuncHashInserir(l);
        novoElemento->prox = NULL;
        l->tamanho++;

    }else{
        novoElemento->chaveAnterior = l->ultimo->chave;
        l->ultimo->prox = novoElemento;
        l->ultimo = novoElemento;
        novoElemento->chave = FuncHashInserir(l);
        novoElemento->prox = NULL;
        l->tamanho++;
    }
}

void atualizar(TipoLista* l, int id, int valor){
    TipoElemento* aux = l->primeiro;
    while(aux!=NULL){
        if(aux->id == id){
            break;
        }
        aux = aux->prox;
    }
    aux->valor = aux->valor + valor;

}

void remover(TipoLista* l, int id){
    TipoElemento* antElemento = l->primeiro;
    TipoElemento* proxElemento = l->primeiro->prox;
    TipoElemento* aux;
    int cont;

    if(l->primeiro->id == id){
        l->primeiro = proxElemento;
        antElemento = NULL;
        free(antElemento);
        l->tamanho--;
        
        aux=l->primeiro;
        while(aux!=NULL){
            FuncHash(l, aux);
            aux = aux->prox;
        }
        return;
    }

    else if(l->ultimo->id == id){
        while(antElemento->prox!=l->ultimo){
            antElemento = antElemento->prox;
        }
        antElemento->prox = NULL;
        l->ultimo = antElemento;
        l->tamanho--;

        aux=l->primeiro;
        while(aux!=NULL){
            FuncHash(l, aux);
            aux = aux->prox;
        }
        return;
    }

    while(proxElemento!=NULL){
        if(proxElemento->id == id){;
            break;
        }
        cont++;
        antElemento = proxElemento;
        proxElemento = proxElemento->prox;
    }

    antElemento->prox = proxElemento->prox;
    proxElemento = NULL;
    free(proxElemento);

    l->tamanho--;
    aux=l->primeiro;
    while(aux!=NULL){
        FuncHash(l, aux);
        aux = aux->prox;
    }
}

void transferir(TipoLista* l, int IDpaga, int valor, int IDrecebe){
    TipoElemento*aux = l->primeiro;
    TipoElemento* pagador = l->primeiro;
    TipoElemento* recebedor = l->primeiro;
    while(pagador->id!=IDpaga){
        pagador = pagador->prox;
        if(IDpaga == NULL){
            return;
        }
    }

    while(recebedor->id!=IDrecebe){
        recebedor = recebedor->prox;
        if(IDrecebe == NULL){
            return;
        }
    }

    recebedor->valor = recebedor->valor + valor;
    pagador->valor = pagador->valor - valor;

    return;
}

void imprimir(TipoLista* l){
    TipoElemento* aux = l->primeiro;
    while(aux!=NULL){
       printf("id: %d | valor: %d | hashanterior: %d | hash: %d\n", aux->id, aux->valor, aux->chaveAnterior, aux->chave);
        aux = aux->prox;
    }
}

int main(){
    int op;
    int id;
    int valor;
    int IDpaga;
    int IDrecebe;

    TipoLista lista;

    iniciarLista(&lista);

    while(op!=-1){
        scanf("%d", &op);
        //inserir 
        if(op==1){
            scanf("%d %d", &id, &valor);
            inserirFim(&lista, id, valor);

        }

        // atualizar
        else if(op==2){
            scanf("%d %d", &id, &valor);
            atualizar(&lista, id, valor);
            atualizaHash(&lista);
        }

        //remover
        else if(op==3){
            scanf("%d", &id);
            remover(&lista, id);
        }

        //transferir
        else if(op==4){
            scanf("%d %d %d", &IDpaga, &valor, &IDrecebe);
            transferir(&lista, IDpaga, valor, IDrecebe);
            atualizaHash(&lista);
        }

        else if(op==5){
            imprimir(&lista);
        }

        else if(op==6){
            printf("%d %d \n", lista.ultimo->chaveAnterior, lista.ultimo->chave);
        }
    }
    return 0;    
}