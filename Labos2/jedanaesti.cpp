#include <iostream>
#include <cstring>
using namespace std;

void Zamijeni(string *prvi, string *drugi){
   string temp = *prvi;
   *prvi = *drugi;
   *drugi = temp;
}

void ShellSort(string A[], int n, int smjer){
   int i, j;
   for(int step = n/2; step>0; step=step/2){
      for(i = step; i<n; i++){
         string temp = A[i];
         for(j=i; j>=step && A[j-step] > temp; j-=step ){
            A[j] = A[j-step];
         }
         A[j] = temp;
      }
   }
}
int main(void){
    int N = 10;
    string A[10];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int dir;
    cout << "dir?: ";
    cin >> dir;
    ShellSort(A, N, dir);
    for(int i = 0; i < N; i++)
        cout << A[i] << " ";
    cout << endl;
    system("pause");
    return 0;

}