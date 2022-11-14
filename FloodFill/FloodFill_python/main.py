#!/usr/bin/python

# Import module queue, floodfill
import Floodfill

# floodfill.func()
def imprime_arreglo(arr):
  for r in range(len(arr)):
    for c in range(len(arr[r])):
      print(arr[r][c], end=" ")
    print()


def main():
  arr = [[1, 1, 1, 1, 1, 1, 1, 1], [1, 1, 1, 1, 1, 1, 0, 0],
         [1, 0, 0, 1, 1, 0, 1, 1], [1, 2, 2, 2, 2, 0, 1, 0],
         [1, 1, 1, 2, 2, 0, 1, 0], [1, 1, 1, 2, 2, 2, 2, 0],
         [1, 1, 1, 1, 1, 2, 1, 1], [1, 1, 1, 1, 1, 2, 2, 1]]

  x = 4
  y = 4
  c = 3
  row = len(arr) - 1
  col = len(arr[0]) - 1

  imprime_arreglo(arr)
  Floodfill.floodfill(row, col, arr, x, y, c)
  print()
  imprime_arreglo(arr)
  
if __name__ == "__main__":
  main()
