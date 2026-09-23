#include <stdio.h>
#include <stdlib.h>
#include <Headers/Structs.h>
#include <Headers/MenuProfessor.h>

void menuProfessor(Professor listaProfessor[], int *qtdProfessor) {
    int sairProfessor = 0;
    int opcaoProfessor;
    
    while (!sairProfessor) {
        printf("\n");
        printf("========================================\n");
        printf("              MÓDULO PROFESSOR \n");
        printf("========================================\n");
        printf("0 - Voltar\n");
        printf("1 - Cadastrar Professor\n");
        printf("2 - Listar Professor\n");
        printf("3 - Atualizar Professor\n");
        printf("4 - Excluir Professor\n");
        printf("========================================\n");
        printf("Opção: ");
        scanf("%d", &opcaoProfessor);

        switch (opcaoProfessor) {
        case 0:
            sairProfessor = 1;
            break;
        case 1:
            *qtdProfessor = cadastrarProfessor(listaProfessor, *qtdProfessor);
            break;
        case 2:
            listarProfessor(listaProfessor, *qtdProfessor);
            break;
        case 3:
            atualizarProfessor(listaProfessor, *qtdProfessor);
            break;
        case 4:
            *qtdProfessor = excluirProfessor(listaProfessor, *qtdProfessor);
            break;
        default:
            printf("Opção Inválida\n");
            break;
        }
    }
}