#ifndef VALIDATIONSPROFESSOR_H
#define VALIDATIONSPROFESSOR_H
#include <stdbool.h>
#include <Headers/Structs.h>
#include <string.h>

bool validaNome(char nome[]);

bool validaSexo(char sexo);

bool validaData(Data nascimento);

bool validaCPF(char cpf[]);

#endif