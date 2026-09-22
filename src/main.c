#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <Headers/Structs.h>
#include <Headers/MenuAluno.h>
#include <Headers/MenuDisciplina.h>
#include <Headers/MenuRelatorio.h>

#define VAGAS 50
#define TAM_PROFESSOR 50


int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); // acentos saem certos no terminal do Windows
    SetConsoleCP(CP_UTF8);       // e a digitação com acento também
    #endif

    int qtdAlunos = 0;
    Aluno *alunos = malloc(VAGAS * sizeof(Aluno));
    int sair = 0;
    int opcao;

    int qtdProfessor = 0;
    Professor listaProfessor[TAM_PROFESSOR];


    Disciplina *disciplinas = malloc(MAX_Disciplinas * sizeof(Disciplina));
    int qtdDisciplinas = 0;



    while(!sair) {
        printf("\n");
        printf("========================================\n");
        printf("              PROJETO ESCOLA\n");
        printf("========================================\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        printf("4 - Relatórios\n");
        printf("========================================\n");

        scanf("%d", &opcao);

        switch(opcao) { 
            case 0: 
                sair = 1;
                break;        
            
            case 1: 
                menuAluno(alunos, &qtdAlunos);
                break;
            
            case 2:

                break;

            case 3:
                menuDisciplina(disciplinas, &qtdDisciplinas, alunos, qtdAlunos);
                break;

            case 4:
                menuRelatorios(alunos, qtdAlunos, disciplinas, qtdDisciplinas);
                break;
        }
    }

    free(alunos);
    free(disciplinas);
    return 0;
}