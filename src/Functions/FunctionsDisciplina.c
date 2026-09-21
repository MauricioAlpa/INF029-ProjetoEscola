#include <Headers/Structs.h>
#include <Headers/FunctionsDisciplina.h>




void listarTodasDisciplinas(Disciplina *disciplinas, int qtdDisciplinas) {

    for (int i = 0; i < qtdDisciplinas; i++) {
        printf("Nome: %s | Codigo: %s | Semestre: %s | Professor: %s\n",
               disciplinas[i].nome, disciplinas[i].codigo,
               disciplinas[i].semestre, disciplinas[i].professor);
    }
    printf("\n");
}

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas) {
    if (*qtdDisciplinas >= MAX_Disciplinas) {
        printf("Limite de disciplinas atingido.\n\n");
        return;
    }

    //Variaveis para continuar pegando entrada do user ate estarem certas
    bool validadoNome = false, validadoCodigo = false, validadoSemestre = false, validadoProfessor = false;

    while (!validadoNome) {
        char nome[50]; //variavel temporaria para verificação do nome.

        printf("Nome da disciplina: ");
        if (fgets(nome, 50, stdin) == NULL) {
            return; //fim da entrada (EOF), evita ficar preso no laço
        }
        if (strchr(nome, '\n') == NULL) {
            flush_in(); //o texto passou do tamanho: descarta o resto para não atrapalhar o próximo fgets
        }
        nome[strcspn(nome, "\n")] = '\0';
        toLowerCase(nome); //padroniza em minusculo

        if (validaNomeDisciplina(nome)) {
            retiraEspaco(nome); //retira espaco no final e no comeco do nome
            strcpy(disciplinas[*qtdDisciplinas].nome, nome);
            validadoNome = true;
        } else {
            printf("\n");
            printf("Nome inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    while (!validadoCodigo) {
        char codigo[10]; //variavel temporaria para verificação do código.

        printf("Código da disciplina: ");
        if (fgets(codigo, 10, stdin) == NULL) {
            return;
        }
        if (strchr(codigo, '\n') == NULL) {
            flush_in();
        }
        codigo[strcspn(codigo, "\n")] = '\0';
        toLowerCase(codigo); //padroniza em minusculo

        if (validaCodigoDisciplina(codigo)) {
            retiraEspaco(codigo);
            strcpy(disciplinas[*qtdDisciplinas].codigo, codigo);
            validadoCodigo = true;
        } else {
            printf("\n");
            printf("Código inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    int repetido = 0;
    for (int i = 0; i < *qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigo, disciplinas[*qtdDisciplinas].codigo) == 0) {
            repetido = 1;
            break;
        }
    }

    if (repetido) {
        printf("Já existe uma disciplina com esse código.\n\n");
        return;
    }

    while (!validadoSemestre) {
        char semestre[10]; //variavel temporaria para verificação do semestre.

        printf("Semestre da disciplina: ");
        if (fgets(semestre, 10, stdin) == NULL) {
            return;
        }
        if (strchr(semestre, '\n') == NULL) {
            flush_in();
        }
        semestre[strcspn(semestre, "\n")] = '\0';
        toLowerCase(semestre); //padroniza em minusculo

        if (validaSemestreDisciplina(semestre)) {
            retiraEspaco(semestre);
            strcpy(disciplinas[*qtdDisciplinas].semestre, semestre);
            validadoSemestre = true;
        } else {
            printf("\n");
            printf("Semestre inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    while (!validadoProfessor) {
        char professor[50]; //variavel temporaria para verificação do professor.

        printf("Professor da disciplina: ");
        if (fgets(professor, 50, stdin) == NULL) {
            return;
        }
        if (strchr(professor, '\n') == NULL) {
            flush_in();
        }
        professor[strcspn(professor, "\n")] = '\0';
        toLowerCase(professor); //padroniza em minusculo

        if (validaProfessorDisciplina(professor)) {
            retiraEspaco(professor);
            strcpy(disciplinas[*qtdDisciplinas].professor, professor);
            validadoProfessor = true;
        } else {
            printf("\n");
            printf("Professor inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    disciplinas[*qtdDisciplinas].qtdAlunos = 0;

    printf("Disciplina cadastrada com sucesso!\n\n");

    (*qtdDisciplinas)++;
}

void atualizarDisciplina(Disciplina *disciplinas, int qtdDisciplinas) {
    char codigo[10];
    int indice = -1;

    printf("Código da disciplina a ser atualizada: ");
    if (fgets(codigo, 10, stdin) == NULL) {
        return; 
    }
    if (strchr(codigo, '\n') == NULL) {
        flush_in(); 
    }
    codigo[strcspn(codigo, "\n")] = '\0';
    toLowerCase(codigo); 

    if (!validaCodigoDisciplina(codigo)) {
        printf("Código inválido: não pode ficar em branco.\n\n");
        return;
    }
    retiraEspaco(codigo);

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Disciplina não encontrada.\n\n");
        return;
    }

    printf("\n");
    printf("Dados atuais -> Nome: %s | Semestre: %s | Professor: %s\n",
           disciplinas[indice].nome, disciplinas[indice].semestre, disciplinas[indice].professor);
    printf("Digite os novos dados (o código não pode ser alterado).\n\n");

    //Variaveis temporarias: só vão para a disciplina no final, quando os 3 campos estiverem válidos
    char nome[50], semestre[10], professor[50];
    bool validadoNome = false, validadoSemestre = false, validadoProfessor = false;

    while (!validadoNome) {
        printf("Novo nome da disciplina: ");
        if (fgets(nome, 50, stdin) == NULL) {
            return;
        }
        if (strchr(nome, '\n') == NULL) {
            flush_in();
        }
        nome[strcspn(nome, "\n")] = '\0';
        toLowerCase(nome);

        if (validaNomeDisciplina(nome)) {
            retiraEspaco(nome);
            validadoNome = true;
        } else {
            printf("\n");
            printf("Nome inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    while (!validadoSemestre) {
        printf("Novo semestre da disciplina: ");
        if (fgets(semestre, 10, stdin) == NULL) {
            return;
        }
        if (strchr(semestre, '\n') == NULL) {
            flush_in();
        }
        semestre[strcspn(semestre, "\n")] = '\0';
        toLowerCase(semestre);

        if (validaSemestreDisciplina(semestre)) {
            retiraEspaco(semestre);
            validadoSemestre = true;
        } else {
            printf("\n");
            printf("Semestre inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    while (!validadoProfessor) {
        printf("Novo professor da disciplina: ");
        if (fgets(professor, 50, stdin) == NULL) {
            return;
        }
        if (strchr(professor, '\n') == NULL) {
            flush_in();
        }
        professor[strcspn(professor, "\n")] = '\0';
        toLowerCase(professor);

        if (validaProfessorDisciplina(professor)) {
            retiraEspaco(professor);
            validadoProfessor = true;
        } else {
            printf("\n");
            printf("Professor inválido: não pode ficar em branco.\n");
            printf("\n");
        }
    }

    strcpy(disciplinas[indice].nome, nome);
    strcpy(disciplinas[indice].semestre, semestre);
    strcpy(disciplinas[indice].professor, professor);

    printf("\n--- DISCIPLINA %s ATUALIZADA ---\n", disciplinas[indice].codigo);
    printf("Nome: %s | Codigo: %s | Semestre: %s | Professor: %s\n\n",
           disciplinas[indice].nome, disciplinas[indice].codigo,
           disciplinas[indice].semestre, disciplinas[indice].professor);
}

void excluirDisciplina(Disciplina *disciplinas, int *qtdDisciplinas) {
    char codigo[10];
    int indice = -1;

    printf("Código da disciplina a ser excluída: ");
    if (fgets(codigo, 10, stdin) == NULL) {
        return; 
    }
    if (strchr(codigo, '\n') == NULL) {
        flush_in();
    }
    codigo[strcspn(codigo, "\n")] = '\0';
    toLowerCase(codigo); 

    if (!validaCodigoDisciplina(codigo)) {
        printf("Código inválido: não pode ficar em branco.\n\n");
        return;
    }
    retiraEspaco(codigo);

    for (int i = 0; i < *qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Disciplina não encontrada.\n\n");
        return;
    }

    int alunosMatriculados = disciplinas[indice].qtdAlunos;

    
    for (int i = indice; i < *qtdDisciplinas - 1; i++) {
        disciplinas[i] = disciplinas[i + 1];
    }
    (*qtdDisciplinas)--;

    printf("Disciplina excluída com sucesso!\n");
    if (alunosMatriculados > 0) {
        printf("%d aluno(s) matriculado(s) nela foram desvinculados.\n", alunosMatriculados);
    }
    printf("\n");
}

void inserirAlunoDisciplina(Disciplina *disciplinas, int qtdDisciplinas, Aluno *alunos, int qtdAlunos) {
    char codigo[10];
    int matricula, indice = -1, existe = 0, ja_Matriculado = 0;

    printf("Código da disciplina: ");
    if (fgets(codigo, 10, stdin) == NULL) {
        return; 
    }
    if (strchr(codigo, '\n') == NULL) {
        flush_in(); 
    }
    codigo[strcspn(codigo, "\n")] = '\0';
    toLowerCase(codigo); 

    if (!validaCodigoDisciplina(codigo)) {
        printf("Código inválido: não pode ficar em branco.\n\n");
        return;
    }
    retiraEspaco(codigo);

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Disciplina não encontrada.\n\n");
        return;
    }

    if (disciplinas[indice].qtdAlunos >= MAX_Disciplinas) {
        printf("Disciplina sem vagas.\n\n");
        return;
    }

    printf("Matrícula do aluno: ");
    int lido = scanf("%d", &matricula);
    flush_in(); 
    if (lido != 1) {
        printf("Matrícula inválida.\n\n");
        return;
    }

    for (int i = 0; i < qtdAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            existe = 1;
            break;
        }
    }

    if (!existe) {
        printf("Matrícula não cadastrada.\n\n");
        return;
    }

    for (int i = 0; i < disciplinas[indice].qtdAlunos; i++) {
        if (disciplinas[indice].matriculas[i] == matricula) {
            ja_Matriculado = 1;
            break;
        }
    }

    if (ja_Matriculado) {
        printf("Aluno já matriculado nessa disciplina.\n\n");
        return;
    }

    disciplinas[indice].matriculas[disciplinas[indice].qtdAlunos] = matricula;
    disciplinas[indice].qtdAlunos++;
    printf("Aluno inserido com sucesso!\n\n");
}

void excluirAlunoDisciplina(Disciplina *disciplinas, int qtdDisciplinas) {
    char codigo[10];
    int matricula, indice = -1, posicao = -1;

    printf("Código da disciplina: ");
    if (fgets(codigo, 10, stdin) == NULL) {
        return; 
    }
    if (strchr(codigo, '\n') == NULL) {
        flush_in();
    }
    codigo[strcspn(codigo, "\n")] = '\0';
    toLowerCase(codigo);

    if (!validaCodigoDisciplina(codigo)) {
        printf("Código inválido: não pode ficar em branco.\n\n");
        return;
    }
    retiraEspaco(codigo);

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Disciplina não encontrada.\n\n");
        return;
    }

    printf("Matrícula do aluno: ");
    int lido = scanf("%d", &matricula);
    flush_in();
    if (lido != 1) {
        printf("Matrícula inválida.\n\n");
        return;
    }

    for (int i = 0; i < disciplinas[indice].qtdAlunos; i++) {
        if (disciplinas[indice].matriculas[i] == matricula) {
            posicao = i;
            break;
        }
    }

    if (posicao == -1) {
        printf("Aluno não está matriculado nessa disciplina.\n\n");
        return;
    }

    for (int i = posicao; i < disciplinas[indice].qtdAlunos - 1; i++) {
        disciplinas[indice].matriculas[i] = disciplinas[indice].matriculas[i + 1];
    }
    disciplinas[indice].qtdAlunos--;
    printf("Aluno excluído da disciplina!\n\n");
}

void listarUmaDisciplina(Disciplina *disciplinas, int qtdDisciplinas, Aluno *alunos, int qtdAlunos) {
    char codigo[10];
    int indice = -1;

    printf("Código da disciplina: ");
    if (fgets(codigo, 10, stdin) == NULL) {
        return; 
    }
    if (strchr(codigo, '\n') == NULL) {
        flush_in(); 
    }
    codigo[strcspn(codigo, "\n")] = '\0';
    toLowerCase(codigo); 

    if (!validaCodigoDisciplina(codigo)) {
        printf("Código inválido: não pode ficar em branco.\n\n");
        return;
    }
    retiraEspaco(codigo);

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (strcmp(disciplinas[i].codigo, codigo) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Disciplina não encontrada.\n\n");
        return;
    }

    printf("\n");
    printf("Nome: %s | Codigo: %s | Semestre: %s | Professor: %s\n",
           disciplinas[indice].nome, disciplinas[indice].codigo,
           disciplinas[indice].semestre, disciplinas[indice].professor);
    printf("Alunos matriculados: %d/%d\n", disciplinas[indice].qtdAlunos, MAX_Disciplinas);

    if (disciplinas[indice].qtdAlunos == 0) {
        printf("Nenhum aluno matriculado nessa disciplina.\n");
    }

    for (int i = 0; i < disciplinas[indice].qtdAlunos; i++) {
        int matricula = disciplinas[indice].matriculas[i];
        int posicao = 0;

        if (existeMatricula(alunos, qtdAlunos, matricula, &posicao)) {
            printf("  Matrícula: %d | Nome: %s\n", matricula, alunos[posicao].nome);
        } else {
            printf("  Matrícula: %d\n", matricula); 
        }
    }
    printf("\n");
}

void listarDisciplinasMaisDe40Alunos(Disciplina *disciplinas, int qtdDisciplinas) {
    int encontradas = 0;

    for (int i = 0; i < qtdDisciplinas; i++) {
        if (disciplinas[i].qtdAlunos > 40) {
            printf("Nome: %s | Codigo: %s | Semestre: %s | Professor: %s\n",
                   disciplinas[i].nome, disciplinas[i].codigo,
                   disciplinas[i].semestre, disciplinas[i].professor);
            printf("  Alunos: %d\n", disciplinas[i].qtdAlunos);
            encontradas++;
        }
    }

    if (encontradas == 0) {
        printf("Nenhuma disciplina com mais de 40 alunos.\n");
    }
    printf("\n");
}