#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Aluno{
        char nome[50];
        int matricula;
        float notas[3];
        float mediaFinal;
    }Aluno;


void menu(Aluno *vetor, int *qtd){
    int numero;
    printf("####### MENU #######\n");

    do{
        printf
        ("1.Cadastrar ALuno\n2.Listar todos os alunos e suas medias\n3.consultar aluno por matricula\n4.mostrar aluno com maior media\n5.Calcular media geral da turma\n6.sair");
        printf("digite o numero de acordo com a opcao: ");
        switch(numero){
            case 1:
                cadastrarAlunos(vetor, &qtd, MAX);
                printf("-> Cadastrar aluno\n");
                break;
            case 2:
                printf("-> Listar alunos\n");
                break;
            case 3:
                 printf("-> Consultar matrícula\n");
                 break;
            case 4:
                printf("-> Mostrar maior média\n");
                break;
            case 5:
                printf("-> Calcular média geral\n");
                break;
            case 6:
                printf("Saindo do menu...\n");
                break;
            default:
                printf("opcao invalida. Digite novamente\n");
        }
    }while(numero !=6);
}

float calcularMedia(Aluno *aluno){
    float soma = 0.0;

    for(int i=0;i<3;i++){
        printf("digite a nota[%d]", i);
        scanf("%f", &aluno->notas[i]);
        soma+=aluno->notas[i];
    }

    aluno->mediaFinal = soma/3;
    return aluno->mediaFinal;
}

void cadastrarAlunos(Aluno *vetor, int *qtd, int max){
    for(int i=*qtd;i<max;i++){
        printf("digite a matricula do aluno[%d]\n", i);
        scanf("%d", &vetor[i].matricula);

        getchar();
        printf("digite o nome do aluno[%d]", i);
        fgets(vetor[*qtd].nome, sizeof(vetor[*qtd].nome), stdin);
        vetor[*qtd].nome[strcspn(vetor[*qtd].nome, "\n")] = '\0';

        for(int i=0;i<3;i++){
            printf("digite a nota[%d]",i);
            scanf("%f", &vetor[*qtd].notas[i]);
        }

        calcularMedia(&vetor[i]);

        char opcao;
        printf("deseja cadastrar outro aluno? (s\n)");
        getchar();
        scanf("%c", &opcao);

        if(opcao == 'n' || opcao == 'N'){
            break;
        }

        (*qtd)++;
    }
}

void listarAlunos(Aluno *vetor, int qtd){
    if(qtd == 0){
        printf("nenhum aluno cadastrado");
    }
    for(int i=0;i<qtd;i++){
        printf("nome completo: %s", vetor[i].matricula);
        printf("numero da matricula: %d", vetor[i].matricula);
        for(int j=0;j<3;j++){
            printf("nota[%d]: %f",j,vetor[i].notas[j]);
        }
        printf("media final do aluno: %f", vetor[i].mediaFinal);
    }
}

int main(){

    Aluno alunos[MAX];

    return 0;
}