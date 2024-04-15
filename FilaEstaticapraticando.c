#include <stdio.h>
#include <stdbool.h> 
#define TAMANHO 10

typedef struct{
	int inicio;
	int fim;
	int vetor[TAMANHO];
	int qtde;
}FilaEstatica;

void iniciarFilaEstatica(FilaEstatica *f){
	f->inicio=0;
	f->fim=-1;
	f->qtde=0;
}

bool estaVaziaFilaEstatica(FilaEstatica *f){
	return(f->qtde==0);
}

bool estaCheiaFilaEstatica(FilaEstatica *f){
	return(f->qtde==TAMANHO);
}

int incrementarFilaEstatica(int indice){
	int retorno;
	if(indice == TAMANHO-1){
		retorno = 0;
	}else{
		retorno = indice+1;
	}
	return(retorno);
}

void inserirFilaEstatica(FilaEstatica *f, int x){
	if(!estaCheiaFilaEstatica(f)){
		f->fim=incrementarFilaEstatica(f->fim);
		f->vetor[f->fim]=x;
		f->qtde=f->qtde+1;
	}else{
		printf("Fila esta cheia\n");
	}
}

void imprimirFilaEstatica(FilaEstatica *f){
	if(!estaVaziaFilaEstatica(f)){
		int n=f->inicio;
		while(n!=f->fim){
			printf( "%d ", f->vetor[n]);
			n = incrementarFilaEstatica(n);
		}
	printf(" %d \n", f->vetor[n]);
	}else{
		printf("Fila esta vazia\n");
	}
}

void removerFilaEstatica(FilaEstatica *f){
	if(!estaVaziaFilaEstatica(f)){
		f->inicio =incrementarFilaEstatica(f->inicio);
		f->qtde--;
	}else{
		printf("Fila esta vazia\n");
	}
}

int primeiroElementoFilaEstatica(FilaEstatica *f){
		if(!estaVaziaFilaEstatica(f)){
		printf("%d\n",f->vetor[f->inicio]);
		}else{
			printf("Fila esta vazia\n");
	}
}

int ultimoElementoFilaEstatica(FilaEstatica *f){
		if(!estaVaziaFilaEstatica(f)){
			return(f->vetor[f->fim]);
		}else{
			printf("Fila esta vazia\n");
	}
}

void tamanhoFilaEstatica(FilaEstatica *f){
	if(!estaVaziaFilaEstatica(f)){
			printf("%d\n", f->qtde);
		}else{
			printf("Fila esta vazia\n");
	}
}
	
int main(int argc, char* argv[]){
	 FilaEstatica fila;
  iniciarFilaEstatica(&fila);
  if(estaVaziaFilaEstatica(&fila)) {
    printf("Fila vazia!\n");
  } else {
    printf("Ha elementos na fila\n");
  }

  if(estaCheiaFilaEstatica(&fila)) {
    printf("Fila cheia!\n");
  } else {
    printf("Nao esta cheia!\n");
  }
  tamanhoFilaEstatica(&fila);
  

  int inserir[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int i;
  for(i = 0; i < 11; i++) {
    inserirFilaEstatica(&fila, inserir[i]);
    imprimirFilaEstatica(&fila);
  }
  primeiroElementoFilaEstatica(&fila);
  tamanhoFilaEstatica(&fila);

  for(i = 0; i < 11; i++) {
    removerFilaEstatica(&fila);
    imprimirFilaEstatica(&fila);
  }
  return 0;
}

