#include <iostream>
using namespace std;

struct Zapis
{
   int postanskiBroj;
   string nazivMjesta;
};

void insertionSort(Zapis A[], int n, char smjer)
{
   int i, j;
   struct Zapis tmp;
   for (i = 1; i < n; i++)
   {
      tmp = A[i];
      for (j = i; j >= 1 && tmp.postanskiBroj < A[j-1].postanskiBroj; j--)
      {  
         A[j] = A[j-1];
      }
      A[j] = tmp;
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

   insertionSort(zapis, n, smjer);
   for (int i = 0; i < n; i++)
   {
      cout << zapis[i].postanskiBroj << " " << zapis[i].nazivMjesta << endl;
   }
   system("pause");
   return 0;
}