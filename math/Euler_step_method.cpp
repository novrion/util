#include <iostream>



inline double Derivative(const double x, const double y) {
  return 2 * x;
}


int main() {

  double xs, xe, ys, ye;
  double step;

  std::cout << "x start: "; 
  std::cin >> xs;
  std::cout << "x end: ";
  std::cin >> xe;
  std::cout << "y start: ";
  std::cin >> ys;
  std::cout << "step: ";
  std::cin >> step;


  for (xs; xs < xe; xs += step) {
    ye += Derivative(cur_x, 0) * step;
  }


  std::cout << ye;
  std::cin >> step;





  return 0;
}