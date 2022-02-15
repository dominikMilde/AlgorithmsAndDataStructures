#include <iostream>
using namespace std;

class Red{
   private:
    struct Cvor{
      int broj;
      Cvor *next;
    };
    Cvor *ulaz = nullptr;
    Cvor *izlaz = nullptr;

   public:
    bool dodaj(int broj){
       Cvor *newElement = new Cvor;
       if(newElement == nullptr){
          return false;
       }
       newElement-> broj = broj;
       newElement-> next = nullptr;
       if(ulaz == nullptr){
          izlaz = newElement;
       }
       else{
          ulaz->next = newElement;
       }
       ulaz = newElement;
       return true;
    }

    bool skini(int* broj){
      if(izlaz == nullptr){
         return false;
      }
      *broj = izlaz->broj;
      Cvor *tmp = izlaz;
      izlaz = izlaz->next;
      if (izlaz == nullptr){
         ulaz = nullptr;
      }
      delete tmp;
      return true;
   }

   bool poljeURed (int polje[], int n){
      bool stat;
      if(n<=0)
         return true;
      if(dodaj(polje[n-1])){
         cout << "Dodajem: " << polje[n-1] << endl; 
         return poljeURed(polje, n-1);
      } 
      return false;
   }
};

int main(void){
   Red r;

   int broj;
   /*for(int i=0; i<3; i++){
      r.skini(&broj);
      cout << broj << endl;
   }*/
   int polje[3] = {1,2,3};
   r.poljeURed(polje, 3);

   r.skini(&broj);
   cout << broj << endl;
   system("pause");
   return 0;
}