/*
                                               -----------------------------------
                                                    Q U I Z by Lília & Renata
                                               -----------------------------------

   ----------------------------------------------------------------------------------------------------------------------------
   HEADERS & SOURCES:

            display.c & display.h            ==> Todos os textos que aparecem no jogo
   manipular_arquivo.c & manipular_arquivo.h ==> Tudo relacionado a manipulação de arquivos (abrir, fechar e modificar)
   ----------------------------------------------------------------------------------------------------------------------------

   ----------------------------------------------------------------------------------------------------------------------------
   FUNÇÕES GLOBAIS:

    ->EM DISPLAY:
        creditos(): void ==> Créditos do jogo
        guia(): void     ==> Apresenta o guia do jogo
        menu(): void     ==> Estrutura do menu com suas opções
        titulo(): void   ==> Nome do quiz

    ->EM MANIPULAR_ARQUIVO:
        addPontuacao(char*jogador, int pontuacao): int ==> Adiciona uma nova entrada em pontuacao.txt
        modificarTxt(char*nArquivo): int               ==> Modifica o .txt das perguntas e respostas
        mostrarRanking(): int                          ==> Mostra o ranking salvo em pontuacao.txt

    ->EM QUIZ:
        nivel(char*nomeJogador, char dificuldade, char (*pergunta)[1000], char (*resposta)[1000], char * comparacao): int
		                ==> Estrutura dos níveis do jogo
		mainQuiz(): int ==> Estrutura do jogo
   ----------------------------------------------------------------------------------------------------------------------------

   ----------------------------------------------------------------------------------------------------------------------------
   VARIÁVEIS:

        _| NUM ==> É usada em várias outras variáveis para fazer comparações, o valor original é 10 |_

    ->DE CONTROLE:
        opcao: int        ==> Opção do menu
        repeticao: int    ==> default = 1; Continua a exibir o menu após sair da opção escolhida
        randomico:  int   ==> Número  que recebe valor da função geradorAleatorio(): int
	    alternativa: char ==> Recebe A B C D ou P, compara a resposta do usuário com o array de respostas certas.
                          	  Tambem recebe F I D para editar os txt de modificar os arquivos de perguntas & respostas
	    questões: int     ==> default = 1; Numera as respostas e reseta a cada nível novo
    |NUM| arr: bool       ==> Inicia com NUM zeros, o número escolhido modifica para 1 para não ser escolhido novamente

    ->DE PERGUNTAS & RESPOSTAS:
    |NUM| perguntas: char              ==> Perguntas retiradas do arquivo 'perguntas(faceis/intermediarias/dificeis).txt'
    |NUM| respostas: char              ==> Respostas retiradas do arquivo 'respostas(faceis/intermediarias/dificeis).txt'
    |NUM| corretasFaceis: char         ==> As opções corretas das perguntas fáceis, respectivamente
    |NUM| corretasIntermediarias: char ==> As opções corretas das perguntas intermediárias, respectivamente
    |NUM| corretasDificeis: char       ==> As opções corretas das perguntas difíceis, respectivamente
    |NUM| resta: int                   ==> Resta(m) ... pergunta(s) para o fim do nível

    ->DE JOGADOR:
        nomeJogador: char ==> Nome do jogador
        pontuacao: int    ==> Pontuação do jogador
	    acertos: int      ==> Acertos por nível
	    erros: int        ==> Erros por nível
   ----------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

#define NUM 10

#include "manipular_arquivo.h"
#include "display.h"
/*
													PARA A INTEGRAÇÃO
int mainQuiz();

*/

int nivel(char*nomeJogador, char dificuldade, char (*pergunta)[1000], char (*resposta)[1000], char * comparacao);

