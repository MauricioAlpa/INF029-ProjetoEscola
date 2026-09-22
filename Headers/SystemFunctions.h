#ifndef SYSTEMFUNCTIONS_H
#define SYSTEMFUNCTIONS_H
#include <stdio.h>
#include <time.h>
#include <Headers/Structs.h>


void toLowerCase(char string[]);

void retiraBarraN(char string[]);

void retiraEspaco(char string[]);

char toLowerChar(char caractere);

void flush_in();

void listaAniversariantes(Aluno *alunos, int qtdAlunos);

#endif
