# Pseudocode
# Inicia en un pivote, el primero de la lista
# Itera aumentando en una posición el pivote
#   Para cada iteración, encuentra el menor/mayor número
#    Intercambia el menor/mayor con el pivote
#    Regresa

# Declaramos la lista
lista = [0,1,2,3,4,5,6,7,8,9]

# Declaramos la función selectionsort
def selectionsort(lista):
  for i in range(0, len(lista)):
    bandera = False
    piv = lista[i]
    index = 0
    for j in range(i + 1, len(lista)):
      if (piv < lista[j]):
        piv = lista[j]
        bandera = True
        index = j
    
    if (bandera):
      tmp = lista[i]
      lista[i] = lista[index]
      lista[index] = tmp
        

# Función para imprimir valores en una lista
def imprimirLista(lista):
  for i in lista:
    print(i, " ", end="")
    
print("Lista desordenada: ", end="")
imprimirLista(lista)
print()

# Llamamos a la función selectionsort
selectionsort(lista)

print("Lista ordenada: ", end="") 
imprimirLista(lista)


