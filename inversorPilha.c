#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TAM 10

typedef struct{
	int vetor[TAM];
	int topo;
}PilhaEstatica;

typedef struct{
	int vetor1[TAM];
	int topo1;
}PilhaEstatica2;

void iniciarPilhaEstatica (PilhaEstatica *p){
		p->topo=0;
}
void iniciarPilhaEstatica2 (PilhaEstatica2 *p2){
		p2->topo1=0;
}

bool estaVaziaPilhaEstatica(PilhaEstatica *p){
	return(p->topo==0);
}

bool estaVaziaPilhaEstatica2(PilhaEstatica2 *p2){
	return(p2->topo1==0);
}

bool estaCheiaPilhaEstatica(PilhaEstatica *p){
	return(p->topo==TAM);
}

bool estaCheiaPilhaEstatica2(PilhaEstatica2 *p2){
	return(p2->topo1==TAM);
}

void imprimirPilhaEstatica(PilhaEstatica *p){
	int i;
	for(i=0; i< p->topo; i++){
		printf("%d ", p->vetor[i]);
	}
	printf("\n");
	
}

void imprimirPilhaEstatica2(PilhaEstatica2 *p2){
	int i;
	for(i=0; i< p2->topo1; i++){
		printf("%d ", p2->vetor1[i]);
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

void inserirPilhaEstatica2(PilhaEstatica2 *p2, int x){
	if(!estaCheiaPilhaEstatica2(p2)){
		 p2->vetor1[p2->topo1]=x;
		 p2->topo1++;
	}else{
		printf("Pilha esta cheia\n");
	}
}

int removePilhaEstatica(PilhaEstatica *p){
	if(!estaVaziaPilhaEstatica(p)){
	int aux;
	 	 
		 p->topo--;
		 aux= p->vetor[p->topo];
		 return (aux);
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
	
	PilhaEstatica2 pilha2;
	iniciarPilhaEstatica2 (&pilha2);
	
	int vetorN[10]= {1,2,3,4,5,6,7,8,9,10};
	int i;
	int x;
	
	removePilhaEstatica(&pilha);
	for( i=0; i<TAM; i++){
		inserirPilhaEstatica(&pilha, vetorN[i]);
	}
	imprimirPilhaEstatica(&pilha);
	for( i=0; i<TAM; i++){
		x=removePilhaEstatica(&pilha);
	    inserirPilhaEstatica2(&pilha2,x);
	}

	imprimirPilhaEstatica(&pilha);
	
	imprimirPilhaEstatica2(&pilha2);
	
}
