#include "DynamicArray.h"
#include "Persona.h"
#include <iostream>
#include <string>

int main() {

  Persona *arrayPersonas = new Persona[0];
  DynamicArray<Persona> list(arrayPersonas, 0);
  Persona persona1("Nagata", 17);
  Persona persona2("Mitsuru", 30);
  Persona persona3("LadelA", 22);
  list.pushback(persona1);
  list.pushback(persona2);
  list.insert(persona3, 0);
  list.remove(1);
  list.print();

  float *arrayFlotante = new float[0];
  DynamicArray<float> list2(arrayFlotante, 0);
  list2.pushback(12.5);
  list2.pushback(18.9);
  list2.print();

  int *arrayEntero = new int[0];
  DynamicArray<int> list3(arrayEntero, 0);
  list3.pushback(18);
  list3.pushback(20);
  list3.print();

  string *arrayString = new string[0];
  DynamicArray<string> list4(arrayString, 0);
  list4.pushback("|Un string|");
  list4.pushback("|Aqui otro|");
  list4.print();

  return 0;
}
