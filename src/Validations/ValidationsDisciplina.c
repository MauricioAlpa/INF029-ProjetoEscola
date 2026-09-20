#include <Headers/ValidationsDisciplina.h>
#include <ctype.h>


static bool temConteudo(char texto[]){

    for(int i = 0; texto[i] != '\0'; i++){
        if(!isspace((unsigned char)texto[i])){
            return true;
        }
    }

    return false;
}

bool validaNomeDisciplina(char nome[]){
    return temConteudo(nome);
}

bool validaCodigoDisciplina(char codigo[]){
    return temConteudo(codigo);
}

bool validaSemestreDisciplina(char semestre[]){
    return temConteudo(semestre);
}

bool validaProfessorDisciplina(char professor[]){
    return temConteudo(professor);
}