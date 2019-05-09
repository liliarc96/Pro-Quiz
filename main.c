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
  char dificuldade;
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

        abrirRanking();
        printf("\n");

        system("pause");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 3:
        printf("\n----CADASTRAR PERGUNTAS----\n\n");
        printf("Deseja cadastrar uma pergunta de qual dificuldade?\n"
               "\nPressione E para fáceis, M para intermediárias e H para difíceis\n");

        fflush(stdin);
        dificuldade = getchar();

        if(dificuldade == 'E'){
            printf("\nEscolheu perguntas fáceis.\n\n");
            nomeArquivo = "perguntasfaceis.txt";
            abrirArquivo(nomeArquivo);
        }else if(dificuldade == 'M'){
            printf("\nEscolheu perguntas intermediárias.\n\n");
            nomeArquivo = "perguntasintermediarias.txt";
            abrirArquivo(nomeArquivo);
        }else if(dificuldade == 'H'){
            printf("\nEscolheu perguntas difíceis.\n\n");
            nomeArquivo = "perguntasdificeis.txt";
            abrirArquivo(nomeArquivo);
        }else{
            printf("\nOpção incorreta.");
        }

        printf("\n");
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
