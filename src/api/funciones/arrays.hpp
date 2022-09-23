#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

// Adding an element to the array.
template <typename T>
int add(T arr[], int &len, T e)
{
   arr[len] = e;
   len++;
   return len - 1;
}

// Inserting an element into the array at a specific position.
template <typename T>
void insert(T arr[], int &len, T e, int p)
{
   for (int i = len; i > p; i--)
   {
      arr[i] = arr[i - 1];
   }
   arr[p] = e;
   len++;
}

// Removing an element from the array.
template <typename T>
T remove(T arr[], int &len, int p)
{
   T ret;
   for (int i = p; i < len; i++)
   {
      if (i == p)
      {
         ret = arr[i];
      }
      arr[i] = arr[i + 1];
   }
   return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K k, int cmpTK(T, K))
{
   for (int i = 0; i < len; i++)
   {
      if (cmpTK(arr[i], k) == 0)
      {
         return i;
      }
   }
   return -1;
}

template <typename T>
int orderedInsert(T arr[], int &len, T e, int cmpTT(T, T))
{
   for (int i = 0; i < len; i++)
   {
      // Checking if the element is greater than the element in the array. If it is, it inserts the element into the array at the position of the element in the array.
      if (cmpTT(arr[i], e) >= 0)
      {
         insert(arr, len, e, i);
         return i;
      }
   }
   return add(arr, len, e);
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   // Bubble sort algorithm.
   for (int j = 0; j < len; j++)
   {
      for (int i = 0; i < len - 1; i++)
      {
         if (cmpTT(arr[i], arr[i + 1]) > 0)
         {
            T aux = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = aux;
         }
      }
   }
}
#endif
