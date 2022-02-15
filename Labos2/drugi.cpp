#include <iostream>
using namespace std;

void zamjeni(int &a, int &b){
   int c = a;
   a = b;
   b = c;
}
void selection2Sort(int A[], int n, char smjer){
   int j, i, min, max;
   for(i=0, j=n-1; i<n; i++, j--){
      min = i;
      max = j;
      for(int k = i; k<=j; k++){
         if(A[k] <= A[min]) min = k;
         if(A[k] >= A[max]) max = k;
      }

      if (min == j && max == i) zamjeni(A[j], A[i]);
      else if(i == max && j != min){
         zamjeni(A[i], A[min]); 
         zamjeni(A[j], A[min]);
      }
      else if(j == min && i != max){
         zamjeni(A[j], A[max]);
         zamjeni(A[i], A[max]);
      }
      else{
         zamjeni(A[j], A[max]);
         zamjeni(A[i], A[min]);
      }
   }
}

int main(void)
{
   int n;
   cin >> n;
   int zapis[n];
   for (int i = 0; i < n; i++)
   {
      int p;
      cin >> p;
      zapis[i] = p;
   }
   char smjer;
   cin >> smjer;

   selection2Sort(zapis, n, smjer);
   for (int i = 0; i < n; i++)
   {
      cout << zapis[i] << endl;
   }
   system("pause");
   return 0;
}