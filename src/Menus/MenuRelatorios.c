#include <Headers/MenuRelatorio.h>

void menuRelatorios(Aluno *alunos, int qtdAlunos, Disciplina *disciplinas, int qtdDisciplinas, Professor listaProfessor[], int qtdProfessor) {

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

        int resultado = scanf("%d", &opcaoRelatorio);
        flush_in(); // descarta o resto da linha (inclusive o \n) para as funções que usam fgets começarem com o buffer limpo

        if (resultado == EOF) {
            return;
        }

        if (resultado != 1) {
            printf("\nOpção inválida!\n");
            continue;
        }

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
                if (qtdProfessor == 0) {
                    printf("Nenhum professor cadastrado!\n");
                } else {
                    listarProfessor(listaProfessor, qtdProfessor);
                }
                break;

            case 3:
                printf("\n--- Listar Disciplinas ---\n");

                 if (qtdDisciplinas == 0) {
                    printf("Nenhuma disciplina cadastrada.\n\n");
                }
                else {
                    listarTodasDisciplinas(disciplinas, qtdDisciplinas);
                }
                
                break;

            case 4:
                printf("\n--- Listar uma Disciplina ---\n");

                if (qtdDisciplinas == 0) {
                    printf("Nenhuma disciplina cadastrada.\n\n");
                }
                else {
                    listarUmaDisciplina(disciplinas, qtdDisciplinas, alunos, qtdAlunos);
                }

                break;

            case 5: {
                char sexo;
                bool result = false;
                
                do
                {
                    printf("\n--- Listar Alunos por Gênero ---\n");

                    printf("\n");
                    printf("Escolha o filtro por gênero(M/F): \n");
                    scanf(" %c", &sexo);
                    

                    sexo = toLowerChar(sexo);
                    result = validaSexo(sexo);
                
                    if(result){
                        listarAlunoSexo(alunos, qtdAlunos, sexo);
                    }else {
                        printf("\nDigite um gênero válido(M/F)\n");
                        printf(" ");
                    }

                } while (!result);
                

                break;
            }

            case 6:
                printf("\n--- Alunos ordenados por Nome ---\n");

                if (qtdAlunos == 0) {
                    printf("Lista vazia.\n");
                } else {
                    ordenarAlunosPorNome(alunos, qtdAlunos);
                }

                break;
                
            case 7:
                printf("\n--- Listar Alunos ordenados por Data de Nascimento ---\n");
                break;

            case 8:
                if (qtdProfessor == 0) {
                    printf("Nenhum professor cadastrado!\n");
                } else {
                    bool result = false;
                    char sexo;

                    do
                    {
                        printf("\n--- Listar Professores por Sexo ---\n");

                        printf("\n");
                        printf("Escolha o filtro por gênero(M/F): \n");
                        scanf(" %c", &sexo);
                        

                        sexo = toLowerChar(sexo);
                        result = validaSexo(sexo);
                    
                        if(result){
                            listarProfessorSexo(listaProfessor, qtdProfessor, sexo);
                        }else {
                            printf("\nDigite um gênero válido(M/F)\n");
                            printf(" ");
                        }

                    } while (!result);
                        
                }
                break;

            case 9:
                printf("\n--- Listar Professores ordenados por Nome ---\n");
                if (qtdProfessor == 0) {
                    printf("Nenhum professor cadastrado!\n");
                } else {
                    ordenarProfessoresPorNome(listaProfessor, qtdProfessor);
                }
                break;

            case 10:
                printf("\n--- Listar Professores ordenados por Data de Nascimento ---\n");
                if (qtdProfessor == 0) {
                    printf("Nenhum professor cadastrado!\n");
                } else {
                    ordenarProfessoresPorDataNascimento(listaProfessor, qtdProfessor);
                }
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

                if (qtdDisciplinas == 0) {
                    printf("Nenhuma disciplina cadastrada.\n\n");
                }
                else {
                    listarDisciplinasMaisDe40Alunos(disciplinas, qtdDisciplinas);
                }

                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
}