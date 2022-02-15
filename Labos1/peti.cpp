#include <iostream>
using namespace std;
template <typename T>
int binarnoTrazi(T polje[], int n, T x)
{
   int lijevi = 0;
   int desni = n - 1;
   int indeks = -1;
   bool nasao = false;

   while (lijevi <= desni)
   {
      int srednji = (lijevi + desni) / 2;

      if (abs(polje[srednji] - x) < 10e-6)
      {
         nasao = true;
         indeks = srednji;
         break;
      }
      else if (x < polje[srednji])
      {
         desni = srednji - 1;
      }
      else if (x > polje[srednji])
      {
         lijevi = srednji + 1;
      }
   }
   return indeks;
}

int main(void)
{
   int n;
   cin >> n;

   float x;
   cin >> x;

   float *A;
   A = new float[n];

   for (int i = 0; i < n; i++)
   {
      A[i] = i * 1.1;
   }

   int rez = binarnoTrazi(A, n, x);
   if (rez == -1)
   {
      cout << "ne postoji";
   }
   else
   {
      cout << "indeks:" << rez;
   }
   system("pause");
   return 0;
}