/*
 * Objetivo: O objetivo desse programa, é criar uma aplicação multi threds para encontrar palavras em um caça-palavras.
 * Descrição: Dado um arquivo de texto contendo palavras a serem encontradas e um caça-palavras, o programa
 * cria uma thread para buscar cada palavras
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>
 #define MAX_CHAR 30 //Limite da matriz contendo caça palavras
 #define QTDE 20 //Limite de palavras a serem encontradas
 char cc_palavras[MAX_CHAR][MAX_CHAR];

 // Lê arquivo e salva em uma matriz a sequencia de palavras
 void le_arquivo(FILE * arq, char matriz[][MAX_CHAR], char * result) {
   for (int i = 0; !feof(arq) != 0; i++) {
     // Lê uma linha (inclusive com o '\n')
     result = fgets(matriz[i], MAX_CHAR, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
     if (matriz[i][0] == '-') {
       matriz[i][0] = '\0';
       return;
     }
   }
 }

 int procura_letra(char palavra[], int n_letra, int linha, int coluna, int valor) {
   char letra = palavra[n_letra];
   if (letra == '\n') return 1;
   if (linha >= 0 && coluna >= 0 && cc_palavras[linha][coluna] != '\0' && cc_palavras[linha][coluna] != '\n' && letra == cc_palavras[linha][coluna]) {
     switch (valor) {
       case 1 :
       return procura_letra(palavra, n_letra+1, linha-1, coluna+1, valor);
       break;

       case 2 :
       return procura_letra(palavra, n_letra+1, linha, coluna+1, valor);
       break;

       case 3 :
       return procura_letra(palavra, n_letra+1, linha+1, coluna+1, valor);
       break;

       case 4 :
       return procura_letra(palavra, n_letra+1, linha+1, coluna, valor);
       break;

       case 5 :
       return procura_letra(palavra, n_letra+1, linha+1, coluna-1, valor);
       break;

       default :
       return 0;
     }
   } else return 0;
 }

 int * procura_palavra(char palavra[]) {
   char letra = palavra[0];
   int *p_status, status[] = {0, 0, 0};
   p_status = status;

   for (int i = 0; cc_palavras[i][0] != '\0'; i++) {
     for (int j = 0; cc_palavras[i][j] != '\0' && cc_palavras[i][j] != '\n'; j++) {
       if (letra == cc_palavras[i][j]) {
         if (procura_letra(palavra, 1, i-1, j+1, 1)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, 1, i, j+1, 2)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, 1, i+1, j+1, 3)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, 1, i+1, j, 4)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, 1, i+1, j-1, 5)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         }
       }
     }
   }
   return p_status;
 }

 void* f_thread(char palavra[]) {
   int *p_status;
   p_status = procura_palavra(palavra);
   if (p_status[0]) printf(" %s(%d, %d)\n", palavra,p_status[1]+1, p_status[2]+1);
   else printf(" %sNão foi encontrada\n", palavra);
   return NULL;
 }

 void main() {
   FILE *arq;
   char palavras[QTDE][MAX_CHAR];
   char *result;
   pthread_t thr[QTDE];
   //int *p_status;

   // Abre um arquivo TEXTO para LEITURA
   arq = fopen("palavras.txt", "rt");
   if (arq == NULL) {  // Se houve erro na abertura
     printf("Problemas na abertura do arquivo\n");
     return;
   }

   le_arquivo(arq, palavras, result);
   le_arquivo(arq, cc_palavras, result);

   for (int i = 0; palavras[i][0] != '\0'; i++) pthread_create(&thr[i], NULL, f_thread, palavras[i]);
   for (int i = 0; palavras[i][0] != '\0'; i++) pthread_join(thr[i], NULL);

   fclose(arq);

   return;
 }
