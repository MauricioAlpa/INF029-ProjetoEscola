#include <Headers/FunctionsAluno.h>

void cadastrarAluno(Aluno *alunos, int *qtdAlunos){


    //Variaveis para continuar pegando entrada do user ate estarem certas
    bool validadoMatricula = false, validadoNome = false, validadoSexo = false, validadoNascimento = false, validadoCpf = false;
    bool result = false; 

    while(!validadoMatricula){
        int matricula;
        
        printf("Digite a matrícula do aluno(a): \n");
        scanf("%i", &matricula);
        flush_in();//Limpo o buffer para nao atrapalhar o fgets com o \n

        result = validaMatricula(matricula, alunos, *qtdAlunos);

        if(result){

            alunos[*qtdAlunos].matricula = matricula;
            validadoMatricula = true;

        }else{
            printf("\n");
            printf("Digite um número inteiro, entre 1 e 51\n");
            printf("\n");
        }
    }

    while(!validadoNome){
        char nome[50]; //variavel temporaria para verificação do nome.

        printf("Digite o nome do aluno: \n");
        fgets(nome, 50, stdin);

        retiraEspaco(nome);//retira espaco no final e no comeco do nome
        retiraBarraN(nome);//retira o /n do final

        if(strlen(nome) > 0){//verifica se nome não está vazio

            toLowerCase(nome);//função para padronizar os nomes em minusculo, caso o user digite: MaUrIcIo
            
            result = validaNome(nome);

            if(result){
                strcpy(alunos[*qtdAlunos].nome, nome);
                validadoNome = true;
            }else{
                printf("Digite um nome válido.\n");
            }
        }else{
            printf("Inválido: Digite algum nome.\n");
        }
    }

    while(!validadoSexo){
        char sexo;

        printf("Digite o gênero(M/F) do aluno(a): \n");
        scanf("%c", &sexo);

        result = validaSexo(sexo);

        if(result){

            alunos[*qtdAlunos].sexo = sexo;
            validadoSexo = true;

        }else{
            printf("Digite o gênero do aluno apenas como M para masculino e F para feminino.\n");
        }
    }

    while(!validadoNascimento){
        Data nascimento; //variavel temporaria para verificação do nascimento.

        printf("Digite a data de nascimento (DD/MM/AAAA): \n");
        if (scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano) == 3) {

            flush_in();//limpo buffer
            result = validaData(nascimento); //Chama a função para validar a data e retornar true ou false

            if(result){

                alunos[*qtdAlunos].nascimento = nascimento;
                validadoNascimento = true;

            }else{
                printf("Data inválida.\n");
            }

        }else {
            flush_in();//limpo buffer
            printf("Erro: Formato de data inválido. Use o padrão DD/MM/AAAA.\n");
        }
    }

    while(!validadoCpf){
        char cpf[12];//variavel temporaria para verificação do CPF.

        printf("Digigte o cpf do aluno: \n");
        fgets(cpf, 12, stdin);


        if(strlen(cpf) > 0){//verifica se o cpf não está vazio
            retiraBarraN(cpf);
            retiraEspaco(cpf);

            result = validaCPF(cpf);

            if(result){
                strcpy(alunos[*qtdAlunos].cpf, cpf);
                validadoCpf = true;
            }else{
                printf("O CPF deve conter apenas números.");
            }
        }else{
            printf("Digite um CPF.\n");
        }
    }

    printf("\n--- ALUNO CADASTRADO ---\n");
    printf("Matrícula: %d\n", alunos[*qtdAlunos].matricula);
    printf("Nome: %s\n", alunos[*qtdAlunos].nome);
    printf("Sexo: %c\n", alunos[*qtdAlunos].sexo);
    printf("Nascimento: %02d/%02d/%04d\n",
           alunos[*qtdAlunos].nascimento.dia,
           alunos[*qtdAlunos].nascimento.mes,
           alunos[*qtdAlunos].nascimento.ano);
    printf("CPF: %s\n", alunos[*qtdAlunos].cpf);
    printf("\n");
}

void listarAlunos(Aluno *alunos, int qtdAlunos){
    for(int i = 0; i < qtdAlunos; i++){
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Sexo: %c\n", alunos[i].sexo);
        printf("Nascimento: %02d/%02d/%04d\n",
           alunos[i].nascimento.dia,
           alunos[i].nascimento.mes,
           alunos[i].nascimento.ano);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("\n");
    }
}

