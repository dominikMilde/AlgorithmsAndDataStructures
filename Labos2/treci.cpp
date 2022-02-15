#include <iostream>
using namespace std;

struct Zapis
{
   int sifraJela;
   string nazivJela;
};

void obicanBubbleSort(Zapis A[], int n, char smjer)
{
   for (int i = 0; i < n - 1; i++)
   {
      struct Zapis tmp;
      for (int j = 0; j < n - i - 1; j++)
      {
         if (A[j].sifraJela > A[j + 1].sifraJela && smjer == '0')
         {
            tmp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = tmp;
         }
         if (A[j].sifraJela < A[j + 1].sifraJela && smjer == '1')
         {
            tmp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = tmp;
         }
      }
   }
}
int main(void)
{
   int n;
   cin >> n;
   Zapis zapis[n];
   for (int i = 0; i < n; i++)
   {
      int p;
      string nM;
      cin >> p;
      cin >> nM;
      zapis[i] = Zapis{p, nM};
   }
   char smjer;
   cin >> smjer;

   obicanBubbleSort(zapis, n, smjer);
   for (int i = 0; i < n; i++)
   {
      cout << zapis[i].sifraJela << " " << zapis[i].nazivJela << endl;
   }
   system("pause");
   return 0;
}