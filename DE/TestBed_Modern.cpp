#include "TestBed_Modern.hpp"

double tbm::rastrigin(const std::vector<double>& x)
{
    const double A = 10.0;
    const double pi = 3.14159265358979323846;

    double result = A * static_cast<double>(x.size());

    for (size_t i = 0; i < x.size(); ++i)
    {
        result += (x[i] * x[i]) - A * std::cos(2.0 * pi * x[i]);
    }

    return result;
}

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

// Wrapper with the standard choice m = 10
double tbm::michalewicz_m10(const std::vector<double>& x)
{
    return tbm::michalewicz(x, 10);
}

// Optional extra wrappers if you want to compare different m values
double tbm::michalewicz_m5(const std::vector<double>& x)
{
    return tbm::michalewicz(x, 5);
}

double tbm::michalewicz_m20(const std::vector<double>& x)
{
    return tbm::michalewicz(x, 20);
}