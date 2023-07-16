#include <iostream>
#include <memory>
#include <list>
#include <algorithm>

/* template<typename T>
struct Storage {
  typedef std::list<T, std::allocator<T>> type;
};

template<typename T>
class Client {
private:
  typename Storage<T>::type data;
public:
  Client(int n, const T& val) : data(n,val) {}
  
  void print() const {
    std::for_each(data.begin(), data.end(), [](const T& n) {
      std::cout << n << ", ";
    });
    std::cout << "\n";
  }
};

int main () {
  int n = 10;
  int val = 2;
  Client<int> myClient(n,val);
  myClient.print();
  return 0;
} */

template<typename T>
using Storage = std::list<T, std::allocator<T>>;

template<typename T>
class Client {
private:
  Storage<T> data;
public:
  Client(int n, const T& val) : data(n, val) {}
  
  void print() const {
    std::for_each(data.begin(), data.end(), [](const T& n) {
      std::cout << n << ", ";
    });
    std::cout << "\n";
  }
};

int main () {
  int n = 3;
  int val = 7;
  Client<int> myClient(n, val);
  myClient.print();
  return 0;
}
