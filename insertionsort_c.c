#include <stdio.h>

// Prototipos de funciones
void insercion(int a[], int indiceDer, int valor);
void insercionSort(int a[]);
void imprimir_arreglo(int a[]);

// variables globales
const int N = 10;

int main(void) {
  
  int a[] = {8, -6, 7, -4, 5, -3, 2, 10, 1, 9};

  printf("Lista desordenada: ");
  imprimir_arreglo(a);

  insercionSort(a);

  printf("Lista ordenada: ");
  imprimir_arreglo(a);
}

void insercion(int a[], int indiceDer, int valor) {
  int i = indiceDer;
  for (; i >= 0 && a[i] > valor; i--)
    a[i + 1] = a[i];
  a[i + 1] = valor; 
}

void insercionSort(int a[]) {
  for (int i = 1; i < N; i++)
    insercion(a, i - 1, a[i]);
}

void imprimir_arreglo(int a[]) {
  for (int i = 0; i < N; i++) {
    printf("%i ", a[i]);
  }
  printf("\n");
}