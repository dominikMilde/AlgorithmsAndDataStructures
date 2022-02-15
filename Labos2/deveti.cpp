#include <iostream>
#include <cstring>
using namespace std;

class Vozilo{
   string naziv;
   int godina;

   public:
   void setNaziv(string naziv){
      this->naziv = naziv;
   }
   void setGodina(int godina){
      this->godina = godina;
   }

   Vozilo(string naziv, int godina){
      setNaziv(naziv);
      setGodina(godina);
   }
   ~Vozilo(){}

   Vozilo &operator=(const Vozilo &o){
      setNaziv(o.naziv);
      setGodina(o.godina);
      return *this;
   }

   bool operator<(const Vozilo &o){
      if(this->naziv != o.naziv)
         return this->naziv < o.naziv;
      else
      {
         return this->godina < o.godina;
      }
   }
   friend ostream& operator<< (ostream &a, Vozilo &v) {
        a << "{" << v.naziv << ", " << v.godina << "}";
        return a;
    }  
};

void Zamijeni(Vozilo &prvi, Vozilo &drugi){
   Vozilo tmp = prvi;
   prvi = drugi;
   drugi = tmp;
}

template <class T> void SelectionSort(T A[], int n){
   int i, j;
   for(i=0;  i<n; i++){
      int min = i;
      for(j=i+1; j<n; j++){
         if(A[j] < A[min]){
            min = j;
         }
      }
      Zamijeni(A[i], A[min]);
   }
}


int main(void){
   Vozilo A[6] = {{"Pauegot",1981},{"Pauegot",1983},{"Ranulet",1967}, {"Fait",1972}, {"BWM",1985}, {"Merdesec",1983}};
   int N = 6;
   SelectionSort(A, N);
   for(int i = 0; i < N; i++) {
      cout << A[i] << " ";
   }
   cout << endl;
   system("pause");
   return 0;
   
}
