#include <iostream>
#include <stdio.h>
#include <stdlib.h>


struct aluno{
    char nome[20];
    int matricula;
    float nota;
};
typedef struct elemento* lista;

struct elemento{
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

using namespace std;

lista* criaLista(){
    lista* li = (lista*) malloc(sizeof(lista));
    if(li!=NULL){
        *li = NULL;
    return li;
    }
}


void liberaLista(lista* li){
    if(li != NULL){
        Elem* no;
        while((*li)!= NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
int main(){
    lista *li;
    li = criaLista();
    int op;
    do{
        cout << "\tººººMENUºººº\n";
        cout << "1- Inserir no inicio\n";
        cout << "2- inserir no final\n";
        cout << "3- Inserir antes de\n";
        cout << "4- Inserir depois de\n";
        cout << "5- Listar\n";

        cout << "Digite uma opcao e pressione ENTER\n";

        cin >> op;

        switch(op){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }while(op!=5);

    return 0;
}
