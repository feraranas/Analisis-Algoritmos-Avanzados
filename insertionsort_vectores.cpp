#include <iostream>
#include <vector>
using namespace std;

vector<int> insertionsort(vector<int> a);
void imprime_vector(vector<int> a);

int main() {
  
  vector<int> a = {5, 3, 0, 1, 4, 2};

  cout << "Arreglo desordenado: ";
  imprime_vector(a);
  cout << endl;
  
  a = insertionsort(a);
  cout << "Arreglo ordenado: ";
  imprime_vector(a);
  
}

// Ordenamiento por inserción
vector<int> insertionsort(vector<int> a) {
  
  // Iniciamos el pivote en 1
  int i = 1, j, n = a.size(), index;
    
  while (i < n) {

    bool bandera = false;
    
    for (j = i - 1; j >= 0; j--) {
      if (a[i] > a[j]) {
        index = j;
        bandera = true;
      }
    }

    // Declaramos el iterador para el vector
    vector<int>::iterator ptr = a.begin();

    // En caso de que en la iteración encuentre un número mayor
    if (bandera) {
      // Fijamos el iterador en la posición a insertar
      advance(ptr, index);

      // Insertas el elemento en su posición correcta
      a.insert(ptr, a[i]);
    
      // Eliminas el elemento de la posición incorrecta
      a.erase(a.begin() + i + 1);
    }

    // Incrementamos el pivote
    i++;
  }
  
  return a;
}

// Función para imprimir un vector usando iteradores
void imprime_vector(vector<int> a) {
  for (auto i = a.begin(), n = a.end(); i < n; ++i) cout << *i << " ";
}