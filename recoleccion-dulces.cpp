#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int encuentra_maxima_suma_subarreglo(vector<int> arr);

int main() {
  vector<int> arr = {-2, 3, 5, 6, -1};
  cout << encuentra_maxima_suma_subarreglo(arr) << endl;
}

int encuentra_maxima_suma_subarreglo(vector<int> arr) {
  
  // Guardamos dos apuntadores, 
  // uno al inicio y otro al final de cada sub-arreglo
  int n = arr.size();
  int maxima_suma_actual = 0;
  int maxima_suma_overall = INT_MIN;
  for (const auto &i: arr) {
    maxima_suma_actual += i;
    if (maxima_suma_actual > maxima_suma_overall) {
      maxima_suma_overall = maxima_suma_actual;
    }
    // Para la siguiente iteración, el valor inicial de maxima_suma_actual
    // es la suma máxima de el indice previo, solo queremos agregarlo a la nueva suma si ayuda a incrementarla
    // en otro caso lo reseteamos a 0
    if (i < 0) maxima_suma_actual = 0;
  }

  return maxima_suma_overall;
}