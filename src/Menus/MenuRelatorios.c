#include <Headers/MenuRelatorio.h>

void menuRelatorios(Aluno *alunos, int qtdAlunos) {

    int sairRelatorios = 0;
    int opcaoRelatorio;

    while (!sairRelatorios) {

        printf("\n");
        printf("========================================\n");
        printf("              RELATÓRIOS\n");
        printf("========================================\n");
        printf("0 - Voltar\n");
        printf("1 - Listar Alunos\n");
        printf("2 - Listar Professores\n");
        printf("3 - Listar Disciplinas\n");
        printf("4 - Listar uma Disciplina\n");
        printf("5 - Listar Alunos por Sexo\n");
        printf("6 - Listar Alunos ordenados por Nome\n");
        printf("7 - Listar Alunos ordenados por Data de Nascimento\n");
        printf("8 - Listar Professores por Sexo\n");
        printf("9 - Listar Professores ordenados por Nome\n");
        printf("10 - Listar Professores ordenados por Data de Nascimento\n");
        printf("11 - Aniversariantes do Mês\n");
        printf("12 - Buscar Pessoa por Nome\n");
        printf("13 - Alunos matriculados em menos de 3 disciplinas\n");
        printf("14 - Disciplinas com mais de 40 alunos\n");
        printf("========================================\n");

        scanf("%d", &opcaoRelatorio);

        switch (opcaoRelatorio) {

            case 0:
                sairRelatorios = 1;
                break;

            case 1:
                printf("\n--- Listar Alunos ---\n");

                
                if(qtdAlunos == 0){
                    printf("\n");
                    printf("Lista vazia.\n");
                    printf("\n");
                }else{
                    listarAlunos(alunos, qtdAlunos);
                }

                break;

            case 2:
                printf("\n--- Listar Professores ---\n");
                break;

            case 3:
                printf("\n--- Listar Disciplinas ---\n");
                break;

            case 4:
                printf("\n--- Listar uma Disciplina ---\n");
                break;

            case 5:
                printf("\n--- Listar Alunos por Sexo ---\n");
                break;

            case 6:
                printf("\n--- Listar Alunos ordenados por Nome ---\n");
                break;

            case 7:
                printf("\n--- Listar Alunos ordenados por Data de Nascimento ---\n");
                break;

            case 8:
                printf("\n--- Listar Professores por Sexo ---\n");
                break;

            case 9:
                printf("\n--- Listar Professores ordenados por Nome ---\n");
                break;

            case 10:
                printf("\n--- Listar Professores ordenados por Data de Nascimento ---\n");
                break;

            case 11:
                printf("\n--- Aniversariantes do Mês ---\n");
                break;

            case 12:
                printf("\n--- Buscar Pessoa por Nome ---\n");
                break;

            case 13:
                printf("\n--- Alunos matriculados em menos de 3 disciplinas ---\n");
                break;

            case 14:
                printf("\n--- Disciplinas com mais de 40 alunos ---\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
}