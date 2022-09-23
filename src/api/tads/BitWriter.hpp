#ifndef BITWRITER_H_
#define BITWRITER_H_

#include "../funciones/files.hpp"

#include <math.h>

using namespace std;

struct BitWriter
{
  bool bits[8];
  int bitNum; // Numero de bits en el array.
  FILE *f;
};

BitWriter bitWriter(FILE *f)
{
  BitWriter bw;
  bw.bitNum = 0;
  bw.f = f;

  return bw;
}

// Funciones auxiliares.
char _boolArrToChar(bool arr[8]);

void bitWriterWrite(BitWriter &bw, int bit)
{
  bw.bits[bw.bitNum] = (bool)bit;
  bw.bitNum++;

  // Si hay 8 bits escribir un byte.
  if (bw.bitNum == 8)
  {
    write<char>(bw.f, _boolArrToChar(bw.bits));
    bw.bitNum = 0;
  }
}

void bitWriterFlush(BitWriter &bw)
{
  // Completar el array de bits con 0s.
  for (int i = bw.bitNum; i < 8; i++)
  {
    bw.bits[i] = false;
  }
  // Escribir byte.
  write<char>(bw.f, _boolArrToChar(bw.bits));
  bw.bitNum = 0;
}

char _boolArrToChar(bool arr[8])
{
  char c = 0;
  for (int i = 0; i < 8; i++)
  {
    // Valor numerico de el elemento del array.
    int val = (int)arr[i] * pow(2, 7 - i);
    c += val;
  }
  return c;
}

#endif // BITWRITER_H_
