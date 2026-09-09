#include <stdio.h>
#include <Structs.h>
#include <stdlib.h>
#include <Functions.h>
#define VAGAS 50

static void menuAluno(Aluno **alunos, int *vagas, int *qtdAlunos){
    printf("Módulo Aluno\n");
    int sairAluno = 0;
    int opcaoAluno;
    while(!sairAluno) {
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n");
        scanf("%d", &opcaoAluno);

        switch(opcaoAluno) { 
            case 0: {
                sairAluno = 1;
                break;
            }
            case 1: {
                printf("Cadastrar Aluno\n");
                if(*vagas == VAGAS){
                    printf("Lista de Alunos cheia!\n");
                    break;
                } 
                (*vagas)++;
                Aluno *alunosNovo = realloc(*alunos, *vagas * sizeof(Aluno)); //Verifica se a realocação de memotira deu certo.
                if(alunosNovo != NULL){
                    *alunos = alunosNovo;
                    cadastroAlunos(*alunos, *qtdAlunos);
                    (*qtdAlunos)++;
                }else{
                    printf("Memória cheia.");
                    (*vagas)--;
                }
                break;    
            }
            default: {
                printf("Opcao Inválida");
            }

        }
    }
}