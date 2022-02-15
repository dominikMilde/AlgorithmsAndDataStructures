#include <iostream>
#include <string>
using namespace std;
class Osoba
{
   string ime;
   unsigned short int godine;

public:
   void setIme(string ime)
   {
      this->ime = ime;
   }
   void setGodine(unsigned short int godine)
   {
      this->godine = godine;
   }
   string getIme()
   {
      return this->ime;
   }
   unsigned short int getGodine(){
      return this->godine;
   }

   Osoba(string ime, unsigned short int godine){
      setIme(ime);
      setGodine(godine);
   }
   ~Osoba() {}

   Osoba &operator=(const Osoba& o){
      this->ime = o.ime;
      this->godine = o.godine;
      return *this;
   }

   bool operator<(const Osoba& o){
      if(this->getGodine() != o.godine){
         return this->getGodine() < o.godine;
      }
      else{
         return this->getIme() < o.ime;
      }
   }
};

template <class T> void InsertionSort(T A[], int n){
   int i, j;
   for(i = 1; i<n; i++){
      T temp = A[i];
      for(j = i; j>0 && temp < A[j-1]; j--){
         A[j]=A[j-1];
         }
      A[j] = temp;
   }
}

int main(void)
{
   Osoba polje[3] = {{"Marko", 10}, {"Ana", 12}, {"Ivica", 2}};
   InsertionSort(polje, 3);
   cout << polje[0].getIme();
   cout << polje[1].getIme();
   cout << polje[2].getIme();
   system("pause");
   return 0;
}