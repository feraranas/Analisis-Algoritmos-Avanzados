arr = [1,4,1,2,7,5,2]
tamano_arreglo = len(arr)
arr_salida = []
cumulo = []

maximo_elemento_arr = 0

for i in arr:
  if (maximo_elemento_arr < i):
    maximo_elemento_arr = i

for i in range(0, maximo_elemento_arr + 1):
  cumulo.append(0)

for i in arr:
  cumulo[i] += 1

for i in range(1, maximo_elemento_arr + 1):
  cumulo[i] += cumulo[i - 1]

for i in range(0, tamano_arreglo):
  arr_salida.append(0)

for i in arr:
  indice_salida = cumulo[i] - 1
  arr_salida[indice_salida] = i
  cumulo[i] -= 1

for i in arr_salida:
  print(i, end=" ")