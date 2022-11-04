#ifndef COMPRIMIR_H_
#define COMPRIMIR_H_

#include "api/funciones/files.hpp"
#include "api/funciones/strings.hpp"
#include "api/tads/BitWriter.hpp"
#include "api/tads/Map.hpp"
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
void crearLista(List<HuffmanTreeInfo *> &lista, HuffmanTable tabla[]);
HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo *> lista);
void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmanTable tabla[]);
void grabarArchivoComprimido(string fName, HuffmanTable tabla[]);
void grabarHuffmanHeader(FILE *fHuf, HuffmanTable tabla[]);

int cmpHuffmanTreeInfoCount(HuffmanTreeInfo *a, HuffmanTreeInfo *b);

void comprimir(string fName)
{
  HuffmanTable tabla[256];

  // Inicializar tabla
  for (int i = 0; i < 256; i++)
  {
    tabla[i].codigo = "";
    tabla[i].count = 0;
  }

  contarOcurrencias(fName, tabla);

  List<HuffmanTreeInfo *> lista = list<HuffmanTreeInfo *>();
  crearLista(lista, tabla);

  HuffmanTreeInfo *raiz = crearArbol(lista);

  cargarCodigosEnTabla(raiz, tabla);

  grabarArchivoComprimido(fName, tabla);
}

void contarOcurrencias(string fName, HuffmanTable tabla[])
{
  // Se crea un mapa que apunte byte(key,char) => ocurrencias (value,int)
  Map<unsigned char, int> mapaByteOcurrencias = map<unsigned char, int>();
  const char *c = fName.c_str();
  FILE *f = fopen(c, "rb");
  while (!feof(f))
  {
    unsigned char byte = read<unsigned char>(f);
    if (byte == '\0')
      break;
    if (!mapContains(mapaByteOcurrencias, byte))
    {
      mapPut(mapaByteOcurrencias, byte, 1);
      continue;
    }
    int ocurrencias = *mapGet<unsigned char, int>(mapaByteOcurrencias, byte);
    mapPut(mapaByteOcurrencias, byte, ocurrencias + 1);
  }
  fclose(f);
  while (mapHasNext<unsigned char, int>(mapaByteOcurrencias))
  {
    unsigned char key = mapNextKey<unsigned char, int>(mapaByteOcurrencias);
    int value = *mapGet<unsigned char, int>(mapaByteOcurrencias, key);
    tabla[key].count = value;
  }
}

void crearLista(List<HuffmanTreeInfo *> &lista, HuffmanTable tabla[])
{
  for (int i = 0; i < 256; i++)
  {
    // Si hay 1 o mas ocurrencias, agregarlo a la lista.
    if (tabla[i].count > 0)
    {
      HuffmanTreeInfo *hti = huffmanTreeInfo(i, tabla[i].count, NULL, NULL);
      listAdd<HuffmanTreeInfo *>(lista, hti);
    }
  }
  listSort<HuffmanTreeInfo *>(lista, cmpHuffmanTreeInfoCount);
}

HuffmanTreeInfo *crearArbol(List<HuffmanTreeInfo *> lista)
{
  int i = 1;
  while (listSize<HuffmanTreeInfo *>(lista) > 1)
  {
    HuffmanTreeInfo *der = listRemoveFirst<HuffmanTreeInfo *>(lista);
    HuffmanTreeInfo *izq = listRemoveFirst<HuffmanTreeInfo *>(lista);

    long sumaOcurrencias = der->n + izq->n;
    HuffmanTreeInfo *nuevoNodo =
        huffmanTreeInfo(255 + i, sumaOcurrencias, izq, der);

    listOrderedInsert<HuffmanTreeInfo *>(lista, nuevoNodo,
                                         cmpHuffmanTreeInfoCount);

    i++;
  }

  return listRemoveFirst<HuffmanTreeInfo *>(lista);
}

void cargarCodigosEnTabla(HuffmanTreeInfo *raiz, HuffmanTable tabla[])
{
  // TODO
}

void grabarArchivoComprimido(string fName, HuffmanTable tabla[])
{
  string nombreNuevo = fName + ".huf";

  FILE *fHuf = fopen(nombreNuevo.c_str(), "wb");

  grabarHuffmanHeader(fHuf,
                      tabla); // Header que contiene el codigo de cada char.

  unsigned int sizeOriginal = fileSize<unsigned char>(fHuf);

  write<unsigned int>(fHuf, sizeOriginal); // Longitud del archivo original.

  FILE *fOrig = fopen(fName.c_str(), "rb");

  // Escribir el archivo comprimido.
  BitWriter bwHuf = bitWriter(fHuf);

  unsigned char byteOrig = read<unsigned char>(fOrig);
  while (!feof(fOrig))
  {
    string codigo = tabla[byteOrig].codigo;

    // Escribir bit por bit el codigo.
    for (int i = 0; i < length(codigo); i++)
    {
      bitWriterWrite(bwHuf, codigo[i]);
    }

    byteOrig = read<unsigned char>(fOrig);
  }

  fclose(fOrig);
  fclose(fHuf);
}

void grabarHuffmanHeader(FILE *fHuf, HuffmanTable tabla[])
{
  // Contar cuantas hojas hay.
  int numHojas = 0;
  for (int i = 0; i < 256; i++)
  {
    if (tabla[i].count > 0)
    {
      numHojas++;
    }
  }

  // Escribir numero de hojas
  write<unsigned char>(fHuf, numHojas);

  // Escribir cada hoja con sus datos
  for (int i = 0; i < 256; i++)
  {
    if (tabla[i].count <= 0)
    {
      continue;
    }

    write<unsigned char>(fHuf, i); // Codigo en ascii del elemento

    write<unsigned char>(fHuf, length(tabla[i].codigo)); // Largo del codigo.

    string codigo = tabla[i].codigo;

    // Escribir el codigo bit por bit.
    BitWriter bw = bitWriter(fHuf);
    for (int j = 0; j < length(codigo); j++)
    {
      int bit = (codigo[j] == '1') ? 1 : 0;
      bitWriterWrite(bw, bit);
    }
    // Si el codigo no era multiplo de 8, completar con 0s.
    if (length(codigo) % 8 != 0)
    {
      bitWriterFlush(bw);
    }
  }
}

int cmpHuffmanTreeInfoCount(HuffmanTreeInfo *a, HuffmanTreeInfo *b)
{
  return a->n - b->n;
}

#endif // COMPRIMIR_H_
