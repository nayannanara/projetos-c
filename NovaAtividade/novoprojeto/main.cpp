#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char nome[50];
    int idade;
    node *prox;
} dado;

int main(){
    dado *cabeca = (dado *)malloc(sizeof (dado));
    cabeca->prox = NULL;

    dado *item = (dado*)malloc(sizeof(dado));
    printf("Nome: ");
    scanf("%s", &item->nome);
    printf("Idade: ");
    scanf("%d", &item->idade);
    item-> prox = NULL;

    dado *ultimo = cabeca;
    while(ultimo->prox!=NULL){
        ultimo= ultimo->prox;
    }
    ultimo ->prox = item;

    printf("\n\n Lista de Elementos\n\n");
    dado *aux = cabeca->prox;
    while(aux!=NULL){
        printf("Nome: %s, Idade: %d\n",aux->nome, aux->idade);
        aux = aux->prox;
    }


}

