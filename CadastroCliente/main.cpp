#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    char sexo[10];
    char endereco[100];
    int telefone;
}dadosCliente;

dadosCliente vetor[200];
int posicao = 0;

void cadastrar(){
    system ("CLS");
    printf("\n==== EDITAR CADASTRO ====\n");
    printf("Nome: ");
    scanf("%s", &vetor[posicao].nome);
    printf("Idade: ");
    scanf("%d", &vetor[posicao].idade);
    printf("Sexo: ");
    scanf("%s", &vetor[posicao].sexo);
    printf("Endereco: ");
    scanf("%s", &vetor[posicao].endereco);
    printf("Telefone: ");
    scanf("%d", &vetor[posicao].telefone);

    posicao++;
    printf("\n\n=== SALVO! ===\n\n");

}

void listar(){
    system ("CLS");
    printf("\n==== DADOS CADASTRAIS ====\n");
    for(int i=0; i<posicao; i++){
        printf("Nome: %s\n", vetor[i].nome);
        printf("Idade: %d\n", vetor[i].idade);
        printf("Sexo: %s\n", vetor[i].sexo);
        printf("Endereco: %s\n", vetor[i].endereco);
        printf("Telefone: %d\n\n", vetor[i].telefone);
    }
}

void pesquisar(){
    system ("CLS");
    char nomePesquisar[50];
    printf("\nDigite um nome para pesquisar: ");
    scanf("%s", &nomePesquisar);
    printf("\n=== DADOS DO CLIENTE ===\n");
    for(int i=0;i<posicao; i++){
        if(strstr(vetor[i].nome, nomePesquisar) != NULL){
            printf("Nome: %s\n", vetor[i].nome);
            printf("Idade: %d\n", vetor[i].idade);
            printf("Sexo: %s\n", vetor[i].sexo);
            printf("Endereco: %s\n", vetor[i].endereco);
            printf("Telefone: %d\n\n", vetor[i].telefone);
        }
    }
}

void excluir(){
    system ("CLS");
    char nomeExcluir[50];
    int pos = -1;
    listar();
    printf("\nQuem deseja excluir? Digite o nome: ");
    scanf("%s", &nomeExcluir);
    for(int i=0; i<posicao; i++){
        if(strstr(vetor[i].nome, nomeExcluir) != NULL){
            pos = i;
        }
    }
    if(pos >=0){
       for(int i= pos; i<posicao; i++){
            vetor[i] = vetor[i+1];
        }

    posicao--;
    }
    printf("\nExcluido com sucesso\n");
}


void ordenar(dadosCliente vetor[]){
    int x, y;
    dadosCliente aux;
    printf("\nOrdenado em ordem alfabetica\n");
    for (x=0; x <posicao; x++){
        for(y=x; y<posicao; y++){
            if(strcmp(vetor[x].nome, vetor[y].nome) > 0){
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor [y] = aux;
            }
        }
    }
    listar();
}

void alterar(){
    char nomeAlterar[50];
    //listar();
    ordenar(vetor);
    printf("\nQual nome voce deseja alterar? ");
    scanf("%s", &nomeAlterar);
    for(int i=0; i<posicao; i++){
        if(strstr(vetor[i].nome, nomeAlterar) != NULL){
            system ("CLS");
            printf("\n==== INFORME OS NOVOS DADOS CADASTRAIS ====\n");
            printf("Nome: ");
            scanf("%s", &vetor[i].nome);
            printf("Idade: ");
            scanf("%d", &vetor[i].idade);
            printf("Sexo: ");
            scanf("%s", &vetor[i].sexo);
            printf("Endereco: ");
            scanf("%s", &vetor[i].endereco);
            printf("Telefone: ");
            scanf("%d", &vetor[i].telefone);
            printf("\n\n=== DADOS ALTERADOS COM SUCESSO ===\n\n");
        }else{
            printf("Nome nao conta na lista\n");
        }
    }
}
int main(){
    system("color F4");
    int op;
    do{
        printf("บบบบบบบบบบ MENU บบบบบบบบบบบ \n\n");
        printf("\t1- Cadastrar\n");
        printf("\t2- Listar\n");
        printf("\t3- Pesquisar\n");
        printf("\t4- Excluir\n");
        printf("\t5- Alterar\n");
        printf("\t6- Sair\n\n");

        printf("\tDigite uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastrar();
                break;
            case 2:
                listar();
                ordenar(vetor);
                break;
            case 3:
                pesquisar();
                break;
            case 4:
                excluir();
                break;
            case 5:
                alterar();
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida");
                break;

        }
    }while(op!=6);
return 0;
}
