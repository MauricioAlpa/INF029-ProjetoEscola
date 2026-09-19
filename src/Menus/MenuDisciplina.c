#include <Headers/MenuDisciplina.h>

#define MAX_Disciplinas 3
#define VAGAS_DISCIPLINA 5


 {
void menuDisciplina(Aluno *alunos, int qtdAlunos)
    int opcaoDisciplina = 1;

    while (opcaoDisciplina) {
        printf("0 - Voltar\n");
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Inserir aluno em disciplina\n");
        printf("3 - Excluir aluno da disciplina\n");

        int resultado = scanf("%d", &opcaoDisciplina);
        printf("\n");

        if (resultado != 1) {
            while (getchar() != '\n');
            printf("Entrada inválida. Digite um número.\n\n");
            continue;
        }

        switch (opcaoDisciplina) {

            case 0: {
                printf("Voltando...\n");
                break;
            }

            case 1: {
                if (qtdDisciplinas < MAX_Disciplinas) {

                    getchar(); 

                    printf("Nome da disciplina: ");
                    fgets(disciplinas[qtdDisciplinas].nome, 50, stdin);
                    disciplinas[qtdDisciplinas].nome[strcspn(disciplinas[qtdDisciplinas].nome, "\n")] = '\0';

                    printf("Código da disciplina: ");
                    fgets(disciplinas[qtdDisciplinas].codigo, 10, stdin);
                    disciplinas[qtdDisciplinas].codigo[strcspn(disciplinas[qtdDisciplinas].codigo, "\n")] = '\0';

                    
                    int repetido = 0;
                    for (int i = 0; i < qtdDisciplinas; i++) {
                        if (strcmp(disciplinas[i].codigo, disciplinas[qtdDisciplinas].codigo) == 0) {
                            repetido = 1;
                            break;
                        }
                    }

                    if (repetido) {
                        printf("Já existe uma disciplina com esse código.\n\n");
                        break;
                    }

                    printf("Semestre da disciplina: ");
                    fgets(disciplinas[qtdDisciplinas].semestre, 10, stdin);
                    disciplinas[qtdDisciplinas].semestre[strcspn(disciplinas[qtdDisciplinas].semestre, "\n")] = '\0';

                    printf("Professor da disciplina: ");
                    fgets(disciplinas[qtdDisciplinas].professor, 50, stdin);
                    disciplinas[qtdDisciplinas].professor[strcspn(disciplinas[qtdDisciplinas].professor, "\n")] = '\0';

                    disciplinas[qtdDisciplinas].qtdAlunos = 0;

                    printf("Disciplina cadastrada com sucesso!\n\n");

                    qtdDisciplinas++;
                }
                else {
                    printf("Limite de disciplinas atingido.\n\n");
                }
                break;
            }

            case 2: {
                char codigo[10];
                int matricula, indice = -1, existe = 0, ja_Matriculado = 0;

                getchar(); 
                printf("Código da disciplina: ");
                fgets(codigo, 10, stdin);
                codigo[strcspn(codigo, "\n")] = '\0';

                
                for (int i = 0; i < qtdDisciplinas; i++) {
                    if (strcmp(disciplinas[i].codigo, codigo) == 0) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    printf("Disciplina não encontrada.\n\n");
                    break;
                }

                if (disciplinas[indice].qtdAlunos == VAGAS_DISCIPLINA) {
                    printf("Disciplina sem vagas.\n\n");
                    break;
                }

                printf("Matrícula do aluno: ");
                if (scanf("%d", &matricula) != 1) {
                    while (getchar() != '\n');
                    printf("Matrícula inválida.\n\n");
                    break;
                }

                
                for (int i = 0; i < qtdAlunos; i++) {
                    if (alunos[i].matricula == matricula) {
                        existe = 1;
                        break;
                    }
                }

                if (!existe) {
                    printf("Matrícula não cadastrada.\n\n");
                    break;
                }

                
                for (int i = 0; i < disciplinas[indice].qtdAlunos; i++) {
                    if (disciplinas[indice].matriculas[i] == matricula) {
                        ja_Matriculado = 1;
                        break;
                    }
                }

                if (ja_Matriculado) {
                    printf("Aluno já matriculado nessa disciplina.\n\n");
                    break;
                }

                disciplinas[indice].matriculas[disciplinas[indice].qtdAlunos] = matricula;
                disciplinas[indice].qtdAlunos++;
                printf("Aluno inserido com sucesso!\n\n");
                break;
            }

            case 3: {
                char codigo[10];
                int matricula, indice = -1, posicao = -1;

                getchar(); 

                printf("Código da disciplina: ");
                fgets(codigo, 10, stdin);
                codigo[strcspn(codigo, "\n")] = '\0';

               
                for (int i = 0; i < qtdDisciplinas; i++) {
                    if (strcmp(disciplinas[i].codigo, codigo) == 0) {
                        indice = i;
                        break;
                    }
                }

                if (indice == -1) {
                    printf("Disciplina não encontrada.\n\n");
                    break;
                }

                printf("Matrícula do aluno: ");
                if (scanf("%d", &matricula) != 1) {
                    while (getchar() != '\n');
                    printf("Matrícula inválida.\n\n");
                    break;
                }

                
                for (int i = 0; i < disciplinas[indice].qtdAlunos; i++) {
                    if (disciplinas[indice].matriculas[i] == matricula) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    printf("Aluno não está matriculado nessa disciplina.\n\n");
                    break;
                }

                
                for (int i = posicao; i < disciplinas[indice].qtdAlunos - 1; i++) {
                    disciplinas[indice].matriculas[i] = disciplinas[indice].matriculas[i + 1];
                }
                disciplinas[indice].qtdAlunos--;
                printf("Aluno excluído da disciplina!\n\n");
                break;
            }

            
            default: {
                printf("Opção inválida. Tente novamente.\n\n");
                break;
            }
        }
    }
}