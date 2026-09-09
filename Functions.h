#include <Structs.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Validations.h>




static void cadastroAlunos(Aluno *alunos, int *qtdAlunos){
    bool validadoMatricula = false, validadoNome = false, validadoSexo = false, validadoNascimento = false, validadoCPF = false;
    bool result = false;

    while(!validadoMatricula){
        char matricula[12];//variavel temporaria para verificação da matricula.

        printf("Digite a matrícula do aluno: \n");
        fgets(matricula, 12, stdin);

        retiraBarraN(matricula);

        result = validaMatricula(matricula, alunos, qtdAlunos); //Chama a função para validar a matricula e retornar true ou false

        if(result){
            strcpy(alunos[*qtdAlunos].matricula, matricula);
            validadoMatricula = true;
        }else{
            printf("Matricula incompleta ou já existente.\n");
        }
    }
    
    while(!validadoNome){
        char nome[50]; //variavel temporaria para verificação do nome.

        printf("Digite o nome do aluno: \n");
        fgets(nome, 50, stdin);

        if(strlen(nome) > 0){//verifica se nome não está vazio

            retiraBarraN(nome);
            retiraEspaco(nome);
            toLowerCase(nome);
            
            result = validaNome(nome);

            if(result){
                strcpy(alunos[*qtdAlunos].nome, nome);
                validadoNome = true;
            }else{
                printf("Digite um nome válido.");
            }
        }else{
            printf("Inválido: Digite algum nome.");
        }
    }

    while(!validadoSexo){
        char sexo;//variavel temporaria para verificação do sexo.

        printf("Digite o sexo do aluno(M/F): \n");
        scanf("%c", &sexo);

        result = validaSexo(sexo); //Chama a função para validar o sexo e retornar true ou false

        if(result){
            alunos[*qtdAlunos].sexo = sexo;
            validadoSexo = true;
        }else{
            printf("Digite apenas M ou F.\n");
        }
    }

    while(!validadoNascimento){
        Data nascimento; //variavel temporaria para verificação do nascimento.

        printf("Digite a data de nascimento (DD/MM/AAAA): ");
        if (scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano) == 3) {

            result = validaData(nascimento); //Chama a função para validar a data e retornar true ou false

            if(result){
                alunos[*qtdAlunos].nascimento = nascimento;
                validadoNascimento = true;
            }else{
                printf("Data inválida.");
            }

        }else {
            printf("Erro: Formato de data inválido. Use o padrão DD/MM/AAAA.\n");
        }
    }

    while(!validadoCPF){
        char cpf[12];//variavel temporaria para verificação do CPF.

        printf("Digigte o cpf do aluno: \n");
        fgets(cpf, 12, stdin);

        if(strlen(cpf) > 0){//verifica se o cpf não está vazio
            retiraBarraN(cpf);
            retiraEspaco(cpf);

            result = validaCPF(cpf);

            if(result){
                strcpy(alunos[*qtdAlunos].cpf, cpf);
                validadoCPF = true;
            }else{
                printf("O CPF deve conter apenas números.");
            }

        }else{
            printf("Inválido: Digite algum nome.");
        }
    }
};


static char *toLowerCase(char *string){ // Função para mudar todas as letras para lowercase

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32; //Faço +32 pois qualquer Letra maiuscula na tabela ASCII tem seu equivalente minusculo adicioonando 32 Ex: 'A' = 65 e 'a' = 97.
        }
    }

    return string;
}

static char *retiraBarraN(char *string){ //Função para retirar o \n, caso o user erre.
    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == '\n'){
            string[i] = '\0';
        }
    }

    return string;
}

static char *retiraEspaco(char *string){ //Função para retirar espaços do final e do começo.
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
    return string;
}

