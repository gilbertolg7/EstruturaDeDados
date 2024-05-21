#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Gilberto Lima Goncalves  RA 2372541 fiz sozinho por isso demorei mais, desculpa prof 

typedef struct NoArvore* PtrNoArvore;
typedef struct NoArvore {
  int chave; // valor armazenado
//  char* chave;
	int internos;
  PtrNoArvore direita;
  PtrNoArvore esquerda;
} NoArvore;

// ---------------------------------------
// ---------------------------------------

// destruicao
// remover 
// pesquisar
// maximo (int) * | rec | iterativo (while)
// minimo (int) * | rec | iterativo (while)
// tamanho (int) *
// percurso (em ordem, pre ordem, pos Ordem)
// ---------------------------------------
// ---------------------------------------
void iniciaArvoreBinaria(PtrNoArvore *r) {
  (*r) = NULL;
}

bool estaVaziaArvoreBinaria(PtrNoArvore *r) {
  return((*r) == NULL);
}
// ---------------------------------------
// ---------------------------------------
bool inserirArvoreBinaria(PtrNoArvore *no, int valor) {
//bool inserirArvoreBinaria(PtrNoArvore *no, char* valor) {
  // clausulas base (true, false)
  // 1. NULL (ponto de inserção)
  // Toda vez que achar um NULL ? onde vamos inserir o novo elemento:
  if((*no) == NULL) {
    (*no) = malloc(sizeof(NoArvore));
    (*no)->chave = valor;
//    strcpy((*no)->chave, valor);
    (*no)->direita = NULL;
    (*no)->esquerda = NULL;
    return (true);
  }
  // 2. no que j? possui o valor que eu quero inserir
  if((*no)->chave == valor) return (false); // warning
//  if(strcmp((*no)->chave, valor)==0) return (false); // warning

  // clausula recursiva
  if(valor > (*no)->chave) {
//  if(strcmp(valor,(*no)->chave)==1){
    return(inserirArvoreBinaria(&(*no)->direita, valor));
  } else{
    return(inserirArvoreBinaria(&(*no)->esquerda, valor));
  }
}
int altura(PtrNoArvore *no){
	if((*no)== NULL){
		return 0;
	}
	else{
		int altura_esq = altura(&(*no)->esquerda);
		int altura_dir = altura(&(*no)->direita);
		if(altura_esq > altura_dir){
			return (altura_esq +1);
		}else{
			return (altura_dir +1);
		}
			}	
}

// ---------------------------------------
// ---------------------------------------

// print, dir, esq
//PREORDEM
// 1 Printa
// 2 PREORDEM(Esq)
// 3 PREORDEM(Dir)
void PreOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return; //clausula base
  printf("%d ", (*no)->chave);
  PreOrdemArvoreBinaria(&(*no)->esquerda);
  PreOrdemArvoreBinaria(&(*no)->direita);
}

void PreOrdemPrincipal(PtrNoArvore *no) {
  printf("PreOrdem = { ");
  PreOrdemArvoreBinaria(&(*no));
  printf("}\n");
}

//EMORDEM
// 1 EMORDEM(Esq)
// 2 Printa
// 3 EMORDEM(Dir)
void EmOrdemArvoreBinaria(PtrNoArvore *no) {
  if((*no) == NULL) return; //clausula base
  EmOrdemArvoreBinaria(&(*no)->esquerda);
  printf("%d ", (*no)->chave);
  EmOrdemArvoreBinaria(&(*no)->direita);
}

void EmOrdemPrincipal(PtrNoArvore *no) {
  printf("EmOrdem = { ");
  EmOrdemArvoreBinaria(&(*no));
  printf("}\n");
}

//POSORDEM
//1. POSORDEM(Esq)
//2. POSORDEM(Dir)
//3. Printa

// ---------------------------------------
// ---------------------------------------

int pesquisaArvoreBinaria(PtrNoArvore *no, int valor) {
  // clausulas base - recursao
  // se o elemento nao existir -> false [ ptr == NULL] [X]
  if((*no) == NULL) return 0;
  // se existir o elemento -> true [X]
  if((*no)->chave == valor) return (altura(&(*no)));
  // recursiva
  if(valor > (*no)->chave) {
    return(pesquisaArvoreBinaria(&(*no)->direita, valor));
  } else { // <
    return(pesquisaArvoreBinaria(&(*no)->esquerda, valor));
  }
}
// ---------------------------------------
// ---------------------------------------

PtrNoArvore pegarMaiorElemento(PtrNoArvore *no) {
  // vai ter que andar p direita, até que ...
  // o ultimo n? aponta para nulo (dir)
  while ((*no)->direita != NULL) {
    (*no) = (*no)->direita;
  }
  // terminou o while, (*no) cont?m o maior elemento
  // esse cara ? quem a gente precisa retornar
  PtrNoArvore ret = (*no);
  (*no) = (*no)->esquerda; // NULL ou não NULL
  return(ret);
}

