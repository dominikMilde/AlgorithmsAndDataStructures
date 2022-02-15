#include <iostream>

struct povratnaVrijednost
{
   int indeks;
   bool nasao;
};

template <typename T>
povratnaVrijednost binarnoTrazenje(T polje[], int n, T x)
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

   return povratnaVrijednost{indeks, nasao};
}

int main(void)
{

   double *A;
   A = new double[5];
   for (int i = 0; i < 5; i++)
   {
      A[i] = i * 2.2;
   }

   povratnaVrijednost rezz = binarnoTrazenje(A, 5, 6.6);
   std::cout << rezz.indeks << " " << rezz.nasao << std::endl;
   std::cin.get();
   return 0;
}
