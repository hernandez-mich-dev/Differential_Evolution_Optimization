#include <vector>

namespace tbm
{
    double michalewicz(const std::vector<double>& x, int m);
    double michalewicz_m5(const std::vector<double>& x);
    double michalewicz_m20(const std::vector<double>& x);
}