#ifndef FUNCTIONSPROFESSOR_H
#define FUNCTIONSPROFESSOR_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Headers/FunctionsProfessor.h>
#include <Headers/SystemFunctions.h>
#include <Headers/ValidationsProfessor.h>
#include <Headers/Structs.h>

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);

void listarProfessor(Professor listaProfessor[], int qtdProfessor);

void atualizarProfessor(Professor listaProfessor[], int qtdProfessor);

int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

void ordenarProfessoresPorNome(Professor listaProfessor[], int qtdProfessor);

void listarProfessorSexo(Professor listaProfessor[], int qtdProfessores, char sexo);

#endif