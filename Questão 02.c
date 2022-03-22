#include <stdio.h>
#include <stdlib.h>
#define n 39            //definindo o tamanho para a variável n global

/* NOME: ITALO HUGO DA SILVA ALVES
   TURMA: T01
   MATRÍCULA: 2020022286
*/

int main (){
    //adicionando os valores inteiros referentes às letras do nome do aluno de acordo com a tabela ASCII
    int num [n] = {73, 84, 65, 76, 79, 32, 72, 85, 71, 79, 32, 68, 65, 32, 83, 73, 76, 86, 65, 32, 65, 76, 86, 69, 83};
    char * ih ;         //declarando a variável do tipo caractere para fazer a conversão de valores
    ih = ( char *) num;         //convertendo a variável inteira num em caractere e adicionando ela em na variável char ih
	int i;
	for (i = 0; i < n*4; ++i) {         //percorrendo o vetor pós-conversão em strings e imprimindo-o
    printf("%c", *(ih++));
    }
    printf("\n");
return 0;
}
