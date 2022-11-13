/*
Flood fill algorithm

BFS Approach: The idea is to use BFS traversal to replace the color with the new
color.

Create an empty queue lets say Q.
Push the starting location of the pixel as given in the input and apply
replacement color to it.
Iterate until Q is not empty and pop the front node (pixel position).
Check the pixels adjacent to the current pixel and push into
the queue if valid (had not been colored with replacement color and have the
same color as the old color).

*/

#include "queue.h"
using namespace std;

bool pixel_valido(int X, int Y, int ROW, int COL);

void floodfill(int ROW, int COL, int arr[][8], int X, int Y, int C) {

  Queue<pair<int, int>> queue = Queue<pair<int, int>>();

  pair<int, int> p;
  p.first = X;
  p.second = Y;
  int color_original = arr[X][Y];

  queue.push(p);

  while (!queue.empty()) {
    p = queue.pop();

    for (int i = -1; i < 2; i++)
      for (int j = -1; j < 2; j++)
        if (pixel_valido(p.first + i, p.second + j, ROW, COL))
          if (arr[p.first + i][p.second + j] == color_original) {
            pair<int, int> np;
            np.first = p.first + i;
            np.second = p.second + j;
            queue.push(np);
          }

    arr[p.first][p.second] = C;
  }
}

bool pixel_valido(int X, int Y, int ROW, int COL) {
  bool check = false;
  if ((X >= 0 && Y >= 0) && (X <= ROW && Y <= COL))
    check = true;
  return check;
}
