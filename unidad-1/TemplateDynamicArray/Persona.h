#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona {
private:
  string nombre;
  int edad;

public:
  Persona() {
    this->nombre = "";
    this->edad = 0;
  }
  Persona(string n, int e) {
    this->nombre = n;
    this->edad = e;
  }

  ~Persona() {}

  string getName() { return nombre; }
  int getEdad() { return edad; }
  void setEdad(int e) { edad = e; }
  void setNombre(string n) { nombre = n; }
  friend ostream &operator<<(ostream &os, const Persona &persona) {
    os << "|Name: " << persona.nombre << ", Age: " << persona.edad << " |";
    return os;
  }
};

#endif // PERSONA_H
