#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "manipular_arquivo.h"

int modificarTxt(char * nArquivo, char * txt);
int mostrarRanking();
int addPontuacao(char * jogador, int pontuacao);

int modificarTxt(char * nArquivo, char *txt){
    FILE * arquivo;

    arquivo = fopen(nArquivo, "a");
    if(arquivo == NULL){
       printf("\nO arquivo não pode ser aberto...");
       exit(EXIT_FAILURE);
    }
    fprintf(arquivo, "%s\n", txt);
    fclose(arquivo);
    return 0;
}

int mostrarRanking(){

    FILE * arquivo = fopen("pontuacao.txt", "r");
    if(!arquivo) return 0;

    //auxiliar para leitura:
    usuario * lista;

    char linha[150];
    if(fgets(linha, 150, arquivo)==0) return 0;
    //printf("Lido: %s", linha);
    char * nome = strtok(linha, ":");
    char * str_pontuacao = strtok(0,":");
    usuario * usr1 = (usuario *) malloc(sizeof(usuario));
    if(!usr1) return 0;
    strcpy(usr1->nome, nome);
    usr1->pontuacao = atoi(str_pontuacao);
    usr1->proximo = 0;
    lista = usr1;
    usuario * aux = lista;

    while(fgets(linha, 150, arquivo)!=0){

        nome = strtok(linha, ":");
        str_pontuacao = strtok(0,":");
        //novo usuario:
        usuario * novo = (usuario *) malloc(sizeof(usuario));
        if(!novo) return 0;
        strcpy(novo->nome, nome);
        novo->pontuacao = atoi(str_pontuacao);
        novo->proximo = 0;

        aux->proximo = novo;
        aux = aux->proximo;
    }
    aux = lista;

    printf("\nRANKING FINAL:\n\n");
    while(aux!=0){
        printf("%s : %d ponto(s)\n", aux->nome, aux->pontuacao);
        aux = aux->proximo;
    }


    free(usr1);
    fclose(arquivo);
    return 0;
}

int addPontuacao(char * jogador, int pontuacao){
    FILE * arquivo;
    arquivo = fopen("pontuacao.txt", "a");
    if(!arquivo){
       printf("\nO arquivo não pode ser aberto...");
       return 0;
    }
    fprintf(arquivo, "%s: ", jogador);
    fprintf(arquivo, "%d\n", pontuacao);
    fclose(arquivo);
    return 0;
}
