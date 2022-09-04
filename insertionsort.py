arreglo = [8, -6, 7, -4, 5, -3, 2, 10, 1, 9]

def insercion(arreglo, indDer, valor):
  i = indDer
  while (i >= 0 and arreglo[i] > valor):
    arreglo[i + 1] = arreglo[i]
    i = i - 1
  arreglo[i + 1] = valor

def insercionSort(arreglo):
  for i in range(1, len(arreglo)):
    insercion(arreglo, i - 1, arreglo[i])
  
def imprime_arreglo(arreglo):
  for i in arreglo:
    print(i, end=' ')

imprime_arreglo(arreglo)
insercionSort(arreglo)
print()
imprime_arreglo(arreglo)