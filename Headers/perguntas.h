#ifndef PERGUNTAS_H_INCLUDED
#define PERGUNTAS_H_INCLUDED

//TESTE

typedef struct t_quiz{
    char pergunta [10000];
    char resposta [10000];
    struct t_quiz * proximo;
} quiz;

int startquiz(char * nArquivo){

    FILE * arquivo = fopen(nArquivo, "r");
    if(!arquivo) return 0;

    //auxiliar para leitura:
    quiz * lista;

    char linha[150];
    if(fgets(linha, 150, arquivo)==0) return 0;
    printf("Lido: %s", linha);
    /*
    char * pergunta = strtok(linha, "?");
    char * str_resposta = strtok(0,"|");
    quiz * usr1 = (quiz *) malloc(sizeof(quiz));
    if(!usr1) return 0;
    strcpy(usr1->pergunta, pergunta);
    usr1->resposta = atoi(str_resposta);
    usr1->proximo = 0;
    //printf("pergunta lido: %s", usr1->pergunta);
    lista = usr1;
    quiz * aux = lista;

    //printf("quiz: %s, resposta: %d\n", usr1->pergunta, usr1->resposta);

    while(fgets(linha, 150, arquivo)!=0){

        pergunta = strtok(linha, ":");
        str_resposta = strtok(0,":");
        //novo quiz:
        quiz * novo = (quiz *) malloc(sizeof(quiz));
        if(!novo) return 0;
        strcpy(novo->pergunta, pergunta);
        novo->resposta = atoi(str_resposta);
        novo->proximo = 0;

        //adicionar na lista:
        aux->proximo = novo;
        aux = aux->proximo;
        //printf("quiz: %s, resposta: %d\n", pergunta, resposta);
    }
    aux = lista;

    printf("\nPONTUAÇÃO FINAL:\n\n");
    while(aux!=0){
        printf("%s : %d ponto(s)\n", aux->pergunta, aux->resposta);
        aux = aux->proximo;
    }


    free(usr1);
    */
    fclose(arquivo);
    return 0;
}

#endif // PERGUNTAS_H_INCLUDED
