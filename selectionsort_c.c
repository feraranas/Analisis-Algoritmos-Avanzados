#include <stdio.h>

// variables globales
const int N = 10;

// prototipos
void selectionSort(int arreglo[]);
void imprimir_arreglo(int a[]);

int main(void) {
  
  int a[] = {8, -6, 7, -4, 5, -3, 2, 10, 1, 9};
  imprimir_arreglo(a);
  selectionSort(a);
  imprimir_arreglo(a);
}

void selectionSort(int arreglo[]) {

  for (int i = 0; i < N; i++) {
    int max = arreglo[i];
    int indicej = -1;
    for (int j = i + 1; j < N; j++) {
      if (max < arreglo[j]) {
        max = arreglo[j];
        indicej = j;
      }
    }
    if (indicej != -1) {
      int tmp = arreglo[i];
      arreglo[i] = max;
      arreglo[indicej] = tmp;
    }
    
  }
}

void imprimir_arreglo(int a[]) {
  for (int i = 0; i < N; i++) {
    printf("%i ", a[i]);
  }
  printf("\n");
}