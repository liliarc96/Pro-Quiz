#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

void titulo(){
    printf("\n\n _______________________________________________________________________________________  "
           "\n"
           "\n                                         QUIZ                                          "
           "\n"
           "\n"
           " _______________________________________________________________________________________  \n\n\n\n\n\n");
}

void guia(){
    //Como jogar fica aqui
    printf("Isso щ um guia do jogo...\n\n");
}

void menu(){
  printf("\n\n________________________________________________________________________________________\n"
         "1: Jogar;\n\n"
         "2: Ver Ranking;\n\n"
         "3: Cadastrar Perguntas;\n\n"
         "4: Creditos;\n\n"
         "0: Sair;\n"
         "________________________________________________________________________________________");

  printf("\n\nDigite uma opção do menu:\n"
         "> ");
}

#endif // MENU_H_INCLUDED