bool existeMatricula(Aluno *aluno, int qtdAlunos, int matricula, int *posicao){//Função para verificar se existe aluno com a matricula cadastrada.

    for(int i = 0; i < qtdAlunos; i++){

        if(aluno[i].matricula == matricula){
            *posicao = i;
            return true;
        }
    }

    return false;
}

bool atualizarAluno(Aluno *alunos, int qtdAluno){

    int matricula;
    int posicao = 0;
    bool existe = false;

    printf("Digite a matricula do aluno a ser atualizado: \n");

    scanf("%i", &matricula);
    flush_in();//Limpo o buffer para nao atrapalhar o fgets com o \n

    existe = existeMatricula(alunos, qtdAluno, matricula, &posicao);

    if(existe){
      //Reutilizei o código de cadastrar aluno.
        bool validadoMatricula = false, validadoNome = false, validadoSexo = false, validadoNascimento = false, validadoCpf = false;
        bool result = false; 

        
        while(!validadoNome){
            char nome[50]; //variavel temporaria para verificação do nome.

            printf("Digite o nome do aluno: \n");
            fgets(nome, 50, stdin);

            retiraEspaco(nome);//retira espaco no final e no comeco do nome
            retiraBarraN(nome);//retira o /n do final

            if(strlen(nome) > 0){//verifica se nome não está vazio

                toLowerCase(nome);//função para padronizar os nomes em minusculo, caso o user digite: MaUrIcIo
                
                result = validaNome(nome);

                if(result){
                    strcpy(alunos[posicao].nome, nome);
                    validadoNome = true;
                }else{
                    printf("Digite um nome válido.\n");
                }
            }else{
                printf("Inválido: Digite algum nome.\n");
            }
        }

        while(!validadoSexo){
            char sexo;

            printf("Digite o gênero(M/F) do aluno(a): \n");
            scanf("%c", &sexo);

            result = validaSexo(sexo);

            if(result){

                alunos[posicao].sexo = sexo;
                validadoSexo = true;

            }else{
                printf("Digite o gênero do aluno apenas como M para masculino e F para feminino.\n");
            }
        }

        while(!validadoNascimento){
            Data nascimento; //variavel temporaria para verificação do nascimento.

            printf("Digite a data de nascimento (DD/MM/AAAA): \n");
            if (scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano) == 3) {

                flush_in();//limpo buffer
                result = validaData(nascimento); //Chama a função para validar a data e retornar true ou false

                if(result){

                    alunos[posicao].nascimento = nascimento;
                    validadoNascimento = true;

                }else{
                    printf("Data inválida.\n");
                }

            }else {
                flush_in();//limpo buffer
                printf("Erro: Formato de data inválido. Use o padrão DD/MM/AAAA.\n");
            }
        }

        while(!validadoCpf){
                char cpf[12];//variavel temporaria para verificação do CPF.

                printf("Digigte o cpf do aluno: \n");
                fgets(cpf, 12, stdin);

                if(strlen(cpf) > 0){//verifica se o cpf não está vazio
                    retiraBarraN(cpf);
                    retiraEspaco(cpf);

                    result = validaCPF(cpf);

                    if(result){
                        strcpy(alunos[posicao].cpf, cpf);
                        validadoCpf = true;
                    }else{
                        printf("O CPF deve conter apenas números.");
                    }
                }else{
                    printf("Digite um CPF.\n");
                }
            }

            printf("\n--- ALUNO %i ATUALIZADO ---\n", alunos[posicao].matricula);
            printf("Matrícula: %d\n", alunos[posicao].matricula);
            printf("Nome: %s\n", alunos[posicao].nome);
            printf("Sexo: %c\n", alunos[posicao].sexo);
            printf("Nascimento: %02d/%02d/%04d\n",
                alunos[posicao].nascimento.dia,
                alunos[posicao].nascimento.mes,
                alunos[posicao].nascimento.ano);
            printf("CPF: %s\n", alunos[posicao].cpf);
            printf("\n");

            return true;
        }

        return false;
}

bool excluirAluno(Aluno *alunos, int *qtdAluno){
    int matricula;
    int posicao = 0;
    bool existe = false;

    printf("Digite a matricula do aluno a ser excluido: \n");

    scanf("%i", &matricula);
    flush_in();//Limpo o buffer para nao atrapalhar o fgets com o \n

    existe = existeMatricula(alunos, *qtdAluno, matricula, &posicao);

    if(existe){
        for (int i = posicao; i < *qtdAluno - 1; i++) {
            alunos[i] = alunos[i + 1];
        }

        (*qtdAluno)--;

        return true;
    }

    return false;
}