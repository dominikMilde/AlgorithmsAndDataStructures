#include <iostream>
#include <stdlib.h>
using namespace std;

class Stog
{
private:
   static const int MAX = 10;
   int stog[MAX];
   int vrh = -1;

public:
   bool push(int data)
   {
      if (vrh >= MAX - 1)
         return false;
      stog[++vrh] = data;
      return true;
   }
   bool pop(int &data)
   {
      if (vrh < 0)
         return false;
      data = stog[vrh--];
      return true;
   }
};

int main(void)
{

   Stog stog, pomocni;
   stog.push(1);
   stog.push(2);
   stog.push(3);
   int broj;
   stog.pop(broj);
   pomocni.push(broj);
   stog.pop(broj);
   pomocni.push(broj);
   stog.pop(broj);
   pomocni.push(broj);

   for (int i = 0; i < 3; i++)
   {
      pomocni.pop(broj);
      cout << broj << endl;
   }
   system("pause");
   return 0;
}