%%writefile trabalhoed.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ALUNOS 50

typedef struct{
    char nome[50];
       float  nt[3];
       int ativo;
}Aluno;

Aluno alunos[MAX_ALUNOS];

void menu();
void cadastro();
void remover();
void reprovados();
void pesquisar();
void listar();
void aprovados();


int main(int argc, char const *argv[]){
    
    menu();
    return 0;
}

void menu(){
    int resp;
    do{
      printf("\nCadastrar aluno [ 1 ] |\tExcluir aluno [ 2 ] |\tListar Alunos [ 3 ]");
      printf("\nAlunos Aprovados [ 4 ] | Alunos Reprovados [ 5 ]\n");
      scanf("%d",&resp);
      getchar();
      switch(resp){
          case 1:
              cadastro();
          break;
          case 3:
            listar();
           break;
          case 4:
            aprovados();
           break;     
          case 5:
            reprovados();
          break;
      }
       
    }while(resp!=0);
}

void cadastro(){
    char nome[50];
       float  nt[3];
       int resp;
       do{
          printf("\nNome: ");
          fgets(nome,sizeof(nome),stdin);

          printf("\nNota 1: ");
          scanf("%f",&nt[0]);

          printf("\nNota 2: ");
          scanf("%f",&nt[1]);

          printf("\nNota 3: ");
          scanf("%f",&nt[2]);
          for(int i=0; i< MAX_ALUNOS;++i){
              if(alunos[i].ativo==0){
                  alunos[i].nt[0] = nt[0];
                  alunos[i].nt[1] = nt[1];
                  alunos[i].nt[2] = nt[2];
                  strcpy(alunos[i].nome,nome);
                  alunos[i].ativo=1;
                  break;
              }
          }
          printf("Continuar: SIM[ 1 ] | [ 0 ]NAO: ");
          scanf("%d",&resp);
       }while(resp!=0);
}

void listar(){
    printf("\nLISTA DE ALUNOS\n");
    for(int i = 0; i < MAX_ALUNOS;++i){
          if(alunos[i].ativo==1){
            printf("Nome: %s\n", alunos[i].nome);
            printf("NP1:  %0.2f\n", alunos[i].nt[0]);
            printf("NP2:  %0.2f\n", alunos[i].nt[1]);
            printf("Trabalho:  %0.2f\n", alunos[i].nt[2]);
            printf("----------------");
        }
        

    }
}

void reprovados(){
    printf("\nLISTA DE ALUNOS REPROVADOS\n");
    for(int i = 0; i < MAX_ALUNOS;++i){
    float m;
    m = 0;
    m = alunos[i].nt[0] + alunos[i].nt[1] + alunos[i].nt[2];
    m = m/3;
    if(m < 7.0){
        
          if(alunos[i].ativo==1){
            printf("Nome: %s\n", alunos[i].nome);
            printf("NP1:  %0.2f\n", alunos[i].nt[0]);
            printf("NP2:  %0.2f\n", alunos[i].nt[1]);
            printf("Trabalho:  %0.2f\n", alunos[i].nt[2]);
            printf("\n----------------\n");
        }
    }
    }
}

void aprovados(){
    printf("ALUNOS APROVADOS\n");
    for(int i = 0; i < MAX_ALUNOS;++i){
    float m;
    m = 0;
    m = alunos[i].nt[0] + alunos[i].nt[1] + alunos[i].nt[2];
    m = m/3;
    if(m > 7.0){
        
          if(alunos[i].ativo==1){
            printf("Nome: %s\n", alunos[i].nome);
            printf("NP1:  %0.2f\n", alunos[i].nt[0]);
            printf("NP2:  %0.2f\n", alunos[i].nt[1]);
            printf("Trabalho:  %0.2f\n", alunos[i].nt[2]);
            printf("\n----------------\n");
        }
    }
    }
}

void pesquisar(){
    //sera completado
}