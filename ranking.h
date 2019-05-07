typedef struct t_usuario{
    char nome [100];
    unsigned int vitorias;
    struct t_usuario * proximo;
} usuario;

int main(){
    //abre arquivo
    FILE * arquivo = fopen("ranking.txt", "r");
    if(!arquivo) return 0;
    //auxiliar para leitura:
    usuario * lista;
    char linha[150];
    if(fgets(linha, 150, arquivo)==0) return 0;
    //printf("Lido: %s", linha);
    char * nome = strtok(linha, ":");
    char * str_vitorias = strtok(0,":");
    usuario * usr1 = (usuario *) malloc(sizeof(usuario));
    if(!usr1) return 0;
    strcpy(usr1->nome, nome);
    usr1->vitorias = atoi(str_vitorias);
    usr1->proximo = 0;
    //printf("Nome lido: %s", usr1->nome);
    lista = usr1;
    usuario * aux = lista;

    //printf("Usuario: %s, Vitorias: %d\n", usr1->nome, usr1->vitorias);

    while(fgets(linha, 150, arquivo)!=0){

        nome = strtok(linha, ":");
        str_vitorias = strtok(0,":");
        //novo usuario:
        usuario * novo = (usuario *) malloc(sizeof(usuario));
        if(!novo) return 0;
        strcpy(novo->nome, nome);
        novo->vitorias = atoi(str_vitorias);
        novo->proximo = 0;

        //adicionar na lista:
        aux->proximo = novo;
        aux = aux->proximo;
        //printf("Usuario: %s, Vitorias: %d\n", nome, vitorias);
    }
    aux = lista;
    while(aux!=0){
        printf("Nome: %s, vitorias: %d\n", aux->nome, aux->vitorias);
        aux = aux->proximo;
    }


    free(usr1);
    fclose(arquivo);
    return 0;
}
