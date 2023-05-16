#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
// #include "Persona.h"
#include <iostream>
using namespace std;

template <typename T> class DynamicArray {
private:
  T *data;
  int size;

public:
  DynamicArray() {
    data = new T[0];
    this->size = 0;
  }

  DynamicArray(T *arr, int size) {
    data = new T[size];
    this->size = size;
    for (int i = 0; i < size; i++) {
      data[i] = arr[i];
    }
  }

  DynamicArray(const DynamicArray &o) {
    this->size = o.size;
    data = new T[o.size];
    for (int i = 0; i < o.size; i++) {
      data[i] = o.data[i];
    }
  }

  ~DynamicArray() { delete[] data; }

  void pushback(T value) {
    size++;
    T *aux = new T[size];
    for (int i = 0; i < size - 1; i++) {
      aux[i] = data[i];
    }
    delete[] data;
    data = aux;
    data[size - 1] = value;
  }

  void insert(T value, int pos) {
    size++;
    T *aux = new T[size];
    for (int i = 0; i < size - 1; i++) {
      aux[i] = data[i];
    }
    delete[] data;
    data = aux;
    T auxPos;
    for (int i = size - 1; i > pos; i--) {
      auxPos = data[i];
      data[i] = data[i - 1];
      data[i - 1] = auxPos;
    }
    data[pos] = value;
  }

  void remove (int pos) {
    T auxRemove;
    for (int i = pos; i < size-1; i++) {
      auxRemove = data[i];
      data[i] = data[i + 1];
      data[i + 1] = auxRemove;
    }

    size--;
    T *aux = new T[size];
    for (int i = 0; i < size; i++) {
      aux[i] = data[i];
    }
    delete [] data;
    data = aux;
  }

  void print() {
    /* for (int i = 0; i < size; i++) {
      cout << data[i].getName() << endl;
      cout << data[i].getEdad() << endl;
    } */

    for (int i = 0; i < size; i++) {
      cout << data[i] << " ";
    }
    cout << endl;
  }
};

#endif // DYNAMICARRAY_H
