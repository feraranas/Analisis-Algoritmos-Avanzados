#include <iostream>
using namespace std;

void secuenciaFibonacci(int n, int a, int b) {

  // Caso inicial donde a = 0, b = 1
  if (a == 0 && b == 1) cout << a << " " << b;

  int c = a + b;
  
  if (c <= n) {
    cout << " " << c;
    secuenciaFibonacci(n, b, c);
  }
  
}

int main() {
  
  int n;
  do {
    cout << "Ingresa el número a desplegar la secuencia Fibonacci: ";
    cin >> n;
  } while (n < 0);
  
  secuenciaFibonacci(n, 0, 1);
}
