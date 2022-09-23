#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

// A template function that writes a value of type T to a file.
template <typename T>
void write(FILE *f, T t)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   fseek(f, 0, SEEK_CUR);
   fwrite(&t, sizeof(T), 1, f);
}

template <typename T>
T read(FILE *f)
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //
   fseek(f, 0, SEEK_CUR);
   T t;
   fread(&t, sizeof(T), 1, f);
   return t;
}

// Seeking to a position in the file.
template <typename T>
void seek(FILE *f, int n)
{
   // SEEK_SET – It moves file pointer position to the beginning of the file
   fseek(f, sizeof(T) * n, SEEK_SET);
}

// Getting the size of the file.
template <typename T>
int fileSize(FILE *f)
{
   long lastPos = ftell(f) / sizeof(T);
   // Now I set the current position to last one
   fseek(f, 0, SEEK_END);
   int sizeOfFile = ftell(f) / sizeof(T);
   seek<T>(f, lastPos);
   return sizeOfFile;
}

template <typename T>
int filePos(FILE *f)
{
   return ftell(f) / sizeof(T);
}

#endif
