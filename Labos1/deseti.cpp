#include <iostream>
using namespace std;

double f(double z, int k)
{
   if (k == 0)
   {
      return z;
   }
   else
   {
      return (-z * z) / ((2 * k + 1) * 2 * k) * f(z, k - 1);
   }
}

int main(void)
{
   double z;
   cin >> z;

   int k;
   cin >> k;

   cout << f(z, k) << endl;
   system("pause");
   return 0;
}