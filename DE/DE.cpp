#include "DE.hpp"

namespace de {

    Results differentialEvolution(
        CostFunction call,
        int d,
        int np,
        int iteration_max,
        double f,
        double cr,
        double lower,
        double upper,
        double vtr)
    {
        if (np < 4) 
        {
            throw std::invalid_argument("np must be at least 4");
        }
        
        if (d <= 0) 
        {
            throw std::invalid_argument("d must be positive");
        }

        if (iteration_max < 0) 
        {
            throw std::invalid_argument("iteration_max must be nonnegative");
        }
        
        if (lower > upper) {
            throw std::invalid_argument("lower must be <= upper");
        }

        std::vector<double> best_vector;
        double best_cost = std::numeric_limits<double>::infinity();
        int nfe = 0;

        std::vector<std::vector<double>> x1(np, std::vector<double>(d));
        std::vector<std::vector<double>> x2(np, std::vector<double>(d));
        std::vector<double> cost(np);
        std::vector<double> mutant(d);
        std::vector<double> trial(d);

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<double> dist_uni(0.0, 1.0);
        std::uniform_real_distribution<double> dist_param(lower, upper);
        std::uniform_int_distribution<int> dist_NP(0, np - 1);
        std::uniform_int_distribution<int> dist_D(0, d - 1);

        best_vector.assign(d, 0.0);

        for (int i = 0; i < np; ++i) 
        {
            for (int j = 0; j < d; ++j) 
            {
                x1[i][j] = dist_param(gen);
            }

            cost[i] = call(x1[i]);
            nfe++;

            if (cost[i] < best_cost) 
            {
                best_cost = cost[i];
                best_vector = x1[i];
            }
        }

        if (best_cost <= vtr) 
        {

            return Results(best_vector, best_cost, nfe);
        }

        for (int count = 0; count < iteration_max; ++count) 
        {
            for (int i = 0; i < np; ++i) 
            {
                int a, b, c;

                do { a = dist_NP(gen); } while (a == i);
                do { b = dist_NP(gen); } while (b == i || b == a);
                do { c = dist_NP(gen); } while (c == i || c == a || c == b);

                for (int j = 0; j < d; ++j) 
                {
                    mutant[j] = x1[a][j] + f * (x1[b][j] - x1[c][j]);
                }

                int j_rand = dist_D(gen);

                for (int j = 0; j < d; ++j) 
                {
                    if (dist_uni(gen) <= cr || j == j_rand) 
                    {

                        trial[j] = mutant[j];
                    } else {

                        trial[j] = x1[i][j];
                    }
                }

                double score = call(trial);
                nfe++;

                if (score <= cost[i]) 
                {
                    x2[i] = trial;
                    cost[i] = score;

                    if (score < best_cost) 
                    {

                        best_cost = score;
                        best_vector = trial;
                    
                        if (best_cost <= vtr) 
                        {

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