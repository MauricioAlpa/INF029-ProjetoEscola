#include <Headers/MenuAluno.h>
#define VAGAS 50

void menuAluno(Aluno *alunos, int *qtdAlunos){

    int sairAluno = 0;
    int opcaoAluno;

    while(!sairAluno) {
        printf("\n");
        printf("========================================\n");
        printf("              MÓDULO ALUNO\n");
        printf("========================================\n");
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Aluno\n");
        printf("2 - Listar Aluno\n");
        printf("3 - Atualizar Aluno\n");
        printf("4 - Excluir Aluno\n");
        printf("========================================\n");
        scanf("%d", &opcaoAluno);

        switch(opcaoAluno) { 

            case 0: {
                sairAluno = 1;
                break;
            }

            case 1: {

                printf("\n");
                printf("---Cadastrar Aluno---\n");
                printf("\n");

                if(*qtdAlunos == VAGAS){
                    printf("\n");
                    printf("Lista de Alunos cheia!\n");
                    printf("\n");
                    break;
                } 
            
                cadastrarAluno(alunos, qtdAlunos);

                (*qtdAlunos)++;
        
                break;    
            }

            case 2: {

                printf("\n");
                printf("---Listar Alunos---\n");
                printf("\n");

                if(*qtdAlunos == 0){
                    printf("\n");
                    printf("Lista vazia.\n");
                    printf("\n");
                }else{
                    listarAlunos(alunos, *qtdAlunos);
                }
                break;
            }

            case 3: {

                printf("\n");
                printf("---Atualizar Aluno---\n");
                printf("\n");

                bool result = atualizarAluno(alunos, *qtdAlunos);

                if(result){
                    printf("\n");
                    printf("Aluno atualizado com sucesso!\n");
                    printf("\n");

                }else{
                    printf("\n");
                    printf("Aluno não encontrado.\n");
                    printf("\n");
                }

                break;
            }

            case 4: {
                
                printf("\n");
                printf("---Excluir Aluno---");
                printf("\n");

                bool result = excluirAluno(alunos, qtdAlunos);

                if(result){
                    printf("\n");
                    printf("Aluno excluido com sucesso!\n");
                    printf("\n");

                }else{
                    printf("\n");
                    printf("Aluno não encontrado.\n");
                    printf("\n");
                }

                break;
            }

            default: {
                printf("\n");
                printf("Opcao Inválida\n");
                printf("\n");
                break;
            }

        }
    }
}