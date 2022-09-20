#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <new>
using namespace std;

typedef struct dados{
    string nome;
    string curso;
    int idade;
    float salario;
    dados *prox;
}pessoa;

int tamanho(pessoa *ponteiroPrincipal){
    //variavel do tamanho
    int tamanho = 0;
    //ponteiro aux
    pessoa *p = ponteiroPrincipal;
    //percorrer
    while(p->prox!=NULL){
        //atualiza o cursor
        p = p->prox;
    //incrementa
    tamanho++;
    }
return tamanho;
}

void imprimeLista(pessoa *ponteiroPrincipal){
    pessoa *p = ponteiroPrincipal->prox;
    while(p!= NULL){
       cout <<"\nNome: " << p->nome << "\nCurso: " << p->curso << "\nIdade: " << p->idade
       << "\nSalario: " << p->salario << "\n";
        p = p->prox;
    }
}

void inserirInicio(pessoa *&ponteiroPrincipal, string nome, string curso,int idade, float salario){
    cout << "\nPreencha os dados no inicio da lista\n";
    cout << "Nome: ";
    cin >> nome;
    cout << "Curso: ";
    cin >> curso;
    cout << "Idade: ";
    cin >> idade;
    cout << "Salario: ";
    cin >> salario;

    pessoa *novaPessoa = new pessoa;
    novaPessoa->nome = nome;
    novaPessoa->curso = curso;
    novaPessoa->idade = idade;
    novaPessoa->salario = salario;
    novaPessoa->prox = ponteiroPrincipal->prox;
    ponteiroPrincipal->prox = novaPessoa;

}

void inserirFinal(pessoa *&ponteiroPrincipal, string nome, string curso,int idade, float salario){
    cout << "\nPreencha os dados no final da lista da lista\n";
    cout << "Nome: ";
    cin >> nome;
    cout << "Curso: ";
    cin >> curso;
    cout << "Idade: ";
    cin >> idade;
    cout << "Salario: ";
    cin >> salario;

    pessoa *novaPessoa = new pessoa;
    novaPessoa->nome = nome;
    novaPessoa->curso = curso;
    novaPessoa->idade = idade;
    novaPessoa->salario = salario;
    novaPessoa->prox = NULL;

    pessoa *p = ponteiroPrincipal;
    while(p->prox!=NULL){
        p = p->prox;
    }
    p->prox = novaPessoa;

}
int main(){
    int funcaoDesejada = 1;
    string nome, curso;
    int idade;
    float salario;

    pessoa *ponteiroPrincipal = new pessoa;
    ponteiroPrincipal->prox = NULL;

    system("color B0");
    printf("Trabalho Ap1 - com listas encadeadas\n");
    printf("Alunos: Nayanna Nara e Jainel Santana\n\n");
    while (funcaoDesejada <4 && funcaoDesejada >0){
        cout << "\nTAMANHO DA LISTA ATUAL: " <<tamanho(ponteiroPrincipal);
        cout << "\n\tMENU\n";
        cout << "1- Inserir no inicio\n";
        cout << "2- Inserir no final\n";
        cout << "3- Listar \n";
        cout << "4- Sair\n";
        cout << "\nEscolha uma opcao e pressione ENTER: ";

        cin >> funcaoDesejada;

        system("CLS");

        switch(funcaoDesejada){
        case 1:
            inserirInicio(ponteiroPrincipal, nome, curso, idade, salario);
            break;
        case 2:
            inserirFinal(ponteiroPrincipal, nome, curso, idade, salario);
            break;
        case 3:
            imprimeLista(ponteiroPrincipal);
            break;
        case 4:
            break;

        }

    }

    return 0;

}

