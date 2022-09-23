#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// Returning the length of a string.
int length(string s)
{
   int i = 0;
   while (s[i] != '\0')
   {
      i++;
   }
   return i;
}

// Counting the number of times a character appears in a string.
int charCount(string s, char c)
{
   int i = 0, counter_word = 0;
   while (s[i] != '\0')
   {
      if (s[i] == c)
      {
         counter_word++;
      }
      i++;
   }
   return counter_word;
}

string substring(string s, int d, int h)
{
   string word;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (i >= d && i < h)
      {
         word += s[i];
      }
   }
   return word;
}

// Returning the substring of a string from a given position.
string substring(string s, int d) // ok
{
   string word;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (i >= d)
      {
         word += s[i];
      }
   }
   return word;
}

int indexOf(string s, char c) // ok`
{
   int word_position;
   bool assignedValue = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == c)
      {
         word_position = i;
         assignedValue = true;
         break;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int indexOf(string s, char c, int offSet)
{
   int word_position;
   bool assignedValue = false;
   for (int i = offSet; s[i] != '\0'; i++)
   {
      if (s[i] == c)
      {
         word_position = i;
         assignedValue = true;
         break;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

// Searching for a word in a string.
int indexOf(string s, string toSearch)
{
   int word_position = 0;
   bool assignedValue = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (substring(s, i, length(toSearch) + i) == toSearch && !assignedValue)
      {
         word_position = i;
         assignedValue = true;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

int indexOf(string s, string toSearch, int offset) // ok
{
   int word_position = 0;
   bool assignedValue = false;
   for (int i = offset; s[i] != '\0'; i++)
   {
      if (substring(s, i, length(toSearch) + i) == toSearch && !assignedValue)
      {
         word_position = i;
         assignedValue = true;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

// Returning the last index of a character in a string.
int lastIndexOf(string s, char c)
{
   int word_position;
   bool assignedValue = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == c)
      {
         word_position = i;
         assignedValue = true;
      }
   }
   if (!assignedValue)
      return -1;
   return word_position;
}

// Returning the position of the nth occurrence of a character in a string.
int indexOfN(string s, char c, int n)
{
   int occurrences = 0;
   int position_of_occurrence = 0;
   if (n <= 0)
      position_of_occurrence = -1;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (occurrences == n)
      {
         position_of_occurrence = i - 1;
         break;
      }
      if (s[i] == c)
      {
         occurrences++;
      }
   }
   if (n > occurrences)
   {
      position_of_occurrence = length(s);
   }
   return position_of_occurrence;
}

int charToInt(char c)
{
   int integer = 0;
   if (c >= '0' && c <= '9')
   {
      integer = c - 48;
   }
   else
   {
      if (c >= 'A' && c <= 'Z')
      {
         integer = (int)c - 55;
      }
      else
      {
         integer = (int)c - 87;
      }
   }
   return integer;
}

char intToChar(int i)
{
   char charValue;
   if (i >= 0 && i <= 9)
   {
      charValue = i + '0';
   }
   else if (i >= 65 && i <= 90)
   {
      charValue = (char)i;
      return charValue;
   }
   else
   {
      return ' ';
   }
   return charValue;
}

int getDigit(int n, int i)
{
   for (int j = 0; j < i; j++)
   {
      n = n / 10;
   }
   return n % 10;
}

// Counting the number of digits of a number.
int digitCount(int n)
{
   int counter = 0;
   while (n > 0)
   {
      counter++;
      n = n / 10;
   }
   return counter;
}

string intToString(int i)
{
   string string_to_return;
   for (int j = 0; j < digitCount(i); j++)
   {
      string_to_return += intToChar(getDigit(i, j));
   }
   string tmp = "";
   // Reverse
   for (int h = length(string_to_return) - 1; h >= 0; h--)
   {
      tmp += string_to_return[h];
   }
   return tmp;
}

int stringToInt(string s, int b) // ok
{
   int sum = 0;
   int exponent = 0;
   // Reverse
   for (int i = length(s) - 1; i >= 0; i--)
   {
      sum += pow(b, exponent) * charToInt(s[i]);
      exponent++;
   }
   return sum;
}

int stringToInt(string s) // ok
{
   int integer = 0;
   int test = 0;
   for (int i = 0; i < length(s); i++)
   {
      // Se le agrega un 0 y se le suma el num a añadir
      integer = integer * 10 + (int(s[i] - 48));
   }
   return integer;
}

string charToString(char c)
{
   string charConverted(1, c);
   return charConverted;
}

char stringToChar(string s)
{
   char stringConverted = s[0];
   return stringConverted;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
   char buffer[100];
   sprintf(buffer, "%lf", d);
   string ret = buffer;
   return ret;
}
double stringToDouble(string s)
{
   double before = 0;
   double after = 0.0;
   bool hasDot = false;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == '.')
      {
         hasDot = true;
         continue;
      }
      if (hasDot)
      {
         // Parte decimal
         after += (double)charToInt((char)s[i]) / 10;
         hasDot = false;
      }
      else
      {
         // Parte entera
         before = before * 10 + (double)charToInt((char)s[i]);
      }
   }
   return before + after;
}
bool isEmpty(string s)
{
   if (length(s) > 0)
   {
      return false;
   }
   else
   {
      return true;
   }
}

bool startsWith(string s, string x)
{
   int indexOfWord = indexOf(s, x);
   if (indexOfWord < 0)
      return false;
   else if (indexOfWord == 0)
      return true;
   else
      return false;
}

bool endsWith(string s, string x)
{
   int indexOfWord = indexOf(s, x);
   if (indexOfWord < 0)
      // Esta contenida
      return false;
   else if (indexOfWord == 0)
      // No esta al inicio
      return false;
   else if (length(s) - indexOfWord == length(x))
      return true;
   return false;
}

// Checking if a string contains a character.
bool contains(string s, char c)
{
   for (int i = 0; s[i] != '\0'; i++)
   {
      if ((char)s[i] == c)
      {
         return true;
      }
   }
   return false;
}

string replace(string s, char oldChar, char newChar)
{
   string modifiedString = s;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if ((char)s[i] == oldChar)
      {
         modifiedString[i] = newChar;
      }
   }
   return modifiedString;
}

string insertAt(string s, int pos, char c)
{
   string modifiedString;
   string firstQuarterString = substring(s, 0, pos + 1);
   firstQuarterString[length(firstQuarterString) - 1] = c;
   string secondQuarterString = substring(s, pos, length(s));
   modifiedString = firstQuarterString + secondQuarterString;
   return modifiedString;
}

string removeAt(string s, int pos)
{
   string modifiedString;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (i == pos)
         continue;
      modifiedString += s[i];
   }
   return modifiedString;
}

string ltrim(string s)
{
   string modifiedString = s;
   for (int i = 0; s[i] != '\0'; i++)
   {
      if (s[i] == ' ' && modifiedString[0] == ' ')
      {
         modifiedString = removeAt(modifiedString, 0);
      }
   }
   return modifiedString;
}

string rtrim(string s)
{
   string modifiedString = s;
   for (int i = length(s) - 1; i >= 0; i--)
   {
      if (s[i] == ' ' && modifiedString[length(modifiedString) - 1] == ' ')
      {
         modifiedString = removeAt(modifiedString, length(modifiedString) - 1);
      }
   }
   return modifiedString;
}

string trim(string s)
{
   string modifiedString = s;
   modifiedString = ltrim(modifiedString);
   modifiedString = rtrim(modifiedString);
   return modifiedString;
}

string replicate(char c, int n)
{
   string replicatedString;
   for (int i = 0; i < n; i++)
   {
      replicatedString += c;
   }
   return replicatedString;
}

string spaces(int n)
{
   string replicatedString;
   for (int i = 0; i < n; i++)
   {
      replicatedString += ' ';
   }
   return replicatedString;
}

// Adding a character to the left of a string.
string lpad(string s, int n, char c)
{
   if (length(s) == n)
      return s;
   string modifiedString = s;
   for (int i = 0; i < (n - length(s)); i++)
   {
      modifiedString = insertAt(modifiedString, 0, c);
   }
   return modifiedString;
}

// Adding a character to the right of a string.
string rpad(string s, int n, char c)
{
   if (length(s) == n)
      return s;
   string modifiedString = s + ' ';
   for (int i = 0; i < (n - length(s)); i++)
   {
      modifiedString = insertAt(modifiedString, length(modifiedString) - 1, c);
   }
   modifiedString = removeAt(modifiedString, n);
   return modifiedString;
}

string cpad(string s, int n, char c)
{
   if (length(s) == n)
      return s;
   string modifiedString = s;
   int distributionChar = (n - length(s)) / 2;
   modifiedString = lpad(s, length(s) + distributionChar, c);
   modifiedString = rpad(modifiedString, n, c);
   return modifiedString;
}

bool isDigit(char c)
{
   if (c >= '0' && c <= '9')
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLetter(char c)
{
   return isDigit(c) ? false : true;
}

bool isUpperCase(char c)
{
   return c >= 'A' && c <= 'Z' ? true : false;
}

bool isLowerCase(char c)
{
   return !isUpperCase(c);
}

char toUpperCase(char c)
{
   if (c >= 'a' && c <= 'z')
   {
      return c - ('a' - 'A');
   }
   else
   {
      return c;
   }
}

char toLowerCase(char c)
{
   if (c >= 'A' && c <= 'Z')
   {
      return c + ('a' - 'A');
   }
   else
   {
      return c;
   }
}

string toUpperCase(string s)
{
   string modifiedString = "";
   for (int i = 0; s[i] != '\0'; i++)
   {
      modifiedString += toUpperCase(s[i]);
   }
   return modifiedString;
}

string toLowerCase(string s)
{
   string modifiedString = "";
   for (int i = 0; s[i] != '\0'; i++)
   {
      modifiedString += toLowerCase(s[i]);
   }
   return modifiedString;
}

int cmpString(string a, string b)
{
   return a < b ? -1 : 1;
}

int cmpDouble(double a, double b)
{
   return a < b ? -1 : 1;
}

#endif
