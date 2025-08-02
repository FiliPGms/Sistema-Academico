#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[100];
    int matricula;
    float notas[3];
    float media;
} Aluno;

void menu(Aluno *vetor, int *qtd);
void cadastrarAlunos(Aluno *vetor, int *qtd, int max);
void calcularMedia(Aluno *aluno);
void listarAlunos(Aluno *vetor, int qtd);
Aluno* buscarAlunoPorMatricula(Aluno *vetor, int qtd, int mat);
void consultarAluno(Aluno *vetor, int qtd);
Aluno* alunoComMaiorMedia(Aluno *vetor, int qtd);
float calcularMediaGeral(Aluno *vetor, int qtd);

int main() {
    Aluno alunos[MAX];
    int qtdAlunos = 0;

    menu(alunos, &qtdAlunos);

    return 0;
}

void menu(Aluno *vetor, int *qtd) {
    int opcao;

    do {
        printf("\n===== MENU PRINCIPAL =====\n");
        printf("1. Cadastrar alunos\n");
        printf("2. Listar todos os alunos e suas medias\n");
        printf("3. Consultar aluno por matricula\n");
        printf("4. Mostrar aluno com maior media\n");
        printf("5. Calcular media geral da turma\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarAlunos(vetor, qtd, MAX);
                break;
            case 2:
                listarAlunos(vetor, *qtd);
                break;
            case 3:
                consultarAluno(vetor, *qtd);
                break;
            case 4: {
                Aluno *melhor = alunoComMaiorMedia(vetor, *qtd);
                if (melhor != NULL) {
                    printf("Aluno com maior media: %s (%.2f)\n", melhor->nome, melhor->media);
                } else {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;
            }
            case 5:
                printf("media geral da turma: %.2f\n", calcularMediaGeral(vetor, *qtd));
                break;
            case 6:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("opcao invalida. Tente novamente.\n");
        }
    } while(opcao != 6);
}

void cadastrarAlunos(Aluno *vetor, int *qtd, int max) {
    if (*qtd >= max) {
        printf("Limite maximo de alunos atingido.\n");
        return;
    }

    printf("Cadastro do aluno %d:\n", *qtd + 1);
    printf("Nome completo: ");
    getchar(); 
    fgets(vetor[*qtd].nome, sizeof(vetor[*qtd].nome), stdin);
    vetor[*qtd].nome[strcspn(vetor[*qtd].nome, "\n")] = '\0'; 

    printf("matricula: ");
    scanf("%d", &vetor[*qtd].matricula);

    for (int i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &vetor[*qtd].notas[i]);
    }

    calcularMedia(&vetor[*qtd]);
    printf("media calculada: %.2f\n", vetor[*qtd].media);

    (*qtd)++;
}

void calcularMedia(Aluno *aluno) {
    float soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += aluno->notas[i];
    }
    aluno->media = soma / 3;
}

void listarAlunos(Aluno *vetor, int qtd) {
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\nAluno %d\n", i + 1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("matricula: %d\n", vetor[i].matricula);
        printf("Notas: %.2f, %.2f, %.2f\n", vetor[i].notas[0], vetor[i].notas[1], vetor[i].notas[2]);
        printf("media: %.2f\n", vetor[i].media);
    }
}

Aluno* buscarAlunoPorMatricula(Aluno *vetor, int qtd, int mat) {
    for (int i = 0; i < qtd; i++) {
        if (vetor[i].matricula == mat) {
            return &vetor[i];
        }
    }
    return NULL;
}

void consultarAluno(Aluno *vetor, int qtd) {
    int mat;
    printf("Digite a matricula do aluno: ");
    scanf("%d", &mat);

    Aluno *aluno = buscarAlunoPorMatricula(vetor, qtd, mat);
    if (aluno != NULL) {
        printf("Nome: %s\n", aluno->nome);
        printf("media: %.2f\n", aluno->media);
    } else {
        printf("Aluno não encontrado.\n");
    }
}

Aluno* alunoComMaiorMedia(Aluno *vetor, int qtd) {
    if (qtd == 0) return NULL;

    Aluno *maior = &vetor[0];
    for (int i = 1; i < qtd; i++) {
        if (vetor[i].media > maior->media) {
            maior = &vetor[i];
        }
    }
    return maior;
}

float calcularMediaGeral(Aluno *vetor, int qtd) {
    if (qtd == 0) return 0;

    float soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += vetor[i].media;
    }
    return soma / qtd;
}
