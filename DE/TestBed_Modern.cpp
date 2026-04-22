#include "TestBed_Modern.hpp"

double tbm::michalewicz(const std::vector<double>& x, int m)
{
    const double pi = 3.14159265358979323846;

    double result = 0.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        double term1 = std::sin(x[i]);
        double term2 = std::sin(((i + 1) * x[i] * x[i]) / pi);
        result -= term1 * std::pow(term2, 2 * m);
    }

    return result;
}

double tbm::michalewicz_m5(const std::vector<double>& x)
{
    return tbm::michalewicz(x, 5);
}

double tbm::michalewicz_m20(const std::vector<double>& x)
{
    return tbm::michalewicz(x, 20);
}