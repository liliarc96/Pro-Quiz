#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

typedef struct t_usuario{
    char nome [100];
    unsigned int pontuacao;
    struct t_usuario * proximo;
} usuario;

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
    //printf("Nome lido: %s", usr1->nome);
    lista = usr1;
    usuario * aux = lista;

    //printf("Usuario: %s, pontuacao: %d\n", usr1->nome, usr1->pontuacao);

    while(fgets(linha, 150, arquivo)!=0){

        nome = strtok(linha, ":");
        str_pontuacao = strtok(0,":");
        //novo usuario:
        usuario * novo = (usuario *) malloc(sizeof(usuario));
        if(!novo) return 0;
        strcpy(novo->nome, nome);
        novo->pontuacao = atoi(str_pontuacao);
        novo->proximo = 0;

        //adicionar na lista:
        aux->proximo = novo;
        aux = aux->proximo;
        //printf("Usuario: %s, pontuacao: %d\n", nome, pontuacao);
    }
    aux = lista;

    //printf("\nPONTUAÇÃO FINAL:\n\n");
    while(aux!=0){
        //printf("%s : %d ponto(s)\n", aux->nome, aux->pontuacao);
        aux = aux->proximo;
    }


    free(usr1);
    fclose(arquivo);
    return 0;
}

#endif // RANKING_H_INCLUDED