// ---------------------------------------
// ---------------------------------------

bool removerArvoreBinaria(PtrNoArvore *no, int valor) {
  if((*no) == NULL) return false;
  if((*no)->chave == valor) {
    PtrNoArvore rm = (*no);
    // Aqui dentro tem um tratamento maior
    // 4 casos de remo??o
    //  c1: n? que possui filho da direita, mas n?o tem o da esquerda (sub-arvore da esquerda ? nula)
    if((*no)->esquerda == NULL && (*no)->direita != NULL) {
      printf("Debug: caso 1 - sub-arvore esquerda nula\n");
      (*no) = (*no)->direita;
    }
    // c2: n? que ? folha (n?o tem subarvore direita, nem esquerda)
    else if((*no)->direita == NULL && (*no)->esquerda == NULL) {
      printf("Debug: caso 2 - folha\n");
      (*no) = NULL;
    }
    // c3: n? que possui filho da esquerda, mas n?o tem o da direita (sub-arvore direita ? nula)
    else if((*no)->esquerda != NULL && (*no)->direita == NULL) {
      printf("Debug: caso 3 - sub-arvore direita nula\n");
      (*no) = (*no)->esquerda;
    }
    // **c4**: n? que tem ambas as sub-arvores
    else {  // op1: maior da subarvore esquerda
      printf("Debug: caso 4 - existem ambas sub-arvores\n");
      rm = pegarMaiorElemento(&(*no)->esquerda);
      // AQUI (no) = no->esq
      (*no)->chave = rm->chave;
    }
    free(rm);
    return true;
  }
  // recursiva
  if(valor > (*no)->chave) {
    return(removerArvoreBinaria(&(*no)->direita, valor));
  } else { // <
    return(removerArvoreBinaria(&(*no)->esquerda, valor));
  }
}
//     op2: menor da subarvore direita
//          f_aux = menor da subarvore dir (ref)
//                 salvar em um ptr (return)
//                 no = no->dir
// ---------------------------------------
// ---------------------------------------

int main(int argc, const char * argv[]) {
  // N?o tem uma estrutura chamada arvore, raiz (ptr No arvore)
  PtrNoArvore raiz;
  iniciaArvoreBinaria(&raiz); //raiz = NULL;
  if(estaVaziaArvoreBinaria(&raiz)) {
    printf("Arvore vazia!\n");
  }
  inserirArvoreBinaria(&raiz, 5);
  inserirArvoreBinaria(&raiz, 4);
  inserirArvoreBinaria(&raiz, 7);
  inserirArvoreBinaria(&raiz, 3);
  inserirArvoreBinaria(&raiz, 2);
  inserirArvoreBinaria(&raiz, 6);
  inserirArvoreBinaria(&raiz, 8);
  inserirArvoreBinaria(&raiz, 9);
  PreOrdemPrincipal(&raiz);
  EmOrdemPrincipal(&raiz);
  
  // dividi a funcao Árvore Binária de Busca - int profundidade(PtrNoArvore *no, int valor) em duas mas poderia ser feita juntando as duas funcoes de pesquisa e altura//
  
  printf(" %d\n",altura(&raiz)); // funcao para calcular a altura da arvore por inteiro//
  printf(" %d\n",pesquisaArvoreBinaria(&raiz, 5));// funcao para pesquisar e retornar a altura do elemento desejado //
  printf("Profundidade do elemento %d\n",(altura(&raiz)+1)- pesquisaArvoreBinaria(&raiz, 5)); // conta para achar a profundidade, altura +1 menos a altura do elementos desejado//
   

  int query[] = {10, 24, 42, 9, 2, 7, 8};
  
  int i;
  for(i = 0; i < 7; i++) {
    printf("Valor %d ", query[i]);
    if(pesquisaArvoreBinaria(&raiz, query[i])) {
      printf("... elemento foi encontrado\n");
    } else {
      printf("... elemento n?o encontrado\n");
    }
  }
  

  // 2 - caso 2: folha
//  removerArvoreBinaria(&raiz, 2);
  // 5, 4, 3, 7, 6, 8, 9
//  PreOrdemPrincipal(&raiz);
  // 1 (sub-arvore esq nula, mas tem esq)
//  removerArvoreBinaria(&raiz, 8);
  // 5, 4, 3, 7, 6, 9
//  PreOrdemPrincipal(&raiz);
  // 3 (sub-arvore dir nula, mas tem esq)
//  removerArvoreBinaria(&raiz, 4);
//  PreOrdemPrincipal(&raiz);
  // 5, 3, 7, 6, 9
  // 4 (tem ambas as subarvores)
  removerArvoreBinaria(&raiz, 5);
  PreOrdemPrincipal(&raiz);
  //4, 3, 2, 7, 6, 8, 9
  //3, 7, 6, 9
  // nao tem o elemento
//  removerArvoreBinaria(&raiz, 50);
//  PreOrdemPrincipal(&raiz);

  return 0;
}
