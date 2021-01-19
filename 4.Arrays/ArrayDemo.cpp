/*
 * ArrayDemo
 *
 * Created by Rob Nash
 *
 * Modified by Yang Peng on 01/09/18
 */

#include <iostream>
using namespace std;

// Forward declarations.
void display(int *ptr, int size);
void bubble(int* ptr, int size);
void swap(int* idx1, int* idx2);
int linearSearch(int* ptr, int size, int target);

int main(int argc, const char * argv[])
{
  const int SIZE = 7;
  // These are auto variables.
  int *set = new int[SIZE] {1,4,3,2,5,9,8}; // Size implicit
  int *set2 = new int[SIZE] {30, 23, 25, 19, 100, 12, 7};
  // How does it look like in JAVA?
  // int[] myArray = new int[3];
  // int[] myArray = {1, 2, 3};
  // int[] myArray = new int[] {1, 2, 3};
  cout << linearSearch(set, SIZE, 9) << endl;
  // You have to pass the size in; a C++ array is just a dumb block of
  // storage; no size information is carried with it and no bounds
  // checking is done.
  display(set, SIZE);
  bubble(set, SIZE);
  display(set, SIZE);
    
  delete[] set;
  delete[] set2;
  set = nullptr;
  set2 = nullptr;
  
  return 0;
}

void display(int* ptr, int size) {
  for(int i = 0; i < size; i++) {
    cout << ptr[i] << ",";
  }
  cout << std::endl;
}

void bubble(int* ptr, int size) {
  for(int i = 0; i < size; i++) {
    for(int k = 0; k < size - 1 - i; k++) {
      if(ptr[k] < ptr[k+1]) {
		  swap(*(ptr+k), *(ptr+k+1));
      }
    }
  }
// Am I supposed to delete ptr?
}

void swap(int *idx1, int *idx2) {
  int temp = *idx1;
  *idx1 = *idx2;
  *idx2 = temp;
}

int linearSearch(int* ptr, int size, int target) {
  for(int i = 0; i < size; i++) {
    if(ptr[i] == target) {
      return i;
    }
  }
  return -1;
}
 
