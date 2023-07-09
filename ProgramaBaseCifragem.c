// Inclua as bibliotecas padrão necessárias e a biblioteca personalizada "cifra.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cifra.h"

// Define o tamanho do bloco de dados e o tamanho do hash
#define TAM 9
#define HASH_SIZE 9

// Definir byte como char sem sinal
typedef unsigned char byte;

int main()
{
  // Inicializa variáveis
  byte BlocoDados[TAM], ChaveCifragem[TAM];          // Blocos de dados e chave de cifragem
  FILE *ArquivoEntrada, *ArquivoSaida;               // Ponteiros para arquivos de entrada e saída
  char NomeArquivoEntrada[30], NomeArquivoSaida[30]; // Nomes dos arquivos de entrada e saída
  int itens, opcao;                                  // Número de itens lidos do arquivo e a opção do usuário

  // Solicita ao usuário para escolher cifrar ou decifrar
  printf("Digite 1 para cifrar, 2 para decifrar: ");
  scanf("%d", &opcao);

  // Solicita ao usuário os nomes dos arquivos e a chave de cifragem
  printf("Entre com o Nome do Arquivo Para criptografar ou descriptografar = ");
  scanf("%s", NomeArquivoEntrada);
  printf("Entre com o Nome do Arquivo para salvar o resultado = ");
  scanf("%s", NomeArquivoSaida);
  printf("Entre com uma senha de 9 digitos = ");
  scanf("%s", ChaveCifragem);

  // Abre os arquivos de entrada e saída
  ArquivoEntrada = fopen(NomeArquivoEntrada, "rb");
  ArquivoSaida = fopen(NomeArquivoSaida, "wb");

  // Se a opção for 1, então cifre
  if (opcao == 1)
  {
    do
    {
      // Leia os dados do arquivo de entrada
      itens = fread(BlocoDados, 1, TAM, ArquivoEntrada);
      // Se o fim do arquivo ainda não foi atingido
      if (itens != 0)
      {
        // Calcule o hash dos dados lidos
        byte hash[HASH_SIZE];
        calculaHash(BlocoDados, itens, hash);

        // Concatene os dados e o hash
        byte mensagemComHash[TAM + HASH_SIZE];
        memcpy(mensagemComHash, BlocoDados, TAM);
        memcpy(mensagemComHash + TAM, hash, HASH_SIZE);

        // Cifre a mensagem com a chave
        cifra(mensagemComHash, ChaveCifragem, TAM + HASH_SIZE);
        // Escreva a mensagem cifrada no arquivo de saída
        fwrite(mensagemComHash, 1, TAM + HASH_SIZE, ArquivoSaida);
      }
    } while (itens != 0); // Continue até que todos os dados sejam cifrados
  }
  else if (opcao == 2) // Se a opção for 2, então decifre
  {
    do
    {
      // Leia os dados do arquivo de entrada
      itens = fread(BlocoDados, 1, TAM + HASH_SIZE, ArquivoEntrada);
      // Se o fim do arquivo ainda não foi atingido
      if (itens > 0)
      {
        // Decifre a mensagem com a chave
        decifra(BlocoDados, ChaveCifragem, TAM + HASH_SIZE);

        // Separe a mensagem e o hash
        byte mensagem[TAM];
        byte hash[HASH_SIZE];

        memcpy(mensagem, BlocoDados, TAM);
        memcpy(hash, BlocoDados + TAM, HASH_SIZE);

        // Calcule o hash da mensagem
        byte hash_calculado[HASH_SIZE];
        calculaHash(mensagem, TAM, hash_calculado);

        // Se o hash calculado não corresponder ao hash original, imprima um erro
        if (memcmp(hash, hash_calculado, HASH_SIZE) != 0)
        {
          printf("Hash inválido! Os dados foram alterados.\n");
          fwrite(mensagem, 1, TAM, ArquivoSaida);
        }
        else // Se os hashes corresponderem, escreva a mensagem no arquivo de saída
        {
          fwrite(mensagem, 1, TAM, ArquivoSaida);
        }
      }
    } while (itens > 0); // Continue até que todos os dados sejam decifrados
  }

  // Feche os arquivos de entrada e saída
  fclose(ArquivoSaida);
  fclose(ArquivoEntrada);

  // Finalize o programa
  return 0;
}
