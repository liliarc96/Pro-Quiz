#ifndef ETC_H_INCLUDED
#define ETC_H_INCLUDED


//TESTE: gera números aleatórios SEM repetição e retorna o número da questão
int geradorAleatorio(){
    int r;
    time_t t;

    //Gera sequencias diferentes
    srand((unsigned)time(&t));

    r = (rand() % 10);

    return r;
}

#endif // ETC_H_INCLUDED
