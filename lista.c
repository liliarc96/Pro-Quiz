int main()
{
    int num; // ESTE É O NUMERO QUE SERÁ LIDO DO ARQUIVO E PASSADO PARA A LISTA
    tlista *list; // ESTOU CRIANDO A LISTA, NADA DE NOVO
    list = NULL;
    FILE *arquivo; // REFERENCIA DO ARQUIVO, SEMPRE QUE FOR UTILIZAR O ARQUIVO
                   // SERA REFERENDIDO-SE PELO arquivo
    arquivo = fopen("c:\\arq.txt","r"); // O FOPEN ABRE O ARQUIVO, NO CASO
                                        // É PASSADO POR PARAMETRO O ENDEREÇO
                                        // DO ARQUIVO, E O "r" SIGNIFICA QUE
                                        // O ARQUIVO ESTÁ SENDO ABERTO APENAS
                                        // PARA LEITURA
     
    if (arquivo) // CASO NAO TENHA DADO ERRO AO ABRIR O ARQUIVO
       {
           do
             {
                fscanf(arquivo,"%d",&num ); // O FSCANF É IDENTICO AO SCANF QUE
                                            // TODOS CONHECEM, PORÉM ELE É
                                            // UTILIZADO PARA LER DADOS DE
                                            // ARQUIVOS, E É PASSADO COMO
                                            // PARAMETRO, O PROPRIO ARQUIVO
                                            // QUE ESTA SENDO LIDO
                list = lu_insereinicio(list, num); // INSERE O NUMERO NA LISTA
             }while(!feof(arquivo)); // ELE PERCORRERÁ TODAS AS LINHAS DO ARQUIVO
                                     // ENQUANTO O ARQUIVO NAO CHEGAR AO FIM
                                     // FEOF = END OF FILE
         }
          
    lu_exibelista(list); // EXIBE A LISTA
    fclose(arquivo); // FECHA O ARQUIVO
