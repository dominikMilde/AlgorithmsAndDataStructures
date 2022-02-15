#include <iostream>
using namespace std;

int *vratiRandKvadrate(int A[], int n)
{
   int *novo;
   novo = new int[n]{NULL};

   for (int i = 0; i < n; i++)
   {
      int kvadrat = A[i] * A[i];
      while (true)
      {
         int indeks = rand() % n;
         if (novo[indeks] == NULL)
         {
            novo[indeks] = kvadrat;
            break;
         }
      }
   }
   return novo;
}
int main(void)
{
   int n;
   cin >> n;

   int *A;
   A = new int[n];

   for (int i = 0; i < n; i++)
   {
      cin >> A[i];
   }

   int *rez = vratiRandKvadrate(A, n);

   for (int i = 0; i < n; i++)
   {
      cout << rez[i] << endl;
   }
   system("pause");

   return 0;
}