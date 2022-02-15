#include <cmath>
#include <iostream>
using namespace std;

void f(float polje[], int n, int m)
{
   if (n == 0)
   {
      polje[n] = 1.f;
      return;
   }
   polje[n] = polje[n - 1] * m;
   f(polje + 1, n - 1, m);
   return;
}

int main(void)
{

   int n;
   cin >> n;

   int m;
   cin >> m;

   float *polje;
   polje = new float[n]{0};

   f(polje, n, m);

   for (int i = 0; i < n; i++)
   {
      cout << polje[i] << endl;
   }
   system("pause");
   return 0;
}