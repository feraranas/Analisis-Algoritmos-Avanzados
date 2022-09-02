/*

Alumno: Fernando Alfonso Arana Salas
Matricula: A01272933

Tarea: Aplicando "Técnica Recursiva Backtracking & Ramificación y poda"

*/

#include <iostream>
#include <vector>
using namespace std;


/* PROTOTIPOS DE FUNCIONES */
bool busqueda_salida_laberinto(vector<vector<int>> laberinto, vector<vector<int>> vsol, int r, int c);
bool laberinto_recursivo(vector<vector<int>> laberinto, int r, int c, int x, int y, vector<vector<int>>& vsol);
bool valida_posicion(vector<vector<int>> matriz, int x, int y);
void imprimir_matriz(int r, int c, vector<vector<int>> vsol);
int digitization(string M);
int contadorStrings(string M);
int obtenM();
int obtenN();
vector<vector<int>> obtenmatriz(int r, int c);


/* CÓDIGO PRINCIPAL */
int main() {

  // Obtenemos dimensiones de la matriz laberinto del usuario
  int r = obtenM();
  int c = obtenN();

  // Obtenemos la matriz de 1's y 0's del usuario
  vector<vector<int>> matriz = obtenmatriz(r, c);
  
  // Creamos un vector solución de 0's de las mismas dimensiones del laberinto
  vector<vector<int>> vsol;
  for (int i = 0; i < r; i++) {
    vector<int> fila;
    for (int j = 0; j < c; j++)
      fila.push_back(0);
    vsol.push_back(fila);
  }

  // Llamamos a la función recursiva
  if (laberinto_recursivo(matriz, r, c, 0, 0, vsol) == false) {
    cout << "El laberinto no tiene salida.\n";
    return 0;
  }
  
  imprimir_matriz(r, c, vsol);
  return 1;

}



/* FUNCIONES */

// Valida si la posicion actual esta dentro de la matriz & que la posicion sea válida
bool valida_posicion(vector<vector<int>> matriz, int x, int y)
{
  int r = matriz.size();
  int c = matriz[0].size();
  if (x >= 0 && x < r && y >= 0 && y < c && matriz[x][y] == 1)
    return true;
  return false;
}


// Imprime cualquier matriz
void imprimir_matriz(int r, int c, vector<vector<int>> vsol)
{
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      cout << " " << vsol[i][j] << " ";
    cout << endl;
  }
}


// Función backtracking - recursiva para encontrar salida del laberinto
bool laberinto_recursivo(vector<vector<int>> laberinto, int r, int c, int x, int y, vector<vector<int>>& vsol)
{
  // CASO BASE: Estamos situados en los índices terminales y el valor es 1.
  if (x == r - 1 && y == c - 1 && laberinto[x][y] == 1) {
    vsol[x][y] = 1;
    return true;
  }

  // CASO RECURSIVO: Verificamos que el índice es válido
  if (valida_posicion(laberinto, x, y) == true) {
    // Comprobamos que no hemos agregado el índice al vector solucion
    if (vsol[x][y] == 1) return false;
    // Asignamos dicha posicion como parte de la solucion
    vsol[x][y] = 1;
    // Actualizamos nuestra posición en x
    if (laberinto_recursivo(laberinto, r, c, x + 1, y, vsol) == true) return true;
    // Actualizamos nuestra posición en y
    if (laberinto_recursivo(laberinto, r, c, x, y + 1, vsol) == true) return true;
    // Aplicamos backtracking
    vsol[x][y] = 0;
    return false;
  }
  return false;
}


// Convierte strings a digitos
int digitization(string M) {
  int count = contadorStrings(M);
  int entero = 0;
  int arr[count];
  
  for (int i = 0; i < count; i++) {
    if (M[i] >= 48 && M[i] <= 57) {
      arr[i] = M[i] - 48;
    }
    else return -1;
  }

  int j = 1;
  for (int i = count - 1; i >= 0; i--) {
    entero += (int)arr[i] * j;
    j *= 10;
  }

  return entero;
}


// Cuenta los chars en un string
int contadorStrings(string M) {
  int count = 0;
  for (int i = 0; M[i] != '\0'; i++) {
    count++;
  }
  return count; 
}


// Obtiene un entero positivo válido
int obtenM(void) {
  // PIDE AL USUARIO M
  string M;
  int filas;
  do {
    cout << "Ingresa un número M (filas): ";
    cin >> M;
    if (M[0] == 48) filas = -1;
    else filas = digitization(M);
    if (filas == -1) cout << "No ingresaste un número válido. Vuelve a intentarlo.\n";
  } while (filas == -1);  
  return filas;
}


// Obtiene un entero positivo válido
int obtenN(void) {
  // PIDE AL USUARIO N
  int columnas;
  string N;
  do {
    cout << "Ingresa un número N (columnas): ";
    cin >> N;
    if (N[0] == 48) columnas = -1;
    else columnas = digitization(N);
    if (columnas == -1) cout << "No ingresaste un número válido. Vuelve a intentarlo.\n";
  } while (columnas == -1);
  return columnas;
}


// Obtiene un vector de vectores de enteros de 1's y 0's
vector<vector<int>> obtenmatriz(int r, int c) {
  vector<vector<int>> matriz;
  // PIDE AL USUARIO LA MATRIZ
  // M FILAS DE N NUMEROS BOOLEANOS
  for (int i = 0; i < r; i++) {
    vector<int> col;
    for (int j = 0; j < c; j++) {
      string tmp;
      int v;
      do {
        cin >> tmp;
        if (contadorStrings(tmp) != 1) v = -1;
        else v = digitization(tmp);
        if (v != 1 && v != 0) cout << "No ingresaste un número válido. Vuelve a intentarlo.\n";
      } while (v != 1 && v != 0);
      col.push_back(v);
    }
    matriz.push_back(col);
  }
  return matriz;
}