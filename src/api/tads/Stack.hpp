#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include "../funciones/lists.hpp"
#include "List.hpp"
#include <iostream>

using namespace std;

template <typename T>
struct Stack
{
  List<T> l;
};

template <typename T>
Stack<T> stack()
{
  Stack<T> st;
  st.l = list<T>();
  return st;
}

template <typename T>
T *stackPush(Stack<T> &st, T e)
{
  return listAddFirst<T>(st.l, e);
}

template <typename T>
T stackPop(Stack<T> &st)
{
  return listRemoveFirst<T>(st.l);
}

template <typename T>
bool stackIsEmpty(Stack<T> st)
{
  return listIsEmpty<T>(st.l);
}

template <typename T>
int stackSize(Stack<T> st)
{
  return listSize(st.l);
}

#endif
