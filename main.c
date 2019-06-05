/*
                                               -----------------------------------
                                                    Q U I Z by Lília & Renata
                                               -----------------------------------

   --------------------------------------------------------------------------------------------------------------------
   HEADERS & SOURCES:

            display.c & display.h            ==> Todos os textos que aparecem no jogo
   manipular_arquivo.c & manipular_arquivo.h ==> Tudo relacionado a manipulação de arquivos (abrir, fechar e modificar)
               etc.c & etc.h                 ==> Funções que auxiliam no andamento do jogo
   --------------------------------------------------------------------------------------------------------------------

   --------------------------------------------------------------------------------------------------------------------
   FUNÇÕES GLOBAIS:

    ->EM DISPLAY:
        creditos(): void ==> Créditos do jogo
        guia(): void ==> Apresenta o guia do jogo
        menu(): void ==> Estrutura do menu com suas opções
        titulo(): void ==> Nome do quiz

    ->EM MANIPULAR_ARQUIVO:
        addPontuacao(char*jogador, int pontuacao): int ==> Adiciona uma nova entrada em pontuacao.txt
        modificarTxt(char*nArquivo): int ==> Modifica o .txt das perguntas e respostas
        mostrarRanking(): int ==> Mostra o ranking salvo em pontuacao.txt

    ->EM ETC:
        geradorAleatorio(): int ==> Gera um valor aleatório e o retorna
   --------------------------------------------------------------------------------------------------------------------

   --------------------------------------------------------------------------------------------------------------------
   VARIÁVEIS:

        _| NUM ==> É usada em várias outras variáveis para fazer comparações, o valor original é 10 |_

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
   --------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM 10

#include "manipular_arquivo.h"
#include "display.h"
#include "etc.h"

int main(){
    int opcao, repeticao = 1, i;

    char perguntas[NUM][1000];
    char respostas[NUM][1000];
    int resta = NUM;
    char alternativa;

    char corretasFaceis[NUM] = {'B','B','C','C','B','B','B','B','D','D'};
    char corretasIntermediarias[NUM] = {'C','A','B','A','A','A','C','B','C','D'};
    char corretasDificeis[NUM] = {'B','B','B','D','B','A','B','B','C','A'};

    int randomico;
    bool arr[NUM] = {0};

    char nomeJogador[200];
    int pontuacao;
    int acertos;
    int erros;

    int pular = 5;
    int questoes = 1;


    FILE * arquivo;

    arquivo = fopen("perguntasfaceis.txt", "r");
    for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
    fclose(arquivo);

    arquivo = fopen("respostasfaceis.txt", "r");
    for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
    fclose(arquivo);

    system("color 0A");
    titulo();
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

                for(acertos = 0;resta > 0;){
                    randomico = geradorAleatorio();
                    if(!arr[randomico]){
                        printf("\nPERGUNTA %d:\n", questoes);
                        printf("> "
                               "%s\n", perguntas[randomico]);
                        printf("%s\n\n", respostas[randomico]);
                        printf("Pressione a A, B, C ou D para escolher a alternativa, P para pular!\n"
                               "> ");
                        fflush(stdin);
                        alternativa = getchar();
                        if(alternativa == corretasFaceis[randomico]){
                            acertos++;
                            printf("\nACERTOU!\n\n");
                        }else if((alternativa == 'P') && (pular > 0)){
                            pular--;
                            printf("PULOU! %s tem %d pulos restantes!\n\n", nomeJogador, pular);
                        }else{
                            printf("ERROU!\n\n");
                        }
                        arr[randomico] = 1;
                        resta--;
                        questoes++;
                        system("pause");
                        system("cls");
                    }
                }
                system("cls");

                pontuacao = acertos * 10;
                printf("%s, teve %d acertos nesse nivel e obteve uma pontuacao de %d!", nomeJogador, acertos, pontuacao);
                if(acertos < 5){
                    gameOver();
                    system("pause");
                    system("cls");
                }
				else{
                  printf("\n\nParabains, voce completou o nivel FACIL!\n\n");

                  system("pause");
                  system("cls");
                  arquivo = fopen("perguntasintermediarias.txt", "r");
                  for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
                  fclose(arquivo);

                  arquivo = fopen("respostasintermediarias.txt", "r");
                  for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
                  fclose(arquivo);

                  for(i = 0;i < NUM;i++){
                    arr[i] = 0;
                  }

                  for(acertos = erros = 0,resta = NUM,questoes = 1;resta > 0;){
                      randomico = geradorAleatorio();
                      if(!arr[randomico]){
                          printf("\nPERGUNTA %d:\n\n", questoes);
                          printf("> "
                                 "%s\n", perguntas[randomico]);
                          printf("%s\n\n", respostas[randomico]);
                          printf("Pressione a A, B, C ou D para escolher a alternativa, P para pular!\n"
                                 "> ");
                          fflush(stdin);
                          alternativa = getchar();
                          if(alternativa == corretasIntermediarias[randomico]){
                              acertos++;
                              printf("ACERTOU!\n\n");
                          }else if((alternativa == 'P') && (pular > 0)){
                              pular--;
                              printf("PULOU! %s tem %d pulos restantes!\n", nomeJogador, pular);
                          }else{
                              erros++;
                              printf("ERROU!\n\n");
                          }
                          arr[randomico] = 1;
                          resta--;
                          questoes++;
                          system("pause");
                          system("cls");
                      }
                  }
                  system("cls");

                  pontuacao += ((acertos * 30)-(erros * 10));
                  printf("%s, teve %d acertos e %d erros nesse nivel, obtendo uma pontuacao de %d!", nomeJogador, acertos, erros, pontuacao);
                  if(acertos < 6){
                      gameOver();
                      system("pause");
                      system("cls");
                  }
				  else{
                    printf("\n\nParabains, voce completou o nivel INTERMEDIARIO!\n\n");

                    system("pause");
                    system("cls");
                    arquivo = fopen("perguntasdificeis.txt", "r");
                    for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
                    fclose(arquivo);

                    arquivo = fopen("respostasdificeis.txt", "r");
                    for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
                    fclose(arquivo);

                    for(i = 0;i < NUM;i++){
                      arr[i] = 0;
                    }

                    for(acertos = erros = 0,resta = NUM,questoes = 1;resta > 0;){
                        randomico = geradorAleatorio();
                        if(!arr[randomico]){
                            printf("\nPERGUNTA %d:\n\n", questoes);
                            printf("> "
                                   "%s\n", perguntas[randomico]);
                            printf("%s\n\n", respostas[randomico]);
                            printf("Pressione a A, B, C ou D para escolher a alternativa, P para pular!\n"
                                   "> ");
                            fflush(stdin);
                            alternativa = getchar();
                            if(alternativa == corretasDificeis[randomico]){
                                acertos++;
                                printf("\nACERTOU!\n\n");
                            }else if((alternativa == 'P') && (pular > 0)){
                                pular--;
                                printf("PULOU! %s tem %d pulos restantes!\n", nomeJogador, pular);
                            }else{
                                erros++;
                                printf("ERROU!\n\n");
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
                    system("cls");

                    pontuacao += ((acertos * 50)-(erros * 20));
                    printf("%s, teve %d acertos e %d erros nesse nivel, obtendo uma pontuacao final de %d!", nomeJogador, acertos, erros, pontuacao);
				 }
				}

                addPontuacao(nomeJogador,pontuacao);

                mostrarRanking();
                printf("\n\n");
                system("pause");
                system("cls");

                titulo();
                menu();
                scanf("%d", &opcao);
                system("cls");
                break;
              case 2:
                mostrarRanking();
                printf("\n");
                system("pause");
                system("cls");

                titulo();
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
