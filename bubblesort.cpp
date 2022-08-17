#include <iostream>
using namespace std;

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {

  int a[] = {8, 6, 7, 4, 5, 3, 2};
  int j = sizeof(a)/sizeof(int), l = 0, m = 0;

  cout << "Lista desordenada: ";
  while (l < j) cout << a[l++] << " ";
  cout << endl;
  
  for (int i = 0; i < j - 1; i++){
    for (int k = 0; k < j - 1; k++){
      if (a[k] > a[k + 1]){
        // cout << a[k] << " : " << a[k + 1] << endl;
        swap(&a[k], &a[k + 1]);
      }
    }
  }

  cout << "Lista ordenada: ";
  while (m < j) cout << a[m++] << " ";
  cout << endl;
}