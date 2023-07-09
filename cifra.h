#ifndef CIFRA_H // Verifica se CIFRA_H não foi definido para evitar inclusões múltiplas

#define CIFRA_H // Define CIFRA_H

#include <stddef.h>

#include <stdio.h>

typedef unsigned char byte;

#define TAM 9
#define SYMBOLS 256

typedef unsigned char byte;

void cifra(byte *bloco, char *chave, int itens); // Declaração da função Cifra

void decifra(byte *bloco, char *chave, int itens); // Declaração da função Decifra

void calculaHash(const unsigned char *data, size_t data_len, unsigned char *hash);

#endif // CIFRA_H
