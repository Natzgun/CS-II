#include "DynamicIntegerArray.h"
#include <iostream>
using namespace std;

int main() {
  int *first_list = new int[0];
  DynamicIntegerArray list_A(first_list, 0);
  list_A.pushback(100);
  list_A.pushback(12);
  list_A.pushback(77);
  list_A.pushback(24);
  list_A.pushback(20);
  // list_A.pushback(17);
  // list_A.pushback(200);
  list_A.insert(50, 0);
  list_A.insert(777, 4);
  list_A.remove(1);
  list_A.print();
  cout << "Tamanio actual -> " << list_A.getSize() << endl;
  delete[] first_list;
  return 0;
}
