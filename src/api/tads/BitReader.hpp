#ifndef BITREADER_H_
#define BITREADER_H_

#include "../funciones/files.hpp"

#include <math.h>

#define uchar unsigned char

using namespace std;

struct BitReader
{
  bool bits[8];
  int bitNum; // Cantidad de bits ya leídos
  FILE *f;
};

BitReader bitReader(FILE *f)
{
  BitReader br;
  br.bitNum = 8; // Como si no quedaran bits
  br.f = f;

  return br;
}

// Funciones auxiliares
void _readByte(bool arr[8], FILE *f);

int bitReaderRead(BitReader &br)
{
  // Si no hay mas bits, leer un nuevo byte.
  if (br.bitNum >= 8)
  {
    _readByte(br.bits, br.f);

    br.bitNum = 0;
  }
  int bit = (int)br.bits[br.bitNum];
  br.bitNum++;
  return bit;
}

void _readByte(bool arr[8], FILE *f)
{
  uchar byte = read<uchar>(f);

  // Dividir el char en bits y almacenarlos en el array.
  for (int i = 0; i < 8; i++)
  {
    // Obtener el bit en la posicion i.
    int val = (bool)(byte / (int)pow(2, 7 - i));
    arr[i] = (bool)val;

    byte -= val * pow(2, 7 - i);
  }
};

#endif // BITREADER_H_
