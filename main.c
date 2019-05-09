#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "manipular_arquivo.h"
#include "menu.h"

int main()
{
  //Muda para o idioma do sistema:
  setlocale(LC_ALL,"Portuguese");

  //Variáveis de controle:
  int opcao, repeticao = 1;
  char opcaoMenu;
  char * nomeArquivo;

  //Intro,aparece o título e após isso a tela limpa
  titulo();
  system("pause");
  system("cls");
  //Chama o menu:
  menu();

  scanf("%d", &opcao);
  system("cls");

  while(repeticao == 1){
    switch(opcao){
      case 1:
        printf("\n----COMEÇAR JOGO----\n\n");
        /*
        Alguma coisa aparece na tela...
        */
        system("pause");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 2:
        printf("\n----VER RANKING----\n\n");

        nomeArquivo = "ranking.txt";
        abrirArquivo(nomeArquivo);
        system("pause");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 3:
        printf("\n----CADASTRAR PERGUNTAS----\n\n");
        printf("Deseja cadastrar uma pergunta de qual dificuldade?"
               "\nPressione E para fáceis, M para intermediárias e H para difíceis\n");

        fflush(stdin);
        opcaoMenu = getchar();

        if(opcaoMenu == 'E'){
            printf("\nEscolheu perguntas fáceis.");
            nomeArquivo = "perguntasfaceis.txt";
            abrirArquivo(nomeArquivo);
        }else if(opcaoMenu == 'M'){
            printf("\nEscolheu perguntas intermediárias.");
            nomeArquivo = "perguntasintermediarias.txt";
            abrirArquivo(nomeArquivo);
        }else if(opcaoMenu == 'H'){
            printf("\nEscolheu perguntas difíceis.");
            nomeArquivo = "perguntasdificeis.txt";
            abrirArquivo(nomeArquivo);
        }else{
            printf("\nOpção incorreta.");
        }
        system("pause");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 4:
        printf("\n----CRÉDITOS----\n\n");
        /*
        Algo aparece...
        */
        system("pause");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 0:
        system("cls");
        printf("\nAdeus!");
        repeticao = 0;
        break;
      default:
        printf("Opção desejada é inexistente, tente novamente: ");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
    }
  }
    return 0;
}
