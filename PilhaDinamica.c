#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct NoPilha* PtrNoPilha;

struct NoPilha{
	int elemento;
	PtrNoPilha proximo;
}NoPilha;

typedef struct{
	PtrNoPilha topo;
	int qtde;
}PilhaDinamica;


void iniciarPilhaDinamica(PilhaDinamica *p){
	p->topo=NULL;
	p->qtde=0;
}

bool estaVaziaPilhaDinamica(PilhaDinamica *p){
	return(p->topo==NULL);
}

int tamanhoPilhaDinamica(PilhaDinamica *p){
	return(p->qtde);
}

void imprimirPilhaDinamica(PilhaDinamica *p){
		
		PtrNoPilha aux;
		for(aux=p->topo; aux!=NULL; aux = aux->proximo){
			printf("%d ", aux->elemento);
		}
			printf("\n");
	
}

void inserirPilhaDinamica(PilhaDinamica *p, int x){
	PtrNoPilha aux;
	aux=malloc(sizeof(NoPilha));
	aux->elemento=x;
	aux->proximo= p->topo;
	p->topo = aux;
	p->qtde++;
}

void removerPilhaDinamica(PilhaDinamica *p){
	if(!estaVaziaPilhaDinamica(p)){
		PtrNoPilha aux;
		aux=p->topo;
		p->topo=p->topo->proximo;
		free(aux);
		p->qtde--;
	}else{
		printf("Pilha vazia\n");
	}

}
void topoPilhaDinamica(PilhaDinamica *p){

	printf("%d\n",p->topo->elemento );
}


void destruirPilhaDinamica(PilhaDinamica *p){
	if(!estaVaziaPilhaDinamica(p)){
		PtrNoPilha aux;
		while(!estaVaziaPilhaDinamica(p)){
		removerPilhaDinamica(p);
		}
		printf("destruida\n");
	}else{
		printf("Pilha vazia\n");
	}
}


int main(){
	PilhaDinamica pilha;	
	
	iniciarPilhaDinamica(&pilha);
	
	int vetorN[10]= {1,2,3,4,5,6,7,8,9,10};
	int i;
	
	removerPilhaDinamica(&pilha);
	for( i=0; i<10; i++){
		inserirPilhaDinamica(&pilha, vetorN[i]);
	}
	topoPilhaDinamica(&pilha);
	imprimirPilhaDinamica(&pilha);
	removerPilhaDinamica(&pilha);
	imprimirPilhaDinamica(&pilha);
	
	destruirPilhaDinamica(&pilha);
	if(estaVaziaPilhaDinamica(&pilha)){
		printf("Pilha vazia\n");
	}
}
