#include <Headers/MenuAluno.h>
#include <Headers/FunctionsAluno.h>
#include <stdio.h>
#define VAGAS 50

void menuAluno(Aluno *alunos, int *qtdAlunos){

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
                if(*qtdAlunos == VAGAS){
                    printf("Lista de Alunos cheia!\n");
                    break;
                } 
            
                cadastrarAluno(alunos, qtdAlunos);

                (*qtdAlunos)++;
        
                break;    
            }

            default: {

                printf("Opcao Inválida\n");
                break;
            }

        }
    }
}