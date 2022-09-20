#include <stdio.h>
#include <string.h>
typedef struct {
	char nome[30];
	int idade;
	float salario;
}inserir_dado;

inserir_dado vetor[100];
int posLivre = 0;

void cadastrar(){
	   printf("\n======Opcao Inserir =====\n");
	   printf("Digite o nome: ");
	   scanf("%s",&vetor[posLivre].nome);
	   printf("Digite a idade: ");
	   scanf("%d",&vetor[posLivre].idade);
	   printf("Digite o salario: ");
	   scanf("%f",&vetor[posLivre].salario);
       posLivre = posLivre +1;
       printf("\n->Inserido com sucesso.<-\n");

}
void listar(){
	printf("\n=====Dados inseridos=====\n");
	for(int i= 0;i<posLivre;i++){
		printf("->Nome: %s, ",vetor[i].nome);
		printf("Idade: %d, ",vetor[i].idade);
		printf("Salario: %f \n",vetor[i].salario);

	}
	printf("\n=========================\n");
}
void pesquisar(){
	char nomeTeste[30];
	printf("\n======Opcao Pesquisa======\n");
	printf("Digite o nome a ser pesquisado: ");
	scanf("%s",&nomeTeste);
	printf("\n======Resultado da pesquisa======\n");
	for(int i = 0;i<posLivre;i++){
		if(strstr(vetor[i].nome,nomeTeste)!= NULL){
			printf("Nome: %s \nIdade: %d \nSalario: %f \n",vetor[i].nome,vetor[i].idade,vetor[i].salario);
			printf("=================================\n");
		}
	}
}

void excluir(){
	char nomeExcluir[30];
	printf("\n=======Option Excluir======= \n");
	listar();
	printf("============================");
	printf("\nDigite o nome a ser excluido: ");
	scanf("%s", &nomeExcluir);
	for(int i=0; i<posLivre;i++){
		if(strstr(vetor[i].nome, nomeExcluir) != NULL){
			vetor[i] = vetor[i+1];
      	    posLivre--;
      	    printf("\n-> Excluido com sucesso! <- \n");
		}
	}
}


int main(int argc, char** argv)
{

	int opcao;

	do{
		   printf("\n\n==========MENU===========");
		   printf("\n\t1-Inserir \n");
		   printf("\t2-Listar \n");
		   printf("\t3-Pesquisar \n");
		   printf("\t4-Excluir \n");
		   printf("\t5-Sair\n");
		   printf("========================= \n");
		   printf("Digite uma option de Menu: ");
		   scanf("%d",&opcao);

		   switch(opcao)
		   {
		   case 1:
		       cadastrar();
			   break;
		   case 2:
		   		listar();
			   break;
		   case 3:
		   		pesquisar();
			   break;
		   case 4:
	   		   excluir();
			   break;
		   case 5:
		   		break;
		   default:
	   			printf("Opção invalida, tente novamente!");
			   break;
		   }
	}while(opcao!=5);
	return 0;
}
