#include <iostream>
#include <vector>
using namespace std;

const int N = 20;

vector<int> bubblesort(vector<int> a);
void intercambia(int &a, int &b);
void imprime_vector(vector<int> a);

int main() {
  
  vector<int> a;
  int i = 0;
  while (i < N) {
    a.push_back(i);
    i++;
  }
  cout << "Vector desordenado: ";
  imprime_vector(a);
  cout << endl;
  a = bubblesort(a);
  cout << "Vector ordenado: ";
  imprime_vector(a);
}

void imprime_vector(vector<int> a) {
  for (auto i = a.begin(), n = a.end(); i < n; ++i) cout << *i << " ";
}

vector<int> bubblesort(vector<int> a) {

  // Para optimizar el algoritmo, en el mejor de los casos O(n)
  bool bandera = false;
  
  for (auto i = a.begin(), n = a.end(); i < n; ++i) {
    for (int j = 0, n = a.size(); j < n - 1; j++) {
      if (a[j + 1] > a[j]) {
        bandera = true;
        intercambia(a[j + 1], a[j]);
      }
    }
    if (!bandera) break;
  }
  return a;
}

void intercambia(int &a, int &b) {
  int tmp = move(a);
  a = move(b);
  b = move(tmp);
}