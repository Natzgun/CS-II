//
// Created by natzgun on 24/04/23.
//

#ifndef DYNAMICARRAY_DYNAMICINTEGERARRAY_H
#define DYNAMICARRAY_DYNAMICINTEGERARRAY_H

#include <iostream>
#include <iterator>
using namespace std;

class DynamicIntegerArray {
private:
  int *data;
  int size;

public:
  DynamicIntegerArray() {
    this->size = 0;
    data = new int[0];
  }
  DynamicIntegerArray(int *arr, int size) {
    this->size = size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = arr[i];
    }
  }
  DynamicIntegerArray(const DynamicIntegerArray &o) {

    this->size = o.size;
    data = new int[o.size];
    for (int i = 0; i < o.size; i++) {
      data[i] = o.data[i];
    }
  }
  ~DynamicIntegerArray() { delete[] data; }

  int getData(int pos) const { return data[pos]; }
  void setData(int value, int pos) { data[pos] = value; }

  void saveArray(int aux[]) {
    // guardar data antes de que se elimine
    // int *aux = new int[size];
    for (int i = 0; i < size; i++) {
      aux[i] = data[i];
    }
    delete[] data;
    // return aux;
  }

  void copyArray(int aux[]) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = aux[i];
    }
  }

  void pushback(int value) {
    // int *aux = new int[size];
    int aux[size];
    saveArray(aux);
    size++;
    copyArray(aux);
    data[size - 1] = value;
    // delete[] aux;
  }

  void insert(int value, int pos) {
    int aux[size];
    saveArray(aux);
    size++;
    copyArray(aux);
    // recien comewnzamos con el insert
    int auxiliar2;
    for (int i = size - 1; i > pos; i--) {
      auxiliar2 = data[i];
      data[i] = data[i - 1];
      data[i - 1] = auxiliar2;
    }
    data[pos] = value;
  }

  void remove(int pos) {
    int aux[size];
    saveArray(aux);
    int auxRemove;
    for (int i = pos; i < size-1; i++) {
      auxRemove = aux[i];
      aux[i] = aux[i + 1];
      aux[i + 1] = auxRemove;
    }
    size--;
    copyArray(aux);
  }

  int getSize() {
    return size;
  }
  void print() {
    for (int i = 0; i < size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

#endif // DYNAMICARRAY_DYNAMICINTEGERARRAY_H
