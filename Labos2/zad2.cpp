#include<iostream>

using namespace std;

int k[] = {235,53,12,75,55,43,150,};

void selection2Sort(int A[], int n, char smjer) {
    for(int i  = 0; i < n/2; i++) {
        int min = i;
        int max = n-i-1;

        for(int j = i; j < n-i; j++) {
            if((smjer == '0') ? (A[j] < A[min]) : (A[j] > A[min])) {  min = j; }
            if((smjer == '0') ? (A[j] > A[max]) : (A[j] < A[max])) {  max = j; }
        }

        if(min == n-i-1 && max == i) swap(A[max], A[min]);
        else if(min == n-i-1 && max != i) { swap(A[min], A[i]); swap(A[min], A[max]); }
        else if(min != n-i-1 && max == i) { swap(A[max], A[n-i-1]); swap(A[min], A[max]); }
        else { swap(A[n-i-1], A[max]); swap(A[i], A[min]); }
    }
}

int main() {
    selection2Sort(k, 6, '1');
    for(int i = 0; i < 6;i++)  {
        cout << k[i] << ",";
    }

    return 0;
}