#ifndef PERGUNTAS_H_INCLUDED
#define PERGUNTAS_H_INCLUDED


//TESTE: gera números aleatórios SEM repetição e retorna o número da questão
int geradorAleatorio(){
    int r;
    time_t t;

    //Gera sequencias diferentes
    srand((unsigned)time(&t));

    r = (rand() % 10);

    return r;
}

#endif // PERGUNTAS_H_INCLUDED
