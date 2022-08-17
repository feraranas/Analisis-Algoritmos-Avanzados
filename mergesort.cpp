/*
ELABORADO POR FERNANDO ALFONSO ARANA SALAS
*/

#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high);
void mergesort(int a[], int low, int high);

int main()
{

  // Le pide al usuario el número N de números a ordenar
  int N;
  do
  {
    cout << "Cuántos números vas a ordenar?: ";
    cin >> N;
  } while (N < 1);

  // Le pide al usuario los números a ordenar
  int a[N];
  int i = 0, j = 0, k = 0;
  cout << "\nIngresa los N números a ordenar, separados por 'Enter'.\n";
  while (i < N)
    cin >> a[i++];

  // Imprime la lista de números desordenados
  cout << "\nLista desordenada: ";
  while (j < N)
    cout << a[j++] << " ";
  cout << endl;

  // Ordena con algoritmo MergeSort
  mergesort(a, 0, N - 1);

  // Imprime la lista de números ordenados por MergeSort
  cout << "Lista ordenada: ";
  while (k < N)
    cout << a[k++] << " ";
  cout << endl;
}

// Algoritmo 'Venceras'
void merge(int a[], int low, int mid, int high)
{
  int N = high - low + 1;
  int b[N];
  int izq = low, der = mid + 1, Idx = 0;
  while (izq <= mid && der <= high)
  {
    b[Idx++] = (a[izq] >= a[der]) ? a[izq++] : a[der++];
  }
  while (der <= high)
    b[Idx++] = a[der++];
  while (izq <= mid)
    b[Idx++] = a[izq++];
  for (int i = 0; i < N; i++)
    a[low + i] = b[i];
}

// Algoritmo 'Conquista'
void mergesort(int a[], int low, int high)
{
  if (low < high)
  {
    int mid = (high + low) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
  }
}