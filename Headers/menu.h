#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
/*
Header para gráficos do jogo
*/
void titulo(){
    printf("\n\n _______________________________________________________________________________________  "
           "\n                                                                                       "
           "\n                                         QUIZ                                          "
           "\n                                                                                       "
           "\n"
           " _______________________________________________________________________________________  \n\n\n\n\n\n");
}

void guia(){
    //Como jogar fica aqui
    printf("Guia do jogo...\n\n");
}

void menu(){
  printf("\n\n________________________________________________________________________________________\n"
         "1: Jogar;\n\n"
         "2: Ver Ranking;\n\n"
         "3: Cadastrar Perguntas;\n\n"
         "4: Creditos;\n\n"
         "0: Sair;\n"
         "________________________________________________________________________________________");

  printf("\n\n"
         "> ");
}

#endif // MENU_H_INCLUDED
