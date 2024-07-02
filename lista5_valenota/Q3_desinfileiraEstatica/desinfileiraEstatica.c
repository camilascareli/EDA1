#include <stdlib.h>

typedef struct fila{
  int *dados;
  int N, p, u;
} fila;

//fila *criar (int N){
//  fila *p = malloc (sizeof *p);
//  p->dados =malloc(N * sizeof p->dados);
//  p->p = p->u = 0;
//  return p;
//}                        //Até aqui, estrutura necessária pra criar a struct fila

int desenfileira (fila *f, int *y){
 if (f->p == f->u){ // Verifica se a fila está vazia
  return 0;
 }
 
 f->dados[f->p++];      //declarando o próximo elemento da fila como o primeiro
  *y = f->dados[f->p-1];
  

//  if(f->p == f->N){         //parte que faz a fila ser circular  
//    f->p =0;
  
    //f->dados[f->N] *= 2;  //ENUNCIADO TÁ ERRADO, NÃO TEM NADA DE INSERÇÃO NESSA QUESTÃO
    //f->dados = realloc (f, f->N * sizeof(int));
 // } 

  if(*y == f->dados[f->p-1]){
    return 1;
  }
    
  return 0;
  
}
