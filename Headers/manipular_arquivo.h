#ifndef MANIPULAR_ARQUIVO_H_INCLUDED
#define MANIPULAR_ARQUIVO_H_INCLUDED

typedef struct t_usuario{
    char nome [100];
    unsigned int pontuacao;
    struct t_usuario * proximo;
} usuario;

int modificarTxt(char * nArquivo);

int mostrarRanking();

int addPontuacao(char * jogador, int pontuacao);
#endif // MANIPULAR_ARQUIVO_H_INCLUDED
