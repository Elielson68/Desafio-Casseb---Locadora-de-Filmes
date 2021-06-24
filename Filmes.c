#include <stdio.h>
#include <stdlib.h>

typedef struct filmes {
  int codigo;
	char *titulo;
	int ano;
	char *genero;
  struct filmes *prox;
} Filmes;