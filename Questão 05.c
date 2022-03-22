#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_VAGAS 5
#define MAX_TURMAS 2

/* NOME: ITALO HUGO DA SILVA ALVES
   TURMA: T01
   MATRÍCULA: 2020022286
*/

struct aluno{     //Definindo uma estrutura para os dados dos alunos
    int mat;
    char nome[81];
    float notas[2];
    float media;
};
typedef struct aluno Aluno;

struct turma{     //Definindo uma estrutura para os dados das turmas
    char id; 
    int vagas;
    Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;

void menu(){      //Função para o menu do programa
    printf("\n");
    printf("Menu: \n");
    printf("1 - Criar Turma\n");
    printf("2 - Salvar turmas\n");
    printf("3 - Carregar turmas\n");
    printf("4 - Listar turmas\n");
    printf("5 - Matricular aluno\n");
    printf("6 - Lancar notass\n");
    printf("7 - Listar alunos\n");
    printf("8 - Sair\n");
    printf("\nDigite  a opcao: \n");
}

Turma* cria_turma(char id){     //função para definir e alocar o tamanho do espaço para as turmas na memória
  Turma* t = (Turma*) malloc(sizeof(Turma));
  t->id = id;
  int i;
  for(i = 0; i < MAX_VAGAS; i++)     //laço para criar e iniciar as turmas e armazenar o valor NULL nelas
    t->alunos[i] = NULL;

  return t;
}

void CriarEnd_Posicoes(Turma** t){      //cria e aloca os endereços das posições das turmas
  int i;
  for(i = 0; i < MAX_TURMAS; i++){
    t[i] = (Turma*) malloc(sizeof(Turma*));
  }
}

void matricula_aluno(Turma* turma, int mat, char* nome){     //função que aloca e recebe a matricula e nota dos alunos em cada turma
 int i;
 for(i = 0; i < MAX_VAGAS; i++){
   if(turma->alunos[i] == NULL){
     turma->alunos[i] =(Aluno*) malloc(sizeof(Aluno));
     strcpy(turma->alunos[i]->nome, nome);
     turma->alunos[i]->mat = mat;
     turma->alunos[i]->notas[0] = 0.0;
     turma->alunos[i]->notas[1] = 0.0;
     turma->alunos[i]->notas[2] = 0.0;
     break;
   }
 }
}

float grade_aAluno(float n1, float n2, float n3){      //função responsável de fazer a media aritmetica das notas dos alunos
  return ((n1 + n2 + n3) / 3);
}

void lanca_notas(Turma* turma){      //função que imprime as notas dos alunos
  int i;
  for(i = 0; i < MAX_VAGAS; i++){
   if(turma->alunos[i] != NULL){
     printf("Matricula: %d  Aluno: %s\n",turma->alunos[i]->mat,turma->alunos[i]->nome);
     printf("Digite a nota 1: ");
     scanf(" %f",&turma->alunos[i]->notas[0]);
     printf("Digite a nota 2: ");
     scanf(" %f",&turma->alunos[i]->notas[1]);
     printf("Digite a nota 3: ");
     scanf(" %f",&turma->alunos[i]->notas[2]);
     turma->alunos[i]->media = grade_aAluno(turma->alunos[i]->notas[0],turma->alunos[i]->notas[1],turma->alunos[i]->notas[2]);
    }
  }
}

void imprime_alunos(Turma* turma){      //função que imprime os alunos e suas informações
  int i;
  for(i = 0; i < MAX_VAGAS; i++){
   if(turma->alunos[i] != NULL){
     printf("Matricula: %d\n",turma->alunos[i]->mat);
     printf("Nomes: %s\n",turma->alunos[i]->nome);
     printf("Media: %.1f\n",turma->alunos[i]->media);
     printf("\n");
    }
  }
}

void qtdDisponivelTurma(Turma* turma){      //exibe a quantidade de vagas em cada turma com um contador
  int cont = 0, i;
  for(i = 0; i < MAX_VAGAS;i++){
     if(turma->alunos[i] == NULL){
       cont++;
     }
  }
  turma->vagas = cont;
  cont = 0;
  printf("Turma %c – %d vagas disponíveis\n",turma->id,turma->vagas);
}

int main(void){

  Turma** t;      //chamando a struct com notação de ponteiro
  CriarEnd_Posicoes(t);
  int indiceTurmas = 0, op;

  printf("\nBem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidadesde\nmatricula, lancamento de notas e listagem de alunos\nAutor: Ada Lovelace  Versao: 1.0\n");
  menu();     //chamando a função menu
  scanf("%d",&op);
  while(op != 8){
  	
    if(op == 1){
      if(indiceTurmas < MAX_TURMAS){      //opção para chamar a função de criar uma nova turma
        char idTurma;
        printf("Criando nova turma...\n");
        scanf(" %c",&idTurma);
        t[indiceTurmas] = cria_turma(idTurma);
        printf("Turma %c criada com sucesso!\n",idTurma);
        indiceTurmas++;
      }
    }
    
    if(op == 4){      //opção para chamar a função que lista as turmas
      printf("Listando turmas...\n");
      int i;
      for(i = 0; i < MAX_TURMAS; i++){
        if(t[i] != NULL){
          qtdDisponivelTurma(t[i]);
        }
      }
    }

    if(op == 5){      //opção para matricular um aluno em uma das turmas
      int mat;
      char idTurma;
      char nomeAluno[20];
      printf("Matriculando aluno...\n");
      printf("Digite o id da turma: ");
      scanf(" %c",&idTurma);
      printf("Digite a matricula: ");
      scanf(" %d",&mat);
      printf("Digite o nome: ");
      scanf(" %[^\n]s",nomeAluno);
      if(t[0]->id != idTurma && t[1]->id != idTurma && t[2]->id != idTurma){
        printf("Turma Inexistente!\n");
      }else{
        int i;
        for(i = 0; i < MAX_TURMAS; i++){
          if(t[i]->id == idTurma){
            matricula_aluno(t[i],mat,nomeAluno);
          }
        } 
           printf("Aluno matriculado com sucesso!\n");     
        }
    }

    if(op == 6){      //opção para lançar as notas de uma turma
      char idTurma;
      printf("Lancando notas...\n");
      printf("Digite o id da turma: ");
      scanf(" %c",&idTurma);  
      fflush(stdin);
      if(t[0]->id != idTurma && t[1]->id != idTurma && t[3]->id != idTurma){
        printf("Turma inexistente!\n");
      }else{
        int i;
        for(i = 0; i < MAX_TURMAS; i++){
        if(t[i]->id == idTurma){
           lanca_notas(t[i]);
          }
        }
      }
    }

    if(op == 7){      //opção para listar os alunos de uma das turmas
      char idTurma;
      printf("Listando alunos...\n");
      printf("Digite o id da turma: ");
      scanf(" %c",&idTurma);
       if(t[0]->id != idTurma && t[1]->id != idTurma && t[3]->id != idTurma){
        printf("Turma inexistente!\n");
      }else{
        int i;
        for(i = 0; i < MAX_TURMAS; i++){
        if(t[i]->id == idTurma){
           imprime_alunos(t[i]);
         }
        }
      }
    }
    if(op < 0 || op > 8){     
      printf("opcao invalida!!\n");
    }
    menu();
    scanf("%d",&op);
  }
  printf("Obrigado por usar este programa!\n");
  
  return 0;
}