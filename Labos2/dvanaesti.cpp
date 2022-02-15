#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int nadiHibbard(int n){
   return log2(n-1);
}

void ShellSort_Hibbard(string A[], int n, int smjer){
   int i, j;
   for(int step = pow(2, log2((int)n)) - 1; step>=1; step=step/2){
      for(i = step; i<n; i++){
         string temp = A[i];
         for(j=i; j>=step && (smjer == 1 ? A[j-step] < temp : A[j-step] > temp); j-=step ){
            A[j] = A[j-step];
         }
         A[j] = temp;
      }
   }
}
int main(void){
    int N = 10;
    string A[N];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int dir;
    cout << "dir?: ";
    cin >> dir;
    ShellSort_Hibbard(A, N, dir);
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    system("pause");
    return 0;

}