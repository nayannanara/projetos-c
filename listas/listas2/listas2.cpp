#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new>

typedef struct dados{
    int elemento;
    string nome;
    string curso;
    int matricula;
    float salario;
    struct dados *prox;
}aluno;

void inserirInicio(aluno **topo, int ele){
    aluno *novo;
    novo = malloc(sizeof(aluno));
    novo->elemento = ele;
    if(*topo==NULL){
        novo->prox = NULL;
        *topo = novo;
    }else{
        novo->prox = *topo;
        *topo = novo;
    }
}

main(){
    aluno *topo = NULL;
    inserirInicio(&topo,3);


}
