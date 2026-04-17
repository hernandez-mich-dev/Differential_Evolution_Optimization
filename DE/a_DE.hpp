#ifndef a_DE_HPP
#define a_DE_HPP

#include "result_struct.hpp"
#include <algorithm>
#include <limits>
#include <random>
#include <stdexcept>
#include <vector>

namespace a_de 
{

    using CostFunction = double (*)(const std::vector<double>&);

    Results differentialEvolution(

        CostFunction call,
        int d,
        int np,
        int iteration_max,
        double lower,
        double upper,
        double vtr);

    }

#endif