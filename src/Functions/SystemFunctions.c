#include <Headers/SystemFunctions.h>

void toLowerCase(char string[]){ // Função para mudar todas as letras para lowercase

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32; //Faço +32 pois qualquer Letra maiuscula na tabela ASCII tem seu equivalente minusculo adicioonando 32 Ex: 'A' = 65 e 'a' = 97.
        }
    }
}

void retiraBarraN(char string[]){ //Função para retirar o \n, caso o user erre.
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
    }
}

void retiraEspaco(char string[]){ //Função para retirar espaços do final e do começo.

    int i = 0, primeiraOcorrencia = 0; //Primeira ocorrencia vai pegar o indice da primeira letra.
    
    while(string[primeiraOcorrencia] == ' '){
        primeiraOcorrencia++; //Procuro a primeira ocorrencia de uma letra
    }

    for(i; string[primeiraOcorrencia] != '\0'; i++){
        string[i] = string[primeiraOcorrencia];
        primeiraOcorrencia++;//movo a string para esquerda.
    }
 
    string[i] = '\0';//Para colocar p \0 no ultimo espaço 

    while(string[i-1] == ' '){//Uso o i como indicador do novo tamanho da minha string e so então  retiro do final.
        
        string[i - 1] = '\0';
        
        i--;
    }
}

void flush_in() { //Peguei essa funcao no stackOverFlow para limpar o buffer pos scanf, para nao atrapalhar o fgets
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}