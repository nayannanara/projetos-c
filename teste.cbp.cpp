#include <stdio.h>
#include <cstdlib>
#define vetmax 3

int opc;
int qtdCliente = vetmax;

struct endereco{
       char logradouro[30];
       char bairro[30];
};

struct cliente{
       char nome[20];
       struct endereco ende;
}cliente[vetmax];

void inserir(){
   system("cls");
   int i;
   for(i=0;i<qtdCliente;i++){

      printf("\n Informe seu Nome: ");
      scanf("%s", cliente[i].nome);

      printf("\n Informe seu Logradouro: ");
      scanf("%s", cliente[i].ende.logradouro);

      printf("\n Informe seu Bairro: ");
      scanf("%s", cliente[i].ende.bairro);

   }

}

void alterar(){
   system("cls");

   int id;

   printf("\n Informe o ID: ");
   fflush(stdin);
   scanf("%d", id);

   system("cls");
   printf("\n Informe os novos dados:\n\n ");

   printf("\n Informe seu Nome: ");
   scanf("%s", cliente[id].nome);

   printf("\n Informe seu Logradouro: ");
   scanf("%s", cliente[id].ende.logradouro);

   printf("\n Informe seu Bairro: ");
   scanf("%s", cliente[id].ende.bairro);

   system("cls");
   printf("DADOS ALTERADOS COM SUCESSO!");

}

void consultar(){
   system("cls");
   int i;

   printf("Clientes Cadastrados:\n");
   for(i=0;i<qtdCliente;i++){

      printf("%d - %s \n", i, cliente[i].nome);

   }

}

void excluir(){
   system("cls");

   int id;

   printf("\n Informe o ID: ");
   fflush(stdin);
   scanf("%d", id);

   /*cliente[id].nome = "";
   cliente[id].ende.logradouro = "";
   cliente[id].ende.bairro = "";*/

   system("cls");
   printf("DADOS APAGADOS COM SUCESSO!");

}

void menu(){
     printf("\n 1 - Inserir");
     printf("\n 2 - Alterar");
     printf("\n 3 - Consultar");
     printf("\n 4 - Excluir");
     printf("\n 0 - Sair\n");
     scanf("%d",&opc);
}

int main(){

    do{
       menu();
       switch (opc){
          case 1:
             inserir();
          break;
          case 2:
             alterar();
          break;
          case 3:
             consultar();
          break;
          case 4:
             excluir();
          break;
       }
    }while(opc!=0);

    system("pause");
    return 0;
}
