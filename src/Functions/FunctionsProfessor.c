#include <Headers/FunctionsProfessor.h>
#define TAM_PROFESSOR 50

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor) {
	bool result = false;
	printf("\n--- Cadastrar Professor ---\n");
	if (qtdProfessor == TAM_PROFESSOR) {
		printf("Lista de Professores cheia!\n");
	} else {

		bool matriculaValido = false;
		while(!matriculaValido){
			int matriculaTemp;
			printf("\nDigite a matricula do professor: \n");
			scanf("%i", &matriculaTemp);
			flush_in();

			result = validaMatricula(matriculaTemp, listaProfessor, qtdProfessor);

			if(result){
				listaProfessor[qtdProfessor].matricula = matriculaTemp;
				matriculaValido = true;
			}else{
				printf("Mátricula já existe ou incorreta, digite um número inteiro.");
			}
		}

		bool nomeValido = false;
		while (!nomeValido) {
			char nome[50]; 
			printf("Digite o nome: \n");
			fgets(nome, 50, stdin);

			retiraEspaco(nome);
			retiraBarraN(nome);

			if(strlen(nome) > 0){
				toLowerCase(nome);

				result = validaNome(nome);

				if (result) {
					strcpy(listaProfessor[indice].nome, nome);
					nomeValido = true;
				} else {
					printf("\nNome inválido! (Deve ter entre 1 e 20 caracteres)\n");
				}
			} else {
				printf("\n");
            	printf("Inválido: Digite algum nome.\n");
           	 	printf("\n");
			}
		}

		bool sexoValido = false;
		while (!sexoValido) {
			char sexo;

			printf("Digite o sexo (M/F): ");
			scanf(" %c", &sexo);
			flush_in();

			sexo = toLowerChar(sexo);

			result = validaSexo(sexo);

			if (result) {
				listaProfessor[qtdProfessor].sexo = sexo;
				sexoValido = true;
			} else {
				printf("Sexo inválido! Digite apenas M ou F.\n");
			}
		}

		bool cpfValido = false;
		while (!cpfValido) {
			char cpf[12];

			printf("Digite o CPF (somente números): ");
			fgets(cpf, 12, stdin);

			if(strlen(cpf) > 0){
				retiraBarraN(cpf);
				retiraEspaco(cpf);
				result = validaCPF(cpf);

				if (result) {
					strcpy(listaProfessor[qtdProfessor].cpf, cpf);
					cpfValido = true;
				} else {
					printf("CPF inválido!\n");
				}
			}else {
				printf("\n");
				printf("Digite um CPF\n");
				printf("\n");
			}
		}

		bool dataValida = false;
		while (!dataValida) {
			Data nascimento;

			printf("Digite a data de nascimento (dd/mm/aaaa): ");
			if (scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano) == 3) {
	
				flush_in();

				result = validaData(nascimento);	

				if (result) {
					listaProfessor[qtdProfessor].nascimento = nascimento;
					dataValida = true;
				} else {
					printf("Data inválida!\n");

				}
			} else {
				flush_in();
            	printf("\n");
            	printf("Erro: Formato de data inválido. Use o padrão DD/MM/AAAA.\n");
            	printf("\n");
			}
		}

		listaProfessor[qtdProfessor].ativo = 1;
		qtdProfessor++;
		printf("\nProfessor cadastrado com sucesso!\n");
	}
	
	return qtdProfessor;
}

void listarProfessor(Professor listaProfessor[], int qtdProfessor) {
	printf("Listar Professor\n");
	if (qtdProfessor == 0) {
		printf("Lista Professor Vazia!\n");
	} else {
		printf("\nProfessores Cadastrados:\n");
        int i;
        for (i = 0; i < qtdProfessor; i++){
            printf("\n--- PROFESSOR CADASTRADO ---\n");
            printf("Matrícula: %d\n", listaProfessor[i].matricula);
            printf("Nome: %s\n", listaProfessor[i].nome);
            printf("Sexo: %c\n", listaProfessor[i].sexo);
            printf("Data de Nascimento: %d/%d/%d\n", listaProfessor[i].nascimento.dia, listaProfessor[i].nascimento.mes, listaProfessor[i].nascimento.ano);
            printf("CPF: %s\n", listaProfessor[i].cpf);
        }
        printf("\n");
	}
}