//Níveis do jogo!
int nivel(char * nomeJogador, char dificuldade, char (*pergunta)[1000], char (*resposta)[1000], char * comparacao){
    int randomico;
    bool arr[NUM] = {0};
    int resta = NUM;
    time_t t;

    int acertos;
    int erros;
    int questoes = 1;
    int pontuacao = 0;

    char alternativa;

    srand((unsigned)time(&t));

    for(acertos = erros = 0;resta > 0;){
        randomico = (rand() % 10);
		if(!arr[randomico]){
			printf("\nPERGUNTA %d:\n", questoes);

			printf("> "
                   "%s\n", pergunta[randomico]);

			printf("%s\n\n", resposta[randomico]);

			printf("Pressione A, B, C ou D para escolher a alternativa, P para pular!\n"
                   "> ");
			fflush(stdin);
			alternativa = getchar();
			if(alternativa == comparacao[randomico]){
				acertos++;
				printf("\nACERTOU!\n\n");
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

	if(dificuldade == 'F'){
        pontuacao = acertos * 10;
        printf("\n\nCompletou o nivel FACIL!\n\n");
	}else if(dificuldade == 'M'){
	    pontuacao = ((acertos * 30)-(erros * 10));
	    printf("\n\nCompletou o nivel INTERMEDIARIO!\n\n");
	}else if(dificuldade == 'D'){
        pontuacao += ((acertos * 50)-(erros * 20));
        printf("\n\nCompletou o nivel DIFICIL!\n\n");
	}
	printf("%s teve %d acertos, %d erros e obteve uma pontuacao de %d nesse nivel!\n\n", nomeJogador, acertos, erros, pontuacao);

	system("pause");
	system("cls");

	return pontuacao;
}

int main(){
    int opcao, repeticao = 1, i;

    char texto[1000];
    char perguntas[NUM][1000];
    char respostas[NUM][1000];
    char alternativa;
    char * nomeArquivo;

    char corretasFaceis[NUM] = {'B','B','C','C','B','B','B','B','D','D'};
    char corretasIntermediarias[NUM] = {'C','A','B','A','A','A','C','B','C','D'};
    char corretasDificeis[NUM] = {'B','B','B','D','B','A','B','B','C','A'};

    char nomeJogador[200];
    int pontuacao = 0;

    FILE * arquivo;

    //Muda a cor do background para preto (0) e da cor da letra para verde(A)
    system("color 0A");
    //Primeira chamada do título do jogo (Trivia) e do menu
    titulo();
    menu();
    //Usuário escolhe uma opção do menu (1,2,3,4 ou 0)
    scanf("%d", &opcao);
    system("cls");

    //Enquando o case 0 não for escolhido o menu continua a ser mostrado
    while(repeticao == 1){
        switch(opcao){
                case 1:
					//Usuário escolhe o seu nickname
					printf("Insira o nome do jogador:\n"
						"> ");
					scanf("%s", nomeJogador);
					system("cls");
					//Mostra um breve tutorial de como jogar
					guia();
					system("pause");
					system("cls");

					//O JOGO COMEÇA AQUI!!!

                    //Inicializando o nível FÁCIL!
                    arquivo = fopen("perguntasfaceis.txt", "r");
                    for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
                    fclose(arquivo);

                    arquivo = fopen("respostasfaceis.txt", "r");
                    for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
                    fclose(arquivo);

					//Começa nível fácil:
					alternativa = 'F';
					pontuacao += nivel(nomeJogador, alternativa, perguntas, respostas, corretasFaceis);
					system("cls");

					//Inicializando o nível INTERMEDIÁRIO!
					arquivo = fopen("perguntasintermediarias.txt", "r");
                    for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
                    fclose(arquivo);

                    arquivo = fopen("respostasintermediarias.txt", "r");
                    for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
                    fclose(arquivo);

                    //Começa nível intermediário:
                    alternativa = 'M';
                    pontuacao += nivel(nomeJogador, alternativa, perguntas, respostas, corretasIntermediarias);
					system("cls");

					//Inicializando o nível DIFÍCIL!
					arquivo = fopen("perguntasdificeis.txt", "r");
					for (i=0; i< NUM && fgets(perguntas[i], 1000, arquivo) != NULL; i++);
					fclose(arquivo);

					arquivo = fopen("respostasdificeis.txt", "r");
					for (i=0; i< NUM && fgets(respostas[i], 1000, arquivo) != NULL; i++);
					fclose(arquivo);

					//Começa nível difícil:
					alternativa = 'D';
					pontuacao += nivel(nomeJogador, alternativa, perguntas, respostas, corretasDificeis);
                    system("cls");

                    //Adiciona a pontuação:
					addPontuacao(nomeJogador,pontuacao);

					//Mostra o ranking:
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
                    printf("A T E N C A O ! ! !\n\n\n"
                           "Obedeca a formatacao de perguntas e repostas!\n"
                           "> Digite qual a dificuldade que deseja modificar:\n\n"
                           "F para faceis;\n"
                           "I para intermediarias;\n"
                           "D para dificeis;\n"
                           "> ");
                    fflush(stdin);
					alternativa = getchar();

					if(alternativa == 'F'){
                        nomeArquivo = "perguntasfaceis.txt";
                        printf("\nDigite a pergunta desejada:\n"
                               "> ");
                        scanf("%s", texto);

                        modificarTxt(nomeArquivo, texto);

                        nomeArquivo = "respostasfaceis.txt";
                        printf("\nDigite as respostas desejadas:\n"
                               "> ");
                        scanf("%s", texto);

                        modificarTxt(nomeArquivo, texto);
					}else if(alternativa == 'I'){
					    nomeArquivo = "perguntasintermediarias.txt";
                        printf("\nDigite a pergunta desejada:\n"
                               "> ");
                        scanf("%s", texto);

                        modificarTxt(nomeArquivo, texto);

                        nomeArquivo = "respostasintermediarias.txt";
                        printf("\nDigite as respostas desejadas:\n"
                               "> ");
                        scanf("%s", texto);

                        modificarTxt(nomeArquivo, texto);
					}else if(alternativa == 'D'){
					    nomeArquivo = "perguntasdificeis.txt";
                        printf("\nDigite a pergunta desejada:\n"
                               "> ");
                        scanf("%s", texto);

                        modificarTxt(nomeArquivo, texto);

                        nomeArquivo = "respostasdificeis.txt";
                        printf("\nDigite as respostas desejadas:\n"
                               "> ");
                        scanf("%s", texto);

                        modificarTxt(nomeArquivo, texto);
					}else{
					    printf("OPCAO INVALIDA!");
					}

                    titulo();
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
					titulo();
					menu();
					scanf("%d", &opcao);
					break;
        }
    }
    return 0;
}
