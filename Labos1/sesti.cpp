#include <iostream>

using namespace std;

char *ostaviSlova(string ulaz)
{
   char *izlaz;
   int count = 0;
   izlaz = (char *)malloc(sizeof(char) * ulaz.length() + 1);

   for (int i = 0; i < ulaz.length(); i++)
   {
      if (ulaz[i] >= 'a' && ulaz[i] <= 'z' || ulaz[i] >= 'A' && ulaz[i] <= 'Z')
      {
         izlaz[count] = ulaz[i];
         count++;
      }
   }

   izlaz[count] = '\0';
   izlaz = (char *)realloc(izlaz, sizeof(char) * count + 1);

   return izlaz;
}

int main(void)
{
   string ulaz = "ASP_r1";
   cout << ostaviSlova(ulaz) << endl;
   system("pause");
   return 0;
}