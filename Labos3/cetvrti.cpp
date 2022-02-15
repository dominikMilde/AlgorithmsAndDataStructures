#include <iostream>

using namespace std;
class Stog
{
private:
   static const int MAX = 100;
   int stack[MAX];
   int vrh = -1;

public:
   bool dodaj(int broj)
   {
      if (vrh >= MAX - 1)
         return false;
      stack[++vrh] = broj;
      return true;
   }
   bool izvadi(int &broj)
   {
      if (vrh < 0)
         return false;
      broj = stack[vrh--];
      return true;
   }
};

int main(void)
{
   Stog s;
   s.dodaj(1);
   s.dodaj(2);
   s.dodaj(3);

   int broj;
   s.izvadi(broj);
   cout << broj;
   system("pause");
   return 0;
}