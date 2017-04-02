/* TITULO: Resposta da questão 6 do T14
 * DATA: 28/Março/2017
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct {
    char nome[200];
    char idade;
    char observacao[30000];
    int valor;
} DADOS;

/* BEGIN Contribuição do aluno */
/* Esta função precisava ser implementada */
int compara(DADOS * i, DADOS * f)
{
    int c;

    c = strcasecmp(f->nome, i->nome);
    if (c) {
        // Não são iguais. Basta retornar o resultado da comparação
        return (c);
    }

    /* Se empate, ou seja, c==0 (nomes iguais) o critério de desempate
     * é a idade */
    return (f->idade - i->idade);
}

/* END contribuição do aluno */

int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);

        if (letra == 13) {
            i = i - 1;
            continue;
        }
        if ((letra == 10) && (i == 0)) {
            i = i - 1;
            continue;
        }
        if (letra == 10) {
            break;
        }
        s[i] = letra;
    }
    s[i] = 0;
    return (i);
}

int imprime_vet(DADOS * v, int t)
{
    int i;

    for (i = 0; i < t; i++) {
        printf("Elemento [%d]\n\tNome: [%s]\n\tIdade: [%d]\n\tObservacao: [%s]\n\tValor:[%d]\n", i, v[i].nome, v[i].idade, v[i].observacao, v[i].valor);
    }
}

int ledados(DADOS * v, int t)
{
    int i;
    printf("Digite dados:\n");

    for (i = 0; i < t; i++) {
        printf("v[%d].nome: ", i);
        lestring(v[i].nome, 200);

        printf("v[%d].idade: ", i);
        scanf("%d", (int *) &v[i].idade);

        printf("v[%d].observacao: ", i);
        lestring(v[i].observacao, 30000);

        printf("v[%d].valor: ", i);
        scanf("%d", &v[i].valor);
    }
    return (i);
}

int main()
{
    // tamanho do vetor pode vir em argv[1]
    int tam;
    DADOS *vet;

/* Digita tam ou vem de um arquivo */
    if (tam == 0) {
        printf("Quantos elementos você quer? \n");
        scanf("%d", &tam);
    }

    vet = (DADOS *) malloc(tam * sizeof(DADOS));
    if (vet == NULL) {
        fprintf(stderr, "ERRO NO MALLOC\n");
        return (1);
    }

    ledados(vet, tam);
    imprime_vet(vet, tam);

    /* BEGIN contribuição do aluno */
    /* Esta chamada precisava ser implementada */
    qsort(vet, tam, sizeof(DADOS), (int (*)(const void *, const void *)) compara);
    /* END contribuição do aluno */

    /* Todo o resto do código foi previamente fornecido */
    imprime_vet(vet, tam);
}
