N = 62


# Crear un nuevo nodo
class nuevoNodo:

  def __init__(self, letra):
    self.letra = letra
    self.n = [None] * N
    self.flag = False


def index(letra):
  indice = 0
  if ord(letra) >= 65 and ord(letra) <= 90:
    indice = ord(letra) - 55
  elif ord(letra) >= 97 and ord(letra) <= 122:
    indice = ord(letra) - 61
  elif ord(letra) >= 48 and ord(letra) <= 57:
    indice = ord(letra) - 48
  return indice


# Insertar palabra al trie
def insertar_palabra(palabra, i, n, raiz):
  indice = index(palabra[i])
  if i < n:
    if i == n - 1:
      if raiz.n[indice] == None:
        raiz.n[indice] = nuevoNodo(palabra[i])
        raiz.n[indice].flag = True
        return
    else:
      if raiz.n[indice] is None:
        raiz.n[indice] = nuevoNodo(palabra[i])
        insertar_palabra(palabra, i + 1, n, raiz.n[indice])
      else:
        insertar_palabra(palabra, i + 1, n, raiz.n[indice])
  return


# Buscar palabra en trie
def buscar_palabra(palabra, i, n, raiz):
  indice = index(palabra[i])
  if i < n:
    if i == n - 1:
      if raiz.n[indice].flag == True and raiz.n[indice] is not None:
        print(": Si existe en el trie")
        return
    if raiz.flag == True:
      print(": No existe en el trie")
      return
    if raiz.n[indice] == None:
      print(": No existe en el trie")
    if raiz.n[indice] is not None:
      buscar_palabra(palabra, i + 1, n, raiz.n[indice])


# Función auxiliar para dfs
def es_hoja(raiz):
  return raiz.flag is not False


# Recorrido depth first search
def dfs(raiz, str, nivel):
  if es_hoja(raiz):
    print(str)

  for i in range(N):
    if raiz.n[i]:
      str[nivel] = raiz.n[i].letra
      dfs(raiz.n[i], str, nivel + 1)


# Driver code
def main():
  ##############################
  print("INGRESAR PALABRAS\n")
  while True:  # Try -- Except
    try:
      n = int(input("Ingresa un numero n: "))
    except ValueError:
      print("Respuesta inválida. Vuelve a intentarlo.")
      continue
    else:
      break

  raiz = nuevoNodo(None)

  print("Ingresa ", n, " palabras: (Unicamente valores alfanuméricos)")
  for i in range(n):
    palabra = input("Palabra {}: ".format(i + 1))
    if palabra.isalnum():
      # Inserta palabras en trie
      insertar_palabra(palabra, 0, len(palabra), raiz)
      # palabras.append(palabra)
    else:
      print("Input inválido. Vuelve a intentarlo.")
      return 1

  ##############################
  print("\nBUSCAR PALABRAS\n")
  while True:
    try:
      n = int(input("Ingresa un numero n (palabras a buscar): "))
    except ValueError:
      print("Respuesta inválida. Vuelve a intentarlo.")
      continue
    else:
      break

  print("Ingresa ", n,
        " palabras a buscar: (Unicamente valores alfanuméricos)")
  for i in range(n):
    palabra = input("Palabra {}: ".format(i + 1))
    buscar_palabra(palabra, 0, len(palabra), raiz)
  ##############################

  print("\nRECORRIDO DEPTH FIRST SEARCH\n")
  str = [None] * 20
  dfs(raiz, str, 0)


# main
if __name__ == '__main__':
  main()
