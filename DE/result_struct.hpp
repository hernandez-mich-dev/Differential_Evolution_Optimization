#ifndef RESULT_STRUCT_HPP
#define RESULT_STRUCT_HPP

#include <vector>

struct Results
{
    std::string test_name;
    std::vector<double> best_vector;
    double best_cost;
    int nfe;

    Results()
    {}

    Results(std::vector<double>& best_v, double best_c, int n):
        best_vector(best_v), best_cost(best_c), nfe(n)
        {}
};

#endif