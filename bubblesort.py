arreglo = [8, -6, 7, -4, 5, -3, 2, 10, 1, 9]

def bubbleSort(arreglo):
  for i in range(0, len(arreglo)):
    for j in range(0, len(arreglo) - 1):
      if (arreglo[j] > arreglo[j + 1]):
        tmp = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = tmp;
  
def imprime_arreglo(arreglo):
  for i in arreglo:
    print(i, end=' ')

imprime_arreglo(arreglo)
bubbleSort(arreglo)
print()
imprime_arreglo(arreglo)