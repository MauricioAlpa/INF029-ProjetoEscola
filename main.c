#include <stdio.h>
#define TAM_ALUNO 3

typedef struct aln {
    int matricula;
    char sexo;
    int ativo;
} Aluno;

int main() {

    Aluno listaAluno[TAM_ALUNO];
    int sair = 0;
    int qtdAluno = 0;
    int opcao;

    while(!sair) {
        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf("%d", &opcao);

        switch(opcao) { 
            case 0: {
                sair = 1;
                break;        
            }
            case 1: {
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
                            if(qtdAluno == TAM_ALUNO){
                                printf("Lista de Alunos cheia!\n");
                            } else { 
                                printf("Digite a mátricula: ");
                                int matricula;
                                scanf("%d", &matricula);
                                if(matricula < 0) { 
                                    printf("Matricula Invalida\n");
                                } else {
                                listaAluno[qtdAluno].matricula = matricula;
                                listaAluno[qtdAluno].ativo = 1;

                                qtdAluno++;
                                printf("Cadastrado com sucesso!\n");
                                }
                            }
                            
                            break;
                        }
                        case 2: {
                            printf("Listar Aluno\n");
                            if(qtdAluno == 0) { 
                                printf("Lista Aluno Vazia!\n");
                            } else {
                                for(int i = 0; i < qtdAluno ; i++){
                                    if(listaAluno[i].ativo == 1) {
                                        printf("Matrícula: %d\n", listaAluno[i].matricula);
                                    }
                                }
                            }
                            break;
                        }
                        case 3: {
                            printf("Atualizar Aluno\n");
                            printf("Digite a mátricula: ");
                            int matricula;
                            int achou = 0;
                            scanf("%d", &matricula);
                            if(matricula < 0) { 
                                printf("Matricula Invalida\n");
                            } else {
                                 for(int i = 0; i < qtdAluno; i++){
                                    if(matricula == listaAluno[i].matricula && listaAluno[i].ativo) {
                                        printf("Digite a nova mátricula: ");
                                        int novamatricula;
                                        scanf("%d", &novamatricula);
                                        listaAluno[i].matricula = novamatricula;
                                            
                                        achou = 1;
                                        break;
                                    }
                                }
                                if(achou) {
                                    printf("Aluno atualizado com sucesso!\n");
                                } else {
                                    printf("Matricula inexistente!\n");
                                }    
                            }
                            break;
                        }
                        case 4: {
                            printf("Excluir Aluno\n");
                            printf("Digite a mátricula: ");
                            int matricula;
                            int achou = 0;
                            scanf("%d", &matricula);
                            if(matricula < 0) { 
                                printf("Matricula Invalida\n");
                            } else {
                                 for(int i = 0; i < qtdAluno; i++){
                                    if(matricula == listaAluno[i].matricula) {

                                        for(int j = i; j < qtdAluno - 1; j++) {
                                            listaAluno[j].matricula = listaAluno[j + 1].matricula;
                                            listaAluno[j].sexo = listaAluno[j + 1].sexo;
                                            listaAluno[j].ativo = listaAluno[j + 1].ativo;
                                        }
                                        qtdAluno--;
                                        achou = 1;
                                        break;
                                    }
                                }
                                if(achou) {
                                    printf("Aluno excluido com sucesso!\n");
                                } else {
                                    printf("Matricula inexistente!\n");
                                }    
                            }
                            break;
                        }
                        default: {
                            printf("Opcao Inválida");
                        }

                    }
                }
                break;        
            }
            case 2: {
                printf("Modulo Professor\n");
                break;        
            }
            case 3: {
                printf("Modulo Disciplina\n");
                break;        
            }
            default: {
                printf("Opção Inválida\n");
            }

        }
        
    }
    return 0;
}