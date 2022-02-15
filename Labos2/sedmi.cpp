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
      newElement->next = nullptr;
      if (head == nullptr)
      {
         head = newElement;
      }
      else
      {
         Cvor<T> *p;
         for (p = head; p->next; p = p->next)
            ;
         p->next = newElement;
      }
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
   lista.upis(3);
   lista.upis(1);
   lista.upis(2);
   lista.upis(11);

   lista.ispis();
   return 0;
}