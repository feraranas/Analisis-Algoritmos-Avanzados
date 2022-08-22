#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void selectionsort(vector<int> &v);
void imprimevector(vector<int> v);


int main() {
  vector<int> v = {0,1,2,3,4,5,6,7,8,9};
  cout << "Lista desordenada: ";
  imprimevector(v);
  selectionsort(v);
  cout << endl;
  cout << "Lista ordenada: ";
  imprimevector(v);
  cout << endl;
}

  
void selectionsort(vector<int> &v) {

  for (int i = 0, n = v.size(); i < n; ++i) {
    bool bandera = false;
    int piv = v[i], index;
    for (int j = i + 1; j < n; ++j) {
      if (v[i] < v[j]) {
        bandera = true;
        index = j;
        piv = v[j];
      }
    }
    if (bandera) swap(v[i], v[index]);
  }
}

void imprimevector(vector<int> v) {
  for (auto i = v.begin(), j = v.end(); i < j; ++i) {
    cout << *i << " ";
  }
}