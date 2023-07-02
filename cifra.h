// cifra.h

#ifndef CIFRA_H // Verifica se CIFRA_H não foi definido para evitar inclusões múltiplas
#define CIFRA_H // Define CIFRA_H

#include <stdio.h>

#define TAM 9
#define SYMBOLS 256

typedef unsigned char byte;

void Cifra(byte *bloco, char *chave, int itens); // Declaração da função Cifra

void Decifra(byte *bloco, char *chave, int itens); // Declaração da função Decifra

#endif // CIFRA_H
