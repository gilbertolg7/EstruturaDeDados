#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TAM 10

typedef struct{
	int vetor[TAM];
	int topo;
}PilhaEstatica;

void iniciarPilhaEstatica (PilhaEstatica *p){
		p->topo=0;
}

bool estaVaziaPilhaEstatica(PilhaEstatica *p){
	return(p->topo==0);
}

bool estaCheiaPilhaEstatica(PilhaEstatica *p){
	return(p->topo==TAM);
}

void imprimirPilhaEstatica(PilhaEstatica *p){
	int i;
	for(i=0; i< p->topo; i++){
		printf("%d ", p->vetor[i]);
	}
	printf("\n");
	
}
void inserirPilhaEstatica(PilhaEstatica *p, int x){
	if(!estaCheiaPilhaEstatica(p)){
		 p->vetor[p->topo]=x;
		 p->topo++;
	}else{
		printf("Pilha esta cheia\n");
	}
}

void removePilhaEstatica(PilhaEstatica *p){
	if(!estaVaziaPilhaEstatica(p)){
		 p->topo--;
	}else{
		printf("Pilha esta vazia\n");
	}
}
void destruirPilhaEstatica(PilhaEstatica *p){
	if(!estaVaziaPilhaEstatica(p)){
		int i;
		for(i=p->topo; i>=0; i--){
			p->topo--;
		}
	printf("Pilha destruida\n");
	}else{
		printf("Pilha esta vazia\n");
		}
	}

int main(){
	PilhaEstatica pilha;
	iniciarPilhaEstatica (&pilha);
	int vetorN[10]= {1,2,3,4,5,6,7,8,9,10};
	int i;
	
	removePilhaEstatica(&pilha);
	for( i=0; i<TAM; i++){
		inserirPilhaEstatica(&pilha, vetorN[i]);
	}
	imprimirPilhaEstatica(&pilha);
	inserirPilhaEstatica(&pilha, 22);
	
	removePilhaEstatica(&pilha);
	imprimirPilhaEstatica(&pilha);
	
	destruirPilhaEstatica(&pilha);
	imprimirPilhaEstatica(&pilha);
	
}
