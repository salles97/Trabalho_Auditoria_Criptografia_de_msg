/********************************************************
 *  gcc ProgramaBaseCifragem.c cifragem.c decifragem.c -o cifragem *
 *  Para executar ./cifragem                             *
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "cifra.h"

#define TAM 9
#define SYMBOLS 256

int main()
{
  char BlocoDados[TAM], ChaveCifragem[TAM];
  FILE *ArquivoEntrada, *ArquivoSaida;
  char NomeArquivoEntrada[30], NomeArquivoSaida[30];
  int Itens, opcao;

  printf("Digite 1 para cifrar, 2 para decifrar: ");
  scanf("%d", &opcao);

  printf("Entre com o Nome do Arquivo Para criptografar ou descriptografar = ");
  scanf("%s", NomeArquivoEntrada);
  printf("Entre com o Nome do Arquivo para salvar o resultado = ");
  scanf("%s", NomeArquivoSaida);
  printf("Entre com uma senha de 9 digitos = ");
  scanf("%s", ChaveCifragem);

  ArquivoEntrada = fopen(NomeArquivoEntrada, "rb");
  ArquivoSaida = fopen(NomeArquivoSaida, "wb");
  do
  {
    Itens = fread(BlocoDados, 1, TAM, ArquivoEntrada);
    if (Itens != 0)
    {
      if (opcao == 1)
      {
        Cifra(BlocoDados, ChaveCifragem, Itens);
      }
      else if (opcao == 2)
      {
        Decifra(BlocoDados, ChaveCifragem, Itens);
      }
      fwrite(BlocoDados, Itens, 1, ArquivoSaida);
    }
  } while (!feof(ArquivoEntrada));

  fclose(ArquivoSaida);
  fclose(ArquivoEntrada);

  return 0;
}
