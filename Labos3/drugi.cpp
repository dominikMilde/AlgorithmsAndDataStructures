#include <iostream>
using namespace std;

class Red {
private:
   struct Cvor {
      double broj;
      Cvor *next;
   };
   Cvor *read = nullptr;
   Cvor *write = nullptr;

public:
   bool dodaj(double broj) {
      Cvor *novi = new Cvor;
      if (novi == nullptr)
         return false;
      novi->next = nullptr;
      novi->broj = broj;
      if (write == nullptr) {
         read = novi;
      } else {
         write->next = novi;
      }
      write = novi;
      return true;
   }

   bool skini(double* broj) {
      if (read == nullptr)
         return false;
      *broj = read->broj;
      Cvor *tmp = read;
      read = read->next;
      if (read == nullptr)
         write = nullptr;
      delete tmp;
      return true;
   }
};
int main(void){
   Red r;

   r.dodaj(4.11);
   r.dodaj(3.1233);

   double p;
   r.skini(&p);

   cout<<p;
     r.skini(&p);

   cout<<p;
   system("pause");
   return 0;
}