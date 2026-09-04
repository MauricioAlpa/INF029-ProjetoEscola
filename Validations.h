#include <stdbool.h>
#include <Structs.h>
#include <string.h>
#define MATRICULA_TAM 12

static bool validaMatricula(char *matricula, Aluno *alunos, int qtdAlunos){ //Passo quantidade de Alunos pois preciso verificar o tamanho do vetor no for
    bool validado = false, matriculaExiste = false;
    int tamanho = strlen(matricula);

    for(int i = 0; i < qtdAlunos; i++){ //For com a função de verificar se já existe uma matricula igual a essa. Se sim, a matricula já existe muda de false para true
        if (strcmp(alunos[i].matricula, matricula) == 0){
            matriculaExiste = true;
        }
    }

    if(tamanho == MATRICULA_TAM || !matriculaExiste){
        validado = true;
    }

    return validado;
}

static bool validaSexo(char sexo){
    if(sexo != 'M' && sexo != 'F'){
        return false;
    }

    return true;
}

static bool validaData(Data nascimento){
    if((nascimento.ano > 2019 || nascimento.ano < 1920) || (nascimento.dia > 31 || nascimento.dia < 1) || (nascimento.mes > 12 || nascimento.mes < 1)){
        return false;
    }

    return true;
}