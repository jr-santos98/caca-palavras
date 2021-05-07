/*
 * Objetivo: O objetivo desse programa, é dado um arquivos de texto com palavras a serem buscadas e um caça palavras,
 * ele encontra as palavras e retorna a localização de onde elas começam.
 */
 #include <stdio.h>
 #include <stdlib.h>
 #define MAX_CHAR 30 //Limite da matriz contendo caça palavras
 #define QTDE 20 //Limite de palavras a serem encontradas

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

 int procura_letra(char palavra[], char matriz[][MAX_CHAR], int n_letra, int linha, int coluna, int valor) {
   char letra = palavra[n_letra];
   if (letra == '\n') return 1;
   if (linha >= 0 && coluna >= 0 && matriz[linha][coluna] != '\0' && matriz[linha][coluna] != '\n' && letra == matriz[linha][coluna]) {
     switch (valor) {
       case 1 :
       return procura_letra(palavra, matriz, n_letra+1, linha-1, coluna+1, valor);
       break;

       case 2 :
       return procura_letra(palavra, matriz, n_letra+1, linha, coluna+1, valor);
       break;

       case 3 :
       return procura_letra(palavra, matriz, n_letra+1, linha+1, coluna+1, valor);
       break;

       case 4 :
       return procura_letra(palavra, matriz, n_letra+1, linha+1, coluna, valor);
       break;

       case 5 :
       return procura_letra(palavra, matriz, n_letra+1, linha+1, coluna-1, valor);
       break;

       default :
       return 0;
     }
   } else return 0;
 }

 int * procura_palavra(char palavra[], char matriz[][MAX_CHAR]) {
   char letra = palavra[0];
   int *p_status, status[] = {0, 0, 0};
   p_status = status;

   for (int i = 0; matriz[i][0] != '\0'; i++) {
     for (int j = 0; matriz[i][j] != '\0' && matriz[i][j] != '\n'; j++) {
       if (letra == matriz[i][j]) {
         if (procura_letra(palavra, matriz, 1, i-1, j+1, 1)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, matriz, 1, i, j+1, 2)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, matriz, 1, i+1, j+1, 3)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, matriz, 1, i+1, j, 4)) {
           status[0] = 1;
           status[1] = i;
           status[2] = j;
           return p_status;
         } else if (procura_letra(palavra, matriz, 1, i+1, j-1, 5)) {
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

 void main() {
   FILE *arq;
   char palavras[QTDE][MAX_CHAR], cc_palavras[MAX_CHAR][MAX_CHAR];
   char *result;
   int *p_status;
   // Abre um arquivo TEXTO para LEITURA
   arq = fopen("palavras.txt", "rt");
   if (arq == NULL) {  // Se houve erro na abertura
     printf("Problemas na abertura do arquivo\n");
     return;
   }

   le_arquivo(arq, palavras, result);
   le_arquivo(arq, cc_palavras, result);
   for (int i = 0; palavras[i][0] != '\0'; i++) {
     p_status = procura_palavra(palavras[i], cc_palavras);
     if (p_status[0]) printf(" %s(%d, %d)\n", palavras[i],p_status[1]+1, p_status[2]+1);
     else printf(" %sNão foi encontrada\n", palavras[i],p_status[1], p_status[2]);
   }

   fclose(arq);
 }
