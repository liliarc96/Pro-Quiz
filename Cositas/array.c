#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
int main ( void )
{
static const char filename[] = "faceis.txt";
FILE *file = fopen ( filename, "r" );
int i, j;
char arra[21][1500];
char linhas[21]; /quantidade de linhas/
for(i=0; i<21; i++)
for(j=0; j<21; j++)
arra[j] = '?';
for(i=0; i<21; i++)
linhas = '?';
if ( file != NULL )
{
i=0;
while ( fgets ( linhas, sizeof linhas, file ) != NULL ) / le a linha */
{
strcpy(arra, linhas);
printf("array ----> %s ", &arra);
i++;
}
fclose ( file );
}
else
{
perror ( filename ); 
}
return 0;
}
