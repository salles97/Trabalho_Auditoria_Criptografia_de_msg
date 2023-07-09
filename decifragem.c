// #include <stdio.h>
// #include <stdlib.h>
typedef unsigned char byte;

void decifra(byte *bloco, char *chave, int itens)
{
  int i;
  for (i = 0; i < itens; i++)
  {
    if (i % 2 == 0)
      bloco[i] = ((bloco[i] - (chave[i] << 1)) << 1);
    else
      bloco[i] = ((bloco[i] - (chave[i] >> 1)) >> 1);
    // printf("[%d] %3d\n", i, bloco[i]);
  }
}