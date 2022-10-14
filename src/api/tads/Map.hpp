
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;
template <typename K, typename V>
int cmpKV(K a, V b)
{
   if (a == b)
   {
      return 0;
   }
   else
   {
      return -1;
   }
}
template <typename K, typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int pos;
};
//[key1,  key2,  key3  ]
// |        |      |
//[value1,value2,value3]
template <typename K, typename V>
Map<K, V> map()
{
   Map<K, V> m;
   m.keys = arr<K>();
   m.values = arr<V>();
   m.pos = 0;
   return m;
}

template <typename K, typename V>
V *mapGet(Map<K, V> m, K k)
{
   int index = arrayFind<K, K>(m.keys, k, cmpKV);
   if (index == -1)
   {
      return NULL;
   }
   V *p = arrayGet<V>(m.values, index);
   return p;
}

template <typename K, typename V>
V *mapPut(Map<K, V> &m, K k, V v)
{
   V *p = mapGet<K, V>(m, k);
   if (p != NULL)
   {
      // replace
      int index = arrayFind<K, K>(m.keys, k, cmpKV);
      arraySet<V>(m.values, index, v);
      return arrayGet<V>(m.values, index);
   }
   else
   {
      // No existe
      arrayAdd<K>(m.keys, k);
      int index = arrayAdd<V>(m.values, v);
      V *p = arrayGet<V>(m.values, index);
      return p;
   }
}

// Checking if the map contains the key.
template <typename K, typename V>
bool mapContains(Map<K, V> m, K k)
{
   int index = arrayFind<K, K>(m.keys, k, cmpKV);
   if (index == -1)
   {
      return false;
   }
   return true;
}

// Removing the key and value from the map.
template <typename K, typename V>
V mapRemove(Map<K, V> &m, K k)
{
   V v;
   int index = arrayFind<K, K>(m.keys, k, cmpKV);
   arrayRemove<K>(m.keys, index);
   arrayRemove<V>(m.values, index);
   return v;
}

template <typename K, typename V>
void mapRemoveAll(Map<K, V> &m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template <typename K, typename V>
int mapSize(Map<K, V> m)
{
   return arraySize<K>(m.keys);
}

template <typename K, typename V>
bool mapHasNext(Map<K, V> m)
{
   if (mapSize<K, V>(m) > m.pos)
   {
      m.pos++;
      return true;
   }
   else
   {
      return false;
   }
}

template <typename K, typename V>
K mapNextKey(Map<K, V> &m)
{
   K key = *arrayGet<K>(m.keys, m.pos);
   m.pos++;
   return key;
}

template <typename K, typename V>
V *mapNextValue(Map<K, V> &m)
{
   V *pointer = arrayGet<V>(m.values, m.pos);
   return pointer;
}

template <typename K, typename V>
void mapReset(Map<K, V> &m)
{
   m.pos = 0;
}

template <typename K, typename V>
void mapSortByKeys(Map<K, V> &m, int cmpKK(K, K))
{
   // Copy of auxkeys and auxValues
   Array<K> auxKeys = m.keys;
   Array<V> auxValues = m.values;
   // Create an empty values array with the cap of the prev values array
   Array<V> newValues = arr<V>();
   newValues.cap = arraySize<V>(m.values);
   arraySort<K>(m.keys, cmpKK);
   int counter = 0;
   // Iterate over the old keys array
   while (counter < arraySize(auxKeys.arr))
   {
      K prevKey = *arrayGet<K>(auxKeys, counter);
      V prevValue = *arrayGet<K>(auxValues, counter);
      // Find the old key in the new sorted key array and get the index
      int newPos = arrayFind<K, V>(m.keys, prevKey, cmpKV);
      // Assign to the newValues in the new index the old value
      arrayInsert<V>(newValues, prevValue, newPos);
   }
   // override the old values array with the new sorted values array
   m.values = newValues;
}

template <typename K, typename V>
void mapSortByValues(Map<K, V> &m, int cmpVV(V, V))
{
   Array<K> auxKeys = m.keys;
   Array<V> auxValues = m.values;
   Array<K> newKeys = arr<V>();
   newKeys.cap = arraySize<V>(m.keys);
   arraySort<K>(m.values, cmpVV);
   int counter = 0;
   // Iterate over the old keys array
   while (counter < arraySize(auxValues))
   {
      V prevValue = *arrayGet<V>(auxValues, counter);
      K prevKey = *arrayGet<K>(auxKeys, counter);
      int newPos = arrayFind<K, V>(m.values, prevValue, cmpKV);
      arrayInsert<V>(newKeys, prevKey, newPos);
   }
   m.keys = newKeys;
}

#endif
