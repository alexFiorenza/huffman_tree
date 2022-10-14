#ifndef COMPRIMIR_H_
#define COMPRIMIR_H_

#include "api/tads/huffman/HuffmanSetup.hpp"
#include <string>

using namespace std;

struct HuffmanTable
{
  string codigo;
  int count;
};

// Declaraciones de funciones
void contarOcurrencias(string fName, HuffmanTable tabla[]);
void crearLista(List<HuffmanTreeInfo> &lista, HuffmanTable tabla[]);
HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo> lista);
void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmanTable tabla[]);
void grabarArchivoComprimido(string fName, HuffmanTable tabla[]);

int cmpHuffmanTreeInfoCount(HuffmanTreeInfo a, HuffmanTreeInfo b);

void comprimir(string fName)
{
  HuffmanTable tabla[256];
  contarOcurrencias(fName, tabla);

  List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
  crearLista(lista, tabla);

  HuffmanTreeInfo *raiz = crearArbol(lista);

  cargarCodigosEnTabla(raiz, tabla);

  grabarArchivoComprimido(fName, tabla);
}

void contarOcurrencias(string fName, HuffmanTable tabla[])
{
  // TODO
}

void crearLista(List<HuffmanTreeInfo> &lista, HuffmanTable tabla[])
{
  for (int i = 0; i < 256; i++)
  {
    // Si hay 1 o mas ocurrencias, agregarlo a la lista.
    if (tabla[i].count > 0)
    {
      HuffmanTreeInfo *hti = huffmanTreeInfo(i, tabla[i].count, NULL, NULL);
      listAdd<HuffmanTreeInfo>(lista, *hti);
    }
  }
  listSort<HuffmanTreeInfo>(lista, cmpHuffmanTreeInfoCount);
}

HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo> lista)
{
  // TODO
}

void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmanTable tabla[])
{
  // TODO
}

void grabarArchivoComprimido(string fName, HuffmanTable tabla[])
{
  // TODO
}

int cmpHuffmanTreeInfoCount(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
  return a.n - b.n;
}

#endif // COMPRIMIR_H_
