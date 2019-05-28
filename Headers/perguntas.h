#ifndef PERGUNTAS_H_INCLUDED
#define PERGUNTAS_H_INCLUDED

typedef struct t_quiz{
    char * pergunta [10000];
    char * resposta [10000];
    struct t_quiz * proximo;
} quiz;

//TESTE: gera números aleatórios SEM repetição e retorna o número da questão
int geradorAleatorio(){
    int r, i, n = 10;
    bool arr[10] = {0}; //array booleano contendo somente false
    time_t t;

    //Gera sequencias diferentes
    srand((unsigned)time(&t));

    for(i = 0;i < n; ++i){
        //r recebe um número aléatório entre 1 e 10
        //pois rand()%10 gera só de 0 até 9
        r = 1 + (rand() % 10);

        if(!arr[r]){
            printf("%d\n",r);
        }else{
            i--;
        }
        arr[r]=1;
    }
    return r;
}

int startquiz(char * perguntas, char * respostas){

    FILE * arquivo = fopen(perguntas, "r");

    if(!arquivo) return 0;

    //auxiliar para leitura:
    quiz * lista;

    char linha[200];
    if(fgets(linha, 200, arquivo)==0) return 0;
    //printf("Lido: %s", linha);

    char * pergunta = strtok(linha, ";");

    quiz * usr1 = (quiz *) malloc(sizeof(quiz));

    if(!usr1) return 0;

    strcpy(usr1 -> pergunta, pergunta);
    usr1 -> proximo = 0;

    lista = usr1;
    quiz * aux = lista;

    while(fgets(linha, 200, arquivo)!=0){
        pergunta = strtok(linha, ";");
        //novo quiz:
        quiz * novo = (quiz *) malloc(sizeof(quiz));
        if(!novo) return 0;
        strcpy(novo -> pergunta, pergunta);
        novo -> proximo = 0;
        //adicionar na lista:
        aux->proximo = novo;
        aux = aux->proximo;
        printf("%s\n", pergunta);
    }
    aux = lista;

    fclose(arquivo);
    printf("\n");
    //COMEÇA RESPOSTAS
    arquivo = fopen(respostas, "r");

    FILE * arquivo2 = fopen(respostas, "r");

    if(!arquivo2) return 0;

    char linha2[200];
    if(fgets(linha2, 200, arquivo)==0) return 0;

    char * resposta = strtok(linha2, ";");

    if(!aux) return 0;
    strcpy(aux->resposta, resposta);

    aux = aux->proximo;

    while(fgets(linha2, 200, arquivo)!=0){
        resposta = strtok(linha2, ";");
        resposta = linha2;
        if(!aux) return 0;
        strcpy(aux->resposta, resposta);

        aux = aux->proximo;
        printf("%s\n", resposta);
    }

    free(usr1);
    fclose(arquivo2);
    return 0;
}

/*
void perguntasToChar(char * nArquivo){
    FILE * arquivo = fopen(nArquivo, "r");
    int i;
    char perguntas[20][1000];

    printf("\n\nLENDO PERGUNTAS:\n\n");
    for (i=0; i<20 && fgets(perguntas[i], 1000, arquivo) != NULL; i++){
            printf("%s", perguntas[i]);
    }
    printf("\nACABOU DE LER PERGUNTAS!\n\n");
    fclose(arquivo);
}

void respostasToChar(char * nArquivo){
    FILE * arquivo = fopen(nArquivo, "r");
    int i;
    char respostas[20][1000];

    printf("\n\nLENDO RESPOSTAS:\n\n");
    for (i=0; i<20 && fgets(respostas[i], 1000, arquivo) != NULL; i++){
            printf("%s", respostas[i]);

    }
    printf("\nACABOU DE LER RESPOSTAS!\n");
    fclose(arquivo);
}
*/

#endif // PERGUNTAS_H_INCLUDED
