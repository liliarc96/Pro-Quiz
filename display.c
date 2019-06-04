#include <stdio.h>
#include <stdlib.h>

#include "display.h"

void titulo();
void guia();
void menu();
void creditos();

void titulo(){
    printf("\n\n\n"
            " ::::::::   :::    ::: ::::::::::: ::::::::: \n"
            ":+:    :+:  :+:    :+:     :+:          :+: \n"
            "+:+    +:+  +:+    +:+     +:+         +:+  \n"
            "+#+    +:+  +#+    +:+     +#+        +#+  \n"
            "+#+  # +#+  +#+    +#+     +#+       +#+   \n"
            "#+#   +#+   #+#    #+#     #+#      #+#  \n"
            " ###### ###  ########  ########### ######### \n"
            "\n\n\n"
           );
}

void guia(){
    printf("\n\n _______________________________________________________________________________________  "
           "\n                                                                                       "
           "\n                                        UM                                        "
           "\n                                       GUIA                                              "
           "\n"
           " _______________________________________________________________________________________  \n\n\n"
           "Esse e um quiz elaborado para testar seus conhecimentos gerais sobre as mais diversas\n"
           "areas. Ele e dividido em tres categorias de dificuldade:\n"
           "FACIL, INTERMEDIARIO e DIFICIL.\n\n\n"
           "Cada pergunta do nivel FACIL vale 10 pontos por acerto, o jogador nao perde nada\n"
           "por errar e passa para o nivel INTERMEDIARIO se acertar 5 perguntas ou mais.\n\n"
           "Cada pergunta do nivel INTERMEDIARIO vale 30 pontos por acerto, cada erro\n"
           "diminui a pontuacao em 10 pontos e o jogador passa para o nivel DIFICIL\n"
           "se acertar 6 perguntas ou mais.\n\n"
           "Cada pergunta do nivel DIFICIL vale 50 pontos por acerto e cada erro\n"
           "diminui a pontuacao em 20 pontos.\n\n\n");
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

void creditos(){
    printf("\n\nQ U I Z by Lilia & Renata\n\n");
}
