#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <future>


using namespace std;

int generateNumbers(int minRange, int maxRange) {
  return rand() % (maxRange - minRange + 1) + minRange;
}

void print(vector<int> randomIntegers) {
  for (int i = 0; i < 1000; ++i) {
    cout << randomIntegers[i] << " ";
    if ((i + 1) % 10 == 0) {
       cout << endl;
    }
  }
}

int maxNumber(vector<int>& randomIntegers) {
  int aux = randomIntegers[0];
  for (int i = 1; i < randomIntegers.size(); ++i){
    if (randomIntegers[i] > aux) {
      aux = randomIntegers[i];
    }
  }

  return aux;
}

int minNumber(vector<int>& randomIntegers) {
  int aux = randomIntegers[0];
  for (int i = 1; i < randomIntegers.size(); ++i){
    if (randomIntegers[i] < aux) {
      aux = randomIntegers[i];
    }
  }

  return aux;
}

float promedio(vector<int>& randomIntegers) {
  float aux{0};
  for (int i = 0; i < randomIntegers.size(); ++i){
    aux += randomIntegers[i];
  }

  return aux/1000;
}

int mostNumber(vector<int>& randomIntegers) {
  const int range = 20001;
  vector<int> frequencyCount(range, 0);
  for (int num : randomIntegers) {
    int index = num + 10000;
    frequencyCount[index]++;
  }
  int mostRepeat = 0;
  int maxFrequency = 0;

  for (int i = 0; i < range; ++i) {
    if (frequencyCount[i] > maxFrequency) {
      mostRepeat = i - 10000;
      maxFrequency = frequencyCount[i];
    }
  }
  return mostRepeat;
}

vector<int> multiplyFive(vector<int>& randomIntegers, vector<int>& multiplesOf5) {
  for (int& num : randomIntegers) {
    if (num % 5 == 0) {
      multiplesOf5.push_back(num * 100);
    }
  }

  return multiplesOf5;
}

int main () {
  int min = -10000;
  int max = 10000;
  vector<int> randomIntegers;
  vector<int> m5;
  srand(time(0));

  for (int i = 0; i < 1000; ++i) {
    int randNumber = generateNumbers(min, max);
    randomIntegers.push_back(randNumber);
  }

  /* auto start = chrono::high_resolution_clock::now();

  cout << "Max: " << maxNumber(randomIntegers) << endl;
  cout << "Min: " << minNumber(randomIntegers) << endl;
  cout << "Promedio: " << promedio(randomIntegers) << endl;
  cout << "Most: " << mostNumber(randomIntegers) << endl;
  multiplyFive(randomIntegers, m5);

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();

  std::cout << "Ejecución: " << duration << "ms" << std::endl; */
  

  auto start = std::chrono::high_resolution_clock::now();

  future<int> maxFuture = async(launch::async, maxNumber, ref(randomIntegers));
  future<int> minFuture = async(launch::async, minNumber, ref(randomIntegers));
  future<float> promedioFuture = async(launch::async, promedio, ref(randomIntegers));
  future<int> mostFuture = async(launch::async, mostNumber, ref(randomIntegers));
  future<vector<int>> multiplyFuture = async(launch::async, multiplyFive, ref(randomIntegers), ref(m5));

  int maxValue = maxFuture.get();
  int minValue = minFuture.get();
  float avgValue = promedioFuture.get();
  int mostValue = mostFuture.get();
  multiplyFuture.get();

  cout << "Max: " << maxValue << endl;
  cout << "Min: " << minValue << endl;
  cout << "Promedio: " << avgValue << endl;
  cout << "Most: " << mostValue << endl;

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start).count();

  std::cout << "Ejecución: " << duration << " ms" << endl;
  // print(randomIntegers);

  return 0;
}
