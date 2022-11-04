#ifndef DESCOMPRIMIR_H_
#define DESCOMPRIMIR_H_

#include "api/funciones/files.hpp"
#include "api/funciones/strings.hpp"
#include "api/tads/BitReader.hpp"
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
  // Recuperar numero de hojas.
  int numHojas = read<unsigned char>(f);

  HuffmanTreeInfo *raiz = huffmanTreeInfo(256, 0, NULL, NULL);

  // Leer registros de codigos.
  for (int i = 0; i < numHojas; i++)
  {
    // Numero (ascii) del byte.
    unsigned char numElemento = read<unsigned char>(f);
    // Longitud del codigo en bits.
    unsigned char codLen = read<unsigned char>(f);

    // Leer codigo bit por bit, creando nodos necesarios en el arbol.
    HuffmanTreeInfo *aux = raiz;
    BitReader br = bitReader(f);
    for (int j = 0; j < codLen - 1; j++)
    {
      if (bitReaderRead(br) == 1) // Si es uno, ir a derecha.
      {
        // Crear el elemento si es necesario, y moverse a la derecha.
        if (aux->right == NULL)
        {
          aux->right = huffmanTreeInfo(256, 0, NULL, NULL);
        }
        aux = aux->right;
      }
      else // Si es cero, ir a izquierda.
      {
        // Crear el elemento si es necesario, y moverse a la izquierda.
        if (aux->left == NULL)
        {
          aux->left = huffmanTreeInfo(256, 0, NULL, NULL);
        }
        aux = aux->left;
      }
    }
    // Luego de crear todas las ramas del arbol, ubicar el elemento como una
    // hoja.
    if (bitReaderRead(br) == 1) // Leer el ultimo bit del codigo.
    {
      aux->right = huffmanTreeInfo(numElemento, 0, NULL, NULL);
    }
    else
    {
      aux->left = huffmanTreeInfo(numElemento, 0, NULL, NULL);
    }
  }
  return raiz;
}

void grabarArchivoDescomprimido(HuffmanTreeInfo *ht, FILE *f, string nuevoFName)
{
  // TODO
}

#endif
