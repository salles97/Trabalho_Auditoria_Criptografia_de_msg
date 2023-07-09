#include <stdio.h>

typedef unsigned char byte;

void cifra(byte *bloco, char *chave, int itens)
{
  int i;
  for (i = 0; i < itens; i++)
  {
    if (i % 2 == 0)
      bloco[i] = (bloco[i] >> 1) + (chave[i] << 1);
    else
      bloco[i] = (bloco[i] << 1) + (chave[i] >> 1);
    // printf("[%d] %3d\n", i, bloco[i]);
  }
}
