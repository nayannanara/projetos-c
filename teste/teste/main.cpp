#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
    char nome [50];
    int idade;
    float salario;
}dadosCliente;

dadosCliente dadosVetor[200];
int posicao=0;
int i;

void inserir(){
    printf("\n\n****Editar cadastro****\n\n");
    printf("Nome: ");
    scanf("%s", &dadosVetor[posicao].nome);
    printf("idade: ");
    scanf("%d", &dadosVetor[posicao].idade);
    printf("Salario: ");
    scanf("%f", &dadosVetor[posicao].salario);

    posicao=posicao+1;

    printf("Voce salvou com sucesso!\n");
}
void listar(){
    printf("****Listar cadastro****\n");
    for(i=0;i<posicao;i++){
    printf("Nome: %s \n", dadosVetor[i].nome);
    printf("Idade: %d \n", dadosVetor[i].idade);
    printf("Salario: %f \n", dadosVetor[i].salario);
    }
  }
void pesquisar(){

    printf("~~~~Pesquisar cadastro~~~~\n");
    char nomePesquisar [50];
    printf("Digite um nome para pesquisa:\n");
    scanf("%s", &nomePesquisar);

    for(int i=0;i<posicao;i++){
      if(strcmp(dadosVetor[i].nome,nomePesquisar)==0){
        printf("Nome: %s \n",dadosVetor[i].nome);
        printf("Idade: %d \n",dadosVetor[i].idade);
        printf("Salario: %f \n",dadosVetor[i].salario);

      }
    }

}
void excluir(){
    printf("####Excluir####\n");
    int pos= -1;
    char nomeExluir[50];
    printf("Qual nome deseja exluir?\n");
    scanf("%s", &nomeExluir);
    for (int i=0;i<posicao;i++){
            if(strcmp(dadosVetor[i].nome,nomeExluir)==0){
                pos=i;
            }
        }
        if (pos>=0){

            for(int i=pos;i<posicao;i++){
            dadosVetor[i]=dadosVetor[i+1];
                }
        }
        posicao--;
}

int main(){
    int opcao;
    do{
    printf("\n\n======Menu======\n");
    printf("1 - Inserir\n");
    printf("2 - Listar\n");
    printf("3 - Pesquisar \n");
    printf("4 - Excluir\n");
    printf("5 - Alterar \n");
    printf("6 - Sair\n");

    printf("Digite uma opcao: ");
    scanf("%d",&opcao);

    switch(opcao){
    case 1:
        inserir();
        break;
    case 2:
        listar();
        break;
    case 3:
        pesquisar();
        break;
    case 4:
        printf("Opcao 4 Ecluir\n");
        break;
    case 5:
        printf("Opcao 5 Alterar\n");
        break;
    case 6:
        break;
    default:
        printf("Opcao Invalida:\n");
            }
        }while (opcao!=6);
}
