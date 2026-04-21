#include "TestBed_2.hpp"

//Hyper-Ellipsoid
//IPR: xj 2 [1; 1]
//The global minimum is f11(0) = 0 
//VTR was set to 1.e10
double tb2::hyper_ellipsoid(const std::vector<double>& x)
{
    double result = 0.0;

    for (size_t i = 0; i < x.size(); i++)
    {
        double j = i + 1.0;
        result += (j * j) * (x[i] * x[i]);
    }
    return result;
}

//Katsuura's Function
//IPR: xj 2 [-1000, 1000]
//Global minimum f_12(0) = 1
//VTR set to 1.05
// Katsuura's Function
// IPR: x_j in [-1000, 1000]
// Global minimum f_12(0) = 1
// VTR = 1.05
double tb2::katsuura(const std::vector<double>& x)
{
    const int beta = 32;
    double result = 1.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        double inner = 0.0;

        for (int k = 0; k <= beta; ++k)
        {
            double two_k = std::pow(2.0, k);
            double v = two_k * x[i];
            inner += std::abs(v - std::round(v)) / std::pow(2.0, k + 1);
        }

        result *= (1.0 + (i + 1.0) * inner);
    }

    return result;
}

//Griewangk's Function
//IPR: xj [-600, 600]
//Global minimum f_14(0) = 0
//VTR set to 1.e^{-3}
double tb2::griewank_f14(const std::vector<double>& x)
{
    double result     = 0.0;
    double p = 1.0;

    for (size_t i = 0; i < x.size(); i++)
    {
        result     += (x[i] * x[i]) / 4000.0;
        p *= std::cos(x[i] / std::sqrt(i + 1.0));
    }

    return result - p + 1.0;
}

//Ackley's Function
//IPR: xj [-30, 30]
//Global minimum f_15(0) = 0
//VTR set to 1.e^{-3}
double tb2::ackley(const std::vector<double>& x)
{
    const double pi = 3.14159265358979323846;
    double D = static_cast<double>(x.size());
    double result_sq = 0.0;
    double result_cos = 0.0;

    for (size_t i = 0; i < x.size(); i++)
    {
        result_sq  += x[i] * x[i];
        result_cos += std::cos(2.0 * pi * x[i]);
    }

    double part1 = -20.0 * std::exp(-0.02 * std::sqrt(result_sq / D));
    double part2 = -std::exp(result_cos / D);

    return part1 + part2 + 20.0 + std::exp(1.0);
}

// Rastrigin's Function
// IPR: x_j in [-600, 600]
// Global minimum is f_13(0) = 0
// VTR = 0.9
double tb2::rastrigin(const std::vector<double>& x)
{
    const double pi = 3.14159265358979323846;
    const double D = static_cast<double>(x.size());

    double result = 10.0 * D;

    for (size_t i = 0; i < x.size(); ++i)
    {
        result += (x[i] * x[i]) - 10.0 * std::cos(2.0 * pi * x[i]);
    }

    return result;
}

