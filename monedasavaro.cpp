#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// PROTOTIPOS DE FUNCIONES
int moneda_optima(vector<int> tupla, int billetesYmonedas[], int N, int i, int cambio);
void cambio_monedas_dinamico(int N, int billetesYmonedas[], int P, int Q);
void cambio_monedas_avaro(int N, int billetesYmonedas[], int P, int Q);

// STRUCTURE
struct PyQ {
  int precioP;
  int pagoP;
};


// CODIGO PRINCIPAL
int main(void)
{

  // Ingresa el número de monedas N
  int N, i = 0;
  cout << "Ingresa la cantidad de billetes/monedas: ";
  do {
    cin >> N;
    
    if (N <= 0) {
      cout << "Ingresa un número mayor a cero\n";
    }
    
  } while (N <= 0);

  
  // Declaramos los arreglos a llenar
  int billetesYmonedas[N];

  // Ingresa las denominaciones de las N monedas
  cout << "\nIngresa las denominaciones de los billetes/monedas: (enter por cada billete/moneda)\n\n";
  do
  {
    
    cout << "Billete/Moneda " << i + 1 << ": ";
    cin >> billetesYmonedas[i];
    
    if (billetesYmonedas[i] <= 0) { 
      cout << "\nEl billete/moneda debe tener denominación mayor a cero!\n\n";
      do {
        cout << "Ingresa una nueva denominación para el Billete/moneda " << i + 1 << ": ";
        cin >> billetesYmonedas[i];
      } while (billetesYmonedas[i] <= 0);
    }
    i++;
  } while (i < N);

  
  // Declaramos los arreglos a llenar
  PyQ listaPyQ[N];
  
  // Ingresa el número de productos M
  int M, j = 0;
  cout << "\nIngresa la cantidad productos: ";
  
  do {
    cin >> M;
    
    if (M <= 0) {
      cout << "Ingresa un número mayor a cero\n";
    }
    
  } while (M <= 0);

  // Ingresa el precio de un producto y la denominación de la moneda con que lo paga
  cout << "\nP: precio de un producto dado y Q: billete/moneda con que se paga dicho producto.\n\n";
  do {
    
    cout << "P(" << j + 1 << "): ";
    cin >> listaPyQ[j].precioP;
    
    if (listaPyQ[j].precioP <= 0) {
      do {
        cout << "El precio del producto debe ser mayor a cero.\n\n";
        cout << "P(" << j + 1 << "): ";
        cin >> listaPyQ[j].precioP;
        cout << endl;
      } while (listaPyQ[j].precioP <= 0);
    }

    cout << "Q(" << j + 1 << "): ";
    cin >> listaPyQ[j].pagoP;
    
    if (listaPyQ[j].pagoP <= 0) {
      do {
        cout << "El billete/moneda debe ser mayor a cero.\n\n";
        cout << "Q(" << j + 1 << "): ";
        cin >> listaPyQ[j].pagoP;
        cout << endl;
      } while (listaPyQ[j].pagoP <= 0);
    }

    cout << endl;
    ++j;
  } while (j < M);


  // Programación dinámica
  cout << "\n\n PROGRAMACIÓN DINÁMICA\n\n";
  for (int k = 0; k < M; ++k) {
    cout << "Cambio del producto " << k + 1 << ": \n";
    cambio_monedas_dinamico(N, billetesYmonedas, listaPyQ[k].precioP, listaPyQ[k].pagoP);
    cout << endl;
  }

  // Programación avara
  cout << "\n\n PROGRAMACIÓN AVARA\n\n";
  for (int k = 0; k < M; ++k) {
    cout << "Cambio del producto " << k + 1 << ": \n";
    cambio_monedas_avaro(N, billetesYmonedas, listaPyQ[k].precioP, listaPyQ[k].pagoP);
    cout << endl;
  }
}


// FUNCION AUXILIAR para programación dinámica
int moneda_optima(vector<int> tupla, int billetesYmonedas[], int N, int cambio) {
  for (int i = 0; i < N; i++) {
    if (billetesYmonedas[i] <= cambio) {
      int r = cambio - billetesYmonedas[i];
      if (tupla.empty()) {
        tupla.push_back(r);
        tupla.push_back(billetesYmonedas[i]);
      } 
      else {
        if (r <= tupla[0]) {
          tupla[0] = r;
          tupla[1] = billetesYmonedas[i];
        }
      }
    }
  }
  return tupla[1];
}

// PSEUDOCÓDIGO:
    // Si el precio del producto es menor al billete con el que pagué
    //   Encuentro el cambio que le debo al cliente
    //   Encuentro el billete de mayor denominación disponible para dar cambio
    //   Imprimo dicho billete -> representando el cambio a entregarle al cliente
    //   Actualizo la suma restante de cambio por entregar
    //   Regreso

// Función con programación dinámica
void cambio_monedas_dinamico(int N, int billetesYmonedas[], int P, int Q) {
  
  // Caso base
  if (P < Q) {
    int cambio = Q - P;
    vector<int> tupla(0);
    int m = moneda_optima(tupla, billetesYmonedas, N, cambio);
    cout << m << endl;
    cambio_monedas_dinamico(N, billetesYmonedas, m, cambio);
  }
}

// Función con programación codiciosa/avaro/voraz
void cambio_monedas_avaro(int N, int billetesYmonedas[], int P, int Q) {
  
  int cambio = Q - P;
  sort(billetesYmonedas, billetesYmonedas + N);
  
  for (int i = N - 1; i >= 0; i--) {
    while (cambio >= billetesYmonedas[i]) {
      cambio -= billetesYmonedas[i];
      cout << billetesYmonedas[i] << endl;
    }
  }
}
