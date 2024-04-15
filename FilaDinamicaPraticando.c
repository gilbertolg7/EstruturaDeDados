#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NoFila* PtrNoFila;

typedef struct NoFila{
	int dado;
	PtrNoFila proximo;
}NoFila;

typedef struct{
	PtrNoFila inicio;
	PtrNoFila fim;
	int qtdeElementos;
}FilaDinamica;

void iniciarFilaDinamica(FilaDinamica *f){
	f->inicio=NULL;
	f->fim=NULL;
	f->qtdeElementos=0;
}

bool estaVaziaFilaDinamica(FilaDinamica *f){
	return(f->inicio==NULL);
}

void inserirFilaDinamica(FilaDinamica *f, int x){
	PtrNoFila aux = malloc(sizeof(NoFila));
	aux->dado = x;
	aux->proximo=NULL;
	
	if(estaVaziaFilaDinamica(f)){
		f->inicio=aux;
	
	}else{
		f->fim->proximo=aux;
	}
	f->fim=aux;
	f->qtdeElementos++;
	
}

void removerFilaDinamica(FilaDinamica *f){
	PtrNoFila aux;
	if(!estaVaziaFilaDinamica(f)){
		aux=f->inicio;
		f->inicio=f->inicio->proximo;
		free(aux);
		f->qtdeElementos--;
	}else{
		printf("Fila Vazia\n");
	}

}

void imprimirInicioFila(FilaDinamica *f){
	printf("%d este e o inicio da Fila\n", f->inicio->dado);
}

void imprimirFimFila(FilaDinamica *f){
	printf("%d este e o inicio da Fila\n", f->fim->dado);
}

void imprimirFila(FilaDinamica *f){
	PtrNoFila aux;
	for(aux=f->inicio; aux!=NULL; aux=aux->proximo){
		printf("%d ", aux->dado);
	}
	printf("\n");
}

	int main(){
	
	FilaDinamica fila;
	iniciarFilaDinamica(&fila);	
	if(estaVaziaFilaDinamica(&fila)){
		printf("Fila vazia!\n");
	}

	int vetor[]={5,8,9,15,21};
	int i;
	for(i=0;i<5;i++){
		inserirFilaDinamica(&fila, vetor[i]);
		imprimirFila(&fila);

	}
	imprimirFimFila(&fila);
	imprimirInicioFila(&fila);
	
	
			
	removerFilaDinamica(&fila);
	imprimirFila(&fila);

	
	
	return 0;
}
