#ifndef TESTBED_3_HPP
#define TESTBED_3_HPP

#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
    
namespace tb3 
{
    //Goldstein’s function
    //f_16(+/-3) = 7
    //IPR xj \in [-10, 10]
    //VTR itself was set to 1.e^{-6}
    double goldstein (const std::vector<double>& x);

    double u(double z, double a, double k, double m);
    //Penalized Shubert Function
    //f_17(x)
    //The global minimum is f17(-7.70831) = f17(-1.42513) = f17(-4.85805) = -12.8708855
    double shubert(double x);

    double penalized_shubert(const std::vector<double>& x);

    //Two-dimensional Penalized Shubert Function
    //f_18(x)
    //There are 18 global minima with value -186.7309088 in the region bounded by the IPR.
    double penalized_shubert_2d(const std::vector<double>& x);

    //Two-dimensional modified and penalized Shubert Function
    //The global minimum is f19(-1.42513; -0.80032) = -186.7309088
    double modified_shubert(const std::vector<double>& x, double beta);

    double modified_shubert_b10(const std::vector<double>& x);
    double modified_shubert_b05(const std::vector<double>& x);

    //Six-hump Camel Function
    //The global minimum is f20(-0.0898, 0.7126) = f20(0.0898, -0.7126) = -1.0316285
    double six_hump_camel(const std::vector<double>& x);

    //f_21(x)
    double g2(const std::vector<double>& x);

    double f21(const std::vector<double>& x);

    double g3(const std::vector<double>& x);

    //The global minimum is f22(1 ) = 0
    double f22(const std::vector<double>& x);

    double g4(const std::vector<double>& x);

    //The global minimum is f23(1 ) = 0
    double f23(const std::vector<double>& x);

    //Global min f24(1) = 0
    double f24(const std::vector<double>& x);

    //The global minimum is f25(-1.0466805696) = -0.3523861
    double f25(const std::vector<double>& x);

    //The global minimum is f26(-1.0466805696; 0) = -0.3523861.
    double f26(const std::vector<double>& x);

    //The global minimum is f27(0 ) = 0
    double f27(const std::vector<double>& x);

    //See documentation for global mins
    double f28(const std::vector<double>& x, int n);

    double f28_n1(const std::vector<double>& x);
    double f28_n2(const std::vector<double>& x);
    double f28_n3(const std::vector<double>& x);
    double f28_n4(const std::vector<double>& x);
    double f28_n5(const std::vector<double>& x);
    double f28_n6(const std::vector<double>& x);

    // The global minimum is f29(0 ) = 0
    double f29(const std::vector<double>& x);

    //The global minimum is f30(1523.2; 277.5) = -0.000888085
    double f30(const std::vector<double>& x);
}

#endif