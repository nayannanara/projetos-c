#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <new>
#define TAM 10

void imprimeVetor(int vetor[TAM]){
    for(int i=0; i<TAM; i++){
        printf("%d - ", vetor[i]);
    }
}

int main(){
    int pilha[TAM];
    int topo = -1;

    imprimeVetor(pilha);

    if(topo == TAM - 1){
        printf("Pilha Cheia");
    }else{
        topo++;
        pilha[topo] = 5;
    }

    imprimeVetor(pilha);
}
