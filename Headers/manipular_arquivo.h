#ifndef MANIPULAR_ARQUIVO_H_INCLUDED
#define MANIPULAR_ARQUIVO_H_INCLUDED

/*
Para abrir tanto o ranking.txt para modificar o ranking quanto
abrir o perguntas(dificuldade) para adicionar novas perguntas
*/

//Função que recebe o nome do arquivo (4 opções):
int abrirArquivo(char * nArquivo){
    //Abre arquivo:
    FILE * arquivo = fopen(nArquivo, "r");
    if(!arquivo){
       printf("\nO arquivo não pode ser aberto...");
       return 0;
    }else{
        printf("\nSe você estiver lendo essa mensagem, o arquivo '%s' foi aberto corretamente!", nArquivo);
    }
    //Fechar arquivo:
    fclose(arquivo);
    return 0;
}

#endif // MANIPULAR_ARQUIVO_H_INCLUDED
