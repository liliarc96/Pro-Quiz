/*
                                       -----------------------------------
                                            Q U I Z by L�lia & Renata
                                       -----------------------------------

   --------------------------------------------------------------------------------------------------------------
   HEADERS:

       display.h       ==> Header com todos os textos do jogo
   manipular_arquivo.h ==> Fun��es relacionadas a manipula��o de arquivos (abrir, fechar e modificar)
       ranking.h       ==> Guarda as pontua��es e os nomes dos jogadores
   --------------------------------------------------------------------------------------------------------------

   --------------------------------------------------------------------------------------------------------------
   FUN��ES GLOBAIS:

    ->EM DISPLAY.H:
        creditos(): void ==> Cr�ditos do jogo
        guia(): void ==> Apresenta o guia do jogo
        menu(): void ==> Estrutura do menu com suas op��es
        titulo(): void ==> Nome do quiz

    ->EM MANIPULAR_ARQUIVO.H:
        abrirRanking(): int ==> Mostra o ranking salvo em pontuacao.txt
        modificarArquivo(char*nArquivo): int ==> Modifica o arquivo escolhido

    ->EM PERGUNTAS.H:
        geradorAleatorio(): int ==> Gera um valor aleat�rio e o retorna

    ->EM RANKING.H:
        mostrarRanking(): int ==> Guarda o ranking salvo em pontuacao.txt
   --------------------------------------------------------------------------------------------------------------

   --------------------------------------------------------------------------------------------------------------
   VARI�VEIS:

        _| NUM ==> � usada em v�rias outras vari�veis para fazer compara��es, o valor � 10 |_

    ->DE CONTROLE:
        opcao: int ==> Op��o do menu
        repeticao: int ==> default = 1; Continua a exibir o menu ap�s sair da op��o escolhida
        randomico: unsigned int ==> N�mero  que recebe valor da fun��o geradorAleatorio(): int
    |NUM| arr: bool ==> Inicia com NUM zeros, o n�mero escolhido modifica para 1 para n�o ser escolhido novamente

    ->DE PERGUNTAS & RESPOSTAS:
    |NUM| perguntas: char ==> Perguntas retiradas do arquivo 'perguntas(faceis/intermediarias/dificeis).txt'
    |NUM| respostas: char ==> Respostas retiradas do arquivo 'respostas(faceis/intermediarias/dificeis).txt'
    |NUM| corretasFaceis: char ==> As op��es corretas das perguntas f�ceis, respectivamente
    |NUM| corretasIntermediarias: char ==> As op��es corretas das perguntas intermedi�rias, respectivamente
    |NUM| corretasDificeis: char ==> As op��es corretas das perguntas dif�ceis, respectivamente
    |NUM| resta: int ==> Resta(m) ... pergunta(s) para o fim do n�vel

    ->DE JOGADOR:
        nomeJogador: char ==> Nome do jogador
        pontuacao: int ==> Pontua��o do jogador
        pular: int ==> Quantidade de pulos que o jogador ainda tem
   --------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NUM 10

#include "manipular_arquivo.h"
#include "display.h"
#include "ranking.h"
#include "perguntas.h"

int main()
{
    /*
    INICIALIZA��O DE VARI�VEIS
    */
    int opcao, repeticao = 1, i;
    //MATRIZ DAS PERGUNTAS:
    char perguntas[NUM][1000];
    //MATRIZ DAS RESPOSTAS:
    char respostas[NUM][1000];
    //COMPARA��O DAS RESPOSTAS CERTAS:
    char corretasFaceis[NUM] = {'B','B','C','C','B','B','B','B','D','D'};
    char corretasIntermediarias[NUM] = {'A','D','B','B','B','C','A','D','C','A'};
    char corretasDificeis[NUM] = {'A','B','A','C','A','C','D','B','A','D'};
    //VARI�VEL QUE RECEBE UM N�MERO ALEAT�RIO E ALINHA PERGUNTAS & RESPOSTAS:
    unsigned int randomico;
    //CHECA SE O N�MERO J� FOI ESCOLHIDO
    bool arr[NUM] = {0};
    //DADOS DO JOGADOR:
    char * nomeJogador[100];
    int pontuacao = 0;
    int acertos;
    int resta = NUM;
    char alternativa;
    //QUANTIDADE DE PULOS RESTANTES:
    int pular = 5;

    //VARI�VEL PARA TESTE!!!!!!
    int questoes = 1;


    /*
    INICIALIZANDO A DIFICULDADE F�CIL
    */
    FILE * arquivo;

    arquivo = fopen("perguntasfaceis.txt", "r");
    for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
    fclose(arquivo);

    arquivo = fopen("respostasfaceis.txt", "r");
    for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
    fclose(arquivo);

    titulo();
    system("pause");
    system("cls");

    /*
    MENU
    */

    menu();

    scanf("%d", &opcao);
    system("cls");

    while(repeticao == 1){
        switch(opcao){
            case 1:
                printf("Insira o nome do jogador:\n"
                       "> ");
                scanf("%s", &nomeJogador);
                system("cls");
                guia();
                system("pause");
                system("cls");
                /*
                COME�ANDO O JOGO
                */
                for(acertos = 0;resta > 0;){
                    randomico = geradorAleatorio();
                    if(!arr[randomico]){
                        printf("PERGUNTA %d:\n", questoes);
                        printf("%s\n", perguntas[randomico]);
                        printf("%s\n\n", respostas[randomico]);
                        printf("Pressione a A, B, C ou D para escolher a alternativa, P para pular!\n"
                               "> ");
                        fflush(stdin);
                        alternativa = getchar();
                        if(alternativa == corretasFaceis[randomico]){
                            acertos++;
                            printf("ACERTOU!\n");
                        }else if((alternativa == 'P') && (pular > 0)){
                            pular--;
                            printf("PULOU! %s tem %d pulos restantes!\n", nomeJogador, pular);
                        }else{
                            printf("ERROU!\n");
                        }
                        arr[randomico] = 1;
                        resta--;
                        questoes++;
                        system("pause");
                        system("cls");
                    }else{
                        arr[randomico] = 1;
                    }
                }
                //MOSTRA A TELA COM A PONTUA��O OBTIDA NO N�VEL E SE TEVE GAME OVER OU N�O
                menu();
                scanf("%d", &opcao);
                system("cls");
                break;
              case 2:
                abrirRanking();
                printf("\n");

                system("pause");
                system("cls");
                menu();
                scanf("%d", &opcao);
                system("cls");
                break;
              case 3:
                menu();
                scanf("%d", &opcao);
                system("cls");
                break;
              case 4:
                /*
                CR�DITOS
                */
                creditos();
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
                break;
    }
  }
    return 0;
}
