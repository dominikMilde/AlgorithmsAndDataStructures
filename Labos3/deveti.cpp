#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <typename T>
class Heap
{
private:
   int size;
   int *elements;
   int j; //idx mjesta gdje dodajem novi element

public:
   Heap(int n)
   {
      this->size = n;
      this->j = 1;
      this->elements = T[n + 1]; //indeksiramo od 1
   }

   ~Heap()
   {
      delete[] this->elements;
   }

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
      idxNew = this->j;        //idx novog elementa
      idxParent = this->j / 2; //idx njegovog roditelja
      newElement = this->elements[this->j];

      while (idxParent > 0 && elements[idxParent] < newElement)
      {
         elements[idxNew] = elements[idxParent];
         idxNew = idxParent;
         idxParent /= 2;
      }
      elements[idxNew] = newElement;
   }
   void addOne(T element)
   {
      if (j >= size + 1)
      {
         throw runtime_error("izvan hrpe, ajde prpe");
      }
      elements[j] = elements;
      adjustOne();
      j++;
   }
};

int main(void)
{
   cout << endl;
   system("pause");
   return 0;
}