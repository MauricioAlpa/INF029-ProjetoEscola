#ifndef FUNCTIONS_DISCIPLINA_H
#define FUNCTIONS_DISCIPLINA_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Headers/Structs.h>
#include <Headers/FunctionsAluno.h>
#include <Headers/SystemFunctions.h>
#include <Headers/ValidationsDisciplina.h>

void listarTodasDisciplinas(Disciplina *disciplinas, int qtdDisciplinas);

void cadastrarDisciplina(Disciplina *disciplinas, int *qtdDisciplinas);

void atualizarDisciplina(Disciplina *disciplinas, int qtdDisciplinas);

void excluirDisciplina(Disciplina *disciplinas, int *qtdDisciplinas);

void inserirAlunoDisciplina(Disciplina *disciplinas, int qtdDisciplinas, Aluno *alunos, int qtdAlunos);

void excluirAlunoDisciplina(Disciplina *disciplinas, int qtdDisciplinas);

void listarUmaDisciplina(Disciplina *disciplinas, int qtdDisciplinas, Aluno *alunos, int qtdAlunos);

void listarDisciplinasMaisDe40Alunos(Disciplina *disciplinas, int qtdDisciplinas);

#endif