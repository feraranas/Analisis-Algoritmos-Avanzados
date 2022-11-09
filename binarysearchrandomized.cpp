/* Elaborado por Fernando Alfonso Arana Salas
Randomized Binary Search Algorithm */

#include <iostream>
#include <vector>
using namespace std;

////////////////////////////////////////
/* PROTOTIPOS DE FUNCIONES n */
////////////////////////////////////////
double verifica_input();
int verifica_numeros(vector<double> &puntos);
int numero_aleatorio(int a, int b);
void busqueda_binaria_randomizada(vector<double> puntos, double num, int a,
                                  int b);
bool orden(vector<double> puntos);

////////////////////////////////////////
/* DRIVER CODE n */
////////////////////////////////////////
int main() {
  vector<double> puntos = {};
  ////////////////////////////////////////
  /* INGRESA NUMERO n */
  ////////////////////////////////////////
  double num = verifica_input();
  if (num == -1) {
    cout << "Input inválido. Vuelve a intentarlo\n";
    return 1;
  }

  if (verifica_numeros(puntos)) {
    cout << "Input inválido. Vuelve a intentarlo\n";
    return 1;
  }

  if (!orden(puntos)) {
    cout << "Ordena el arreglo de manera ASC. Vuelve a intentarlo\n";
    return 1;
  }

  int f = puntos.size();
  busqueda_binaria_randomizada(puntos, num, 0, f - 1);
}

////////////////////////////////////////////////////
/* COMPRUEBA QUE UN ARREGLO ESTÁ ORDENADO ASC */
////////////////////////////////////////////////////
bool orden(vector<double> puntos) {
  for (int i = 0, n = puntos.size(); i < n - 1; i++) {
    if (puntos[i] > puntos[i + 1])
      return false;
  }
  return true;
}

////////////////////////////////////////////////////
/* GENERA UN NÚMERO ALEATORIO ENTRE [X, Y] n */
////////////////////////////////////////////////////
int numero_aleatorio(int a, int b) {
  srand(time(NULL));
  return (a + rand() % (b - a + 1));
}

////////////////////////////////////////////////////
/* ALGORITMO RANDOMIZADO: BUSQUEDA BINARIA n */
////////////////////////////////////////////////////
void busqueda_binaria_randomizada(vector<double> puntos, double num, int a,
                                  int b) {
  if (a <= b) {
    int mitad = numero_aleatorio(a, b);
    if (puntos[mitad] == num) {
      cout << "El elemento esta presente en el indice: " << mitad << endl;
      return;
    } else if (num > puntos[mitad])
      busqueda_binaria_randomizada(puntos, num, mitad + 1, b);
    else
      busqueda_binaria_randomizada(puntos, num, a, mitad - 1);
  } else {
    cout << "El elemento no esta presente en el arreglo" << endl;
    return;
  }
}

////////////////////////////////////////
/* VERIFICA UN NÚMERO INGRESADO n */
////////////////////////////////////////
double verifica_input() {
  string linea;
  getline(cin >> ws, linea);

  // Leemos una linea del usuario y la procesamos
  for (int i = 0, n = linea.length(); i < n; i++) {

    bool negativo = false;
    bool check = false;
    bool decimalTrue = false;
    double numero = 0;
    vector<int> queue;
    double decimal = 0;

    // Si el número viene antecedido de un '-' entonces lo marcamos negativo
    if (linea[i] == 45) {
      negativo = true;
      i++;
    }

    while (i < n) {

      // Si encontramos un punto '.' todo lo que viene precedido es la parte
      // decimal
      if (linea[i] == 46) {
        if (decimal < 1) {
          decimal++;
          i++;
        } else {
          return 1;
        }
      }

      // Buscamos que sean digitos
      if (linea[i] >= 48 && linea[i] <= 57) {
        check = true;

        // Si ya encontramos un punto, procesamos la parte entera
        if (decimal) {
          if (!decimalTrue) {
            for (int j = 0, x = queue.size(), a = 1; j < x; j++, a *= 10)
              numero += queue[j] * a;
            queue.clear();
            decimalTrue = true;
          }
        }

        // Si estamos en la última posición de la linea de input
        if (i == n - 1) {
          queue.insert(queue.begin(), int(linea[i] - 48));
          if (decimal) {
            int decimalTmp = 0, dc = 1;
            int x = queue.size();
            for (int j = 0, a = 1; j < x; j++, a *= 10)
              decimalTmp += queue[j] * a;
            for (int z = 0; z < x; z++) {
              dc *= 10;
            }
            numero = numero + decimalTmp / (float)dc;
            if (check) {
              if (negativo)
                numero = numero * -1;
              return numero;
            } else {
              return -1;
            }
          }
          for (int j = 0, x = queue.size(), a = 1; j < x; j++, a *= 10)
            numero += queue[j] * a;

          if (check) {
            if (negativo)
              numero = numero * -1;
          } else {
            return -1;
          }
          return numero;
        }

        // Agregamos cada digito al inicio
        queue.insert(queue.begin(), int(linea[i] - 48));
        i++;
      } else {
        return -1;
      }
    }

    if (decimal) {
      int decimalTmp = 0, dc = 1;
      int x = queue.size();
      for (int j = 0, a = 1; j < x; j++, a *= 10)
        decimalTmp += queue[j] * a;
      for (int z = 0; z < x; z++) {
        dc *= 10;
      }
      numero = numero + decimalTmp / (float)dc;
      if (check) {
        if (negativo)
          numero = numero * -1;
        return numero;
      } else {
        return -1;
      }
    } else {
      for (int j = 0, x = queue.size(), a = 1; j < x; j++, a *= 10)
        numero += queue[j] * a;

      if (check) {
        if (negativo)
          numero = numero * -1;
        return numero;
      } else {
        return -1;
      }
    }
    i++;
  }
  return 0;
}

