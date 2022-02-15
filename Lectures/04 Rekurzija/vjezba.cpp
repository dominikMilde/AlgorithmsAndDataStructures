#include <iostream>
using namespace std;

int poljeEkstrema(int *a, int n)
{
   if (n <= 2)
   {
      return 1;
   }
   else
   {
      if ((a[n - 3] < a[n - 2]) && (a[n - 1] < a[n - 2]) || (a[n - 3] > a[n - 2]) && (a[n - 1] > a[n - 2]))
      {
         return poljeEkstrema(a, n - 1);
      }
      else
      {
         return 0;
      }
   }
}
int main()
{
   int A[] = {2, 6, 3, 7, 8, 66};
   cout << poljeEkstrema(A, 6);
   cin.get();
   return 0;
}
