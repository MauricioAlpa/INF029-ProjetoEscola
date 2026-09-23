#ifndef MENURELATORIOS_H
#define MENURELATORIOS_H
#include <Headers/FunctionsAluno.h>
#include <Headers/FunctionsDisciplina.h>
#include <Headers/FunctionsProfessor.h>
#include <Headers/ValidationsAluno.h>
#include <Headers/ValidationsProfessor.h>
#include <Headers/ValidationsDisciplina.h>
#include <stdio.h>
#include <Headers/Structs.h>

void menuRelatorios(Aluno *alunos, int qtdAlunos, Disciplina *disciplinas, int qtdDisciplinas, Professor listaProfessor[], int qtdProfessor);

#endif