#define WINDOWS // WINDOWS ou LINUX
#include <stdlib.h>
#include <stdio.h>
#include "../tempo.h"

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
      fprintf(stdout, "Encontrou o valor %i em: ", valor);
      fprintf(stdout, formata(intervalo));
	    return valor;
		}
	}

  intervalo = tempo();
  fprintf(stdout, "Nao encontrou o valor em: ");
  fprintf(stdout, formata(intervalo));
	return NULL;

}

int recursiva(int *vetor, int valor, int inicio, int fim) {
	int metade = (inicio + fim) / 2;
	if (vetor[metade] != valor) {
		if (valor > vetor[metade]) {
			if (vetor[metade + 1] && vetor[metade + 1] <= fim)
				return recursiva(vetor, valor, metade + 1, fim);
				return NULL;
		} else {
			if (vetor[metade - 1])
			  return recursiva(vetor, valor, inicio, metade - 1);
   			return NULL;
		}
	}
	return valor;
}

int buscaBinariaRecursiva(int *vetor, int tam, int valor) {

  int intervalo, result;

  tempo();

  result = recursiva(vetor, valor, 0, tam);

  if ( result == valor ) {
    intervalo = tempo();
    fprintf(stdout, "Encontrou o valor %i em: ", valor);
    fprintf(stdout, formata(intervalo));
    return valor;
  }

  intervalo = tempo();
  fprintf(stdout, "Nao encontrou o valor em: ");
  fprintf(stdout, formata(intervalo));
	return NULL;

}

int buscaBinariaIterativa(int *vetor, int tam, int valor) {

  int intervalo, metade;
  int inicio = 0, fim = tam;

  tempo();

  while (1) {
  	metade = (inicio + fim) / 2;
		if (vetor[metade] != valor) {
			if (valor > vetor[metade]) {
				if (vetor[metade + 1] && vetor[metade + 1] <= fim)
					inicio = metade + 1;
				else break;
			} else {
				if (vetor[metade - 1])
				  fim = metade - 1;
	   		else break;
			}
		} else {
			intervalo = tempo();
	    fprintf(stdout, "Encontrou o valor %i em: ", valor);
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

	int valorAleatorioExistente = rand() % tam;

  fprintf(stdout, "Busca sequencial de um valor aleatorio existente: \n");
	buscaSequencialValor(vetor, tam, valorAleatorioExistente);

  fprintf(stdout, "\n\nBusca sequencial de um valor inexistente: \n");
  buscaSequencialValor(vetor, tam, tam + 1);

  fprintf(stdout, "\n\nBusca binaria recursiva de um valor aleatorio existente: \n");
  buscaBinariaRecursiva(vetor, tam, valorAleatorioExistente);

  fprintf(stdout, "\n\nBusca binaria recursiva de um valor inexistente: \n");
  buscaBinariaRecursiva(vetor, tam, tam + 1);

  fprintf(stdout, "\n\nBusca binaria iterativa de um valor aleatorio existente: \n");
  buscaBinariaIterativa(vetor, tam, valorAleatorioExistente);

  fprintf(stdout, "\n\nBusca binaria iterativa de um valor inexistente: \n");
  buscaBinariaIterativa(vetor, tam, tam + 1);


	free(vetor);

	return(0);
}
