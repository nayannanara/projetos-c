#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <math.h>


/*
	4° Questão:
	Através do comando de repetição FOR escreva um algoritmo que leia uma variável para condição de parada e retorne as seguintes ações:  (Usar Vetores)
	Média dos números pares
	Média dos números ímpares
	A Raiz Quadrada  do número que é a condição de parada

*/

int main()
{
	int k = NULL;	
	int variavelParada = 0;
	float mediaPar = 0;
	float mediaImpar = 0;
	int qtdPar = 0;
	int qtdImpar = 0;
	float raizQuadrada = 0;
	
	printf("Digite um numero q sera a variavel de parada: ");
    scanf("%d", &variavelParada);

	printf("Agora digite o tamanho do vetor: ");
	scanf("%d", &k);

	srand(time(NULL));
	int vetor[k];
	
    for(int i = 0; i < k; i++){
		vetor[i] = rand() % 10 + 1;
        printf("%d\n", vetor[i]);
        if(vetor[i] % 2 == 0){
    		mediaPar += vetor[i];
			qtdPar++;
		}else{
			mediaImpar += vetor[i];
			qtdImpar++;
		}
		
		/*if(vetor[i] == variavelParada){
			raizQuadrada = sqrt(variavelParada);
			break;
		}*/
			
    }
    raizQuadrada = sqrt(variavelParada);
    printf("a media dos numeros pares eh %f \n", mediaPar/qtdPar);
    printf("a media dos numeros impares eh %f \n", mediaImpar/qtdImpar);
    printf("o numero de parada eh %d, e a sua raiz quadrada eh %f ", variavelParada, raizQuadrada);
}