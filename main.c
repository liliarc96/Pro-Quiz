/*
                                       -----------------------------------
                                            Q U I Z by Lília & Renata
                                       -----------------------------------

   --------------------------------------------------------------------------------------------------------------
   HEADERS:

       display.h       ==> Header com todos os textos do jogo
   manipular_arquivo.h ==> Funções relacionadas a manipulação de arquivos (abrir, fechar e modificar)
       ranking.h       ==> Guarda as pontuações e os nomes dos jogadores
   --------------------------------------------------------------------------------------------------------------

   --------------------------------------------------------------------------------------------------------------
   FUNÇÕES GLOBAIS:

    ->EM DISPLAY.H:
        creditos(): void ==> Créditos do jogo
        guia(): void ==> Apresenta o guia do jogo
        menu(): void ==> Estrutura do menu com suas opções
        titulo(): void ==> Nome do quiz

    ->EM MANIPULAR_ARQUIVO.H:
        abrirRanking(): int ==> Mostra o ranking salvo em pontuacao.txt
        modificarArquivo(char*nArquivo): int ==> Modifica o arquivo escolhido

    ->EM PERGUNTAS.H:
        geradorAleatorio(): int ==> Gera um valor aleatório e o retorna

    ->EM RANKING.H:
        mostrarRanking(): int ==> Guarda o ranking salvo em pontuacao.txt
   --------------------------------------------------------------------------------------------------------------

   --------------------------------------------------------------------------------------------------------------
   VARIÁVEIS:

        _| NUM ==> É usada em várias outras variáveis para fazer comparações, o valor é 10 |_

    ->DE CONTROLE:
        opcao: int ==> Opção do menu
        repeticao: int ==> default = 1; Continua a exibir o menu após sair da opção escolhida
        randomico: unsigned int ==> Número  que recebe valor da função geradorAleatorio(): int
    |NUM| arr: bool ==> Inicia com NUM zeros, o número escolhido modifica para 1 para não ser escolhido novamente

    ->DE PERGUNTAS & RESPOSTAS:
    |NUM| perguntas: char ==> Perguntas retiradas do arquivo 'perguntas(faceis/intermediarias/dificeis).txt'
    |NUM| respostas: char ==> Respostas retiradas do arquivo 'respostas(faceis/intermediarias/dificeis).txt'
    |NUM| corretasFaceis: char ==> As opções corretas das perguntas fáceis, respectivamente
    |NUM| corretasIntermediarias: char ==> As opções corretas das perguntas intermediárias, respectivamente
    |NUM| corretasDificeis: char ==> As opções corretas das perguntas difíceis, respectivamente
    |NUM| resta: int ==> Resta(m) ... pergunta(s) para o fim do nível

    ->DE JOGADOR:
        nomeJogador: char ==> Nome do jogador
        pontuacao: int ==> Pontuação do jogador
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
    INICIALIZAÇÃO DE VARIÁVEIS
    */
    int opcao, repeticao = 1, i;
    //MATRIZ DAS PERGUNTAS:
    char perguntas[NUM][1000];
    //MATRIZ DAS RESPOSTAS:
    char respostas[NUM][1000];
    //COMPARAÇÃO DAS RESPOSTAS CERTAS:
    char corretasFaceis[NUM] = {'B','B','C','C','B','B','B','B','D','D'};
    char corretasIntermediarias[NUM] = {'A','D','B','B','B','C','A','D','C','A'};
    char corretasDificeis[NUM] = {'A','B','A','C','A','C','D','B','A','D'};
    //VARIÁVEL QUE RECEBE UM NÚMERO ALEATÓRIO E ALINHA PERGUNTAS & RESPOSTAS:
    unsigned int randomico;
    //CHECA SE O NÚMERO JÁ FOI ESCOLHIDO
    bool arr[NUM] = {0};
    //DADOS DO JOGADOR:
    char * nomeJogador[100];
    int pontuacao = 0;
    int acertos;
    int resta = NUM;
    char alternativa;
    //QUANTIDADE DE PULOS RESTANTES:
    int pular = 5;

    //VARIÁVEL PARA TESTE!!!!!!
    int questoes = 1;


    /*
    INICIALIZANDO A DIFICULDADE FÁCIL
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
                scanf("%s", nomeJogador);
                system("cls");
                guia();
                system("pause");
                system("cls");
                /*
                COMEÇANDO O JOGO
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
                //MOSTRA A TELA COM A PONTUAÇÃO OBTIDA NO NÍVEL E SE TEVE GAME OVER OU NÃO
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
                CRÉDITOS
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
