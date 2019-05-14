#ifndef MANIPULAR_ARQUIVO_H_INCLUDED
#define MANIPULAR_ARQUIVO_H_INCLUDED

//Função que recebe o nome do arquivo (3 opções):
int modificarArquivo(char * nArquivo){
    FILE * arquivo;
    int i,n; //n = número de linhas a serem adicionadas (uma linha para perguntas e uma para respostas)
    char str[1000];

    //Append:
    arquivo = fopen(nArquivo, "a");
    if(arquivo == NULL){
       printf("\nO arquivo não pode ser aberto...");
       exit(EXIT_FAILURE);
    }else{
        for(i = 0, n = 2; i < n + 1; i++){
            fgets(str, sizeof str, stdin);
            fputs(str, arquivo);
        }
    //Fechar arquivo:
    fclose(arquivo);
    return 0;
    }
}



int abrirRanking(){
    int TAMANHO = 100000;
    int totalRead = 0;
    FILE * arquivo;
    char buffer[TAMANHO];

    //Abre arquivo:
    arquivo = fopen("pontuacao.txt", "r");

    if(arquivo == NULL){
       printf("\nO arquivo não pode ser aberto...");
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
