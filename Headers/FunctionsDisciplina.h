#ifndef FUNCTIONS_DISCIPLINA_H
#define FUNCTIONS_DISCIPLINA_H




void listarDisciplinas(struct Disciplina *disciplinas, int qtdDisciplinas) {
    if (qtdDisciplinas == 0) {
        printf("Nenhuma disciplina cadastrada.\n\n");
        return;
    }

    for (int i = 0; i < qtdDisciplinas; i++) {
        printf("Nome: %s | Codigo: %s | Semestre: %s | Professor: %s\n",
               disciplinas[i].nome, disciplinas[i].codigo,
               disciplinas[i].semestre, disciplinas[i].professor);

        printf("  Alunos: %d/%d | Matriculas:", disciplinas[i].qtdAlunos, VAGAS_DISCIPLINA);
        for (int j = 0; j < disciplinas[i].qtdAlunos; j++) {
            printf(" %d", disciplinas[i].matriculas[j]);
        }
        printf("\n");
    }
    printf("\n");
}

#endif