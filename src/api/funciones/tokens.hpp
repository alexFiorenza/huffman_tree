#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// Counting the number of tokens in a string.
int tokenCount(string s, char sep)
{
   int counter = 1;
   if (length(s) == 0)
      return 0;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == sep && s[i + 1] != '\0')
      {
         counter++;
      }
   }
   return counter;
}

// Adding a token to the string.
void addToken(string &s, char sep, string t)
{
   if (length(t) != 0 && !contains(t, sep) && length(s) != 0)
   {
      s += lpad(t, length(t) + 1, sep);
   }
   else
   {
      s = t;
   }
}

// Getting the token at the given index.
string getTokenAt(string s, char sep, int i)
{
   int occurences = charCount(s, sep);
   string newString = s;
   string lastWord = "";
   int counter = 0;
   if (tokenCount(s, sep) - 1 < i || tokenCount(s, sep) == 0 || charCount(s, sep) == 0)
      return s;
   for (int j = 0; s[j] != '\0'; j++)
   {
      if (s[j] == sep && s[j + 1] != '\0' || occurences == counter)
      {
         newString = substring(s, lastWord != "" ? length(lastWord) : 0, occurences != counter ? j : length(s));
         lastWord += newString + sep;
         if (counter < i)
         {
            counter++;
         }
         else
         {
            break;
         }
      }
   }
   return newString;
}

// Removing the token at the given index.
void removeTokenAt(string &s, char sep, int i)
{
   if (tokenCount(s, sep) != 0 && charCount(s, sep) != 0)
   {
      string tokenToRemove = getTokenAt(s, sep, i);
      string tmp;
      int indexOfToken = indexOf(s, tokenToRemove);
      string first_half = substring(s, 0, indexOfToken - 1);
      string second_half = substring(s, i != 0 ? indexOfToken + length(tokenToRemove) : indexOfToken + length(tokenToRemove) + 1, length(s));
      tmp = first_half + second_half;
      s = tmp;
   }
}

// Replacing the token at the given index with the given string.
void setTokenAt(string &s, char sep, string t, int i)
{
   if (tokenCount(s, sep) != 0 && charCount(s, sep) != 0)
   {
      string tokenToRemove = getTokenAt(s, sep, i);
      string tmp;
      int indexOfToken = indexOf(s, tokenToRemove);
      string first_half = substring(s, 0, indexOfToken);
      string second_half = t + substring(s, indexOfToken + length(tokenToRemove), length(s));
      tmp = first_half + second_half;
      s = tmp;
   }
}

// Finding the index of a token in a string.
int findToken(string s, char sep, string t)
{
   int ocurrences = charCount(s, sep);
   int index = -1;
   if (tokenCount(s, sep) != 0 && indexOf(s, t) != -1)
   {
      for (int i = 0; i <= ocurrences; i++)
      {
         string possibleToken = getTokenAt(s, sep, i);
         if (possibleToken == t)
         {
            index = i;
            break;
         }
         else
         {
            index = -1;
         }
      }
   }
   return index;
}

#endif
