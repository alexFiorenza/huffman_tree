#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
  T info;
  Node *next;
};

template <typename T>
Node<T> *add(Node<T> *&p, T e)
{
  Node<T> *q = new Node<T>();
  q->info = e;
  q->next = NULL;
  if (p != NULL)
  {
    Node<T> *r = p;
    while (r->next != NULL)
      r = r->next;
    r->next = q;
    return q;
  }
  else
  {
    p = q;
  }
  return p;
}

template <typename T>
Node<T> *addFirst(Node<T> *&p, T e)
{
  Node<T> *firstNode = new Node<T>();
  firstNode->info = e;
  if (p != NULL)
  {
    firstNode->next = p;
  }
  else
  {
    firstNode->next = NULL;
  }
  p = firstNode;
  return p;
}

template <typename T, typename K>
T remove(Node<T> *&p, K k, int cmpTK(T, K))
{
  if (p != NULL)
  {
    Node<T> *aux = p;
    if (cmpTK(aux->info, k) == 0)
    {
      T data = aux->info;
      p = aux->next;
      delete aux;
      return data;
    }
    while (aux->next != NULL)
    {
      Node<T> *next = aux->next;
      if (cmpTK(next->info, k) == 0)
      {
        T data = next->info;
        aux->next = next->next;
        delete next;
        return data;
      }
      // iterate over list
      aux = aux->next;
    }
  }
  else
  {
    return NULL;
  }
}

template <typename T>
T removeFirst(Node<T> *&p)
{
  T data = p->info;
  Node<T> *next = p->next;

  delete p;
  p = next;

  return data;
}

template <typename T, typename K>
Node<T> *find(Node<T> *p, K k, int cmpTK(T, K))
{
  if (p != NULL)
  {
    Node<T> *aux = p;
    if (cmpTK(aux->info, k) == 0)
    {
      return aux;
    }
    while (aux->next != NULL)
    {
      Node<T> *next = aux->next;
      if (cmpTK(next->info, k) == 0)
      {
        return next;
      }
      // iterate over list
      aux = aux->next;
    }
  }
  else
  {
    return NULL;
  }
}

template <typename T>
Node<T> *orderedInsert(Node<T> *&p, T e, int cmpTT(T, T))
{
  Node<T> *aux = p;

  // Si la lista esta vacia agregar el elem
  if (p == NULL)
  {
    return add(p, e);
  }

  // Checkear si es menor o igual al primer elemento y agregarlo ahí
  if (cmpTT(e, aux->info) <= 0)
  {
    return addFirst(p, e);
  }

  while (aux->next != NULL)
  {
    Node<T> *next = aux->next;

    // Si el elemento es menor o igual al prox insertarlo en esta posicion
    if (cmpTT(e, next->info) <= 0)
    {
      Node<T> *nuevo = new Node<T>();
      nuevo->info = e;
      nuevo->next = next;

      aux->next = nuevo;

      return nuevo;
    }

    aux = aux->next;
  }

  // Si el elem no se menor o igual a ninguno, insertarlo al final.
  return add<T>(p, e);
}

template <typename T>
Node<T> *searchAndInsert(Node<T> *&p, T e, bool &enc, int cmpTT(T, T))
{
  Node<T> *found = find<T, T>(p, e, cmpTT);
  if (found)
  {
    enc = true;
    return found;
  }
  else
  {
    enc = false;
    return orderedInsert<T>(p, e, cmpTT);
  }
  return NULL;
}

template <typename T>
void sort(Node<T> *&p, int cmpTT(T, T))
{
  // TODO: Check
  bool swapped;
  do
  {
    swapped = false;

    Node<T> *current = p;
    Node<T> *previous = NULL;

    while (current->next != NULL)
    {
      Node<T> *next = current->next;

      if (cmpTT(current->info, next->info) > 0)
      {
        if (previous != NULL)
        {
          previous->next = next;
        }
        else
        {
          p = next;
        }
        // Swap elements
        current->next = next->next;
        next->next = current;

        swapped = true;
      }
      previous = current;
      current = next;
    }

  } while (swapped);
}

template <typename T>
bool isEmpty(Node<T> *p)
{
  return p == NULL;
}

template <typename T>
void free(Node<T> *&p)
{
  while (p != NULL)
  {
    Node<T> *aux = p;
    p = aux->next;
    delete aux;
  }
}

template <typename T>
Node<T> *push(Node<T> *&p, T e)
{
  return NULL;
}

template <typename T>
T pop(Node<T> *&p)
{
  T t;
  return t;
}

template <typename T>
Node<T> *enqueue(Node<T> *&p, Node<T> *&q, T e)
{
  return NULL;
}

template <typename T>
Node<T> *enqueue(Node<T> *&q, T e)
{
  return NULL;
}

template <typename T>
T dequeue(Node<T> *&p, Node<T> *&q)
{
  T t;
  return t;
}

template <typename T>
T dequeue(Node<T> *&q)
{
  T t;
  return t;
}

#endif
