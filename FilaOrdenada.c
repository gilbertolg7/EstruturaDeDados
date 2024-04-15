#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NoLista* PtrNoLista;

typedef struct NoLista{
	int dado;
	PtrNoLista proximo;
}NoLista;

typedef struct{
	PtrNoLista inicio;
	int qtdeElementos;
}Lista;

void iniciarLista(Lista *l){
	l->inicio=NULL;
	l->qtdeElementos=0;
}

bool estaVaziaLista(Lista *l){
	return(l->inicio==NULL);
}

void imprimirTamanhoLista(Lista *l){
	printf("%d", l->qtdeElementos);
}

void imprimirLista(Lista *l){
	PtrNoLista aux;
	if(!estaVaziaLista(l)){
	for(aux=l->inicio; aux!=NULL; aux=aux->proximo){
		printf("%d " ,aux->dado);
	}	
		printf("\n");
	}else{
	printf("Lista esta vazia!\n");
	}
}

void inserirLista(Lista *l, int x){
	PtrNoLista novo = malloc(sizeof(NoLista));
	novo->dado = x;
	
	if(estaVaziaLista(l)){
		l->inicio=novo;
		novo->proximo=NULL;
	}else if(x < l->inicio->dado){
		novo->proximo=l->inicio;
		l->inicio=novo;
	}else{
		PtrNoLista aux;
		aux=l->inicio;
		while(aux->proximo!=NULL && x <aux->proximo->dado){
			aux = aux->proximo;
		}
		novo->proximo = aux->proximo;
		aux->proximo = novo;
	}
}

bool removerLista(Lista *l, int x){
	PtrNoLista rm;
	if(estaVaziaLista(l) || x < l->inicio->dado){
		return false;
	}
	if(x == l->inicio->dado){
		rm = l->inicio;
		l->inicio=l->inicio->proximo;
		free(rm);
		l->qtdeElementos--;
		return true;
	}
	PtrNoLista aux;
	aux = l->inicio;
	while(aux->proximo!=NULL && x <aux->proximo->dado){
			aux = aux->proximo;
		}
	if(x < aux->proximo->dado){
		return false;
	}
	rm= aux->proximo;
	aux->proximo= aux->proximo->proximo;
	free (rm);
	l->qtdeElementos--;
		return true;
	}
	


int main(int argc, char * argv[]) {

	Lista lista;
	iniciarLista(&lista);
	if(estaVaziaLista(&lista)){
		printf("Lista esta vazia!\n");
	}
	
	inserirLista(&lista, 10);
	
	inserirLista(&lista, 11);
	
	inserirLista(&lista, 15);
	inserirLista(&lista, 22);
	inserirLista(&lista, 25);
	inserirLista(&lista, 17);	
	inserirLista(&lista, 30);
	imprimirLista(&lista);
	removerLista(&lista,25);
	imprimirLista(&lista);
	removerLista(&lista,10);
	imprimirLista(&lista);
	removerLista(&lista,29);
	imprimirLista(&lista);
	
    return 0;
}
