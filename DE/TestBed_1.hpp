#ifndef TESTBED_1_HPP
#define TESTBED_1_HPP

#include <vector>
#include <random>
#include <cmath>
#include <algorithm>

namespace tb1{

    //First De Jong function (sphere)
    //IPR: x_j [-5.12, 5.12]
    //Global min is f_1(0) = 0
    //VTR set to 1.e^{-6}
    double dejong_f1 (const std::vector<double>& x);

    //De Jong function F2 (Rosenbrock's saddle)
    //IPR: x_j [-2.048, 2.048]
    //Global min is f_2(1) = 0
    //VTR set to 1.e^{-6}
    double dejong_f2 (const std::vector<double>& x);

    //De Jong function F3 (step)
    //IPR: x_j [-2.048, 2.048]
    //Global min is f_3(-5 - epsilon) = 0 where epsilon = [0, 0.12]
    //VTR set to 1.e^{-6}
    double dejong_f3 (const std::vector<double>& x);

    //De Jong function F4 (quartic)
    //IPR: x_j [-1.28, 1.28]
    //Global min is f_4(0) <= 30E[η] = 15 = VTR, wher E[η] is the Expectation of η.
    //VTR set to 1.e^{-6}
    double dejong_f4(const std::vector<double>& x);

    //De Jong function F5 (Shekel’s Foxholes)
    //IPR: x_j \in [-65:536; 65:536]
    //Global min is f_4(0) <= 30E[η] = 15 = VTR, wher E[η] is the Expectation of η.
    //VTR set to 1.e^{-6}
    double dejong_f5(const std::vector<double>& x);

    //Corana's Parabola
    //IPR xj \in [-1000, 1000]
    //Global minimum f_6(-32, -32) 
    double corana_f6 (const std::vector<double>& x);

    //Griewangk’s function: Griewangk
    //IPR: xj \in [-400, 400]
    //f_7(0) = 0
    //VTR defined to be 1.e^{-6}
    double griewangk(const std::vector<double>& x);

    //Zimmermann’s problem: Zimmermann
    //IPR: xj \in [-400, 400]
    //f_7(0) = 0
    //VTR defined to be 1.e^{-6}
    double zimmermann_f8(const std::vector<double>& x);

    double chebyshev(int n, double z);

    double h4(const std::vector<double>& x, double z);

    double sgn(double v);

    // f9: polynomial fitting cost function
    // k: degree parameter (4 for T8, 8 for T16)
    // N: number of sample points (60 for T8, 100 for T16)
    double polynomial_f9(const std::vector<double>& x, int k, int N);

    double polynomial_f9_T8(const std::vector<double>& x);

    double polynomial_f9_T16(const std::vector<double>& x);

}

#endif