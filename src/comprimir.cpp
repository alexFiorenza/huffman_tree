#include "main.hpp"

#include "api/tads/huffman/HuffmanSetup.hpp"
#include <string>

using namespace std;

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
