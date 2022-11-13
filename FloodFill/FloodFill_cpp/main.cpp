#include "floodfill.h"
#include <iostream>
#include <vector>
using namespace std;

const int ROW = 8;
const int COL = 8;
void imprime_2d_array(int arr [][COL]);

int main() {

  int arr[ROW][COL] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 0, 0},
                   {1, 0, 0, 1, 1, 0, 1, 1}, {1, 2, 2, 2, 2, 0, 1, 0},
                   {1, 1, 1, 2, 2, 0, 1, 0}, {1, 1, 1, 2, 2, 2, 2, 0},
                   {1, 1, 1, 1, 1, 2, 1, 1}, {1, 1, 1, 1, 1, 2, 2, 1}};

  // pixel inicial
  int X = 4, Y = 4;

  // color a cambiar
  int C = 3;

  imprime_2d_array(arr);
  cout << endl;
  floodfill(7, 7, arr, X, Y, C);

  imprime_2d_array(arr);
}

void imprime_2d_array(int arr [][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}
