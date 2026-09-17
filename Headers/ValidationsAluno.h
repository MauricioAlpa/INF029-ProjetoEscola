#ifndef VALIDATIONSALUNO_H
#define VALIDATIONSALUNO_H
#include <stdbool.h>
#include <Headers/Structs.h>
#include <string.h>


bool validaMatricula(int matricula, Aluno *alunos, int qtdAlunos);

bool validaNome(char nome[]);

bool validaSexo(char sexo);

bool validaData(Data nascimento);

bool validaCPF(char cpf[]);

#endif