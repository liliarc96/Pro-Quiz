#include <stdio.h>
#include <stdlib.h>

#include "display.h"

void titulo();
void guia();
void menu();
void creditos();
void gameOver();

void titulo(){
    //Se quiser usar "contra barra" no printf voc� precisa usar outra ap�s elas, para n�o ser dada como comando
    printf("\n\n\n"
            "                    ___                                                 ___    \n"
            "                   /\\  \\                      ___                      /\\  \\    \n"
            "      ___         /::\\  \\       ___          /\\  \\        ___         /::\\  \\   \n"
            "     /\\__\\       /:/\\:\\__\\     /\\__\\         \\:\\  \\      /\\__\\       /:/\\:\\  \\  \n"
            "    /:/  /      /:/ /:/  /    /:/__/          \\:\\  \\    /:/__/      /:/ /::\\  \\ \n"
            "   /:/__/      /:/_/:/__/___ /::\\  \\      ___  \\:\\__\\  /::\\  \\     /:/_/:/\\:\\__\\ \n"
            "  /::\\  \\      \\:\\/:::::/  / \\/\\:\\  \\__  /\\  \\ |:|  |  \\/\\:\\  \\__  \\:\\/:/  \\/__/ \n"
            " /:/\\:\\  \\      \\::/~~/~~~~   ~~\\:\\/\\__\\ \\:\\  \\|:|  |   ~~\\:\\/\\__\\  \\::/__/  \n"
            " \\/__\\:\\  \\      \\:\\~~\\          \\::/  /  \\:\\__|:|__|      \\::/  /   \\:\\  \\   \n"
            "      \\:\\__\\      \\:\\__\\         /:/  /    \\::::/__/       /:/  /     \\:\\__\\    \n"
            "       \\/__/       \\/__/         \\/__/      ~~~~           \\/__/       \\/__/    \n"
            "\n\n"
           );
}

void guia(){
    printf("\n\n _______________________________________________________________________________________\n  "
           "  ______            __                                     ___      \n"
           "   /\\__  _\\          /\\ \\__                   __            /\\_ \\     \n"
           "   \\/_/\\ \\/   __  __ \\ \\  _\\    ___    _ __  /\\_\\      __   \\//\\ \\    \n"
           "      \\ \\ \\  /\\ \\/\\ \\ \\ \\ \\/   / __ \\ /\\  __\\\\/\\ \\   / __ \\   \\ \\ \\  \n"
           "       \\ \\ \\ \\ \\ \\_\\ \\ \\ \\ \\_ /\\ \\ \\ \\\\ \\ \\/  \\ \\ \\ /\\ \\ \\ \\_  \\_\\ \\_ \n"
           "        \\ \\_\\ \\ \\____/  \\ \\__\\\\ \\____/ \\ \\_\\   \\ \\_\\\\ \\__/ \\_\\ /\\____\\ \n"
           "         \\/_/  \\/___/    \\/__/ \\/___/   \\/_/    \\/_/ \\/__/\\/_/ \\/____/\n"
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

void gameOver(){
    printf("\n\n\n"
           "      ___           ___           ___           ___                    ___                         ___           ___     \n"
           "     /\\__\\         /\\  \\         /\\  \\         /\\__\\                  /\\  \\          ___          /\\__\\         /\\  \\    \n"
           "    /:/ _/_       /::\\  \\       |::\\  \\       /:/ _/_                /::\\  \\        /\\  \\        /:/ _/_       /::\\  \\   \n"
           "   /:/ /\\  \\     /:/\\:\\  \\      |:|:\\  \\     /:/ /\\__\\              /:/\\:\\  \\       \\:\\  \\      /:/ /\\__\\     /:/\\:\\__\\  \n"
           "  /:/ /::\\  \\   /:/ /::\\  \\   __|:|\\:\\  \\   /:/ /:/ _/_            /:/  \\:\\  \\       \\:\\  \\    /:/ /:/ _/_   /:/ /:/  /  \n"
           " /:/__\\/\\:\\__\\ /:/_/:/\\:\\__\\ /::::|_\\:\\__\\ /:/_/:/ /\\__\\          /:/__/ \\:\\__\\  ___  \\:\\__\\  /:/_/:/ /\\__\\ /:/_/:/__/___ \n"
           " \\:\\  \\ /:/  / \\:\\/:/  \\/__/ \\:\\~~\\  \\/__/ \\:\\/:/ /:/  /          \\:\\  \\ /:/  / /\\  \\ |:|  |  \\:\\/:/ /:/  / \\:\\/:::::/  / \n"
           "  \\:\\  /:/  /   \\::/__/       \\:\\  \\        \\::/_/:/  /            \\:\\  /:/  /  \\:\\  \\|:|  |   \\::/_/:/  /   \\::/~~/~~~~ \n"
           "   \\:\\/:/  /     \\:\\  \\        \\:\\  \\        \\:\\/:/  /              \\:\\/:/  /    \\:\\__|:|__|    \\:\\/:/  /     \\:\\~~\\ \n"
           "    \\::/  /       \\:\\__\\        \\:\\__\\        \\::/  /                \\::/  /      \\::::/__/      \\::/  /       \\:\\__\\ \n"
           "     \\/__/         \\/__/         \\/__/         \\/__/                  \\/__/        ~~~~           \\/__/         \\/__/   \n"
           "\n\n");
}
