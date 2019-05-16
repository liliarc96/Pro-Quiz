#include <stdio.h>
#include <stdlib.h>
#include<string.h>

    int main(void) {
    int i=0;
    int numperguntas=10;
    char* perguntas[10];
    char linhas[21];

    FILE *file;
    file = fopen("faceis.txt", "r");

   while(fgets(linhas, sizeof linhas, file)!=NULL) {
   
    printf("%s", linhas);
    //
    perguntas[i]=malloc(sizeof(linhas));
    strcpy(perguntas[i],linhas);
    i++;
   //
    numperguntas++;
  }

  //
  for (int j=0 ; j<numperguntas+1; j++) {
  printf("\n%s", perguntas[j]);
 }

 fclose(file);
 return 0;
}
