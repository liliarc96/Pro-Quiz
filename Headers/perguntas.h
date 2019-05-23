#ifndef PERGUNTAS_H_INCLUDED
#define PERGUNTAS_H_INCLUDED

//TESTE: gera números aleatórios SEM repetição e retorna o número da questão & resposta correspondente
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

void perguntasToChar(char * nArquivo){
    FILE * arquivo = fopen(nArquivo, "r");
    int i;
    char perguntas[20][1000];

    printf("\n\nLENDO PERGUNTAS:\n\n");
    for (i=0; i<20 && fgets(perguntas[i], 1000, arquivo) != NULL; i++){
            printf("%s", perguntas[i]);
    }
    printf("\nACABOU DE LER PERGUNTAS!\n\n");
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
}


#endif // PERGUNTAS_H_INCLUDED
