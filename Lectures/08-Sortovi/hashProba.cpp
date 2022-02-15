#include <iostream>
#include <list>
using namespace std;

class SimpleHashWithChaining {
   int M;
   list<int> *tablica;

 public:
   SimpleHashWithChaining(int size) {
      this->M = size;
      tablica = new list<int>[M];
   }

   void insert(int key) {
      int index = hash(key);
      tablica[index].push_front(key);
   }

   void remove(int key) {
      int index = hash(key);
      for (auto it = tablica[index].begin(); it != tablica[index].end(); it++) {
         if (*it == key) {
            tablica[index].erase(it);
            break;
         }
      }
   }

   int hash(int x) { return (x % M); }

   void print() {
      cout << "-------------------------------" << endl;
      for (int i = 0; i < M; i++) {
         cout << i;
         for (auto x : tablica[i])
            cout << " --> " << x;
         cout << endl;
      }
      cout << "-------------------------------" << endl;
   }
};

int main() {
   // ulazni elementi - što ako ubacim -1?
   int a[] = {1, 255, 12, 22, 32, 42, 82, 17, 54, 39, 996, INT_MAX, 0};

   int n = sizeof(a) / sizeof(a[0]);

   SimpleHashWithChaining h(10);

   for (int i = 0; i < n; i++)
      h.insert(a[i]);

   h.print();

   // obriši srednji, prvi i zadnji iz jedne od lista
   h.remove(32);
   h.remove(12);
   h.remove(82);

   h.print();
   system("pause");

   return 0;
}