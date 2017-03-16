#define LINUX // WINDOWS ou LINUX
#include <stdlib.h>
#include <stdio.h>
#include "../tempo.h"

int valorAleatorioExistente(int tamVetor) {
  return rand() % tamVetor;
}

int alimentaVETOrdenado(int *v, int t) {

	int i;
	
	for (i = 0; i < t; i++) {
		v[i] = i;
	}
	return(i);

}

int buscaSequencialValor(int *vetor, int tam, int valor) {

	int i;
	int intervalo;

  tempo();

	for ( i = 0 ; i < tam ; i++ ) {
		if ( vetor[i] == valor ) {
         intervalo = tempo();
         fprintf(stdout, "Encontrou o valor em: ");
         fprintf(stdout, formata(intervalo));
	       return valor;
		}
	}

  intervalo = tempo();
  fprintf(stdout, "Nao encontrou o valor em: ");
  fprintf(stdout, formata(intervalo));
	return NULL;

}

int forRecursivo(int *vetor, int valor, int index) {
    return vetor[index] == valor ? valor : forRecursivo(vetor, valor, ++index);
}

int buscaBinariaRecursiva(int *vetor, int tam, int valor) {

	int i;
	int intervalo;

  tempo();

  forRecursivo(vetor, valor, 0);

	for ( i = 0 ; i < tam ; i++ ) {
		if ( vetor[i] == valor ) {
      intervalo = tempo();
      fprintf(stdout, "Encontrou o valor em: ");
      fprintf(stdout, formata(intervalo));
	    return valor;
		}
	}

  intervalo = tempo();
  fprintf(stdout, "Nao encontrou o valor em: ");
  fprintf(stdout, formata(intervalo));
	return NULL;

}


int main(int argc, char *argv[])  {
	
	int *vetor;
	int tam;
	int valor = searchValue;

	if (argc != 2){
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

	alimentaVETOrdenado(vetor, tam);

  fprintf(stdout, "Busca sequencial de um valor aleatorio existente: \n");
	buscaSequencialValor(vetor, tam, valorAleatorioExistente);

  fprintf(stdout, "\n\nBusca sequencial de um valor inexistente: \n");
  buscaSequencialValor(vetor, tam, tam + 1);

  fprintf(stdout, "\n\nBusca binaria recursiva de um valor aleatorio existente: \n");
  buscaBinariaRecursiva(vetor, tam, valorAleatorioExistente);

	free(vetor);
}