#define LINUX // WINDOWS ou LINUX
#include <stdlib.h>
#include <stdio.h>
#include "../tempo.h"

int alimentaVETAleatorio(int *v, int t) {

	int i;
	int MAX = 20000000; // seria de -20000000 a 20000000
	
	for (i = 0; i < t; i++) {
		v[i] = (rand() % (MAX+MAX)) - MAX;
	}
	return(i);

}

int sequencial(int n) {
	if (n < 0) return -1;
	return n > 0 ? n + sequencial(--n) : 0;
}

int ordenaDados(int *v, int tam) {
  int i, j, x;
 
  for (i = 0 ; i < ( tam - 1 ); i++) {
    for (j = 0 ; j < tam - i - 1; j++) {
      if (v[j] > v[j+1]) {
        x      = v[j];
        v[j]   = v[j+1];
        v[j+1] = x;
      }
    }
  }
}

int buscaSequencialValor(int *vetor, int tam, int valor) {

	int i;
	int intervalo;

	tempo();

	for ( i = 0 ; i < tam ; i++ ) {
		if ( vetor[i] == valor ) {
	       intervalo = tempo;
	       return sequencial(valor);
		}
	}

	intervalo = tempo;
	return NULL;

}


int main(int argc, char *argv[])  {
	
	int *vetor;
	int tam;
	int valor = 10; /* Depois usar um rand (valor aleatório) 
					   DICA: para pegar um valor não existente no vetor,
					   basta procurar por um valor fora do range da funcao "geraVetAleatorio"
					*/
	
	if (argc!=2){
		fprintf(stderr, "Erro. Precisa passar o tamanho do vetor\n");
		return(1);
	}

	tam = atoi(argv[1]);
	vetor = (int *) malloc(tam * sizeof(int));

	if (vetor == NULL) {
		fprintf(stderr, "ERRO ao tentar alocar %d inteiros\n", tam);
		return(2);
	}

	srand(time(NULL));

	alimentaVETAleatorio(vetor, tam);

	ordenaDados(vetor, tam);

	buscaSequencialValor(vetor, tam, valor);

	free(vetor);
}