#include <iostream>
#include <cmath>



inline double Derivative(const double x, const double y) {
    return 2 * sqrt(y);
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

    ye = ys;
    for (xs; xs <= xe; xs += step) {
        ye += Derivative(xs, ye) * step;
    }


    std::cout << ye;
    std::cin >> step;





    return 0;
}