void atualizarProfessor(Professor listaProfessor[], int qtdProfessor) {
    printf("\n--- Atualizar Professor ---\n");

	int matricula;
	bool result = false;

    if (qtdProfessor == 0) {
        printf("Nenhum professor cadastrado!\n");
        return;
    }

    printf("Digite a matrícula do professor que deseja atualizar: ");
    scanf("%d", &matricula);

    int indice = -1;
    for (int i = 0; i < qtdProfessor; i++) {
        if (listaProfessor[i].matricula == matricula && listaProfessor[i].ativo) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Matrícula inexistente ou professor inativo!\n");
        return;
    }

    printf("\nProfessor encontrado: %s\n", listaProfessor[indice].nome);
    printf("Digite os novos dados:\n");

	bool nomeValido = false;
	while (!nomeValido) {
		char nome[50]; 
		printf("Digite o nome: \n");
		fgets(nome, 50, stdin);

		retiraEspaco(nome);
		retiraBarraN(nome);

		if(strlen(nome) > 0){
			toLowerCase(nome);

			result = validaNome(nome);

			if (result) {
				strcpy(listaProfessor[indice].nome, nome);
				nomeValido = true;
			} else {
				printf("\nNome inválido! (Deve ter entre 1 e 20 caracteres)\n");
			}
		} else {
			printf("\n");
			printf("Inválido: Digite algum nome.\n");
			printf("\n");
		}
	}

	bool sexoValido = false;
	while (!sexoValido) {
		char sexo;

		printf("Digite o sexo (M/F): ");
		scanf(" %c", &sexo);
		flush_in();

		sexo = toLowerChar(sexo);

		result = validaSexo(sexo);

		if (result) {
			listaProfessor[indice].sexo = sexo;
			sexoValido = true;
		} else {
			printf("Sexo inválido! Digite apenas M ou F.\n");
		}
	}

	bool cpfValido = false;
	while (!cpfValido) {
		char cpf[12];

		printf("Digite o CPF (somente números): ");
		fgets(cpf, 12, stdin);

		if(strlen(cpf) > 0){
			retiraBarraN(cpf);
			retiraEspaco(cpf);
			result = validaCPF(cpf);

			if (result) {
				strcpy(listaProfessor[indice].cpf, cpf);
				cpfValido = true;
			} else {
				printf("CPF inválido!\n");
			}
		}else {
			printf("\n");
			printf("Digite um CPF\n");
			printf("\n");
		}
	}

	bool dataValida = false;
	while (!dataValida) {
		Data nascimento;

		printf("Digite a data de nascimento (dd/mm/aaaa): ");
		if (scanf("%d/%d/%d", &nascimento.dia, &nascimento.mes, &nascimento.ano) == 3) {

			flush_in();

			result = validaData(nascimento);	

			if (result) {
				listaProfessor[indice].nascimento = nascimento;
				dataValida = true;
			} else {
				printf("Data inválida!\n");

			}
		} else {
			flush_in();
			printf("\n");
			printf("Erro: Formato de data inválido. Use o padrão DD/MM/AAAA.\n");
			printf("\n");
		}
	}

	printf("\n--- ALUNO %i ATUALIZADO ---\n", listaProfessor[indice].matricula);
	printf("Matrícula: %d\n", listaProfessor[indice].matricula);
	printf("Nome: %s\n", listaProfessor[indice].nome);
	printf("Sexo: %c\n", listaProfessor[indice].sexo);
	printf("Nascimento: %02d/%02d/%04d\n",
			listaProfessor[indice].nascimento.dia,
			listaProfessor[indice].nascimento.mes,
			listaProfessor[indice].nascimento.ano);
	printf("CPF: %s\n", listaProfessor[indice].cpf);
	printf("\n");

    printf("\nCadastro do professor atualizado com sucesso!\n");
}

