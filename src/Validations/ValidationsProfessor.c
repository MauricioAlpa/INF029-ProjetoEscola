#include <Headers/ValidationsProfessor.h>

bool validaNomeProfessor(char nome[]){
    if(strlen(nome) - 1 > 20 || strlen(nome) - 1 <= 0){
        return false;
    }

    return true;
}

bool validaSexoProfessor(char sexo){
    if(sexo != 'm' && sexo != 'f'){
        return false;
    }

    return true;
}

bool validaDataProfessor(Data nascimento) {
    if (nascimento.ano < 1920 || nascimento.ano > 2026 || nascimento.mes < 1 || nascimento.mes > 12) {
        return false;
    }

    int diasNoMes;

    switch (nascimento.mes) {
        case 2:
            if ((nascimento.ano % 4 == 0 && nascimento.ano % 100 != 0) || (nascimento.ano % 400 == 0)) {
                diasNoMes = 29;
            } else {
                diasNoMes = 28;
            }
            break;
        case 4: 
        case 6: 
        case 9: 
        case 11:
            diasNoMes = 30;
            break;
        default:
            diasNoMes = 31;
            break;
    }

    if (nascimento.dia < 1 || nascimento.dia > diasNoMes) {
        return false;
    }

    return true;
}

bool validaCPFProfessor(char cpf[]){//Função para verificar se existem apenas números no CPF
    if (strlen(cpf) != 11) {
        return false;
    }
    
    for(int i = 0; cpf[i] != '\0'; i++){
        if(cpf[i] < '0' || cpf[i] > '9'){
            return false;
        }
    }

    return true;
}

bool validaMatriculaProfessor(int matricula, Professor professores[], int qtdProfessor){ //Passo quantidade de Alunos pois preciso verificar o tamanho do vetor no for
    bool validado = false, matriculaExiste = false;

    for(int i = 0; i < qtdProfessor; i++){ //For com a função de verificar se já existe uma matricula igual a essa. Se sim, a matricula já existe muda de false para true
        if (professores[i].matricula == matricula){
            matriculaExiste = true;
        }
    }

    if((matricula > 0 && matricula <= 50) && !matriculaExiste){
        validado = true;
    }

    return validado;
}