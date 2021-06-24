#include <stdio.h>
#include <string.h>
#include "Filmes.c"

void InserirFilme(Filmes **filmes, char *titulo, int ano, char *genero) {
  Filmes *nf = (Filmes*) malloc(sizeof(Filmes));
  nf->titulo = (char*) malloc (25*sizeof(char));
  nf->genero = (char*) malloc (25*sizeof(char));

  nf->titulo = titulo;
  nf->genero = genero;
  nf->ano = ano;
  nf->prox = NULL;
  if(*filmes==NULL) { 
    nf->codigo = 202001;
    *filmes = nf;
  }
  else{
    int cod = 202002;
    Filmes *aux = *filmes;
    while(aux->prox != NULL){
      cod++;
      aux = aux->prox;
    }
    nf->codigo = cod;
    aux->prox = nf;
  }

}

void AtualizarFilme(Filmes **filmes, int cod, int ano, char *titulo, char *genero){
  Filmes *aux = *filmes;
  while(aux != NULL){
    if(aux->codigo == cod){
      aux->ano = ano;
      aux->titulo = titulo;
      aux->genero = genero;
    }
    aux = aux->prox;
  }
}
void ListarFilmes(Filmes **filmes){
  Filmes *aux = *filmes;
  while(aux != NULL){
    printf("Título: %s | Ano: %d | Gênero: %s | Código: %d\n", aux->titulo, aux->ano, aux->genero, aux->codigo);
    aux = aux->prox;
  }
}
void TotalFilmes(Filmes **filmes){
  Filmes *aux = *filmes;
  int total = 0;
  while(aux != NULL){
    aux = aux->prox;
    total++;
  }
  printf("\nTotal de filmes cadastrados: %d\n", total);
}

void TotalGenero(Filmes **filmes, char *genero){
  Filmes *aux = *filmes;
  int total = 0;
  while(aux != NULL){
    if(strcmp(aux->genero, genero) == 0){
      total++;
    }
    aux = aux->prox;
  }
  printf("\nTotal de filmes do gênero %s cadastrados: %d\n", genero, total);
}

void BuscarFilme(Filmes **filmes, int codigo){
  Filmes *aux = *filmes;
  while(aux != NULL){
    if(aux->codigo == codigo){
      printf("\nINFO. FILME\nTITULO: %s | ANO: %d | GÊNERO: %s\n", aux->titulo, aux->ano, aux->genero);
    }
    aux = aux->prox;
  }
}

void BuscarGenero(Filmes **filmes, char *genero){
  Filmes *aux = *filmes;
  printf("\nINFO. FILMES DO GÊNERO: %s\n", genero);
  while(aux != NULL){
    if(strcmp(aux->genero, genero) == 0){
      printf("\nTITULO: %s | ANO: %d | GÊNERO: %s\n", aux->titulo, aux->ano, aux->genero);
    }
    aux = aux->prox;
  }
}

void BuscarMaisAntigo(Filmes **filmes){
  Filmes *aux = *filmes;
  Filmes *fa;
  int ano = 999999;
  while(aux != NULL){
    if(aux->ano < ano){
      ano = aux->ano;
      fa = aux;
    }
    aux = aux->prox;
  }
  printf("\nFilmes mais antigo:\nTitulo: %s | Ano: %d | Genero: %s | Código: %d", fa->titulo, fa->ano, fa->genero, fa->codigo);
}

void RemoverFilme(Filmes **filmes, int codigo){
  Filmes *aux = *filmes;
  if(codigo == 202001){
    *filmes = aux->prox;
    //free(aux);
  }
  else{
    Filmes *anterior;
    Filmes *sucessor;
    Filmes *excluir;
    while(aux->prox != NULL){
      if(aux->prox->codigo == codigo){
        anterior = aux;
        excluir = aux->prox;
        sucessor = aux->prox->prox;
        break;
      }
      aux = aux->prox;
    }
    anterior->prox = sucessor;
    free(excluir);
  }

}