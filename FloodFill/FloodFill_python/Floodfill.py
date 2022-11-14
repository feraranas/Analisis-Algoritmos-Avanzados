#!/usr/bin/python

# Import module queue, floodfill
import Queue


def pixel_valido(x, y, row, col):
  check = False
  if ((x >= 0 and y >= 0) and (x <= row and y <= col)):
    check = True
  return check


def floodfill(row, col, arr, x, y, c):

  queue = Queue.Queue()
  p = (x, y)
  color_original = arr[x][y]
  queue.push(p)

  while (queue.empty() != True):
    p = queue.pop()
    for i in range(-1, 2):
      for j in range(-1, 2):
        if (pixel_valido(p[0] + i, p[1] + j, row, col) == True):
          if (arr[p[0] + i][p[1] + j] == color_original):
            np = (p[0] + i, p[1] + j)
            queue.push(np)
    arr[p[0]][p[1]] = c
