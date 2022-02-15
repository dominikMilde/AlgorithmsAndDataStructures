#include <iostream>
#include <string>
using namespace std;

string spojiStringove(string A, string B)
{
   int ind1 = 0, ind2 = 0;
   string rezultat = "";
   while (A[ind1] != '\0' || B[ind2] != '\0')
   {
      if (A[ind1] != '\0') //ima u prvome
      {
         if (B[ind2] != '\0') //ima u drugome
         {
            if (A[ind1] > B[ind2])
            {
               rezultat += A[ind1];
               ind1++;
            }
            else
            {
               rezultat += B[ind2];
               ind2++;
            }
         }
         else
         {
            rezultat += A[ind1];
            ind1++;
         }
      }
      else
      {
         rezultat += B[ind2];
         ind2++;
      }
   }
   return rezultat;
}

int main(void)
{
   string A = "ecaDB", B = "dbECA";
   string rez = spojiStringove(A, B);
   cout << rez << endl;
   system("pause");
   return 0;
}