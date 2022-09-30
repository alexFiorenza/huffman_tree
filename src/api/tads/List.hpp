#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include "../funciones/lists.hpp"
#include <iostream>

using namespace std;

template <typename T> struct List
{
  Node<T> *node;
  Node<T> *iterator;
};

template <typename T> List<T> list()
{
  List<T> lst;
  lst.node = NULL;
  return lst;
}

template <typename T> T *listAdd(List<T> &lst, T e)
{
  Node<T> *element = add<T>(lst.node, e);
  return &(element->info);
}

template <typename T> T *listAddFirst(List<T> &lst, T e)
{
  Node<T> *element = addFirst<T>(lst.node, e);
  return &(element->info);
}

template <typename T, typename K>
T listRemove(List<T> &lst, K k, int cmpTK(T, K))
{
  T element = remove<T, K>(lst.node, k, cmpTK);
  return element;
}

template <typename T> T listRemoveFirst(List<T> &lst)
{
  return removeFirst<T>(lst.node);
}

template <typename T, typename K> T *listFind(List<T> lst, K k, int cmpTK(T, K))
{
  Node<T> *element = find<T, K>(lst.node, k, cmpTK);
  return &(element->next);
}

template <typename T> bool listIsEmpty(List<T> lst)
{
  return isEmpty<T>(lst.node);
}

template <typename T> int listSize(List<T> lst)
{
  int i = 0;
  // Count the nodes
  for (Node<T> *aux = lst.node; aux != NULL; i++)
  {
    i++;
  }
  return i;
}

template <typename T> void listFree(List<T> &lst) { free<T>(lst.node); }

template <typename T> T *listOrderedInsert(List<T> &lst, T t, int cmpTT(T, T))
{
  return &orderedInsert<T>(lst.node, t, cmpTT);
}

template <typename T> void listSort(List<T> &lst, int cmpTT(T, T))
{
  sort<T>(lst.node, cmpTT);
}

template <typename T> void listReset(List<T> &lst)
{
  // Reset the iterator to the first node
  lst.iterator = lst.node;
}

template <typename T> bool listHasNext(List<T> lst)
{
  // Check if the iterator is not null
  return lst.iterator != NULL;
}

template <typename T> T *listNext(List<T> &lst)
{
  // Get the next element
  lst.iterator = lst.iterator->next;
  return &(lst.iterator->info);
}

template <typename T> T *listNext(List<T> &lst, bool &endOfList)
{
  if (listHasNext(lst))
  {
    endOfList = false;
    return listNext(lst);
  }
  else
  {
    endOfList = true;
    return NULL;
  }
}

#endif
