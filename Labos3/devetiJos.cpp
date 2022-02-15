#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Heap
{
private:
   int size;
   int *elements;
   int j;

public:
   Heap(int n)
   {
      this->size = n;
      this->elements = new int[size + 1];
      this->j = 1;
   }
   ~Heap() { delete[] this->elements; }

   void adjustOne()
   {
      int idxNew, idxParent;
      idxNew = j;
      idxParent = idxNew / 2;
      int newElement = elements[idxNew];
      while (idxParent > 0 && elements[idxParent] > newElement)
      {
         elements[idxNew] = elements[idxParent];
         idxNew = idxParent;
         idxParent /= 2;
      }
      elements[idxNew] = newElement;
   }

   void addOne(int novi)
   {
      if (j >= size + 1)
      {
         cout << "izvan";
         return;
      }
      elements[j] = novi;
      adjustOne();
      j++;
   }

   void print()
   {
      int tmp;
      for (int i = 1, tmp = 2; i < j; i++)
      {
         cout << " " << elements[i];
         if (i == tmp - 1)
         {
            cout << endl;
            tmp *= 2;
         }
      }
   }

   void adjusstOneSubTree(int i, int n)
   {
      int idxChild = 2 * i;
      int rootElement;

      while (idxChild <= n)
      {
         if ((idxChild < n) && elements[idxChild] > elements[idxChild + 1])
         {
            idxChild++;
            //sada mi je idx na manjem djetetu
         }
         if (rootElement >= elements[idxChild])
         {
            break;
         }
         elements[idxChild / 2] = elements[idxChild];
         idxChild *= 2;
      }
      elements[idxChild / 2] = rootElement;
   }

   void addAll(int src[], int n)
   {
      if (j >= (size + 1))
      {
         // neki error
      }
      for (int i = 1; i <= n; i++)
      {
         elements[j++] = src[i - 1];
      }
      adjustAll();
   }

   void adjustAll()
   {
      for (int i = size / 2; i >= 1; i--)
      {
         adjusstOneSubTree(i, size);
      }
   }
};

main(void)
{
   int A[] = {6, 26, 75, 31, 13, 46};

   int n = sizeof(A) / sizeof(int);

   Heap h1(n);

   for (int i = 0; i < n; i++)
      h1.addOne(A[i]);
   h1.print();

   Heap h2(n);
   h2.addAll(A, n);
   h2.print();

   system("pause");
   return 0;
}