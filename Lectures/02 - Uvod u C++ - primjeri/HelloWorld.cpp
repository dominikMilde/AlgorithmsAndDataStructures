#include <iostream>
using namespace std;

int main(void) {
   int n = 2;
   cout << "Hello world" << endl;
   cin >> n;

   for (int i = 0; i < n; i++) {
      cout << "Ovoliko puta" << endl;
   }

   cout << "Reci dalje" << endl;
   int m = 3;

   cin >> m;

   system("pause");
   return 0;
}