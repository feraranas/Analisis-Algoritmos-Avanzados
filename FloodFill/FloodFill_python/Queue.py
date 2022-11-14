# Data type in Python similar to structs are ¡¡¡Classes!!!
class node:
  # constructor
  def __init__(self, data=None, next=None):
    self.data = data
    self.next = next


class Queue:
  # constructor
  def __init__(self):
    self.inicio = None
    self.fin = None

  # agregar al queue
  def push(self, data):
    nuevo = node(data)
    if (self.inicio):
      tmp = self.fin
      tmp.next = nuevo
      self.fin = tmp.next
    else:
      self.inicio = nuevo
      self.fin = nuevo

  # eliminar del queue
  def pop(self):
    if (self.inicio):
      valor = self.inicio.data
      tmp = self.inicio
      self.inicio = self.inicio.next
      tmp.next = None
      del tmp
      return valor

  # imprimir queue
  def imprimir(self):
    if (self.inicio):
      tmp = self.inicio
      while (tmp):
        print(tmp.data, end=" ")
        tmp = tmp.next
      print()

  # checa si vacio
  def empty(self):
    check = False
    if (self.inicio):
      return check
    else:
      check = True
    return check
