#include <iostream>
#include <stdlib.h>
using namespace std;

class Stog
{
private:
   struct Cvor
   {
      int data;
      Cvor *next;
   };
   Cvor *vrh = nullptr;

public:
   bool push(int data)
   {
      Cvor *newElement = new Cvor;
      if (newElement == nullptr)
         return false;
      newElement->data = data;
      newElement->next = vrh;
      vrh = newElement;
      return true;
   }
   bool pop(int &data)
   {
      if (vrh == nullptr)
         return false;
      data = vrh->data;
      Cvor *tmp = vrh;
      vrh = vrh->next;
      delete tmp;
      return true;
   }
};
int main(void)
{
   Stog s;
   srand(501);
   for (int i = 0; i < 101; i++)
   {
      s.push(rand() % 101);
   }
   int broj;

   for (int i = 0; i < 101; i++)
   {
      s.pop(broj);
      cout << broj << " ";
   }
   system("pause");
   return 0;
}