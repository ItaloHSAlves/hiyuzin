#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/* NOME: ITALO HUGO DA SILVA ALVES
   TURMA: T01
   MATRÍCULA: 2020022286
*/

void palavraEmbaralhada(char* palavra) {      //função para embaralhar as strings
  if (strlen(palavra) > 3) {      //condição para verificar se o tamanho da string é maior que 3, afim de que, não embaralhe as palavras desse tamanho    
    int pos1, pos2;                             
    int limiteMaximo = strlen(palavra) - 2;     //declarando um limite maximo para a palavra e diminuindo dois valores dela que correspondem à primeira e ultima letra da string

    //adicionando o mod da equação com o limite maximo e adicinando +1 para que o resto não dê 0 nas variaveis pos1 e 2
    pos1 = (rand() % limiteMaximo) + 1;     
    pos2 = (rand() % limiteMaximo) + 1;     

    //trocando e embaralhando as strings de lugar com o auxílio de uma variável auxiliar
    int aux = palavra[pos1];      
    palavra[pos1] = palavra[pos2];      
    palavra[pos2] = aux;      
  }
}

int main(){

  srand(time(NULL));                                  

  FILE *arqEntrada = fopen("Q3_entrada.txt", "rt");       //abrinco um arquivo de entrada existente para leitura

  char** texto = (char**)malloc(sizeof(char)*10000);      //alocando o espaço na memória para a variável char, do tipo ponteiro, texto

  int scanResult;     //declarando as variáveis de subrtituição e contagem
  int cont = 0;
 
  do {
    char* palavra = (char*)malloc(100);
    scanResult = fscanf(arqEntrada, "%s", palavra);     //passando o conteúdo do arquivo para a variável substituta
    texto[cont] = palavra;      //passando o conteúdo da variável palavra para a variável texto para manipular ela posteriormente
    cont++;
  }while (scanResult != EOF);    
  fclose(arqEntrada);     //fechando o arquivo de entrada

  FILE *arqSaida = fopen("Q3_saida.txt", "w+");     //abrindo um arquivo de leitura/escrita para o texto de saída

  for (int i = 0; i < cont; i++) {      //laço para percorrer os vetores e montar as strings embaralhadas
    palavraEmbaralhada(texto[i]);     //chamando a função com a palavra embaralhada
    texto[i][strlen(texto[i])] = ' ';   //adicionando um espaço entre as strings
    fputs(texto[i], arqSaida);      //escrevendo as strings no arquivo de saída
  }
  fclose(arqSaida);     //fechando o arquivo de saída
  return 0;
}

