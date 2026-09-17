#include <Headers/MenuAluno.h>
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

                printf("---Cadastrar Aluno---\n");
                printf("\n");

                if(*qtdAlunos == VAGAS){
                    printf("Lista de Alunos cheia!\n");
                    break;
                } 
            
                cadastrarAluno(alunos, qtdAlunos);

                (*qtdAlunos)++;
        
                break;    
            }

            case 2: {

                printf("---Listar Alunos---\n");
                printf("\n");

                if(*qtdAlunos == 0){
                    printf("Lista vazia.\n");
                }else{
                    listarAlunos(alunos, *qtdAlunos);
                }
                break;
            }

            case 3: {

                printf("---Atualizar Aluno---\n");
                printf("\n");

                bool result = atualizarAluno(alunos, *qtdAlunos);

                if(result){

                    printf("Aluno atualizado com sucesso!\n");

                }else{

                    printf("Aluno não encontrado.\n");
                }

                break;
            }

            case 4: {
                
                printf("---Excluir Aluno---");
                printf("\n");

                bool result = excluirAluno(alunos, qtdAlunos);

                if(result){

                    printf("Aluno excluido com sucesso!\n");

                }else{
                    printf("Aluno não encontrado.\n");
                }

                break;
            }

            default: {

                printf("Opcao Inválida\n");
                break;
            }

        }
    }
}