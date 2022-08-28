#include <iostream>
#include <vector>
using namespace std;

int suma_maxima_adyacentes(vector<vector<int>> matriz);
int maxima_suma_region(vector<vector<int>> matriz, int a, int b, int c, int d);


int main() {
  vector<vector<int>> matriz = {{1, 0, 0, 0},
                                {1, 1, 1, 0},
                                {1, 1, 1, 0},
                                {0, 0, 1, 1}};

  cout << suma_maxima_adyacentes(matriz) << endl;
}

int suma_maxima_adyacentes(vector<vector<int>> matriz) {
  
  int r = matriz.size();
  int c = matriz[0].size();
  int maximo = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int maximo_region = maxima_suma_region(matriz, i, j, r, c);
      if (maximo < maximo_region) {
        maximo = maximo_region;
      }
    }
  }
  return maximo;
}

int maxima_suma_region(vector<vector<int>> matriz, int a, int b, int c, int d) {
  
  // Caso base: terminamos de llenar desde la celda actual
  if (a >= c || b >= d || matriz[a][b] == 0) {
    return 0;
  }

  // Marcamos cada celda como 'visitada' una vez que la recorremos
  matriz[a][b] = 0;
  int s = 1;
  
  // Visitamos todas las direcciones
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      s += maxima_suma_region(matriz, a + i, b + j, c, d);
    }
  }

  return s;
}