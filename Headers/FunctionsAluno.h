#ifndef FUNCTIONSALUNO_H
#define FUNCTIONSALUNO_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Headers/FunctionsAluno.h>
#include <Headers/SystemFunctions.h>
#include <Headers/ValidationsAluno.h>
#include <Headers/Structs.h>

void cadastrarAluno(Aluno *alunos, int *qtdAlunos);

void listarAlunos(Aluno *alunos, int qtdAlunos);

bool existeMatricula(Aluno *aluno, int qtdAlunos, int matricula, int *posicao);

bool atualizarAluno(Aluno *alunos, int qtdAluno);

bool excluirAluno(Aluno *alunos, int *qtdAluno);

#endif