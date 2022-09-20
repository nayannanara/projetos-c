#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
    int elemento;
    char nome[30];
    char curso[30];
    int matricula;
    float salario;
    struct dados *prox;
}aluno;

void inserirInicio(aluno **topo, int ele){
    aluno *novo;
    novo = (aluno*)malloc(sizeof(aluno));
    novo->elemento = ele;
    if(*topo==NULL){
        novo->prox = NULL;
        *topo = novo;
    }else{
        novo->prox = *topo;
        *topo = novo;
    }
    aluno *novo = (aluno*)malloc(sizeof(aluno));
    printf("Nome: ");
    scanf("%s", &novo->nome);
    printf("Curso: ");
    scanf("%s", &novo->curso);
    printf("Matricula: ");
    scanf("%d", &novo->matricula);
    printf("Salario: ");
    scanf("%f", &novo->salario);
    novo->prox = NULL;

}

void printar(aluno *topo){
    aluno *aux;
    aux = topo;
    if(aux==NULL){

    }else{
        do{
            printf("%d->", aux->elemento);
            aux = aux->prox;
        }while(aux!=NULL);
    }
}

main(){
    aluno *topo = NULL;
    inserirInicio(&topo,3);
    printar(topo);


}

