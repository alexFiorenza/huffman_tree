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
void crearLista(List<HuffmanTreeInfo> lista, HuffmanTable tabla[]);
HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo> lista);
void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmanTable tabla[]);
void grabarArchivoComprimido(string fName, HuffmanTable tabla[]);

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
  // Se crea un mapa que apunte byte(key,char) => ocurrencias (value,int)
  Map<char, int> mapaByteOcurrencias = map<char, int>();
  FILE *f = fopen("test.txt", "r+b");
  while (!feof(f))
  {
    unsigned char myByte = read<unsigned char>(f);
    if (mapContains(mapaByteOcurrencias, myByte))
    {
      int *p = *mapGet(mapaByteOcurrencias, myByte);
    }
  }
}
void crearLista(List<HuffmanTreeInfo> lista, HuffmanTable tabla[])
{
  // TODO
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

#endif // COMPRIMIR_H_
