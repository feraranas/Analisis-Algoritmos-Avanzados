#include <stdio.h>

// variables globales
const int N = 10;

// prototipos
void bubbleSort(int arreglo[]);
void imprimir_arreglo(int a[]);

int main(void) {
  
  int a[] = {8, -6, 7, -4, 5, -3, 2, 10, 1, 9};
  imprimir_arreglo(a);
  bubbleSort(a);
  imprimir_arreglo(a);
}

void bubbleSort(int arreglo[]) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arreglo[j] > arreglo[j + 1]) {
        int tmp = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = tmp;
      }
    }
  }
}

void imprimir_arreglo(int a[]) {
  for (int i = 0; i < N; i++) {
    printf("%i ", a[i]);
  }
  printf("\n");
}