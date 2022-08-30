#include <iostream>
#include <iomanip>
using namespace std;

const int N = 8;
const int M = 8;

int indice_valido(int vsol[N][M], int x, int y);
void imprimir_vector(int vsol[N][M]);
int busqueda_solucion_matriz(int a, int b, int i, int vsol[N][M], int x[], int y[]);

int main()
{
  // Posición inicial caballo (Podemos solicitar dicho input)
  int a = 0, b = 0;

  // Tamaño de matriz n x m (Podemos solicitar dicho input)

  // Vector solución
  int vsol[N][M];
  
  // Tablero matriz
  for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
          vsol[i][j] = -1;

  // Definimos todas las 8 posiciones que puede tomar un caballo.
  int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
  int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

  // Posicion inicial del caballo.
  vsol[a][b] = 0;

  int tf = busqueda_solucion_matriz(a, b, 1, vsol, x, y);
  if (tf == 0) {
    cout << "No hay solución." << endl;
    return 0;
  } else imprimir_vector(vsol);
  
  return 1;
}

/* Función para comprobar indices válidos en el tablero*/
int indice_valido(int vsol[N][M], int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < M
            && vsol[x][y] == -1);
}

/* Función para imprimir arreglo bidimensional*/
void imprimir_vector(int vsol[N][M]) 
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << " " << setw(2) << vsol[i][j] << " ";
    }
    cout << endl;
  }
}

/* Función utiliza backtracking */
int busqueda_solucion_matriz(int a, int b, int i, int vsol[N][M], int x[8], int y[8]) 
{
  int k, posible_casilla_x, posible_casilla_y;

  // Caso base
  if (i == N * M) return 1;

  // Itera por todas las coordenadas restantes
  for (k = 0; k < N; k++) {
    
    posible_casilla_x = a + x[k];
    posible_casilla_y = b + y[k];
    
    if (indice_valido(vsol, posible_casilla_x, posible_casilla_y)) {
      vsol[posible_casilla_x][posible_casilla_y] = i;
      if (busqueda_solucion_matriz(posible_casilla_x, posible_casilla_y, i + 1, vsol, x, y) == 1) 
        return 1;
      else 
        vsol[posible_casilla_x][posible_casilla_y] = -1;
    }
  }

  return 0;
}


/* Función previa para encontrar posibles casillas de movimiento */
/*
vector<pares> posiciones_para_mover_caballo(int a, int b, int n, int m) {

  // Guardar las posibles casillas
  vector<pares> pcasillas;
  
  for (int k = -2; k < 3; k++) {
    if (k == 0) continue;
    pares pos;
    for (int n = 0, i = 1, j = 2; n < 2; n++) {
      if (abs(k) == 2) {
        if (a + k >= n ||
            b + i >= m ||
            a + k < 0 ||
            b + i < 0) { continue; }
        else {// (a+k, b+i)
        pos.x = a + k;
        pos.y = b + i;
        i *= -1;
        }
      }
      else {
        if (a + k >= n ||
            b + j >= m ||
            a + k < 0 ||
            b + j < 0) { continue;}
        else {
          // (a+k, b+j)
          pos.x = a + k;
          pos.y = b + j;
          j *= -1;
        }
      }
    }
    pcasillas.push_back(pos);
  }

  return pcasillas;
}
*/