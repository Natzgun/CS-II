#include <iostream>
#include <ostream>
#include <memory>
// using std::cout;
// using std::cin;
using namespace std;

/* class Point {
private:
  double x,y;
  
public:
  Point(); 
  Point(int _x, int _y) {
    this->x = _x;
    this->y = _y;
  }; 
  Point(const Point& point);
  void X(double _x){
    this->x = _x;
  }
  void Y(double _y){
    this->y = _y;
  }
  friend ostream& operator<<(ostream& os, Point& point) {
    os << point.x << " - " << point.y << endl;
    return os;
  }
}; */

template <typename T>
class Point {
private:
  T x, y;
public:
  Point();
  Point(T _x, T _y) {
    this->x = _x;
    this->y = _y;
  }
  Point(const Point& point);
  void X(T _x) {
    this->x = _x;
  }
  void Y(T _y) {
    this->y = _y;
  }
  friend std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.x << " - " << point.y << std::endl;
    return os;
  }
};


int main () {
/* try {
  double* d = new double(1.0);
  Point* pt = new Point(1.0, 2.0);

  *d = 2.0;
  (*pt).X(3.0);
  (*pt).Y(3.0);

  pt->X(4.0);
  pt->Y(4.0);
  cout << *pt << endl;

  throw std::runtime_error("Ha ocurrrido un erro");

  delete d;
  delete pt;
} catch (const std::exception& e) {
  cout << "Excepción capturada: " << e.what() << endl;
} */
/* try {
  auto d = std::make_unique<double>(1.0);
  auto pt = std::make_unique<Point<double>>(1.0,2.0);

  *d = 2.0;
  (*pt).X(3.0);
  (*pt).Y(3.0);

  pt->X(4.0);
  pt->Y(4.0);
  cout << *pt << endl;

  throw std::runtime_error("Ha ocurrrido un erro");
} catch (const std::exception& e) {
  cout << "Excepción capturada: " << e.what() << endl;
}

  auto ptn1 = std::make_unique<double>(1.123);
  auto ptn2 = std::make_unique<double>();
  ptn2 = std::move(ptn1);

  cout << *ptn2 << endl;

*/
  return 0;
}
