#include <stdio.h>
//Headers:
#include "ranking.h"
#include "menu.h"

int main(void) {
  //Variáveis de controle:
  int opcao, repeticao;
  
  //Chama o menu:
  menu();
  
  scanf("%d", &opcao);
  while(repeticao == 1){
    switch(opcao){
      case 1:
        printf("\n----COMEÇAR JOGO----\n\nDigite um número: ");
        menu();
        scanf("%d", &opcao);
        break;
      case 2:
        printf("\n----VER RANKING----\n\nDigite um número: ");
        menu();
        scanf("%d", &opcao);
        break;
      case 3:
        printf("\n----CADASTRAR PERGUNTAS----\n\n");
        menu();
        scanf("%d", &opcao);
        break;
      case 4:
        printf("\n----CRÉDITOS----\n\n");
        menu();
        scanf("%d", &opcao);
        break;
      case 0:
        printf("\nAdeus!");
        repeticao = 0;
        break;
      default:
        printf("Opção desejada é inexistente, tente novamente: ");
        menu();
        scanf("%d", &opcao);
        break;
    }
    
    return 0;
  } 
