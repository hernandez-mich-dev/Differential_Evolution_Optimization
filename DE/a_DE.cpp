#include "a_DE.hpp"

namespace a_de {

    Results differentialEvolution_jDE(
        CostFunction call,
        int d,
        int np,
        int iteration_max,
        double lower,
        double upper,
        double vtr)
    {
        if (np < 4) {
            throw std::invalid_argument("np must be at least 4");
        }
        if (d <= 0) {
            throw std::invalid_argument("d must be positive");
        }

        std::vector<double> best_vector(d, 0.0);
        double best_cost = std::numeric_limits<double>::infinity();
        int nfe = 0;

        const double threshold1 = 0.1;
        const double threshold2 = 0.1;
        const double F_lower = 0.1;
        const double F_upper = 0.9;

        std::vector<std::vector<double>> x1(np, std::vector<double>(d));
        std::vector<std::vector<double>> x2(np, std::vector<double>(d));
        std::vector<double> cost_vector(np);
        std::vector<double> trial_vector(d);
        std::vector<double> mutant_vector(d);

        std::vector<double> F_vector(np, 0.5);
        std::vector<double> CR_vector(np, 0.1);

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<double> uniform_distribution(0.0, 1.0);
        std::uniform_real_distribution<double> distribution_parameter(lower, upper);
        std::uniform_int_distribution<int> np_distribution(0, np - 1);
        std::uniform_int_distribution<int> d_distribution(0, d - 1);

        for (int i = 0; i < np; ++i)
        {
            for (int j = 0; j < d; ++j)
            {
                x1[i][j] = distribution_parameter(gen);
            }

            cost_vector[i] = call(x1[i]);
            nfe++;

            if (cost_vector[i] < best_cost)
            {
                best_cost = cost_vector[i];
                best_vector = x1[i];
            }
        }

        if (best_cost <= vtr) {
            return Results(best_vector, best_cost, nfe);
        }

        for (int g = 0; g < iteration_max; ++g)
        {
            for (int i = 0; i < np; ++i)
            {
                double F_adaptable = F_vector[i];
                double CR_adaptable = CR_vector[i];

                if (uniform_distribution(gen) < threshold1)
                {
                    F_adaptable = F_lower + uniform_distribution(gen) * (F_upper - F_lower);
                }

                if (uniform_distribution(gen) < threshold2)
                {
                    CR_adaptable = uniform_distribution(gen);
                }

                int a, b, c;
                do { a = np_distribution(gen); } while (a == i);
                do { b = np_distribution(gen); } while (b == i || b == a);
                do { c = np_distribution(gen); } while (c == i || c == a || c == b);

                for (int j = 0; j < d; ++j)
                {
                    mutant_vector[j] = x1[a][j] + F_adaptable * (x1[b][j] - x1[c][j]);
                }

                int j_rand = d_distribution(gen);

                for (int j = 0; j < d; ++j)
                {
                    if (uniform_distribution(gen) <= CR_adaptable || j == j_rand)
                    {
                        trial_vector[j] = mutant_vector[j];
                    }
                    else
                    {
                        trial_vector[j] = x1[i][j];
                    }

                    trial_vector[j] = std::clamp(trial_vector[j], lower, upper);
                }

                double score = call(trial_vector);
                nfe++;

                if (score <= cost_vector[i])
                {
                    x2[i] = trial_vector;
                    cost_vector[i] = score;
                    F_vector[i] = F_adaptable;
                    CR_vector[i] = CR_adaptable;

                    if (score < best_cost)
                    {
                        best_cost = score;
                        best_vector = trial_vector;

                        if (best_cost <= vtr) {
                            return Results(best_vector, best_cost, nfe);
                        }
                    }
                }
                else
                {
                    x2[i] = x1[i];
                }
            }

            x1 = x2;
        }

        return Results(best_vector, best_cost, nfe);
    }
}