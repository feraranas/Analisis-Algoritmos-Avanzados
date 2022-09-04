#include <iostream>
using namespace std;

const int N = 10;

// Funciones prototipo
void insercion(int arreglo[N], int indiceDer, int valor);
void insercionSort(int arreglo[N]);

int main() {

  int a[N] = {8, -6, 7, -4, 5, -3, 2, 10, 1, 9};
  int l = 0, m = 0;

  cout << "Lista desordenada: ";
  while (l < N) cout << a[l++] << " ";
  cout << endl;

  insercionSort(a);

  cout << "Lista ordenada: ";
  while (m < N) cout << a[m++] << " ";
  cout << endl;
}

void insercion(int arreglo[N], int indiceDer, int valor) {
  int i = indiceDer;
  for (;
       i >= 0 && arreglo[i] > valor;
       i--)
    arreglo[i + 1] = arreglo[i];
  arreglo[i + 1] = valor;
}

void insercionSort(int arreglo[N]) {
  for (int i = 0; i < N; i++) {
    insercion(arreglo, i - 1, arreglo[i]);
  }
}