#include <string.h>

void calculaHash(const unsigned char *data, size_t data_len, unsigned char *hash)
{
  unsigned char result = 0;
  for (size_t i = 0; i < data_len; i++)
  {
    result ^= data[i];
  }
  memcpy(hash, &result, sizeof(unsigned char));
}