int excluirProfessor(Professor listaProfessor[], int qtdProfessor) {
	printf("Excluir Professor\n");
	printf("Digite a matrícula: ");
	int matricula;
	int achou = 0;
	scanf("%d", &matricula);
	if (matricula < 0) {
		printf("Matricula Invalida\n");
	} else {
		for (int i = 0; i < qtdProfessor; i++) {
			if (matricula == listaProfessor[i].matricula) {
				for (int j = i; j < qtdProfessor - 1; j++) {
					listaProfessor[j].matricula = listaProfessor[j + 1].matricula;
					listaProfessor[j].sexo = listaProfessor[j + 1].sexo;
					listaProfessor[j].ativo = listaProfessor[j + 1].ativo;
				}
				qtdProfessor--;
				achou = 1;
				break;
			}
		}
		if (achou) {
			printf("Professor excluido com sucesso!\n");
		} else {
			printf("Matricula inexistente!\n");
		}
	}
	return qtdProfessor;
}

void listarProfessorSexo(Professor listaProfessor[], int qtdProfessor, char sexo) {
    sexo = toLowerChar(sexo);

    int encontrados = 0;
    for (int i = 0; i < qtdAlunos; i++) {
        if (listaProfessor[i].ativo && listaProfessor[i].sexo == sexo) {
            printf("\n");
            printf("Matrícula: %d\n", listaProfessor[i].matricula);
            printf("Nome: %s\n", listaProfessor[i].nome);
            printf("Sexo: %c\n", listaProfessor[i].sexo);
            printf("Nascimento: %02d/%02d/%04d\n",
                   listaProfessor[i].nascimento.dia,
                   listaProfessor[i].nascimento.mes,
                   listaProfessor[i].nascimento.ano);
            printf("CPF: %s\n", listaProfessor[i].cpf);
            printf("\n");
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum professor encontrado com o sexo informado.\n");
    }
}

void ordenarProfessoresPorNome(Professor listaProfessor[], int qtdProfessor) {
    if (qtdProfessor == 0) {
        printf("Nenhum professor cadastrado!\n");
        return;
    }

    Professor copia[TAM_PROFESSOR];

    for (int i = 0; i < qtdProfessor; i++) {
        copia[i] = listaProfessor[i];
    }

    for (int i = 0; i < qtdProfessor - 1; i++) {
        for (int j = i + 1; j < qtdProfessor; j++) {
            if (strcmp(copia[i].nome, copia[j].nome) > 0) {
                Professor temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtdProfessor; i++) {
        if (copia[i].ativo) {
            printf("\n");
            printf("Matrícula: %d\n", copia[i].matricula);
            printf("Nome: %s\n", copia[i].nome);
            printf("Sexo: %c\n", copia[i].sexo);
            printf("Nascimento: %02d/%02d/%04d\n",
                   copia[i].nascimento.dia,
                   copia[i].nascimento.mes,
                   copia[i].nascimento.ano);
            printf("CPF: %s\n", copia[i].cpf);
            printf("\n");
        }
    }
}

void ordenarProfessoresPorDataNascimento(Professor listaProfessor[], int qtdProfessor) {

    Professor copia[TAM_PROFESSOR];

    for (int i = 0; i < qtdProfessor; i++) {
        copia[i] = listaProfessor[i];
    }

    for (int i = 0; i < qtdProfessor - 1; i++) {
        for (int j = i + 1; j < qtdProfessor; j++) {
            
            bool trocar = false;

            if (copia[i].nascimento.ano > copia[j].nascimento.ano) {
                trocar = true;
            } else if (copia[i].nascimento.ano == copia[j].nascimento.ano) {
                if (copia[i].nascimento.mes > copia[j].nascimento.mes) {
                    trocar = true;
                } else if (copia[i].nascimento.mes == copia[j].nascimento.mes) {
                    if (copia[i].nascimento.dia > copia[j].nascimento.dia) {
                        trocar = true;
                    }
                }
            }

            if (trocar) {
                Professor temp = copia[i];
                copia[i] = copia[j];
                copia[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtdProfessor; i++) {
        if (copia[i].ativo) {
            printf("\n");
            printf("Nascimento: %02d/%02d/%04d\n",
                   copia[i].nascimento.dia,
                   copia[i].nascimento.mes,
                   copia[i].nascimento.ano);
            printf("Matrícula: %d\n", copia[i].matricula);
            printf("Nome: %s\n", copia[i].nome);
            printf("Sexo: %c\n", copia[i].sexo);
            printf("CPF: %s\n", copia[i].cpf);
            printf("\n");
        }
    }
}