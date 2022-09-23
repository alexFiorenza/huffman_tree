#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template <typename T>
struct Coll
{
   char sep;
   string token;
   int pos;
};

template <typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.sep = sep;
   c.pos = 0;
   return c;
}

template <typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.sep = '|';
   c.token = "";
   c.pos = 0;
   return c;
}

// A function that returns the size of the collection.
template <typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.token, c.sep);
}

// Removing all the tokens from the collection.
template <typename T>
void collRemoveAll(Coll<T> &c)
{
   c.token = "";
}

// Removing the token at position p from the collection.
template <typename T>
void collRemoveAt(Coll<T> &c, int p)
{
   removeTokenAt(c.token, c.sep, p);
}

// Adding a token to the collection.
template <typename T>
int collAdd(Coll<T> &c, T t, string tToString(T))
{
   addToken(c.token, c.sep, tToString(t));
   return collSize<T>(c) - 1;
}

template <typename T>
void collSetAt(Coll<T> &c, T t, int p, string tToString(T))
{
   setTokenAt(c.token, c.sep, tToString(t), p);
}

// Getting the token at position p from the collection.
template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   return tFromString(getTokenAt(c.token, c.sep, p));
}

// A function that returns the position of the token in the collection that matches the key.
template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   int result;
   T tString;
   for (int i = 0; i < collSize(c); i++)
   {
      tString = collGetAt(c, i, tFromString);
      result = cmpTK(tString, k);
      if (result == 0)
      {
         return i;
      }
   }
   return -1;
}

template <typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
}
// Checking if the collection has a next value.
template <typename T>
bool collHasNext(Coll<T> c)
{
   if (c.pos < collSize(c))
   {
      return true;
   }
   else
   {
      return false;
   }
}

// Returning the next value in the collection.
template <typename T>
T collNext(Coll<T> &c, T tFromString(string))
{
   c.pos++;
   T collPos = collGetAt(c, c.pos, tFromString);
   return collPos;
}

// Returning the next value in the collection and indicates if you reach the final step of the collection.
template <typename T>
T collNext(Coll<T> &c, bool &endOfColl, T tFromString(string))
{
   c.pos++;
   T collPos = collGetAt(c, c.pos, tFromString);
   if (c.pos == collSize(c))
   {
      endOfColl = true;
   }
   else
   {
      endOfColl = false;
   }
   return collPos;
}

// Resetting the position of the collection to 0.
template <typename T>
void collReset(Coll<T> &c)
{
   c.pos = 0;
}
#endif
