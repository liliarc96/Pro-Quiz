#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "etc.h"

int geradorAleatorio();

int geradorAleatorio(){
    int r;
    time_t t;

    //Gera sequencias diferentes
    srand((unsigned)time(&t));

    r = (rand() % 10);

    return r;
}
