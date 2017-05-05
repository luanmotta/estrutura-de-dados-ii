char buscaARVBin(struct AV *raiz, char nomebuscado[]) {

  if (raiz == NULL)
    return NULL;
  
  if (raiz->nome == nomebuscado || buscaARVBin(raiz->esq, nomebuscado) || buscaARVBin(raiz->dir, nomebuscado)
    return nomebuscado;

  return NULL;
}

// pensei em fazer essa funcao de maneira iterativa, apenas comecei.
int impArvVal(struct AV *raiz, int valorbuscado) {

  while (*raiz != NULL) {

    if (raiz->valor == valorbuscado)
      printf("%s", raiz->nome);

    

  }

  if (raiz == NULL)
    return NULL;
  
  if (raiz->nome == nomebuscado || buscaARVBin(raiz->esq, nomebuscado) || buscaARVBin(raiz->dir, nomebuscado)
    return nomebuscado;

}