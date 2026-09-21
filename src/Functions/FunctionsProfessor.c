#include <Headers/FunctionsAluno.h>

int cadastrarProfessor(Professor listaProfessor[], int qtdProfessor) {
	printf("\n--- Cadastrar Professor ---\n");
	if (qtdProfessor == TAM_PROFESSOR) {
		printf("Lista de Professores cheia!\n");
	} else {
		int matricula;
		printf("Digite a matrícula: ");
		scanf("%d", &matricula);

		if (matricula <= 0) {
			printf("Matrícula Inválida!\n");
		} else {
			listaProfessor[qtdProfessor].matricula = matricula;

			getchar();

			bool nomeValido = false;
			while (!nomeValido) {
				printf("Digite o nome: ");
				fgets(listaProfessor[qtdProfessor].nome, 50, stdin);

				if (!validaNome(listaProfessor[qtdProfessor].nome)) {
					printf("Nome inválido! (Deve ter entre 1 e 20 caracteres)\n");
				} else {
					retiraBarraN(listaProfessor[qtdProfessor].nome);
					nomeValido = true;
				}
			}

			bool sexoValido = false;
			while (!sexoValido) {
				printf("Digite o sexo (M/F): ");
				scanf(" %c", &listaProfessor[qtdProfessor].sexo);

				if (!validaSexo(listaProfessor[qtdProfessor].sexo)) {
					printf("Sexo inválido! Digite apenas M ou F.\n");
				} else {
					sexoValido = true;
				}
			}

			bool cpfValido = false;
			while (!cpfValido) {
				printf("Digite o CPF (somente números): ");
				scanf("%s", listaProfessor[qtdProfessor].cpf);

				if (!validaCPF(listaProfessor[qtdProfessor].cpf)) {
					printf("CPF inválido!\n");
				} else {
					cpfValido = true;
				}
			}

			bool dataValida = false;
			while (!dataValida) {
				printf("Digite a data de nascimento (dd mm aaaa): ");
				scanf("%d/%d/%d", 
					&listaProfessor[qtdProfessor].nascimento.dia, 
					&listaProfessor[qtdProfessor].nascimento.mes, 
					&listaProfessor[qtdProfessor].nascimento.ano);

				if (!validaData(listaProfessor[qtdProfessor].nascimento)) {
					printf("Data inválida!\n");
				} else {
					dataValida = true;
				}
			}

			listaProfessor[qtdProfessor].ativo = 1;
			qtdProfessor++;
			printf("\nProfessor cadastrado com sucesso!\n");
		}
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

    if (qtdProfessor == 0) {
        printf("Nenhum professor cadastrado!\n");
        return;
    }

    int matricula;
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

    getchar();

    bool nomeValido = false;
    while (!nomeValido) {
        printf("Digite o novo nome: ");
        fgets(listaProfessor[indice].nome, 50, stdin);

        if (!validaNome(listaProfessor[indice].nome)) {
            printf("Nome inválido! (Deve ter entre 1 e 20 caracteres)\n");
        } else {
            retiraBarraN(listaProfessor[indice].nome);
            nomeValido = true;
        }
    }

    bool sexoValido = false;
    while (!sexoValido) {
        printf("Digite o novo sexo (M/F): ");
        scanf(" %c", &listaProfessor[indice].sexo);

        if (!validaSexo(listaProfessor[indice].sexo)) {
            printf("Sexo inválido! Digite apenas M ou F.\n");
        } else {
            sexoValido = true;
        }
    }

    bool cpfValido = false;
    while (!cpfValido) {
        printf("Digite o novo CPF (somente números): ");
        scanf("%s", listaProfessor[indice].cpf);

        if (!validaCPF(listaProfessor[indice].cpf)) {
            printf("CPF inválido!\n");
        } else {
            cpfValido = true;
        }
    }

    bool dataValida = false;
    while (!dataValida) {
        printf("Digite a nova data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", 
            &listaProfessor[indice].nascimento.dia, 
            &listaProfessor[indice].nascimento.mes, 
            &listaProfessor[indice].nascimento.ano);

        if (!validaData(listaProfessor[indice].nascimento)) {
            printf("Data inválida!\n");
        } else {
            dataValida = true;
        }
    }

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
