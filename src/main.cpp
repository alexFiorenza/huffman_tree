#ifndef _MAIN
#define _MAIN

#include "main.hpp"
#include "api/funciones/files.hpp"
#include "api/funciones/strings.hpp"
#include "api/funciones/tokens.hpp"
#include "api/tads/Array.hpp"
#include "api/tads/Coll.hpp"
#include "api/tads/List.hpp"
#include "api/tads/Map.hpp"
#include "api/tads/Queue.hpp"
#include "api/tads/Stack.hpp"

#include "comprimir.hpp"
#include "descomprimir.hpp"

#include <iostream>

using namespace std;
int main(int argc, char **argv)
{
  string fName = argv[1];

  if (!endsWith(fName, ".huf"))
  {
    comprimir(fName);
  }
  else
  {
    descomprimir(fName);
  }

  return 0;
}

#endif
