#include <Headers/ValidationsDisciplina.h>
#include <ctype.h>

// Função auxiliar (só existe dentro deste arquivo, por isso o static).
// Retorna true se o texto tiver pelo menos um caractere que não seja espaço, tab ou \n.
// Ou seja: texto vazio ou só com espaços é considerado "em branco" e retorna false.
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