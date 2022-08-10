#include <stdio.h>
#include <stdlib.h>
#include "lista.h" //biblioteca .h com as assinaturas
#include <unistd.h>


int main(void) {
  system("clear");
  // variavel tamanho é usada para definir quantos algarismos teremos no nosso numero grande
  int tamanho = 12,num;
  char opcao;
	Lista *l1;
	Lista *l2;
	
  // arquivo usado para entrada dos numeros grandes
	FILE *arq;
  
	l1 = criar();
	l2 = criar();


  //menu inicial
  printf("================== Soma de Números Grandes ==================\n\n");
  printf("Olá Usuário, seja bem vindo!\n");
  printf("Esse programa mostra a soma de dois números contidos no arquivo ao lado ('entrada.txt')\n\n");
  printf("[A] para mostrar o resultado");
  printf("\n[S] para sair do programa\n");


	
  scanf(" %c", &opcao);
  while(opcao != 'a' && opcao != 's'){
    printf("Digite um valor válido! \n");
    scanf(" %c", &opcao);

  }
	// switch com as opcoes do menu
  switch (opcao){
    case 'a':    
      arq = fopen("entrada.txt","r+"); // abertura do arquivo para entrada de dados
      for(int i = 0;i<tamanho;i++){
        fscanf(arq, " %d" ,&num);
        inserir(l1,num);

      }
      for(int i = 0;i<tamanho;i++){
        fscanf(arq, " %d" ,&num);
        inserir(l2,num);

      }
      fclose(arq); // fechando o arquivo

      // usamos a funcao somar para somar os 2 numeros grandes
      somar(l1,l2);
      break;
		
		case 's':
    printf("Saindo...");
		break;
	}
  
	liberar(l1);
	liberar(l2);
  return 0;
}



