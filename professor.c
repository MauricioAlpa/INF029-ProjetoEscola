#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_escola.h"
#define TAM_PROFESSOR 3

typedef struct {
    int matricula;
    char sexo;
    int ativo;
} Professor;

void mainProfessor();
int menuProfessor();
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
void atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

int mainProfessor() {
    Professor listaProfessor[TAM_PROFESSOR];
    int qtdProfessor = 0;
    int opcaoProfessor = 0;
    int sairProfessor = 0;

    while (!sairProfessor) {
        opcaoProfessor = menuProfessor();

        switch (opcaoProfessor) {
            case 0:
                sairProfessor = 1;
                break;
            case 1:
                qtdProfessor = cadastrarProfessor(listaProfessor, qtdProfessor);
                break;
            case 2:
                listarProfessor(listaProfessor, qtdProfessor);
                break;
            case 3:
                atualizarProfessor(listaProfessor, qtdProfessor);
                break;
            case 4:
                qtdProfessor = excluirProfessor(listaProfessor, qtdProfessor);
                break;
            default:
                printf("Opcao Inválida\n");
                break;
        }
    }
    return 0;
}

int menuProfessor() {
    int opcaoProfessor = 0;

    printf("\n--- MENU PROFESSOR ---\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professor\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    printf("Opção: ");
    scanf("%d", &opcaoProfessor);

    return opcaoProfessor;
}

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Cadastrar Professor\n");
    if (qtdProfessor == TAM_PROFESSOR) {
        printf("Lista de Professores cheia!\n");
    } else {
        printf("Digite a matrícula: ");
        int matricula;
        scanf("%d", &matricula);
        if (matricula < 0) {
            printf("Matricula Invalida\n");
        } else {
            listaProfessor[qtdProfessor].matricula = matricula;
            listaProfessor[qtdProfessor].ativo = 1;

            qtdProfessor++;
            printf("Cadastrado com sucesso!\n");
        }
    }
    return qtdProfessor;
}

void listarProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Listar Professor\n");
    if (qtdProfessor == 0) {
        printf("Lista Professor Vazia!\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (listaProfessor[i].ativo == 1) {
                printf("Matrícula: %d\n", listaProfessor[i].matricula);
            }
        }
    }
}

void atualizarProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Atualizar Professor\n");
    printf("Digite a matrícula: ");
    int matricula;
    int achou = 0;
    scanf("%d", &matricula);
    if (matricula < 0) {
        printf("Matricula Invalida\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (matricula == listaProfessor[i].matricula && listaProfessor[i].ativo) {
                printf("Digite a nova matrícula: ");
                int novamatricula;
                scanf("%d", &novamatricula);
                listaProfessor[i].matricula = novamatricula;

                achou = 1;
                break;
            }
        }
        if (achou) {
            printf("Professor atualizado com sucesso!\n");
        } else {
            printf("Matricula inexistente!\n");
        }
    }
}

int excluirProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("Excluir Professor\n");
    printf("Digite a matrícula: ");
    int matricula;
    int achou = 0;
    scanf("%d", &matricula);
    if (matricula < 0) {
        printf("Matricula Invalida\n");
    } else {
        for (int i = 0; i < qtdProfessor; i++) {
            if (matricula == listaProfessor[i].matricula) {
                for (int j = i; j < qtdProfessor - 1; j++) {
                    listaProfessor[j].matricula = listaProfessor[j + 1].matricula;
                    listaProfessor[j].sexo = listaProfessor[j + 1].sexo;
                    listaProfessor[j].ativo = listaProfessor[j + 1].ativo;
                }
                qtdProfessor--;
                achou = 1;
                break;
            }
        }
        if (achou) {
            printf("Professor excluido com sucesso!\n");
        } else {
            printf("Matricula inexistente!\n");
        }
    }
    return qtdProfessor;
}