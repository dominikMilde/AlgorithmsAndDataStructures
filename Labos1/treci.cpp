#include <iostream>
#include <cmath>
using namespace std;
double pi(int n)
{
   if (n == 1)
   {
      return 4;
   }
   else
   {
      return (pi(n - 1) + pow(-1, n + 1) * 4.0 / (2 * n - 1));
   }
}

int main(void)
{
   int n;
   cin >> n;

   float *A;
   A = new float[n];

   for (int i = 0; i < n; i++)
   {
      A[i] = pi(i + 1);
   }

   for (int i = 0; i < n; i++)
   {
      cout << A[i] << endl;
   }

   system("pause");
   return 0;
}