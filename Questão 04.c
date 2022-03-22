#include <stdio.h>
#include <stdlib.h>

/* NOME: ITALO HUGO DA SILVA ALVES
   TURMA: T01
   MATRÍCULA: 2020022286
*/

void criarMatriz (int linhas, int colunas, int **matriz){           //criando uma função para montar e imprimir a matriz 
    int i, j, cont, limitecolunas, limitelinhas, comp, x;
    cont = 0; 
    limitecolunas = colunas;            //declarando o valor do limite de linhas e colunas
    limitelinhas = linhas;
    comp = linhas * colunas;            //declarando o tamanho da matriz
    x = 1; 
    i = 0 ;

    //percorrendo a matriz e definindo seu escopo bidimensional epiral com laços de repetição para estruturar seu formato e sentido
    while (x<= comp){                                       
        for(j=cont;j < limitecolunas;j++ ){
            matriz[i][j] = x++;
        }
        for(i = cont + 1;i < limitelinhas;i++){
            matriz[i][j-1]= x++;
        }
        for (j = limitecolunas - 1;j > cont;j--){
            matriz[i-1][j-1]= x++;
        }
        for (i = limitelinhas - 1; i > cont + 1; i--){
             matriz[i-1][j]= x++;
        }
        cont++;
        limitecolunas --;
        limitelinhas--;
    }
    //imprimindo a matriz 
    for (i =0; i < linhas;i++){
        printf("\n");
            for (j = 0; j < colunas ; j++){
                printf("%d\t", matriz[i][j]);
        }
    }
    }

int main (){
    int linhas, colunas, **matriz;
    printf ("Digite a quantidade de linhas: \n");           
    scanf("%d", &linhas);           //lendo o tamanho das linhas da matriz
    printf("Digite a quantidades de colunas: \n");
    scanf("%d", &colunas);          //lendo o tamanho das colunas da matriz
    //alocando um espaço na memória para a matriz 
    matriz = (int **) calloc(linhas, sizeof(int*));         
        int i;
        for(i=0; i<linhas; i++){
        matriz[i] = (int*) calloc(colunas, sizeof(int));
        }
    criarMatriz(linhas, colunas, matriz);           //chamando a função com a matriz espiral
    return 0;
}
