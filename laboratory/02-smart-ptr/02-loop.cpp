#include <iostream>
#include <memory>
#include <fstream>
#include <stdexcept>
using namespace std;

using spFile = std::shared_ptr<ofstream>;
int main() {
  auto FileFinalizer = [](std::ofstream* filePtr) {
    std::cout << "Ejecutando stored lambda function como custom deleter" << std::endl;
    if (filePtr->is_open()) {
      std::cout << "Cerrando archivo..." << std::endl;
      filePtr->close();
    }
    std::cout << "Eliminando ofstream..." << std::endl;
    delete filePtr;
  };
  std::string filename = "archivo.txt";
  spFile file(new ofstream(filename), FileFinalizer);
  try{
    for(int i=1; i<5; i++){
      *file << "Linea" << i <<std::endl;
      if (i == 3) {
        throw std::runtime_error("Error en la linea 3");
      }
    }
  }
  catch(const std::exception& e){
    std::cout << "Excepcion capturada: " << e.what() << std::endl;
    file->close();//necesario
    file->open("archivo.txt", std::ios::app);
    *file << "finish" << endl;
  }
  return 0;
}
