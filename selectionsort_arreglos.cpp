// Ordenamiento por selección usando arreglos estáticos
#include <iostream>
using namespace std;

int main() {

  int a[] = {0,1,2,3,4,5,6,7,8,9,10};
  int j = sizeof(a)/sizeof(int), l = 0, m = 0;

  cout << "Lista desordenada: ";
  while (l < j) cout << a[l++] << " ";
  cout << endl;

  
  for (int i = 0, n = sizeof(a)/sizeof(int); i < n; i++) {

    bool bandera = false;
  
    int max = a[i], index;
     
    for (int j = i + 1, n = sizeof(a)/sizeof(int); j < n; j++) {    
      if (max < a[j]) {
        max = a[j];
        index = j;
        bandera = true;
      }
    }
      
    if (bandera) {
      a[index] = a[i];
      a[i] = max;
    }
  
  }
  cout << "Lista ordenada: ";
  while (m < j) cout << a[m++] << " ";
  cout << endl;
}