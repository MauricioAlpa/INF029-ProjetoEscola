#include <Structs.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Validations.h>




static void cadastroAlunos(Aluno *alunos, int qtdAlunos){
    bool validadoMatricula = false, validadoSexo = false, validadoNascimento = false, validadoCPF = false;
    bool result = false;
    char matricula[12];
    char sexo;
    Data nascimento;
    char cpf[12];


    while(!validadoMatricula){
        printf("Digite a matrícula do aluno: \n");
        fgets(matricula, 12, stdin);

        result = validaMatricula(matricula, alunos, qtdAlunos); //Chama a função para verificar a matricula e retornar true ou false

        if(result){
            strcpy(alunos[qtdAlunos].matricula, matricula);
            validadoMatricula = true;
        }else{
            printf("Matricula incompleta ou já existente.\n");
        }
    }
    
    printf("Digite o nome do aluno: \n");
    fgets(alunos[qtdAlunos].nome, 50, stdin);

    while(!validadoSexo){
        printf("Digite o sexo do aluno(M/F): \n");
        scanf('%c', &sexo);

        result = validaSexo(sexo);

        if(result){
            alunos[qtdAlunos].sexo = sexo;
            validadoSexo = true;
        }else{
            printf("Digite apenas M ou F.\n");
        }
    }

    while(!validadoNascimento){
        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        if (scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano) == 3) {
            result = validaData(nascimento);

            if(result){
                alunos[qtdAlunos].nascimento = nascimento;
                validadoNascimento = true;
            }else{
                printf("Data inválida.");
            }

        }else {
            printf("Erro: Formato de data inválido. Use o padrão DD/MM/AAAA.\n");
        }
    }

    while(!validadoCPF){
    }
};
