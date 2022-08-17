#include <iostream>
using namespace std;

int main() {
  srand(time(NULL));

  int nums[10];
  for (int i = 0; i < 10; i++){
    nums[i] = rand() % 10;
  }

  cout << "Lista original: ";
  for (int i = 0; i < 10; i++){
    cout << nums[i] << " ";
  }
  cout << endl;

  
  for (int i = 0; i < 10; i++){
    bool check = false;
    int index;
    int tmp = nums[i];
    for (int j = i + 1; j < 10; j++){
      if (nums[j] < tmp){
        tmp = nums[j];
        check = true;
        index = j;
      }
    }
    if (check){
      nums[index] = nums[i];
      nums[i] = tmp;
    }
  }
  
  cout << "Lista ordenada: ";
  for (int i = 0; i < 10; i++){
    cout << nums[i] << " ";
  }
}