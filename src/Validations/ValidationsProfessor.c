#include <Headers/ValidationsProfessor.h>

bool validaNome(char nome[]){
    if(strlen(nome) - 1 > 20 || strlen(nome) - 1 <= 0){
        return false;
    }

    return true;
}

bool validaSexo(char sexo){
    if(sexo != 'M' && sexo != 'F'){
        return false;
    }

    return true;
}

bool validaData(Data nascimento) {
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

bool validaCPF(char cpf[]){//Função para verificar se existem apenas números no CPF
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