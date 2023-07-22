#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;

int** genMatriz(int size){
  int** matriz = new int*[size];
  for(int i=0; i<size; ++i) {
    matriz[i] = new int[size];
    for(int j=0; j<size; ++j){
      matriz[i][j] = (rand()%2001)-1000;
    }
  }
  return matriz;
}

int** genMatrizCero(int size){
  int** matriz = new int*[size];
  for(int i=0; i<size; ++i) {
    matriz[i] = new int[size];
    for(int j=0; j<size; ++j){
      if(i != j)
        matriz[i][j] = (rand()%2001)-1000;
      else
        matriz[i][j] = 0;
    }
  }
  return matriz;
}

int** transpuesta(int** m, int fil, int col){
  int** t = new int*[col];
  for(int i=0; i<col; ++i){
    t[i] = new int[fil];
    for(int j=0; j<fil; ++j){
      t[i][j] = m[j][i];
    }
  }
  return t;
}

int** matrizX5(int** m, int fil, int col){
  int** t = new int*[fil];
  for(int i=0; i<fil; ++i){
    t[i] = new int[col];
    for(int j=0; j<col; ++j){
      if(m[i][j]%5 != 0)
        t[i][j] = m[i][j];
      else
        t[i][j] = m[i][j] * 1000;
    }
  }
  return t;  
}

void mostrar(int** m, int fil, int col){
  for(int i=0; i<fil; ++i){
    for(int j=0; j<col; ++j){
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl; 
  }
  std::cout << std::endl; 
}

int maximo(int** m, int fil, int col){
  int max = m[0][0];
  for(int i=0; i<fil; ++i){
    for(int j=0; j<col; ++j){
      if(m[i][j] > max)
        max = m[i][j];
    }
  }
  return max;
}

int minimo(int** m, int fil, int col){
  int min = m[0][0];
  for(int i=0; i<fil; ++i){
    for(int j=0; j<col; ++j){
      if(m[i][j] < min)
        min = m[i][j];
    }
  }
  return min;
}

/*int** masRepetido(int** m, int fil, int col){
  int min = m[0][0];
  for(int i=0; i<fil; ++i){
    for(int j=0; j<col; ++j){
      if(m[i][j] < min)
        min = m[i][j];
    }
  }
  return min;
}*/

int main (int argc, char *argv[]) {
  int size = 500;
  srand(time(NULL));
  int** M = genMatriz(size);
  /*auto start = chrono::high_resolution_clock::now();
  int** M = genMatriz(size);
  int** X = matrizX5(M,size,size);
  int** T = transpuesta(M,size,size);
  int** C = genMatrizCero(size);
  int min = minimo(M,size,size);
  int max = maximo(M,size,size);
  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
  std::cout << "Tiempo de ejecución: " << duration << " microsegundos" << std::endl;*/

  auto start = std::chrono::high_resolution_clock::now();
  std::thread t1(genMatriz, size);
  std::thread t2(matrizX5, M, size, size);
  std::thread t3(transpuesta, M, size, size);
  std::thread t4(genMatrizCero, size);
  std::thread t5(minimo, M, size, size);
  std::thread t6(maximo, M, size, size);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  std::cout << "Tiempo de ejecución: " << duration << " microsegundos" << std::endl;
  return 0;
}
