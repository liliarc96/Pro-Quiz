#ifndef MANIPULAR_ARQUIVO_H_INCLUDED
#define MANIPULAR_ARQUIVO_H_INCLUDED

int modificarTxt(char * nArquivo){
    FILE * arquivo;
    char str[1000];

    //Append:
    arquivo = fopen(nArquivo, "a");
    if(arquivo == NULL){
       printf("\nO arquivo não pode ser aberto...");
       exit(EXIT_FAILURE);
    }
    fgets(str, sizeof str, stdin);
    fputs(str, arquivo);

    fclose(arquivo);
    return 0;
}



int abrirRanking(){
    int TAMANHO = 5000;
    int totalRead = 0;
    FILE * arquivo;
    char buffer[TAMANHO];

    //Abre arquivo:
    arquivo = fopen("pontuacao.txt", "r");

    if(arquivo == NULL){
       printf("\nERRO");
       exit(EXIT_FAILURE);
    }else{
        while(fgets(buffer, TAMANHO , arquivo) != NULL){
            totalRead = strlen(buffer);

            buffer[totalRead - 1] = buffer[totalRead - 1] == '\n' ? '\0' : buffer[totalRead - 1];

            printf("%s\n", buffer);
        }
    }

    //Fechar arquivo:
    fclose(arquivo);
    return 0;
}
#endif // MANIPULAR_ARQUIVO_H_INCLUDED
