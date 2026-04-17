#include "TestBed_1.hpp"

//First De Jong function (sphere)
//IPR: x_j [-5.12, 5.12]
//Global min is f_1(0) = 0
//VTR set to 1.e^{-6}
double tb1::dejong_f1 (const std::vector<double>& x)
{
    double result = 0.0;
    for (size_t i = 0; i < x.size(); i++)
    {
        result += std::pow(x[i], 2); 
    }

    return result;
}

//De Jong function F2 (Rosenbrock's saddle)
//IPR: x_j [-2.048, 2.048]
//Global min is f_2(1) = 0
//VTR set to 1.e^{-6}
double tb1::dejong_f2 (const std::vector<double>& x)
{
    double temp_1 = 0.0;
    double temp_2 = 0.0;
    double result = 0.0;
    for (size_t i = 0; i + 1 < x.size(); ++i)
    {
        temp_1 = (x[i] * x[i]) - x[i + 1];
        temp_1 = temp_1 * temp_1;
        temp_2 = 1.0 - x[i];
        temp_2 = temp_2 * temp_2;
        result += 100.0 * temp_1 + temp_2;
    }

    return result;
}

// De Jong function F3 (modified step)
// IPR: x_j in [-5.12, 5.12]
// Global minimum is f_3(5 - epsilon) = 0 where epsilon in [0, 0.12]
// VTR = 1.e-6
double tb1::dejong_f3(const std::vector<double>& x)
{
    double result = 30.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        if (x[i] >= -5.12 && x[i] <= 5.12)
        {
            result += std::floor(x[i]);
        }
        else
        {
            result *= 30.0 * tb1::sgn(x[i] - 5.12);
        }
    }

    return result;
}

//De Jong function F4 (quartic)
//IPR: x_j [-1.28, 1.28]
//Global min is f_4(0) <= 30E[η] = 15 = VTR, wher E[η] is the Expectation of η.
//VTR set to 1.e^{-6}
double tb1::dejong_f4(const std::vector<double>& x)
{
    static std::mt19937 rng(std::random_device{}());
    static std::uniform_real_distribution<double> uniform(0.0, 1.0);

    double result = 0.0;
    for (size_t j = 0; j < x.size(); ++j)
    {
        double η = uniform(rng);                  
        result += (j + 1) * (x[j] * x[j] * x[j] * x[j]) + η;
    }
    return result;
}

// De Jong function F5 (Shekel’s Foxholes)
// IPR: x_j in [-65.536, 65.536]
// Global minimum is approximately f_5(-32, -32) ~= 0.998004
// VTR = 0.998005
double tb1::dejong_f5(const std::vector<double>& x)
{
    static const double a[25][2] = {
        {-32,-32},{-16,-32},{0,-32},{16,-32},{32,-32},
        {-32,-16},{-16,-16},{0,-16},{16,-16},{32,-16},
        {-32,  0},{-16,  0},{0,  0},{16,  0},{32,  0},
        {-32, 16},{-16, 16},{0, 16},{16, 16},{32, 16},
        {-32, 32},{-16, 32},{0, 32},{16, 32},{32, 32}
    };

    double sum = 0.0;

    for (int i = 0; i < 25; ++i)
    {
        double d0 = x[0] - a[i][0];
        double d1 = x[1] - a[i][1];
        double inner = std::pow(d0, 6) + std::pow(d1, 6);

        sum += 1.0 / ((i + 1) + inner);
    }

    return 1.0 / (0.002 + sum);
}

// Corana's Parabola
// IPR: x_j in [-1000, 1000]
// Global minimum is f_6(x) = 0 for |x_j| < 0.05, j = 1,2,3,4
// VTR = 1.e-6
double tb1::corana_f6(const std::vector<double>& x)
{
    static const double d[4] = {1.0, 1000.0, 10.0, 100.0};

    auto sgn = [](double v) -> double {
        if (v > 0.0) return 1.0;
        if (v < 0.0) return -1.0;
        return 0.0;
    };

    double result = 0.0;

    for (int i = 0; i < 4; ++i)
    {
        double z_j = std::floor(std::abs(x[i] / 0.2) + 0.49999) * sgn(x[i]) * 0.2;

        if (std::abs(x[i] - z_j) < 0.05)
        {
            double t = z_j - 0.05 * sgn(z_j);
            result += 0.15 * t * t * d[i];
        }
        else
        {
            result += d[i] * x[i] * x[i];
        }
    }

    return result;
}

