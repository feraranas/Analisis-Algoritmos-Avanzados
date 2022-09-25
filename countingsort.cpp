#include <iostream>

int main() {
  
  int arr[] = {1,4,1,2,7,5,2};
  int tamano_arr = sizeof(arr) / sizeof(arr[0]);
  int i, max_value = 0;
  int arr_salida[tamano_arr];
  
  for (i = 0; i < tamano_arr; i++)
    if (max_value < arr[i]) max_value = arr[i];

  int cumulo[max_value + 1];
  
  for (i = 0; i < max_value + 1; i++) cumulo[i] = 0;

  for (i = 0; i < tamano_arr; i++)
    cumulo[arr[i]]++;

  for (i = 1; i < max_value + 1; i++) {
    cumulo[i] += cumulo[i - 1];
  }
  
  int indice_salida = 0;
  for (i = 0; i < tamano_arr; i++) {
    indice_salida = cumulo[arr[i]] - 1;
    arr_salida[indice_salida] = arr[i];
    cumulo[arr[i]] -= 1;
  }

  for (i = 0; i < tamano_arr; i++) std::cout << arr_salida[i] << " ";
  std::cout << std::endl;
}