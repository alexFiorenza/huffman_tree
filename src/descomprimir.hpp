#ifndef DESCOMPRIMIR_H_
#define DESCOMPRIMIR_H_

#include "api/funciones/strings.hpp"
#include "api/tads/huffman/HuffmanSetup.hpp"
#include <string>

using namespace std;

HuffmanTreeInfo *recomponerArbol(FILE *f);
void grabarArchivoDescomprimido(HuffmanTreeInfo *ht, FILE *f,
                                string nuevoFName);

void descomprimir(string fName)
{
  FILE *f = fopen(fName.c_str(), "rb");

  // Recrear el arbol a partir de las entradas al comienzo del archivo.
  HuffmanTreeInfo *ht = recomponerArbol(f);

  // Remover el .huf para obtener el nuevo nombre del archivo.
  string nuevoFName = substring(fName, 0, length(fName) - 4);

  // Leer entradas comprimidas y grabar su equivalente descomprimido.
  grabarArchivoDescomprimido(ht, f, nuevoFName);

  fclose(f);
}

HuffmanTreeInfo *recomponerArbol(FILE *f)
{
  // TODO
  return {};
}

void grabarArchivoDescomprimido(HuffmanTreeInfo *ht, FILE *f, string nuevoFName)
{
  // TODO
}

#endif
