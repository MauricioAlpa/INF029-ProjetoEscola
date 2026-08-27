# INF029-ProjetoEscola

## 📋 Sobre o Projeto

O ""projeto escola** é uma aplicação desenvolvida em C para controle do funcionamento básico de uma escola.

O sistema tem objetivo estrutar o conhecimento em: 

* **Modularização** para separar o código em rotinas de fácil manutenção.
* **Lógica e estruturação do Código**.
* **Cooperação em equipe utilizando ferramentas de versionamente de código**

---

# Funcionalidades

* Cadastro de Alunos (Matrícula, Nome, Sexo, Data Nascimento, CPF).
* Cadastro de Professores (Matrícula, Nome, Sexo, Data Nascimento, CPF).
* Cadastro de Disciplinas (Nome, Código, Semestre, Professor)
    Inserir/Excluir aluno de uma disciplina
*Relatórios
  Listar Alunos
  Listar Professores
  Listar Disciplinas (dados da disciplina sem os alunos)
  Listar uma disciplina (dados da disciplina e os alunos matriculados)
  Listar Alunos por sexo (Masculino/Feminino)
  Listar Alunos ordenados por Nome
  Listar Alunos ordenados por data de nascimento
  Listar Professores por sexo (Masculino/Feminino)
  Listar Professores ordenados por Nome
  Listar Professores ordenados por data de nascimento
  Aniversariantes do mês
  Lista de pessoas (professor/aluno) a partir de uma string de busca. O usuário informa no
  mínimo três letras e deve ser listado todas as pessoas que contem essas três letras no
  nome.
  Lista de alunos matriculados em menos de 3 disciplinas
  Lista de Disciplinas, com nome do professor, que extrapolam 40 vagas.

---

# Fluxo da Aplicação

```
                    USUÁRIO INICIA O PROGRAMA
                              │
                              ▼
                         MENU PRINCIPAL
                              │
          ┌───────────────────┼───────────────────┐
          │                   │                   │
          ▼                   ▼                   ▼
    CADASTROS              DISCIPLINAS        RELATÓRIOS
          │                   │                   │
          │                   │                   ├──► Listar alunos
          │                   │                   ├──► Listar professores
          │                   │                   ├──► Listar disciplinas
          │                   │                   ├──► Listar uma disciplina
          │                   │                   ├──► Alunos por sexo
          │                   │                   ├──► Alunos por nome
          │                   │                   ├──► Alunos por nascimento
          │                   │                   ├──► Professores por sexo
          │                   │                   ├──► Professores por nome
          │                   │                   ├──► Professores por nascimento
          │                   │                   ├──► Aniversariantes do mês
          │                   │                   ├──► Buscar pessoas por nome
          │                   │                   ├──► Alunos com menos de
          │                   │                   │    3 disciplinas
          │                   │                   └──► Disciplinas com mais
          │                   │                        de 40 alunos
          │                   │
          │                   ├──► Cadastrar disciplina
          │                   ├──► Inserir aluno
          │                   │    em disciplina
          │                   └──► Excluir aluno
          │                        de disciplina
          │
          ├──► Cadastrar aluno
          │
          └──► Cadastrar professor
                              │
                              ▼
                       VALIDAR OS DADOS
                              │
                     ┌────────┴────────┐
                     │                 │
                  VÁLIDOS           INVÁLIDOS
                     │                 │
                     ▼                 ▼
              SALVAR/ALTERAR      EXIBIR ERRO
                 DADOS            E VOLTAR AO MENU
                     │
                     ▼
                  MENU
                     │
                     ▼
              CONTINUAR PROGRAMA?
                 │           │
                SIM         NÃO
                 │           │
                 └─────┐     ▼
                       │   ENCERRAR
                       │   PROGRAMA
                       ▼
                 MENU PRINCIPAL
```

---
