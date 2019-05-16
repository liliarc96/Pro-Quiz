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
//TESTE
int testeArray(){
    int i=0;
    int numperguntas = 10;
    char* perguntas[10];
    char linhas[21];

    FILE * arquivo;
    arquivo = fopen("perguntasfaceis.txt", "r");

    while(fgets(linhas, sizeof linhas, arquivo)!=NULL) {

    printf("%s", linhas);
    perguntas[i]= malloc(sizeof(linhas));
    strcpy(perguntas[i],linhas);
    i++;
    numperguntas++;
  }

  for (int j=0 ; j<numperguntas+1; j++) {
  printf("\n%s", perguntas[j]);
 }

 fclose(arquivo);
 return 0;
}

//TESTE
int testeArray2(){
    static const char filename[] = "perguntasfaceis.txt";
    FILE *file = fopen ( filename, "r" );
    int i, j;
    char arra[21][1500];
    char linhas[21]; //quantidade de linhas

    for(i=0; i<21; i++){
        for(j=0; j<21; j++){
            arra[j] = '?';
            for(i=0; i<21; i++){
              linhas = '?';
            }
        }
    }
    if ( file != NULL ){
        i=0;
        while ( fgets ( linhas, sizeof linhas, file ) != NULL ){
            strcpy(arra, linhas);
            printf("array ----> %s ", &arra);
            i++;
        }
        fclose ( file );
    }else{
        perror ( filename );
    }
    return 0;
}

//TESTE
int lista(){
    int num; // ESTE É O NUMERO QUE SERÁ LIDO DO ARQUIVO E PASSADO PARA A LISTA
    tlista * list; // ESTOU CRIANDO A LISTA, NADA DE NOVO
    list = NULL;
    FILE *arquivo; // REFERENCIA DO ARQUIVO, SEMPRE QUE FOR UTILIZAR O ARQUIVO
                   // SERA REFERENDIDO-SE PELO arquivo
    arquivo = fopen("c:\\arq.txt","r"); // O FOPEN ABRE O ARQUIVO, NO CASO
                                        // É PASSADO POR PARAMETRO O ENDEREÇO
                                        // DO ARQUIVO, E O "r" SIGNIFICA QUE
                                        // O ARQUIVO ESTÁ SENDO ABERTO APENAS
                                        // PARA LEITURA

    if (arquivo) // CASO NAO TENHA DADO ERRO AO ABRIR O ARQUIVO
       {
           do
             {
                fscanf(arquivo,"%d",&num ); // O FSCANF É IDENTICO AO SCANF QUE
                                            // TODOS CONHECEM, PORÉM ELE É
                                            // UTILIZADO PARA LER DADOS DE
                                            // ARQUIVOS, E É PASSADO COMO
                                            // PARAMETRO, O PROPRIO ARQUIVO
                                            // QUE ESTA SENDO LIDO
                list = lu_insereinicio(list, num); // INSERE O NUMERO NA LISTA
             }while(!feof(arquivo)); // ELE PERCORRERÁ TODAS AS LINHAS DO ARQUIVO
                                     // ENQUANTO O ARQUIVO NAO CHEGAR AO FIM
                                     // FEOF = END OF FILE
         }

    lu_exibelista(list); // EXIBE A LISTA
    fclose(arquivo); // FECHA O ARQUIVO
}

#endif // PERGUNTAS_H_INCLUDED
