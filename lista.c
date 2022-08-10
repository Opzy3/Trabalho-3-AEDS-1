//Arquivo "lista.c" com os prototipos da funções

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"    //biblioteca propia criada

// definição do struct elemento
struct elemento{
  int number;
  struct elemento *prox;
};

// typedef do struct elemento
typedef struct elemento Elemento;


//Função para criar a lista
Lista* criar(){
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(li != NULL){
    *li = NULL;
  } 

  return li;
}


//Função para liberar a lista
void liberar(Lista *li){
  if(li == NULL){    
    return;
  }

  // libera todos os nós da lista que foram alocados
  Elemento *no;
  while(*li != NULL){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  return;  
}


//Função para criar um elemento
Elemento* criar_elemento(){
  Elemento *no = (Elemento*) malloc(sizeof(Elemento));  

  return no;
}


//Função para inserir um elemento novo nas listas
int inserir(Lista *li, int number){
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  Elemento *aux;
  aux = criar_elemento();


  // atribui valores ao elemento novo
  aux->number = number;
  
  if( (*li) == NULL ){
    *li = aux;

  }else{

    // senão percorre a lista até o fim e insere no final
    Elemento *fim;
    fim = *li;

    while(fim->prox != NULL){
      fim = fim->prox;
    }
    fim->prox = aux;
  }

  return 1;
}

//Função para somar as 2 listas
void somar(Lista *l1, Lista *l2){
	int tamanho = 12;
	int soma[13];
	int vaium = 0;
	Elemento *contador1, *contador2;
	contador1 = *l1;
  contador2 = *l2;
  
  // utilizamos um for para rodar os 12 numeros existentes no arquivo
	for( int i = 0;i<tamanho; i++){
		
		contador1 = *l1;
		contador2 = *l2;
		// usamos esse for para conseguir percorrer as listas, de forma a apontar para o prox elemento
		for(int j = 0; j < tamanho-i-1; j++){
			contador1 = contador1->prox;
			contador2 = contador2->prox;
    }
			
		// Aqui fazemos a soma das 2 listas, e armazenamos num vetor cada algarismo obtido, usamos a logica do vai 1, comum em operações de soma
	 	soma[i] = contador1->number + contador2->number+vaium;
	 	vaium = soma[i]/10;
    soma[i] = soma[i]%10;
	}
  
  printf("\n\n\n");
  system("clear");
  printf("======================================");
  printf("\nO resultado da soma é de: ");


  // for usado para imprimir o resultado na tela 
  for(int j = 11; j >= 0;j--){
    
     printf("%d", soma[j]);

  }
  printf("\n======================================");
}