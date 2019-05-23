#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <time.h>

#include "manipular_arquivo.h"
#include "menu.h"
#include "ranking.h"
#include "perguntas.h"

int main()
{

  //Variáveis de controle:
  int opcao, repeticao = 1;
  char dificuldade;
  char* nomeArquivo;

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
        printf("\n----INICIAR JOGO----\n\n");

        /*

        INSTRUÇÕES

        */
        guia(); //Instruções

        printf("\nDigite a dificuldade: "
               "\nPressione E para faceis, M para intermediarias e H para dificeis\n");

        fflush(stdin);
        dificuldade = getchar();

        if(dificuldade == 'E'){
            nomeArquivo = "perguntasfaceis.txt";
        }else if( dificuldade == 'M'){
            nomeArquivo = "perguntasintermediarias.txt";
        }else if(dificuldade == 'H'){
            nomeArquivo = "perguntasdificeis.txt";
        }

        perguntasToChar(nomeArquivo);

        if(dificuldade == 'E'){
            nomeArquivo = "respostasfaceis.txt";
        }else if( dificuldade == 'M'){
            nomeArquivo = "respostasintermediarias.txt";
        }else if(dificuldade == 'H'){
            nomeArquivo = "respostasdificeis.txt";
        }

        respostasToChar(nomeArquivo);
        //addRanking();

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
        system("cls");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 3:
        printf("\n----CADASTRAR PERGUNTAS----\n\n");
        printf("Deseja cadastrar uma pergunta de qual dificuldade?\n"
               "\nPressione E para faceis, M para intermediarias e H para dificeis\n");

        fflush(stdin);
        dificuldade = getchar();

        if(dificuldade == 'E'){
            nomeArquivo = "perguntasfaceis.txt";
            modificarArquivo(nomeArquivo);
        }else if( dificuldade == 'M'){
            nomeArquivo = "perguntasintermediarias.txt";
            modificarArquivo(nomeArquivo);
        }else if(dificuldade == 'H'){
            nomeArquivo = "perguntasdificeis.txt";
            modificarArquivo(nomeArquivo);
        }else{
            printf("\nIncorreto.");
        }

        printf("\n");
        system("pause");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
      case 4:
        printf("\n----CREDITOS----\n\n");
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
        printf("Inexistente, tente novamente: ");
        menu();
        scanf("%d", &opcao);
        system("cls");
        break;
    }
  }
    return 0;
}