//Griewangk’s function: Griewangk
//IPR: xj \in [-400, 400]
//f_7(0) = 0
//VTR defined to be 1.e^{-6}
double tb1::griewangk(const std::vector<double>& x)
{
    double result = 0.0;
    double p = 1.0; 

    for (int i = 0; i < 10; i++)
    {
        result += (x[i] * x[i]) / 4000.0;
        p *= std::cos(x[i] / std::sqrt(i + 1.0));
    }

    return result - p + 1.0;
}

// Zimmermann’s problem
// IPR: x_j in [0, 100], j = 1, 2
// Global minimum is f_8(7, 2) = 0
// VTR = 1.e-6
double tb1::zimmermann_f8(const std::vector<double>& x)
{
    auto sgn = [](double v) -> double {
        if (v > 0.0) return  1.0;
        if (v < 0.0) return -1.0;
        return 0.0;
    };

    auto p = [](double delta) -> double {
        return 100.0 * (1.0 + delta);
    };

    double h1 = 9.0 - x[0] - x[1];

    double h2 = (x[0] - 3.0) * (x[0] - 3.0)
              + (x[1] - 2.0) * (x[1] - 2.0) - 16.0;

    double h3 = x[0] * x[1] - 14.0;

    return std::max({
        h1,
        p(h2) * sgn(h2),
        p(h3) * sgn(h3),
        p(x[0]) * sgn(-x[0]),
        p(x[1]) * sgn(-x[1])
    });
}

double tb1::chebyshev(int n, double z)
{
    if (n == 0) return 1.0;
    if (n == 1) return z;

    double t_prev = 1.0;
    double t_curr = z;
    double t_next = 0.0;

    for (int i = 1; i < n; i++)
    {
        t_next = 2.0 * z * t_curr - t_prev;
        t_prev = t_curr;
        t_curr = t_next;
    }
    return t_curr;
}

double tb1::h4(const std::vector<double>& x, double z)
{
    double result = 0.0;
    double z_pow  = 1.0;
    for (size_t j = 0; j < x.size(); j++)
    {
        result += x[j] * z_pow;
        z_pow  *= z;
    }
    return result;
}

double tb1::sgn(double v)
{
    if (v > 0.0) return  1.0;
    if (v < 0.0) return -1.0;
    return 0.0;
}

// f9: polynomial fitting cost function
// k: degree parameter (4 for T8, 8 for T16)
// N: number of sample points (60 for T8, 100 for T16)
double tb1::polynomial_f9(const std::vector<double>& x, int k, int N)
{
    int    degree = 2 * k;
    double alpha  = tb1::chebyshev(degree, 1.2);
    double result = 0.0;

    for (int n = 0; n <= N; n++)
    {
        double z    = -1.0 + (2.0 * n) / N;
        double h    = tb1::h4(x, z);

        double over  = h - 1.0;
        result += tb1::sgn(over)  * (over  * over);

        double under = -1.0 - h;
        result += tb1::sgn(under) * (under * under);
    }

    double at_pos = alpha - tb1::h4(x,  1.2);
    double at_neg = alpha - tb1::h4(x, -1.2);

    result += tb1::sgn(at_pos) * (at_pos * at_pos);
    result += tb1::sgn(at_neg) * (at_neg * at_neg);

    return result;
}

// Wrapper for T8 (k = 4, N = 60)
double tb1::polynomial_f9_T8(const std::vector<double>& x)
{
    return tb1::polynomial_f9(x, 4, 60);
}

// Wrapper for T16 (k = 8, N = 100)
double tb1::polynomial_f9_T16(const std::vector<double>& x)
{
    return tb1::polynomial_f9(x, 8, 100);
}
















