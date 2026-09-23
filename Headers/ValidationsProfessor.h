#ifndef VALIDATIONSPROFESSOR_H
#define VALIDATIONSPROFESSOR_H
#include <stdbool.h>
#include <Headers/Structs.h>
#include <string.h>

bool validaNomeProfessor(char nome[]);

bool validaSexoProfessor(char sexo);

bool validaDataProfessor(Data nascimento);

bool validaCPFProfessor(char cpf[]);

bool validaMatriculaProfessor(int matricula, Professor listaProfessor[], int qtdProfessor);

#endif