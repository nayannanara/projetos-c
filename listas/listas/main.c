#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int* alocaVetor(int tam){
    int *v;
    v = (int*) malloc(tam * sizeof(int));
    return v;
}

void imprimeVetorSequencial(int *vetor, int tamanhodaLista){
    for(int i=0; i<tamanhodaLista; i++){
       printf("\nValor %d: %d",i, vetor[i]);
    }
}

int main(){
    system("color B0");
    int vetor[TAM] = {4,5,6}, tamanhodaLista;

    imprimeVetorSequencial(vetor, 3);

    for(int i=0; i< TAM; i++){
        printf("\nDigite os novos valores do vetor: ", " ");
        scanf("%d", &vetor[i]);
    }
    imprimeVetorSequencial(vetor, 3);

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &tamanhodaLista);

    int* vetorLido;
    vetorLido = alocaVetor(tamanhodaLista);

    for(int i=0; i< tamanhodaLista; i++){
        printf("\nDigite os novos valores do vetor: ", " ");
        scanf("%d", &vetorLido[i]);

    }

    imprimeVetorSequencial(vetorLido, tamanhodaLista);

return 0;
}

