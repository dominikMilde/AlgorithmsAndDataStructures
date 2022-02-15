#include <iostream>
using namespace std;

void ispis(float *polje, int n)
{
   if (*polje < 0)
   {
      cout << *polje << endl;
   }

   if (n > 1)
   {
      ispis(polje + 1, n - 1);
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
      float temp;
      cin >> temp;
      A[0 + i] = temp;
   }

   ispis(A, n);

   system("pause");
   return 0;
}