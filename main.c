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
  char * perguntas;
  char * respostas;


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
        guia();

        printf("\nDigite a dificuldade: "
               "\nPressione E para faceis, M para intermediarias e H para dificeis\n");

        fflush(stdin);
        dificuldade = getchar();

        if(dificuldade == 'E'){
            perguntas = "perguntasfaceis.txt";
        }else if( dificuldade == 'M'){
            perguntas = "perguntasintermediarias.txt";
        }else if(dificuldade == 'H'){
            perguntas = "perguntasdificeis.txt";
        }


        //perguntasToChar(nomeArquivo);

        if(dificuldade == 'E'){
            respostas = "respostasfaceis.txt";
        }else if( dificuldade == 'M'){
            respostas = "respostasintermediarias.txt";
        }else if(dificuldade == 'H'){
            respostas = "respostasdificeis.txt";
        }
        system("cls");

        startquiz(perguntas, respostas);

        //respostasToChar(nomeArquivo);
        //addRanking();
        printf("\n\nTeste\n\n");
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
            perguntas = "perguntasfaceis.txt";
            modificarArquivo(perguntas);
        }else if( dificuldade == 'M'){
            perguntas = "perguntasintermediarias.txt";
            modificarArquivo(perguntas);
        }else if(dificuldade == 'H'){
            perguntas = "perguntasdificeis.txt";
            modificarArquivo(perguntas);
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
