#include "Filmes.c"

void InserirFilme(Filmes **filmes, char *titulo, int ano, char *genero);

void AtualizarFilme(Filmes **filmes, int cod, int ano, char *titulo, char *genero);

void ListarFilmes(Filmes **filmes);

void TotalFilmes(Filmes **filmes);

void TotalGenero(Filmes **filmes, char *genero);

void BuscarFilme(Filmes **filmes, int codigo);

void BuscarGenero(Filmes **filmes, char *genero);

void BuscarMaisAntigo(Filmes **filmes);

void RemoverFilme(Filmes **filmes, int codigo);