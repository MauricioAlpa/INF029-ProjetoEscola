#include <stdio.h>
#include <Structs.h>
#include <stdlib.h>
#include <Functions.h>
#define VAGAS 50

static void menuAluno(Aluno *alunos, int vagas){
    printf("Módulo Aluno\n");
    int sairAluno = 0, qtdAlunos = 0;
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
                    if(vagas == VAGAS){
                        printf("Lista de Alunos cheia!\n");
                        break;
                    } 
                    vagas++;
                    Aluno *alunosNovo = realloc(alunos, vagas * sizeof(Aluno)); //Verifica se a realocação de memotira deu certo.
                    if(alunosNovo != NULL){
                        alunos = alunosNovo;
                        cadastroAlunos(alunos, qtdAlunos);
                        qtdAlunos++;
                    }else{
                        printf("Memória cheia.");
                        vagas--;
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
}