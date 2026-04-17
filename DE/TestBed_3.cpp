#include "TestBed_3.hpp"

// Goldstein’s function
// f_16(+/-3) = 7
// IPR xj in [-10, 10]
// VTR itself was set to 1.e-6
double tb3::goldstein(const std::vector<double>& x)
{
    double v = x[0];

    return std::pow(v, 6) - 15.0 * std::pow(v, 4)
         + 27.0 * (v * v) + 250.0;
}

double tb3::u(double z, double a, double k, double m)
{
    if (z > a)
        return k * std::pow(z - a, m);
    else if (z < -a)
        return k * std::pow(-z - a, m);
    else
        return 0.0;
}

// Penalized Shubert Function
// f_17(x)
// The global minimum is f17(-7.70831) = f17(-1.42513) = f17(-4.85805) = -12.8708855
double tb3::shubert(double x)
{
    double result = 0.0;
    for (int i = 1; i <= 5; i++)
        result += i * std::cos((i + 1) * x + i);
    return result;
}

double tb3::penalized_shubert(const std::vector<double>& x)
{
    return tb3::shubert(x[0]) + tb3::u(x[0], 10.0, 100.0, 2.0);
}

// Two-dimensional Penalized Shubert Function
// There are 18 global minima with value -186.7309088 in the region bounded by the IPR.
double tb3::penalized_shubert_2d(const std::vector<double>& x)
{
    return tb3::shubert(x[0]) * tb3::shubert(x[1])
         + tb3::u(x[0], 10.0, 100.0, 2.0)
         + tb3::u(x[1], 10.0, 100.0, 2.0);
}

// Two-dimensional modified and penalized Shubert Function
// The global minimum is f19(-1.42513, -0.80032) = -186.7309088
double tb3::modified_shubert(const std::vector<double>& x, double beta)
{
    double t1 = x[0] + 1.42513;
    double t2 = x[1] + 0.80032;

    return tb3::penalized_shubert_2d(x) + beta * (t1 * t1 + t2 * t2);
}

// Wrappers for modified_shubert
double tb3::modified_shubert_b05(const std::vector<double>& x)
{
    return tb3::modified_shubert(x, 0.5);
}

double tb3::modified_shubert_b10(const std::vector<double>& x)
{
    return tb3::modified_shubert(x, 1.0);
}

// Six-hump Camel Function
// The global minimum is f20(-0.0898, 0.7126) = f20(0.0898, -0.7126) = -1.0316285
double tb3::six_hump_camel(const std::vector<double>& x)
{
    double x1 = x[0];
    double x2 = x[1];

    double t1 = (4.0 - 2.1 * (x1 * x1) + (x1 * x1 * x1 * x1) / 3.0) * (x1 * x1);
    double t2 = x1 * x2;
    double t3 = (-4.0 + 4.0 * (x2 * x2)) * (x2 * x2);

    return t1 + t2 + t3;
}

// f_21(x)
double tb3::g2(const std::vector<double>& x)
{
    const double PI = 3.14159265358979323846;
    double D = static_cast<double>(x.size());

    double arg1 = PI + (PI / 4.0) * (x[0] - 1.0);
    double sum = 10.0 * std::sin(arg1) * std::sin(arg1);

    for (size_t i = 0; i < x.size() - 1; i++)
    {
        double arg = PI + (PI / 4.0) * (x[i + 1] - 1.0);
        double term = 0.125 * (x[i] - 1.0) * (x[i] - 1.0)
                    * (1.0 + 10.0 * std::sin(arg) * std::sin(arg));
        sum += term;
    }

    sum += 0.125 * (x.back() - 1.0) * (x.back() - 1.0);

    return (PI / D) * sum;
}

double tb3::f21(const std::vector<double>& x)
{
    double penalty = 0.0;
    for (size_t i = 0; i < x.size(); i++)
        penalty += tb3::u(x[i], 10.0, 100.0, 4.0);

    return tb3::g2(x) + penalty;
}

double tb3::g3(const std::vector<double>& x)
{
    const double PI = 3.14159265358979323846;
    double D = static_cast<double>(x.size());

    double s1 = std::sin(PI * x[0]);
    double sum = 10.0 * s1 * s1;

    for (size_t i = 0; i < x.size() - 1; i++)
    {
        double s2 = std::sin(PI * x[i + 1]);
        double term = (x[i] - 1.0) * (x[i] - 1.0)
                    * (1.0 + 10.0 * s2 * s2);
        sum += term;
    }

    sum += (x.back() - 1.0) * (x.back() - 1.0);

    return (PI / D) * sum;
}

