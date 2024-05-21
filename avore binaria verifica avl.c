#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// ---------------------------------------
// Gilberto Lima Goncalves  RA 2372541 fiz sozinho por isso demorei mais, desculpa prof 
// ---------------------------------------
// PtrNoArvore = NoArvore* -> PtrNoArvore
typedef struct NoArvore* PtrNoArvore;
// NoArvore
typedef struct NoArvore {
  int chave; // valor armazenado
//  char* chave;
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
  // 1. NULL (ponto de inser��o)
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

bool pesquisaArvoreBinaria(PtrNoArvore *no, int valor) {
  // clausulas base - recursao
  // se o elemento nao existir -> false [ ptr == NULL] [X]
  if((*no) == NULL) return false;
  // se existir o elemento -> true [X]
  if((*no)->chave == valor) return (true);
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
  // vai ter que andar p direita, at� que ...
  // o ultimo n? aponta para nulo (dir)
  while ((*no)->direita != NULL) {
    (*no) = (*no)->direita;
  }
  // terminou o while, (*no) cont?m o maior elemento
  // esse cara ? quem a gente precisa retornar
  PtrNoArvore ret = (*no);
  (*no) = (*no)->esquerda; // NULL ou n�o NULL
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
int altura(PtrNoArvore *no) {
    if ((*no) == NULL)
        return 0;
    return (altura(&(*no)->esquerda), altura(&(*no)->direita)) + 1;
}

bool AVL(PtrNoArvore *no) {
    if ((*no) == NULL)
        return true;

    int altura_esq = altura(&(*no)->esquerda);
    int altura_dir = altura(&(*no)->direita);

    if (abs(altura_esq - altura_dir) <= 1 && AVL(&(*no)->esquerda) && AVL(&(*no)->esquerda))
        return true;
	// utilizei o abs para quando der -1 na conta nao dar errado
    return false;
}

int main(int argc, const char * argv[]) {
  // N?o tem uma estrutura chamada arvore, raiz (ptr No arvore)
  PtrNoArvore raiz;
  iniciaArvoreBinaria(&raiz); //raiz = NULL;
  if(estaVaziaArvoreBinaria(&raiz)) {
    printf("Arvore vazia!\n");
  }
  inserirArvoreBinaria(&raiz, 10);
  inserirArvoreBinaria(&raiz, 5);
  inserirArvoreBinaria(&raiz, 20);
  inserirArvoreBinaria(&raiz, 3);
  inserirArvoreBinaria(&raiz, 8);
  inserirArvoreBinaria(&raiz, 25);
  inserirArvoreBinaria(&raiz, 30);
  inserirArvoreBinaria(&raiz, 40);
 
	//criei 2 funcoes, uma que determina a altura para sabermos e compararmos se a arvore e avl ou nao
	// e outra funcao que compara e retorna se a altura entre a esquerda e a direita nao for superioa a 1 retorna true  se nao false
  
  PreOrdemPrincipal(&raiz);
  EmOrdemPrincipal(&raiz);
	if(AVL(&raiz) == 1){
		printf("Sim a arvore apresentada e AVL\n");
	}
	if(AVL(&raiz) == 0){
		printf("A arvore apresentada nao e AVL\n");
	}

  int query[] = {10, 24, 42, 9, 2, 7, 8};
  //  
  int i;//            X, X, X, V, V, V, V
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
