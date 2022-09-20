#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    char curso[20];
    int idade;
    float salario;
}pessoa;

pessoa vetor[200];
int posicao = 0;

void inserir(){
    printf("\n==== EDITAR CADASTRO ====\n");
    printf("Nome: ");
    scanf("%s", &vetor[posicao].nome);
    printf("Curso: ");
    scanf("%s", &vetor[posicao].curso);
    printf("Idade: ");
    scanf("%d", &vetor[posicao].idade);
    printf("Salario: ");
    scanf("%f", &vetor[posicao].salario);

    posicao++;
    printf("\n\n=== SALVO COM SUCESSO ===\n\n");
}

void listar (){
    printf("\nDADOS CADASTRAIS SALVOS\n\n");
    for(int i=0; i<posicao; i++){
        printf("Nome: %s\n", vetor[i].nome);
        printf("Curso: %s\n", vetor[i].curso);
        printf("Idade: %d\n", vetor[i].idade);
        printf("Salario: %.2f\n\n", vetor[i].salario);

    }

}

void excluir(){
    char nomeExcluir[50];
    int pos = -1;
    listar();
    printf("\nQual aluno deseja excluir da lista?");
    scanf("%s", &nomeExcluir);
    for(int i=0; i<posicao; i++){
        if(strcmp(vetor[i].nome, nomeExcluir) == 0){
            pos = i;
        }
    }
    if(pos >=0 ){
       for(int i= pos; i<posicao; i++){
            vetor[i] = vetor[i+1];
        }

    posicao--;
    }
    printf("\nEXCLUIDO COM SUCESSO\n");
}

int main(){
    int funcaoDesejada = 1;
    system("color B0");
    printf("Trabalho Ap1 - com vetores\n");
    printf("Alunos: Nayanna Nara e Jainel Santana\n");
    printf("Sistema de cadastro de alunos\n\n");
    while (funcaoDesejada <4 && funcaoDesejada >0){
        printf("\n\tMENU\n");
        printf("1- Inserir\n");
        printf("2- Listar\n");
        printf("3- Excluir\n");
        printf("4- Sair\n");
        printf("\nEscolha uma opcao e pressione ENTER: ");

        scanf("%d", &funcaoDesejada);

        system("CLS");

        switch(funcaoDesejada){
        case 1:
            inserir();
            break;
        case 2:
            listar();
            break;
        case 3:
            excluir();
            break;
        case 4:
            break;

        }

    }
    return 0;
}
