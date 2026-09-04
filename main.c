#include <stdio.h>
#include <Structs.h>
#include <Menus.h>
#include <stdlib.h>
#include <Functions.h>
#define VAGAS 50



int main() {

    int vagas = 1;
    Aluno *alunos = NULL;
    int sair = 0;
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
                menuAluno(alunos, vagas);
                break;
            }
        }
    }
    return 0;
}