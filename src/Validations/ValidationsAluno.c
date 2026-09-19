#include <Headers/ValidationsAluno.h>



bool validaMatricula(int matricula, Aluno *alunos, int qtdAlunos){ //Passo quantidade de Alunos pois preciso verificar o tamanho do vetor no for
    bool validado = false, matriculaExiste = false;

    for(int i = 0; i < qtdAlunos; i++){ //For com a função de verificar se já existe uma matricula igual a essa. Se sim, a matricula já existe muda de false para true
        if (alunos[i].matricula == matricula){
            matriculaExiste = true;
        }
    }

    if((matricula > 0 && matricula <= 50) && !matriculaExiste){
        validado = true;
    }

    return validado;
}

bool validaNome(char nome[]){
    if(nome[0] == '\n' || nome[0] == ' '){
        return false;
    }

    return true;
}

bool validaSexo(char sexo){
    if(sexo != 'm' && sexo != 'f'){
        return false;
    }

    return true;
}

bool validaData(Data nascimento){
    if((nascimento.ano > 2019 || nascimento.ano < 1920) || (nascimento.dia > 31 || nascimento.dia < 1) || (nascimento.mes > 12 || nascimento.mes < 1)){
        return false;
    }

    return true;
}

bool validaCPF(char cpf[]){//Função para verificar se existem apenas números no CPF
    for(int i = 0; cpf[i] != '\0'; i++){
        if(cpf[i] < '0' || cpf[i] > '9'){
            return false;
        }
    }

    return true;
}