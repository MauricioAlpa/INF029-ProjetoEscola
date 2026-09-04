#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char matricula[12];
    char nome[50];
    char sexo;
    Data nascimento;
    char cpf[12];
}Aluno;

typedef struct
{
    char matricula[11];
    char nome[50];
    char sexo;
    Data nascimento;
    char cpf[11];
}Professor;

typedef struct
{
    char nome[50];
    char codigo[6];
    int semestre;
    char professor[50];
}Disciplina;

#endif