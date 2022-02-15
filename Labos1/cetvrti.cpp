#include <iostream>
#include <cmath>
using namespace std;

double exp(double x, int n, int *fakt, double *xpot)
{
   if (n == 0)
   {
      return 1;
   }
   return exp(x, n - 1, fakt + 1, xpot + 1) + pow(x, n) * *(xpot + 1) / *(fakt + 1);
}

int main(void)
{
   int n;
   cin >> n;

   double x;
   cin >> x;

   int *fakt;
   fakt = new int[n];
   fakt[0] = 1;

   double *xpot;
   xpot = new double[n];

   for (int i = 1; i < n; i++)
   {
      fakt[i] = i * fakt[i - 1];
   }

   for (int i = 0; i < n; i++)
   {
      xpot[i] = pow(x, i);
   }

   //rezultat
   double *rezultat;
   rezultat = new double[n];
   for (int i = 0; i < n; i++)
   {
      rezultat[i] = exp(x, i, fakt, xpot);
   }

   cout << "REZULTAT" << endl;

   for (int i = 0; i < n; i++)
   {
      cout << rezultat[i] << endl;
   }

   system("pause");
   return 0;
}