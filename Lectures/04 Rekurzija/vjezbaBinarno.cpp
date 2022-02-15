#include <iostream>
using namespace std;

bool binarySearch(int *a, int n, int &elem)
{
   int l = 0;
   int r = n - 1;
   bool found = false;
   int m;
   while (l <= r)
   {
      m = (l + r) / 2;
      if (elem < a[m])
      {
         r = m - 1;
      }
      else if (elem > a[m])
      {
         l = m + 1;
      }
      else
      {
         found = true;
         break;
      }
   }
   return found;
}

int main(void)
{
   int b = 66;
   int *a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int &ref = b;
   if (binarySearch(a, 10, ref))
   {
      cout << "etoga" << endl;
   }
   else
   {
      cout << "nema" << endl;
   }
   system("pause");
   return 0;
}