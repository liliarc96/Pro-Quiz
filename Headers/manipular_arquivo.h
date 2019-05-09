#ifndef MANIPULAR_ARQUIVO_H_INCLUDED
#define MANIPULAR_ARQUIVO_H_INCLUDED

/*
Para abrir tanto o ranking.txt para modificar o ranking quanto
abrir o perguntas(dificuldade) para adicionar novas perguntas
*/

//Função que recebe o nome do arquivo (3 opções):
int abrirArquivo(char * nArquivo){
    FILE * arquivo;
    char caractere;

    //Abre arquivo:
    arquivo = fopen(nArquivo, "r");
    if(arquivo == NULL){
       printf("\nO arquivo não pode ser aberto...");
       exit(EXIT_FAILURE);
    }else{
        //TESTE MOSTRAR CONTEÚDO DO ARQUIVO NO CONSOLE
        do{
            //Lê caractere do arquivo:
            caractere = fgetc(arquivo);

            if(caractere == EOF){
               break;//Se for final da linha, break (se o EOF for impresso aparece ÿ)
            }
            //Mostra caractere no console:
            putchar(caractere);

        } while(caractere != EOF);

        /*
        EOF significa End Of Line /!\
        */
    }

    //Fechar arquivo:
    fclose(arquivo);
    return 0;
}

int abrirRanking(){
    FILE * arquivo;
    char caractere;


    //Abre arquivo:
    arquivo = fopen("pontuacao.txt", "r");
    if(arquivo == NULL){
       printf("\nO arquivo não pode ser aberto...");
       exit(EXIT_FAILURE);
    }else{
        do{
            caractere = fgetc(arquivo);
            if(caractere == EOF){
               break;
            }
            putchar(caractere);

        } while(caractere != EOF);
    }

    //Fechar arquivo:
    fclose(arquivo);
    return 0;
}
#endif // MANIPULAR_ARQUIVO_H_INCLUDED
