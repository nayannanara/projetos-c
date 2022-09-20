#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
	char nome[10];
	int idade;
	no *prox;
} dadoLista;

dadoLista *cabeca;

void inserirFinal(){
	//criando o item na memoria
	dadoLista *item = (dadoLista *) malloc(sizeof(dadoLista));
	printf("Inserir nome:\n");
	scanf("%s",&item->nome);
	printf("Inserir idade:\n");
	scanf("%d",&item->idade);
	//o proximo de item recebe NULL
	item->prox= NULL;
	//criando variavel para receber o valor da cabeca 
	dadoLista *ultimo = cabeca;
	//verifica se a o proximo da cabeça é diferente de NULL
	while(ultimo->prox !=NULL){
		//se sim, ele atribui o valor de ultimo ao proximo
		ultimo = ultimo->prox;
	}
	//atribui o ultimo->prox ao item para encontra ultimo registro da lista 
	ultimo->prox = item;   	
}

void inserirInicio(){
	
}

void listar(){
	printf("\n\nListar dados\n\n");
	dadoLista *aux = cabeca->prox;
	while(aux!=NULL){
		printf("Nome: %s, Idade: %d\n", aux->nome, aux->idade);
		aux =aux->prox;
	}
	
}

int main(){
	int op;
	cabeca = (dadoLista *) malloc(sizeof(dadoLista));
	cabeca->prox = NULL;
	do{
		printf("\n\n  MENU\n"); 
		printf("1 - Inserir Inicio\n");
		printf("2 - Inserir Final\n");
		printf("3 - Listar\n");
		printf("4 - Sair\n");
		printf("Digite a opcao: ");
	
		scanf("%d",&op);
		
		switch(op){
			case 1:
				inserirInicio();
				break;
			case 2:
				inserirFinal();
				break;
			case 3:
				listar();
				break;
			case 4:
				break;
			default:
				printf("\nOpcao Invalida!\n\n");
		}
	}while(op!=4);

	

  return 0;
}