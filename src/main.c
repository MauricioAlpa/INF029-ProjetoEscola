#include <stdio.h>
#include <stdlib.h>
#include <Headers/Structs.h>
#include <Headers/MenuAluno.h>
#define VAGAS 50



int main() {

    int qtdAlunos = 0;
    Aluno *alunos = malloc(VAGAS * sizeof(Aluno));
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
                menuAluno(alunos, &qtdAlunos);
                break;
            }
        }
    }

    free(alunos);
    return 0;
}