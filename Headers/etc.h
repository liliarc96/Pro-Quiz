#ifndef ETC_H_INCLUDED
#define ETC_H_INCLUDED


//TESTE: gera n�meros aleat�rios SEM repeti��o e retorna o n�mero da quest�o
int geradorAleatorio(){
    int r;
    time_t t;

    //Gera sequencias diferentes
    srand((unsigned)time(&t));

    r = (rand() % 10);

    return r;
}

#endif // ETC_H_INCLUDED
