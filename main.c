#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(void) {
  Filmes *filmes;
  filmes = NULL;
  printf("\n1. Inserir filmes e listar eles_______________________\n");
  InserirFilme(&filmes, "Alaskaban", 1298, "Acao");
  InserirFilme(&filmes, "E o reino", 1399, "Acao");
  InserirFilme(&filmes, "De godah", 1488, "Acao");
  InserirFilme(&filmes, "Amém", 1698, "Preguica");
  InserirFilme(&filmes, "Harry Potter", 1999, "Magia");
  InserirFilme(&filmes, "Excalibur", 1698, "Lenda");
  ListarFilmes(&filmes);
  printf("\n_______________________\n");
  printf("\n2. Atualizar Filme_______________________\n");
  AtualizarFilme(&filmes, 202003, 1904, "Rei de ipanema", "Ficção");
  ListarFilmes(&filmes);
  printf("\n_______________________\n");
  printf("\n3. Total de filmes_______________________\n");
  TotalFilmes(&filmes);
  printf("\n_______________________\n");
  printf("\n4. Total de generos_______________________\n");
  TotalGenero(&filmes, "Acao");
  printf("\n_______________________\n");
  printf("\n5. Buscar filme_______________________\n");
  BuscarFilme(&filmes, 202003);
  printf("\n_______________________\n");
  printf("\n6. Buscar filme por gênero_______________________\n");
  BuscarGenero(&filmes, "Ficção");
  printf("\n_______________________\n");
  printf("\n7. Buscar filme mais antigo_______________________\n");
  BuscarMaisAntigo(&filmes);
  printf("\n_______________________\n");
  printf("\n8. Remover filme_______________________\n");
  ListarFilmes(&filmes);
  printf("\n______________________________________\n");
  RemoverFilme(&filmes, 202006);
  ListarFilmes(&filmes);
  printf("\n______________________________________\n");
  return 0;
}