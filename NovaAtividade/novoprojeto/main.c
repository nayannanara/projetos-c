#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade;
} dado;


int main(){
    dado *cabeca = (dado *)malloc(sizeof (dado));
    cabeca->prox = NULL;

    dado *item = (dado*)malloc(sizeof(dado));
    printf("Nome: ");
    scanf("%s", &item->nome);
    printf("Idade: ");
    scanf("%d", &item->nome);
    item-> prox = NULL;

    dado *ultimo = cabeca;
    while(ultimo->prox!-NULL){
        ultimo= ultimo->prox;
    }
    ultimo ->prox = item;

    printf("\n\n\ Lista de Elementos\n\n");
    dado *aux = cabeca->prox;
    while(aux!=NULL){
        printf("Nome: %s, Idade: %d\n",aux->nome, aux->nome);
    }
*/

}

