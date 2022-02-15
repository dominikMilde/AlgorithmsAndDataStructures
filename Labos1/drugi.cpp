#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

int zbrojiKvadrate(int polje[], int n)
{
   if (n == 0)
   {
      return 0;
   }
   int trenutni = (*polje);
   cout << "pregledavam " << trenutni << endl;
   if (sqrt(trenutni) - floor(sqrt(trenutni)) == 0) //kvadrat će uvijek biti već .0
   {
      //cout << "nadoh" << *polje << endl;
      return *polje + zbrojiKvadrate(polje + 1, n - 1);
   }
   else
   {
      return 0 + zbrojiKvadrate(polje + 1, n - 1);
   }
}

int main(void)
{
   int n;
   cin >> n;

   int *A;
   A = new int[n];
   srand(time(NULL));
   for (int i = 0; i < n; i++)
   {
      A[i] = rand() % 10 + 1;
   }

   for (int i = 0; i < n; i++)
   {
      cout << A[i] << endl;
   }
   cout << zbrojiKvadrate(A, n) << endl;

   system("pause");
   return 0;
}