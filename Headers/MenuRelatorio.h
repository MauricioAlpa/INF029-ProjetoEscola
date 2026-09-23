#ifndef MENURELATORIOS_H
#define MENURELATORIOS_H
#include <Headers/FunctionsAluno.h>
#include <Headers/FunctionsDisciplina.h>
#include <Headers/FunctionsProfessor.h>
#include <Headers/ValidationsAluno.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include <Headers/ValidationsProfessor.h>
#include <Headers/ValidationsDisciplina.h>
=======
#include <Headers/SystemFunctions.h>
>>>>>>> 08de52f9c732f5f64a1455b1082f82af98937be1
=======
>>>>>>> f6cbc83161c04b1849a9124d4eeb8307350bd13d
#include <stdio.h>
#include <Headers/Structs.h>
#include <Headers/ValidationsProfessor.h>
#include <Headers/ValidationsDisciplina.h>

void menuRelatorios(Aluno *alunos, int qtdAlunos, Disciplina *disciplinas, int qtdDisciplinas, Professor listaProfessor[], int qtdProfessor);

#endif