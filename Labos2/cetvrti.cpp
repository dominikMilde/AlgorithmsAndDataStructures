#include <iostream>
using namespace std;

void spojiPolja(int A[], int B[], int Rez[], int n1, int n2)
{
   int ind1 = 0, ind2 = 0;
   for (int indRez = 0; indRez < n1 + n2; indRez++)
   {
      if (ind1 < n1) //ima u prvome
      {
         if (ind2 < n2) //ima u drugome
         {
            if (A[ind1] > B[ind2])
            {
               Rez[indRez] = A[ind1];
               ind1++;
            }
            else
            {
               Rez[indRez] = B[ind2];
               ind2++;
            }
         }
         else
         {
            Rez[indRez] = A[ind1];
            ind1++;
         }
      }
      else
      {
         Rez[indRez] = B[ind2];
         ind2++; 
      }
   }
}

int main(void)
{
   int A[] = {6, 5, 4, 4, 2, 1}, B[] = {7, 3, 2, 1};
   int sA = sizeof(A) / sizeof(int), sB = sizeof(B) / sizeof(int);
   int *Rez = new int[sA + sB];
   spojiPolja(A, B, Rez, sA, sB);
   for (int i = 0; i < sA + sB; i++)
   {
      cout << Rez[i] << " ";
   }
   cout << endl;
   system("pause");
   return 0;
}