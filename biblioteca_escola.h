typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char matricula[11];
    char nome[50];
    char sexo;
    Data nascimento;
    char cpf[11];
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

int menuAluno(&alunos, &vagas, &qtdAlunos);

void mainProfessor();
int menuProfessor();
int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor);
void listarProfessor(Professor listaProfessor[], int qtdProfessor);
void atualizarProfessor(Professor listaProfessor[], int qtdProfessor);
int excluirProfessor(Professor listaProfessor[], int qtdProfessor);

menuDisciplina(&));