// The global minimum is f22(1) = 0
double tb3::f22(const std::vector<double>& x)
{
    double penalty = 0.0;
    for (size_t i = 0; i < x.size(); i++)
        penalty += tb3::u(x[i], 10.0, 100.0, 4.0);

    return tb3::g3(x) + penalty;
}

double tb3::g4(const std::vector<double>& x)
{
    const double PI = 3.14159265358979323846;

    double s1 = std::sin(3.0 * PI * x[0]);
    double sum = s1 * s1;

    for (size_t i = 0; i < x.size() - 1; i++)
    {
        double s2 = std::sin(3.0 * PI * x[i + 1]);
        double term = (x[i] - 1.0) * (x[i] - 1.0)
                    * (1.0 + s2 * s2);
        sum += term;
    }

    double sD = std::sin(2.0 * PI * x.back());
    sum += (x.back() - 1.0) * (x.back() - 1.0)
         * (1.0 + sD * sD);

    return 0.1 * sum;
}

// The global minimum is f23(1) = 0
double tb3::f23(const std::vector<double>& x)
{
    double penalty = 0.0;
    for (size_t i = 0; i < x.size(); i++)
        penalty += tb3::u(x[i], 10.0, 100.0, 4.0);

    return tb3::g4(x) + penalty;
}

// Global min f24(1) = 0
double tb3::f24(const std::vector<double>& x)
{
    double penalty = 0.0;
    for (size_t i = 0; i < x.size(); i++)
        penalty += tb3::u(x[i], 5.0, 100.0, 4.0);

    return tb3::g4(x) + penalty;
}

// The global minimum is f25(-1.0466805696) = -0.3523861
double tb3::f25(const std::vector<double>& x)
{
    double v = x[0];
    return 0.25 * (v * v * v * v) - 0.5 * (v * v) + 0.1 * v;
}

// The global minimum is f26(-1.0466805696, 0) = -0.3523861
double tb3::f26(const std::vector<double>& x)
{
    double x1 = x[0];
    double x2 = x[1];

    return 0.25 * (x1 * x1 * x1 * x1) - 0.5 * (x1 * x1)
         + 0.1 * x1 + 0.5 * (x2 * x2);
}

// The global minimum is f27(0) = 0
double tb3::f27(const std::vector<double>& x)
{
    double x1 = x[0];
    double x2 = x[1];

    return 0.5 * (x1 * x1) + 0.5 * (1.0 - std::cos(2.0 * x1)) + (x2 * x2);
}

// See documentation for global mins
double tb3::f28(const std::vector<double>& x, int n)
{
    double x1 = x[0];
    double x2 = x[1];

    double r2 = x1 * x1 + x2 * x2;

    return std::pow(10.0, n) * (x1 * x1)
         + x2 * x2
         - r2 * r2
         + std::pow(10.0, -n) * (r2 * r2 * r2 * r2);
}

// Wrappers for f28
double tb3::f28_n1(const std::vector<double>& x) { return tb3::f28(x, 1); }
double tb3::f28_n2(const std::vector<double>& x) { return tb3::f28(x, 2); }
double tb3::f28_n3(const std::vector<double>& x) { return tb3::f28(x, 3); }
double tb3::f28_n4(const std::vector<double>& x) { return tb3::f28(x, 4); }
double tb3::f28_n5(const std::vector<double>& x) { return tb3::f28(x, 5); }
double tb3::f28_n6(const std::vector<double>& x) { return tb3::f28(x, 6); }

// The global minimum is f29(0) = 0
double tb3::f29(const std::vector<double>& x)
{
    double sum = 0.0;
    for (size_t i = 0; i < x.size(); i++)
        sum += (i + 1.0) * (x[i] * x[i]);

    return std::pow(sum, 0.25);
}

// The global minimum is f30(1523.2, 277.5) = 0.000888085
double tb3::f30(const std::vector<double>& x)
{
    const double z_data[14] = {
        1219, 1371, 1377, 1144, 1201,
        1225, 1244, 1254, 1304, 1328,
        1351, 1356, 1370, 1390
    };

    const int delta[14] = {
        0, 0, 0, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1
    };

    double x1 = x[0];
    double x2 = x[1];

    auto phi = [](double z) -> double {
        return 0.5 * (1.0 + std::erf(z / std::sqrt(2.0)));
    };

    double F = 1.0;
    for (int i = 0; i < 14; i++)
    {
        double p = phi((z_data[i] - x1) / x2);

        double term;
        if (delta[i] == 0)
            term = p;
        else
            term = 1.0 - p;

        F *= term;
    }

    double penalty = tb3::u(x[0], 1.0e4, 100.0, 2.0)
                   + tb3::u(x[1], 1.0e4, 100.0, 2.0);

    return F + penalty;
}