#include <iostream>
#include <cstring>

using namespace std;
void Zamijeni(string *prvi, string *drugi){
   string temp = *prvi;
   *prvi = *drugi;
   *drugi = temp;
}

void BubbleSortPoboljsani(string A[], int n, int smjer){
   for(int i = 0; i<n-1; i++){
      for(int j = 0; j < n-i-1; j++){
         if(A[j+1]<A[j])
            Zamijeni(&A[j+1], &A[j]);
      }
   }
}

int main(void){
   string A[] = {"Zamjena","Ivo", "Marko", "Juraj", "Pero"};
   int N = sizeof(A) / sizeof(string);
   int dir;
   cin >> dir;
   BubbleSortPoboljsani(A, N, dir);
   for(int i = 0; i < N; i++)
        cout << A[i] << " ";
   cout << endl;
   system("pause");
   return 0;
}