/////////////////////////////////////////////////
/* VERIFICA UNA LINEA DE NÚMEROS INGRESADO n */
/////////////////////////////////////////////////
int verifica_numeros(vector<double> &puntos) {
  /* INGRESA LOS PUNTOS n */
  string linea;
  getline(cin >> ws, linea);

  // Leemos una linea del usuario y la procesamos
  for (int i = 0, n = linea.length(); i < n; i++) {

    bool negativo = false;
    bool check = false;
    bool decimalTrue = false;
    bool last = false;
    double numero = 0;
    vector<int> queue;
    double decimal = 0;

    // Si el número viene antecedido de un '-' entonces lo marcamos negativo
    if (linea[i] == 45) {
      negativo = true;
      i++;
    }

    // Leemos números hasta encontrar una ','
    // Al terminar de procesar un número, la secuencia al próximo es ', '
    while (linea[i] != 44 && i < n) {

      // Si encontramos un punto '.' todo lo que viene precedido es la parte
      // decimal
      if (linea[i] == 46) {
        if (decimal < 1) {
          decimal++;
          i++;
        } else {
          return 1;
        }
      }

      // Buscamos que sean digitos
      if (linea[i] >= 48 && linea[i] <= 57) {
        check = true;

        // Si ya encontramos un punto, procesamos la parte entera
        if (decimal) {
          if (!decimalTrue) {
            for (int j = 0, x = queue.size(), a = 1; j < x; j++, a *= 10)
              numero += queue[j] * a;
            queue.clear();
            decimalTrue = true;
          }
        }

        // Si estamos en la última posición de la linea de input
        if (i == n - 1) {
          queue.insert(queue.begin(), int(linea[i] - 48));
          if (decimal) {
            int decimalTmp = 0, dc = 1;
            int x = queue.size();
            for (int j = 0, a = 1; j < x; j++, a *= 10)
              decimalTmp += queue[j] * a;
            for (int z = 0; z < x; z++) {
              dc *= 10;
            }
            numero = numero + decimalTmp / (float)dc;
            if (check) {
              if (negativo)
                numero = numero * -1;
              last = true;
              puntos.push_back(numero);
              break;
            } else {
              return 1;
            }
          }
          for (int j = 0, x = queue.size(), a = 1; j < x; j++, a *= 10)
            numero += queue[j] * a;

          if (check) {
            if (negativo)
              numero = numero * -1;
          } else {
            return 1;
          }
          last = true;
          puntos.push_back(numero);
          break;
        }

        // Agregamos cada digito al inicio
        queue.insert(queue.begin(), int(linea[i] - 48));
        i++;
      } else {
        return 1;
      }
    }

    // Si estamos en la última posición
    if (last)
      break;

    if (decimal) {
      int decimalTmp = 0, dc = 1;
      int x = queue.size();
      for (int j = 0, a = 1; j < x; j++, a *= 10)
        decimalTmp += queue[j] * a;
      for (int z = 0; z < x; z++) {
        dc *= 10;
      }
      numero = numero + decimalTmp / (float)dc;
      if (check) {
        if (negativo)
          numero = numero * -1;
      } else {
        return 1;
      }
    } else {
      for (int j = 0, x = queue.size(), a = 1; j < x; j++, a *= 10)
        numero += queue[j] * a;

      if (check) {
        if (negativo)
          numero = numero * -1;
      } else {
        return 1;
      }
    }
    puntos.push_back(numero);
    i++;
    // Verificamos que sea un espacio después de cada ','
    if (linea[i] != 32)
      return 1;
  }
  return 0;
}
