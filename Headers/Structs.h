#ifndef STRUCTS_H
#define STRUCTS_H
#define MAX_Disciplinas 50

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    int matricula;
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
    char codigo[10];
    char semestre[10];
    char professor[50];
    int matriculas[MAX_Disciplinas];
    int qtdAlunos;
}Disciplina;

#endif