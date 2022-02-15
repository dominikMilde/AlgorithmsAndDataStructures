#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class Heap
{
private:
   int size;
   int *elements;
   int j; // idx mjesta u polju gdje dodajem novi el.

public:
   Heap(int n)
   {
      this->size = n;
      this->j = 1;
      this->elements = new T[n + 1]; //+1 jer krece od 1
   }

   void print()
   {
      cout << "HEAP: ";
      for (int i = 1; i <= this->size; i++) // <j
         cout << this->elements[i] << " ";
      cout << endl;
   }
   void ajdustOne()
   {
      int idxNew = j;
      int idxParent = j / 2;
      int newElement = elements[j];

      while (idxParent > 0 && elements[idxParent] < newElement)
      {
         elements[idxNew] = elements[idxParent];
         idxNew = idxParent;
         idxParent /= 2;
      }
      elements[idxNew] = newElement;
   }

   void adjustOneSub(int i, int n)
   {
      int rootElement = elements[i];
      int idxChild = i * 2;

      while (idxChild <= n)
      {
         if (idxChild < n && elements[idxChild + 1] > elements[idxChild])
         {
            idxChild++;
         }

         if (rootElement >= elements[idxChild])
         {
            break;
         }
            }
   }
   void addOne(int broj)
   {
      if (j >= size + 1)
      {
         return;
      }
      elements[j] = broj;
      ajdustOne();
      j++;
   }
   ~Heap() { delete[] this->elements; }
