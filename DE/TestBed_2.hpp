#ifndef TESTBED_2_HPP
#define TESTBED_2_HPP


#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
    
namespace tb2 
{
    //Hyper-Ellipsoid
    //IPR: xj 2 [1; 1]
    //The global minimum is f11(0) = 0 
    //VTR was set to 1.e10
    double hyper_ellipsoid(const std::vector<double>& x);

    //Katsuura's Function
    //IPR: xj 2 [-1000, 1000]
    //Global minimum f_12(0) = 1
    //VTR set to 1.05
    double katsuura(const std::vector<double>& x);

    //Griewangk's Function
    //IPR: xj [-600, 600]
    //Global minimum f_14(0) = 0
    //VTR set to 1.e^{-3}
    double griewank_f14(const std::vector<double>& x);

    //Ackley's Function
    //IPR: xj [-30, 30]
    //Global minimum f_15(0) = 0
    //VTR set to 1.e^{-3}
    double ackley(const std::vector<double>& x);

}

#endif