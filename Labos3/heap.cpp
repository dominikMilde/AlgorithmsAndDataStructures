#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <typename T>
class Heap
{
private:
   int size;
   T *elements;
   int j; // idx mjesta u polju gdje dodajem novi el.

public:
   Heap(int n)
   {
      this->size = n;
      this->j = 1;
      this->elements = new T[n + 1]; //+1 jer krece od 1
   }

   ~Heap() { delete[] this->elements; }

   void print()
   {
      cout << "HEAP: ";
      for (int i = 1; i <= this->size; i++) // <j
         cout << this->elements[i] << " ";
      cout << endl;
   }

   void adjustOne()
   {
      int idxNew, idxParent;
      T newElement;
      idxNew = this->j;        // idx novog el
      idxParent = this->j / 2; // idx njegovog roditelja
      newElement = this->elements[this->j];

      while ((idxParent > 0) && (this->elements[idxParent] < newElement))
      {
         // roditelj ide "dolje"
         // mogu swap ali malo je jeftinije ovo:
         this->elements[idxNew] = this->elements[idxParent];

         // izracunaj nove idx
         idxNew = idxParent;
         idxParent /= 2;
      }
      // na kraju novi el. stavim na njegovo konacno mjesto
      this->elements[idxNew] = newElement;
   }

   void addOne(T element)
   {
      if (this->j >= (this->size + 1))
      {
         // throw nekog errora
      }
      this->elements[this->j] = element;
      this->adjustOne();
      this->j++;
   }

   void adjustOneSubTree(int i, int n)
   {
      int idxChild;
      T rootElement;
      idxChild = 2 * i; // idxDijete = 2* idxRoditelj (+1)
      rootElement = this->elements[i];

      while (idxChild <= n)
      {
         // nadjemo vece dijete
         if ((idxChild < n) &&
             (this->elements[idxChild] < this->elements[idxChild + 1]))
            idxChild++;

         // sad mi je idxChild na vecem djetetu
         // ako je korijen >= djetetu, gotov sam!
         if (rootElement >= this->elements[idxChild])
            break;

         // inace zamijenim roditelja i vece dijete (opet nije prava zamjena!)
         this->elements[idxChild / 2] = this->elements[idxChild];
         idxChild *= 2;
      }
      this->elements[idxChild / 2] = rootElement;
   }

   void adjustAll()
   {
      for (int i = this->size / 2; i >= 1; i--)
         // za svaki cvor koji je korijen nekog podstabla
         adjustOneSubTree(i, this->size);
   }

   void addAll(T src[], int n)
   {
      if (this->j >= (this->size + 1))
      {
         // neki error
      }
      for (int i = 1; i <= n; i++)
      {
         this->elements[j++] = src[i - 1];
      }
      this->adjustAll();
   }
};

int main()
{

   int A[] = {6, 26, 75, 31, 13, 46};

   int n = sizeof(A) / sizeof(int);

   Heap<int> h1(n);

   for (int i = 0; i < n; i++)
      h1.addOne(A[i]);
   h1.print();

   Heap<int> h2(n);
   h2.addAll(A, n);
   h2.print();

   return 0;
}
