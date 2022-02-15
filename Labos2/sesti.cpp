#include <iostream>
using namespace std;

template <class T>
class Lista
{
   template <class X>
   struct Cvor
   {
      X data;
      struct Cvor<X> *next;
   };

   Cvor<T> *head = nullptr;

public:
   bool upis(T element)
   {
      Cvor<T> *newElement = new (nothrow) Cvor<T>;
      if (newElement == nullptr)
      {
         return false;
      }
      newElement->data = element;
      Cvor<T> **p;
      for (p = &head; *p && element > (*p)->data; p = &((*p)->next))
         ;
      newElement->next = *p;
      *p = newElement;
      return true;
   }

   void ispis()
   {
      Cvor<T> *p;
      for (p = head; p; p = p->next)
      {
         cout << p->data << " ";
      }
      cout << endl;
   }
};

int main(void)
{
   Lista<int> lista;
   lista.upis(1);
   lista.upis(55);
   lista.upis(122);

   lista.ispis();
   return 0;
}