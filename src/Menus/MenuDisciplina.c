#include <Headers/MenuDisciplina.h>

void menuDisciplina(Disciplina *disciplinas, int *qtdDisciplinas, Aluno *alunos, int qtdAlunos) {
    int opcaoDisciplina = 1;

    while (opcaoDisciplina) {
        printf("0 - Voltar\n");
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Inserir aluno em disciplina\n");
        printf("3 - Excluir aluno da disciplina\n");

        int resultado = scanf("%d", &opcaoDisciplina);
        flush_in(); 
        printf("\n");

        if (resultado == EOF) {
            return;
        }

        if (resultado != 1) {
            printf("Entrada inválida. Digite um número.\n\n");
            opcaoDisciplina = 1; 
            continue;
        }

        switch (opcaoDisciplina) {

            case 0: {
                printf("Voltando...\n");
                break;
            }

            case 1: {
                cadastrarDisciplina(disciplinas, qtdDisciplinas);
                break;
            }

            case 2: {
                inserirAlunoDisciplina(disciplinas, *qtdDisciplinas, alunos, qtdAlunos);
                break;
            }

            case 3: {
                excluirAlunoDisciplina(disciplinas, *qtdDisciplinas);
                break;
            }

            default: {
                printf("Opção inválida. Tente novamente.\n\n");
                break;
            }
        }
    }
}