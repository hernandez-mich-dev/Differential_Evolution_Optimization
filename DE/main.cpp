#include <iostream>
#include <map>
#include <fstream>
#include <stdexcept>

#include "DE.hpp"
#include "a_DE.hpp"
#include "TestBed_1.hpp"
#include "TestBed_2.hpp"
#include "TestBed_3.hpp"
#include "TestBed_Modern.hpp"

void run_original_de(std::map<std::string, Results>& f_to_res,
    std::map<std::string, Results>& testbed_2,
    std::map<std::string, Results>& testbed_3,
    std::map<std::string, Results>& testbed_modern);

void run_adaptive_de(std::map<std::string, Results>& f_to_res,
    std::map<std::string, Results>& testbed_2,
    std::map<std::string, Results>& testbed_3,
    std::map<std::string, Results>& testbed_modern);

void write_vectors(const std::vector<std::vector<double>>& v,
                    const std::string& file_name);

//NON-ADAPTIVE testing 
//Testing for Testbeds 1 through 3 as well as Modern
//All results stored in a std::map 
int main(int argc, char* argv[])
{
    static const int NUM_PLOTTED_VECTORS = 3;
    std::map<std::string, Results> f_to_res{};
    std::map<std::string, Results> testbed_2{};
    std::map<std::string, Results> testbed_3{};
    std::map<std::string, Results> testbed_modern{};
    std::string name_of_plot_vectors[NUM_PLOTTED_VECTORS] = {"dejong f2", "dejong f5", "f18"};

    std::string f_name = "";
    std::string a = "";
    if (argc != 2)
    {
        std::cout << "ERROR, main requires 0 or 1 command line arguments\n";
        return 0;
    }

    a = argv[1];

    if (a == "0")
    {
        
        f_name = "de_plot.csv";
        run_original_de(f_to_res, testbed_2, testbed_3, testbed_modern);
    }
    else if (a == "1")
    {
        f_name = "a_de_plot.csv";
        run_adaptive_de(f_to_res, testbed_2, testbed_3, testbed_modern);
    }
    else 
    {
        std::cout << "main requires either 0 or 1 command line arguments\n";
        std::cout << "0 = original DE algorithm\n";
        std::cout << "1 = adapative DE algorithm\n";

        return 0;
    }
}

void run_original_de(std::map<std::string, Results>& f_to_res,
    std::map<std::string, Results>& testbed_2,
    std::map<std::string, Results>& testbed_3,
    std::map<std::string, Results>& testbed_modern)
{

    std::string test_name = "";
    int running_nfe_total = 0;
    int testbed_trial_num = 20;
    int d = 0;
    int np = 0;
    int iteration_max = 0;
    double f = 0.0;
    double cr = 0.0;
    double lower;
    double upper;
    double vtr = 0.0;

    ////////////////////////////// TESTBED 1 BEGINS //////////////////////////////
    running_nfe_total = 0;
    test_name = "dejong f1";
    d = 3;
    np = 5;
    iteration_max = 100;
    f = 0.9;
    cr = 0.1;
    lower = -5.12;
    upper = 5.12;
    vtr = 1e-6;
    Results r_f1{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f1 = de::differentialEvolution(
            tb1::dejong_f1,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f1.nfe;
    }

    r_f1.test_name = test_name;
    r_f1.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f1);

    running_nfe_total = 0;
    test_name = "dejong f2";
    d = 2;
    np = 10;
    iteration_max = 500;
    f = 0.9;
    cr = 0.9;
    lower = -2.048;
    upper = 2.048;
    vtr = 1e-6;
    Results r_f2{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f2 = de::differentialEvolution(
            tb1::dejong_f2,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f2.nfe;
    }

    r_f2.test_name = test_name;
    r_f2.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f2);

    running_nfe_total = 0;
    test_name = "dejong f3";
    d = 5;
    np = 10;
    iteration_max = 500;
    f = 0.9;
    cr = 0.0;
    lower = -5.12;
    upper = 5.12;
    vtr = 1e-6;
    Results r_f3{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f3 = de::differentialEvolution(
            tb1::dejong_f3,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f3.nfe;
    }

    r_f3.test_name = test_name;
    r_f3.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f3);

    running_nfe_total = 0;
    test_name = "dejong f4";
    d = 30;
    np = 10;
    iteration_max = 1000;
    f = 0.9;
    cr = 0.0;
    lower = -1.28;
    upper = 1.28;
    vtr = 15.0;
    Results r_f4{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f4 = de::differentialEvolution(
            tb1::dejong_f4,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f4.nfe;
    }

    r_f4.test_name = test_name;
    r_f4.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f4);

    running_nfe_total = 0;
    test_name = "dejong f5";
    d = 2;
    np = 15;
    iteration_max = 2000;
    f = 0.9;
    cr = 0.0;
    lower = -65.536;
    upper = 65.536;
    vtr = 0.998005;
    Results r_f5{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f5 = de::differentialEvolution(
            tb1::dejong_f5,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f5.nfe;
    }

    r_f5.test_name = test_name;
    r_f5.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f5);

    running_nfe_total = 0;
    test_name = "dejong f6";
    d = 4;
    np = 10;
    iteration_max = 1000;
    f = 0.5;
    cr = 0.0;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1e-6;
    Results r_f6{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f6 = de::differentialEvolution(
            tb1::corana_f6,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f6.nfe;
    }

    r_f6.test_name = test_name;
    r_f6.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f6);

    running_nfe_total = 0;
    test_name = "dejong f7";
    d = 10;
    np = 25;
    iteration_max = 1000;
    f = 0.5;
    cr = 0.2;
    lower = -400.0;
    upper = 400.0;
    vtr = 1e-6;
    Results r_f7{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f7 = de::differentialEvolution(
            tb1::griewangk,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f7.nfe;
    }

    r_f7.test_name = test_name;
    r_f7.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f7);

    running_nfe_total = 0;
    test_name = "dejong f8";
    d = 2;
    np = 10;
    iteration_max = 100;
    f = 0.9;
    cr = 0.9;
    lower = 0.0;
    upper = 100.0;
    vtr = 1e-6;
    Results r_f8{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f8 = de::differentialEvolution(
            tb1::zimmermann_f8,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f8.nfe;
    }

    r_f8.test_name = test_name;
    r_f8.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f8);

    running_nfe_total = 0;
    test_name = "dejong f9_T8";
    d = 9;
    np = 60;
    iteration_max = 2000;
    f = 0.6;
    cr = 1.0;
    lower = -100.0;
    upper = 100.0;
    vtr = 1e-6;
    Results r_f9_T8{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f9_T8 = de::differentialEvolution(
            tb1::polynomial_f9_T8,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f9_T8.nfe;
    }

    r_f9_T8.test_name = test_name;
    r_f9_T8.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f9_T8);

    running_nfe_total = 0;
    test_name = "dejong f9_T16";
    d = 17;
    np = 100;
    iteration_max = 2000;
    f = 0.6;
    cr = 1.0;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1e-6;
    Results r_f9_T16{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f9_T16 = de::differentialEvolution(
            tb1::polynomial_f9_T16,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f9_T16.nfe;
    }

    r_f9_T16.test_name = test_name;
    r_f9_T16.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f9_T16);

    std::cout << "Testbed 1 Results\n";
    for (const auto& [key, value] : f_to_res)
    {
        std::cout << "test name: " << value.test_name
                << ", nfe: " << value.nfe << "\n";
    }

    //////////////////////////////TESTBED 2 BEGINS//////////////////////////////

    test_name = "f11_D30";
    int f11_D30 = 0;
    d = 30;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1.0;
    upper = 1.0;
    vtr = 1e-10;
    Results r_f11_D30{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f11_D30 = de::differentialEvolution(
            tb2::hyper_ellipsoid,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f11_D30 += r_f11_D30.nfe;
    }

    r_f11_D30.test_name = test_name;
    r_f11_D30.nfe = f11_D30 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f11_D30);

    test_name = "f11_D100";
    int f11_D100 = 0;
    d = 100;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1.0;
    upper = 1.0;
    vtr = 1e-10;
    Results r_f11_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f11_D100 = de::differentialEvolution(
            tb2::hyper_ellipsoid,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f11_D100 += r_f11_D100.nfe;
    }

    r_f11_D100.test_name = test_name;
    r_f11_D100.nfe = f11_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f11_D100);

    test_name = "kat_10";
    int kat_10 = 0;
    d = 10;
    np = 15;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1.05;
    Results r_kat_10{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_kat_10 = de::differentialEvolution(
            tb2::katsuura,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        kat_10 += r_kat_10.nfe;
    }

    r_kat_10.test_name = test_name;
    r_kat_10.nfe = kat_10 / testbed_trial_num;
    testbed_2.emplace(test_name, r_kat_10);

    test_name = "kat_30";
    int kat_30 = 0;
    d = 30;
    np = 15;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1.05;
    Results r_kat_30{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_kat_30 = de::differentialEvolution(
            tb2::katsuura,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        kat_30 += r_kat_30.nfe;
    }

    r_kat_30.test_name = test_name;
    r_kat_30.nfe = kat_30 / testbed_trial_num;
    testbed_2.emplace(test_name, r_kat_30);

        test_name = "f13_D20";
    int f13_D20 = 0;
    d = 20;
    np = 25;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -600.0;
    upper = 600.0;
    vtr = 0.9;
    Results r_f13_D20{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f13_D20 = de::differentialEvolution(
            tb2::rastrigin,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f13_D20 += r_f13_D20.nfe;
    }

    r_f13_D20.test_name = test_name;
    r_f13_D20.nfe = f13_D20 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f13_D20);

    test_name = "f13_D100";
    int f13_D100 = 0;
    d = 100;
    np = 25;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -600.0;
    upper = 600.0;
    vtr = 0.9;
    Results r_f13_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f13_D100 = de::differentialEvolution(
            tb2::rastrigin,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f13_D100 += r_f13_D100.nfe;
    }

    r_f13_D100.test_name = test_name;
    r_f13_D100.nfe = f13_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f13_D100);

    test_name = "f14_D20";
    int f14_D20 = 0;
    d = 20;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -600.0;
    upper = 600.0;
    vtr = 1e-3;
    Results r_f14_D20{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f14_D20 = de::differentialEvolution(
            tb2::griewank_f14,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f14_D20 += r_f14_D20.nfe;
    }

    r_f14_D20.test_name = test_name;
    r_f14_D20.nfe = f14_D20 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f14_D20);

    test_name = "f14_D100";
    int f14_D100 = 0;
    d = 100;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.1;
    lower = -600.0;
    upper = 600.0;
    vtr = 1e-3;
    Results r_f14_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f14_D100 = de::differentialEvolution(
            tb2::griewank_f14,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f14_D100 += r_f14_D100.nfe;
    }

    r_f14_D100.test_name = test_name;
    r_f14_D100.nfe = f14_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f14_D100);

    test_name = "f15_D30";
    int f15_D30 = 0;
    d = 30;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -30.0;
    upper = 30.0;
    vtr = 1e-3;
    Results r_f15_D30{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f15_D30 = de::differentialEvolution(
            tb2::ackley,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f15_D30 += r_f15_D30.nfe;
    }

    r_f15_D30.test_name = test_name;
    r_f15_D30.nfe = f15_D30 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f15_D30);

    test_name = "f15_D100";
    int f15_D100 = 0;
    d = 100;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.1;
    lower = -30.0;
    upper = 30.0;
    vtr = 1e-3;
    Results r_f15_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f15_D100 = de::differentialEvolution(
            tb2::ackley,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );

        f15_D100 += r_f15_D100.nfe;
    }

    r_f15_D100.test_name = test_name;
    r_f15_D100.nfe = f15_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f15_D100);

    std::cout << "Testbed 2 Results\n";
    for (const auto& [key, value] : testbed_2)
    {
        std::cout << "test name: " << value.test_name
                  << ", nfe: " << value.nfe << "\n";
    }

    ////////////////////////////// TESTBED 3 BEGINS //////////////////////////////
    int testbed_3_trial_num = 1000;

    test_name = "f16";
    int f16 = 0;
    d = 1;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f16{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f16 = de::differentialEvolution(
            tb3::goldstein,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f16 += r_f16.nfe;
    }
    r_f16.test_name = test_name;
    r_f16.nfe = f16 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f16);

    test_name = "f17";
    int f17 = 0;
    d = 1;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -12.8708855;
    Results r_f17{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f17 = de::differentialEvolution(
            tb3::penalized_shubert,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f17 += r_f17.nfe;
    }
    r_f17.test_name = test_name;
    r_f17.nfe = f17 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f17);

    test_name = "f18";
    int f18 = 0;
    d = 2;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;
    Results r_f18{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f18 = de::differentialEvolution(
            tb3::penalized_shubert_2d,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f18 += r_f18.nfe;
    }
    r_f18.test_name = test_name;
    r_f18.nfe = f18 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f18);

    test_name = "f19_b05";
    int f19_b05 = 0;
    d = 2;
    np = 40;
    iteration_max = 10000;
    f = 1.0;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;
    Results r_f19_b05{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f19_b05 = de::differentialEvolution(
            tb3::modified_shubert_b05,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f19_b05 += r_f19_b05.nfe;
    }
    r_f19_b05.test_name = test_name;
    r_f19_b05.nfe = f19_b05 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f19_b05);

    test_name = "f19_b10";
    int f19_b10 = 0;
    d = 2;
    np = 40;
    iteration_max = 10000;
    f = 1.0;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;
    Results r_f19_b10{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f19_b10 = de::differentialEvolution(
            tb3::modified_shubert_b10,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f19_b10 += r_f19_b10.nfe;
    }
    r_f19_b10.test_name = test_name;
    r_f19_b10.nfe = f19_b10 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f19_b10);

    test_name = "f20";
    int f20 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -1.0316285;
    Results r_f20{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f20 = de::differentialEvolution(
            tb3::six_hump_camel,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f20 += r_f20.nfe;
    }
    r_f20.test_name = test_name;
    r_f20.nfe = f20 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f20);

    test_name = "f21_D2";
    int f21_D2 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f21_D2{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f21_D2 = de::differentialEvolution(
            tb3::f21,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f21_D2 += r_f21_D2.nfe;
    }
    r_f21_D2.test_name = test_name;
    r_f21_D2.nfe = f21_D2 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f21_D2);

    test_name = "f21_D3";
    int f21_D3 = 0;
    d = 3;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f21_D3{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f21_D3 = de::differentialEvolution(
            tb3::f21,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f21_D3 += r_f21_D3.nfe;
    }
    r_f21_D3.test_name = test_name;
    r_f21_D3.nfe = f21_D3 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f21_D3);

    test_name = "f21_D4";
    int f21_D4 = 0;
    d = 4;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f21_D4{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f21_D4 = de::differentialEvolution(
            tb3::f21,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f21_D4 += r_f21_D4.nfe;
    }
    r_f21_D4.test_name = test_name;
    r_f21_D4.nfe = f21_D4 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f21_D4);

    test_name = "f22_D5";
    int f22_D5 = 0;
    d = 5;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f22_D5{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f22_D5 = de::differentialEvolution(
            tb3::f22,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f22_D5 += r_f22_D5.nfe;
    }
    r_f22_D5.test_name = test_name;
    r_f22_D5.nfe = f22_D5 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f22_D5);

    test_name = "f22_D8";
    int f22_D8 = 0;
    d = 8;
    np = 20;
    iteration_max = 8000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f22_D8{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f22_D8 = de::differentialEvolution(
            tb3::f22,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f22_D8 += r_f22_D8.nfe;
    }
    r_f22_D8.test_name = test_name;
    r_f22_D8.nfe = f22_D8 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f22_D8);

    test_name = "f22_D10";
    int f22_D10 = 0;
    d = 10;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f22_D10{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f22_D10 = de::differentialEvolution(
            tb3::f22,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f22_D10 += r_f22_D10.nfe;
    }
    r_f22_D10.test_name = test_name;
    r_f22_D10.nfe = f22_D10 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f22_D10);

    test_name = "f23_D2";
    int f23_D2 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f23_D2{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f23_D2 = de::differentialEvolution(
            tb3::f23,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f23_D2 += r_f23_D2.nfe;
    }
    r_f23_D2.test_name = test_name;
    r_f23_D2.nfe = f23_D2 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f23_D2);

    test_name = "f23_D3";
    int f23_D3 = 0;
    d = 3;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f23_D3{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f23_D3 = de::differentialEvolution(
            tb3::f23,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f23_D3 += r_f23_D3.nfe;
    }
    r_f23_D3.test_name = test_name;
    r_f23_D3.nfe = f23_D3 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f23_D3);

    test_name = "f23_D4";
    int f23_D4 = 0;
    d = 4;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f23_D4{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f23_D4 = de::differentialEvolution(
            tb3::f23,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f23_D4 += r_f23_D4.nfe;
    }
    r_f23_D4.test_name = test_name;
    r_f23_D4.nfe = f23_D4 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f23_D4);

    test_name = "f24_D5";
    int f24_D5 = 0;
    d = 5;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f24_D5{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f24_D5 = de::differentialEvolution(
            tb3::f24,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f24_D5 += r_f24_D5.nfe;
    }
    r_f24_D5.test_name = test_name;
    r_f24_D5.nfe = f24_D5 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f24_D5);

    test_name = "f24_D6";
    int f24_D6 = 0;
    d = 6;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f24_D6{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f24_D6 = de::differentialEvolution(
            tb3::f24,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f24_D6 += r_f24_D6.nfe;
    }
    r_f24_D6.test_name = test_name;
    r_f24_D6.nfe = f24_D6 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f24_D6);

    test_name = "f24_D7";
    int f24_D7 = 0;
    d = 7;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f24_D7{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f24_D7 = de::differentialEvolution(
            tb3::f24,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f24_D7 += r_f24_D7.nfe;
    }
    r_f24_D7.test_name = test_name;
    r_f24_D7.nfe = f24_D7 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f24_D7);

    test_name = "f25";
    int f25 = 0;
    d = 1;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -0.3523861;
    Results r_f25{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f25 = de::differentialEvolution(
            tb3::f25,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f25 += r_f25.nfe;
    }
    r_f25.test_name = test_name;
    r_f25.nfe = f25 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f25);

    test_name = "f26";
    int f26 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -0.3523861;
    Results r_f26{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f26 = de::differentialEvolution(
            tb3::f26,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f26 += r_f26.nfe;
    }
    r_f26.test_name = test_name;
    r_f26.nfe = f26 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f26);

    test_name = "f27";
    int f27 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f27{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f27 = de::differentialEvolution(
            tb3::f27,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f27 += r_f27.nfe;
    }
    r_f27.test_name = test_name;
    r_f27.nfe = f27 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f27);

    test_name = "f28_n1";
    int f28_n1 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 0.4074616;
    Results r_f28_n1{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n1 = de::differentialEvolution(
            tb3::f28_n1,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f28_n1 += r_f28_n1.nfe;
    }
    r_f28_n1.test_name = test_name;
    r_f28_n1.nfe = f28_n1 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n1);

    test_name = "f28_n2";
    int f28_n2 = 0;
    vtr = 18.0586967;
    Results r_f28_n2{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n2 = de::differentialEvolution(
            tb3::f28_n2,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f28_n2 += r_f28_n2.nfe;
    }
    r_f28_n2.test_name = test_name;
    r_f28_n2.nfe = f28_n2 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n2);

    test_name = "f28_n3";
    int f28_n3 = 0;
    vtr = 227.7657500;
    Results r_f28_n3{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n3 = de::differentialEvolution(
            tb3::f28_n3,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f28_n3 += r_f28_n3.nfe;
    }
    r_f28_n3.test_name = test_name;
    r_f28_n3.nfe = f28_n3 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n3);

    test_name = "f28_n4";
    int f28_n4 = 0;
    vtr = 2429.4147670;
    Results r_f28_n4{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n4 = de::differentialEvolution(
            tb3::f28_n4,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f28_n4 += r_f28_n4.nfe;
    }
    r_f28_n4.test_name = test_name;
    r_f28_n4.nfe = f28_n4 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n4);

    test_name = "f28_n5";
    int f28_n5 = 0;
    vtr = 24776.5183423;
    Results r_f28_n5{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n5 = de::differentialEvolution(
            tb3::f28_n5,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f28_n5 += r_f28_n5.nfe;
    }
    r_f28_n5.test_name = test_name;
    r_f28_n5.nfe = f28_n5 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n5);

    test_name = "f28_n6";
    int f28_n6 = 0;
    vtr = 249293.0182630;
    Results r_f28_n6{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n6 = de::differentialEvolution(
            tb3::f28_n6,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f28_n6 += r_f28_n6.nfe;
    }
    r_f28_n6.test_name = test_name;
    r_f28_n6.nfe = f28_n6 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n6);

    test_name = "f29";
    int f29 = 0;
    d = 5;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f29{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f29 = de::differentialEvolution(
            tb3::f29,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f29 += r_f29.nfe;
    }
    r_f29.test_name = test_name;
    r_f29.nfe = f29 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f29);

    test_name = "f30";
    int f30 = 0;
    d = 2;
    np = 30;
    iteration_max = 10000;
    f = 0.5;
    cr = 1.0;
    lower = -1.0e4;
    upper = 1.0e4;
    vtr = 0.000888085;
    Results r_f30{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f30 = de::differentialEvolution(
            tb3::f30,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        f30 += r_f30.nfe;
    }
    r_f30.test_name = test_name;
    r_f30.nfe = f30 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f30);

    std::cout << "Testbed 3 Results\n";
    for (const auto& [key, value] : testbed_3)
    {
        std::cout << "test name: " << value.test_name
                  << ", nfe: " << value.nfe << "\n";
    }

    test_name = "michalewicz_m5";
    int mic_5 = 0;
    d = 2;
    np = 30;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.1;
    lower = 0.0;
    upper = 3.14159265358979323846;
    vtr = -1.8012;
    Results r_mic_5{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_mic_5 = de::differentialEvolution(
            tbm::michalewicz_m5,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        mic_5 += r_mic_5.nfe;
    }

    r_mic_5.test_name = test_name;
    r_mic_5.nfe = mic_5 / testbed_trial_num;
    testbed_modern.emplace(test_name, r_mic_5);

    test_name = "michalewicz_m20";
    int mic_20 = 0;
    d = 2;
    np = 30;
    iteration_max = 10000;
    f = 0.6;
    cr = 0.2;
    lower = 0.0;
    upper = 3.14159265358979323846;
    vtr = -1.8012;
    Results r_mic_20{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_mic_20 = de::differentialEvolution(
            tbm::michalewicz_m20,
            d,
            np,
            iteration_max,
            f,
            cr,
            lower,
            upper,
            vtr
        );
        mic_20 += r_mic_20.nfe;
    }

    r_mic_20.test_name = test_name;
    r_mic_20.nfe = mic_20 / testbed_trial_num;
    testbed_modern.emplace(test_name, r_mic_20);

     std::cout << "Modern Testbed Results\n";
    for (const auto& [key, value] : testbed_modern)
    {
        std::cout << "test name: " << value.test_name
                  << ", nfe: " << value.nfe << "\n";
    }

}

void run_adaptive_de(std::map<std::string, Results>& f_to_res,
    std::map<std::string, Results>& testbed_2,
    std::map<std::string, Results>& testbed_3,
    std::map<std::string, Results>& testbed_modern)
{

    std::string test_name = "";
    int running_nfe_total = 0;
    int testbed_trial_num = 20;
    int d = 0;
    int np = 0;
    int iteration_max = 0;
    double lower;
    double upper;
    double vtr = 0.0;

    ////////////////////////////// TESTBED 1 BEGINS //////////////////////////////
    running_nfe_total = 0;
    test_name = "dejong f1";
    d = 3;
    np = 5;
    iteration_max = 100;
    lower = -5.12;
    upper = 5.12;
    vtr = 1e-6;
    Results r_f1{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f1 = a_de::differentialEvolution(
            tb1::dejong_f1,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f1.nfe;
    }

    r_f1.test_name = test_name;
    r_f1.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f1);

    running_nfe_total = 0;
    test_name = "dejong f2";
    d = 2;
    np = 10;
    iteration_max = 500;
    lower = -2.048;
    upper = 2.048;
    vtr = 1e-6;
    Results r_f2{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f2 = a_de::differentialEvolution(
            tb1::dejong_f2,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f2.nfe;
    }

    r_f2.test_name = test_name;
    r_f2.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f2);

    running_nfe_total = 0;
    test_name = "dejong f3";
    d = 5;
    np = 10;
    iteration_max = 500;
    lower = -5.12;
    upper = 5.12;
    vtr = 1e-6;
    Results r_f3{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f3 = a_de::differentialEvolution(
            tb1::dejong_f3,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f3.nfe;
    }

    r_f3.test_name = test_name;
    r_f3.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f3);

    running_nfe_total = 0;
    test_name = "dejong f4";
    d = 30;
    np = 10;
    iteration_max = 1000;
    lower = -1.28;
    upper = 1.28;
    vtr = 15.0;
    Results r_f4{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f4 = a_de::differentialEvolution(
            tb1::dejong_f4,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f4.nfe;
    }

    r_f4.test_name = test_name;
    r_f4.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f4);

    running_nfe_total = 0;
    test_name = "dejong f5";
    d = 2;
    np = 15;
    iteration_max = 2000;
    lower = -65.536;
    upper = 65.536;
    vtr = 0.998005;
    Results r_f5{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f5 = a_de::differentialEvolution(
            tb1::dejong_f5,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f5.nfe;
    }

    r_f5.test_name = test_name;
    r_f5.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f5);

    running_nfe_total = 0;
    test_name = "dejong f6";
    d = 4;
    np = 10;
    iteration_max = 1000;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1e-6;
    Results r_f6{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f6 = a_de::differentialEvolution(
            tb1::corana_f6,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f6.nfe;
    }

    r_f6.test_name = test_name;
    r_f6.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f6);

    running_nfe_total = 0;
    test_name = "dejong f7";
    d = 10;
    np = 25;
    iteration_max = 1000;
    lower = -400.0;
    upper = 400.0;
    vtr = 1e-6;
    Results r_f7{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f7 = a_de::differentialEvolution(
            tb1::griewangk,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f7.nfe;
    }

    r_f7.test_name = test_name;
    r_f7.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f7);

    running_nfe_total = 0;
    test_name = "dejong f8";
    d = 2;
    np = 10;
    iteration_max = 100;
    lower = 0.0;
    upper = 100.0;
    vtr = 1e-6;
    Results r_f8{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f8 = a_de::differentialEvolution(
            tb1::zimmermann_f8,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f8.nfe;
    }

    r_f8.test_name = test_name;
    r_f8.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f8);

    running_nfe_total = 0;
    test_name = "dejong f9_T8";
    d = 9;
    np = 60;
    iteration_max = 2000;
    lower = -100.0;
    upper = 100.0;
    vtr = 1e-6;
    Results r_f9_T8{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f9_T8 = a_de::differentialEvolution(
            tb1::polynomial_f9_T8,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f9_T8.nfe;
    }

    r_f9_T8.test_name = test_name;
    r_f9_T8.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f9_T8);

    running_nfe_total = 0;
    test_name = "dejong f9_T16";
    d = 17;
    np = 100;
    iteration_max = 2000;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1e-6;
    Results r_f9_T16{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f9_T16 = a_de::differentialEvolution(
            tb1::polynomial_f9_T16,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        running_nfe_total += r_f9_T16.nfe;
    }

    r_f9_T16.test_name = test_name;
    r_f9_T16.nfe = running_nfe_total / testbed_trial_num;
    f_to_res.emplace(test_name, r_f9_T16);

    std::cout << "Testbed 1 Results\n";
    for (const auto& [key, value] : f_to_res)
    {
        std::cout << "test name: " << value.test_name
                << ", nfe: " << value.nfe << "\n";
    }

    //////////////////////////////TESTBED 2 BEGINS//////////////////////////////

    test_name = "f11_D30";
    int f11_D30 = 0;
    d = 30;
    np = 20;
    iteration_max = 5000;
    lower = -1.0;
    upper = 1.0;
    vtr = 1e-10;
    Results r_f11_D30{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f11_D30 = a_de::differentialEvolution(
            tb2::hyper_ellipsoid,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f11_D30 += r_f11_D30.nfe;
    }

    r_f11_D30.test_name = test_name;
    r_f11_D30.nfe = f11_D30 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f11_D30);

    test_name = "f11_D100";
    int f11_D100 = 0;
    d = 100;
    np = 20;
    iteration_max = 5000;
    lower = -1.0;
    upper = 1.0;
    vtr = 1e-10;
    Results r_f11_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f11_D100 = a_de::differentialEvolution(
            tb2::hyper_ellipsoid,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f11_D100 += r_f11_D100.nfe;
    }

    r_f11_D100.test_name = test_name;
    r_f11_D100.nfe = f11_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f11_D100);

    test_name = "kat_10";
    int kat_10 = 0;
    d = 10;
    np = 15;
    iteration_max = 5000;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1.05;
    Results r_kat_10{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_kat_10 = a_de::differentialEvolution(
            tb2::katsuura,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        kat_10 += r_kat_10.nfe;
    }

    r_kat_10.test_name = test_name;
    r_kat_10.nfe = kat_10 / testbed_trial_num;
    testbed_2.emplace(test_name, r_kat_10);

    test_name = "kat_30";
    int kat_30 = 0;
    d = 30;
    np = 15;
    iteration_max = 5000;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1.05;
    Results r_kat_30{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_kat_30 = a_de::differentialEvolution(
            tb2::katsuura,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        kat_30 += r_kat_30.nfe;
    }

    r_kat_30.test_name = test_name;
    r_kat_30.nfe = kat_30 / testbed_trial_num;
    testbed_2.emplace(test_name, r_kat_30);

        test_name = "f13_D20";
    int f13_D20 = 0;
    d = 20;
    np = 25;
    iteration_max = 5000;
    lower = -600.0;
    upper = 600.0;
    vtr = 0.9;
    Results r_f13_D20{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f13_D20 = a_de::differentialEvolution(
            tb2::rastrigin,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f13_D20 += r_f13_D20.nfe;
    }

    r_f13_D20.test_name = test_name;
    r_f13_D20.nfe = f13_D20 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f13_D20);

    test_name = "f13_D100";
    int f13_D100 = 0;
    d = 100;
    np = 25;
    iteration_max = 10000;
    lower = -600.0;
    upper = 600.0;
    vtr = 0.9;
    Results r_f13_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f13_D100 = a_de::differentialEvolution(
            tb2::rastrigin,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f13_D100 += r_f13_D100.nfe;
    }

    r_f13_D100.test_name = test_name;
    r_f13_D100.nfe = f13_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f13_D100);

    test_name = "f14_D20";
    int f14_D20 = 0;
    d = 20;
    np = 20;
    iteration_max = 5000;
    lower = -600.0;
    upper = 600.0;
    vtr = 1e-3;
    Results r_f14_D20{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f14_D20 = a_de::differentialEvolution(
            tb2::griewank_f14,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f14_D20 += r_f14_D20.nfe;
    }

    r_f14_D20.test_name = test_name;
    r_f14_D20.nfe = f14_D20 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f14_D20);

    test_name = "f14_D100";
    int f14_D100 = 0;
    d = 100;
    np = 20;
    iteration_max = 10000;
    lower = -600.0;
    upper = 600.0;
    vtr = 1e-3;
    Results r_f14_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f14_D100 = a_de::differentialEvolution(
            tb2::griewank_f14,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f14_D100 += r_f14_D100.nfe;
    }

    r_f14_D100.test_name = test_name;
    r_f14_D100.nfe = f14_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f14_D100);

    test_name = "f15_D30";
    int f15_D30 = 0;
    d = 30;
    np = 20;
    iteration_max = 5000;
    lower = -30.0;
    upper = 30.0;
    vtr = 1e-3;
    Results r_f15_D30{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f15_D30 = a_de::differentialEvolution(
            tb2::ackley,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f15_D30 += r_f15_D30.nfe;
    }

    r_f15_D30.test_name = test_name;
    r_f15_D30.nfe = f15_D30 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f15_D30);

    test_name = "f15_D100";
    int f15_D100 = 0;
    d = 100;
    np = 20;
    iteration_max = 10000;
    lower = -30.0;
    upper = 30.0;
    vtr = 1e-3;
    Results r_f15_D100{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_f15_D100 = a_de::differentialEvolution(
            tb2::ackley,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );

        f15_D100 += r_f15_D100.nfe;
    }

    r_f15_D100.test_name = test_name;
    r_f15_D100.nfe = f15_D100 / testbed_trial_num;
    testbed_2.emplace(test_name, r_f15_D100);

    std::cout << "Testbed 2 Results\n";
    for (const auto& [key, value] : testbed_2)
    {
        std::cout << "test name: " << value.test_name
                  << ", nfe: " << value.nfe << "\n";
    }

    ////////////////////////////// TESTBED 3 BEGINS //////////////////////////////
    int testbed_3_trial_num = 1000;

    test_name = "f16";
    int f16 = 0;
    d = 1;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f16{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f16 = a_de::differentialEvolution(
            tb3::goldstein,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f16 += r_f16.nfe;
    }
    r_f16.test_name = test_name;
    r_f16.nfe = f16 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f16);

    test_name = "f17";
    int f17 = 0;
    d = 1;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = -12.8708855;
    Results r_f17{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f17 = a_de::differentialEvolution(
            tb3::penalized_shubert,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f17 += r_f17.nfe;
    }
    r_f17.test_name = test_name;
    r_f17.nfe = f17 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f17);

    test_name = "f18";
    int f18 = 0;
    d = 2;
    np = 20;
    iteration_max = 10000;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;
    Results r_f18{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f18 = a_de::differentialEvolution(
            tb3::penalized_shubert_2d,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f18 += r_f18.nfe;
    }
    r_f18.test_name = test_name;
    r_f18.nfe = f18 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f18);

    test_name = "f19_b05";
    int f19_b05 = 0;
    d = 2;
    np = 40;
    iteration_max = 10000;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;
    Results r_f19_b05{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f19_b05 = a_de::differentialEvolution(
            tb3::modified_shubert_b05,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f19_b05 += r_f19_b05.nfe;
    }
    r_f19_b05.test_name = test_name;
    r_f19_b05.nfe = f19_b05 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f19_b05);

    test_name = "f19_b10";
    int f19_b10 = 0;
    d = 2;
    np = 40;
    iteration_max = 10000;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;
    Results r_f19_b10{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f19_b10 = a_de::differentialEvolution(
            tb3::modified_shubert_b10,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f19_b10 += r_f19_b10.nfe;
    }
    r_f19_b10.test_name = test_name;
    r_f19_b10.nfe = f19_b10 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f19_b10);

    test_name = "f20";
    int f20 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = -1.0316285;
    Results r_f20{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f20 = a_de::differentialEvolution(
            tb3::six_hump_camel,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f20 += r_f20.nfe;
    }
    r_f20.test_name = test_name;
    r_f20.nfe = f20 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f20);

    test_name = "f21_D2";
    int f21_D2 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f21_D2{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f21_D2 = a_de::differentialEvolution(
            tb3::f21,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f21_D2 += r_f21_D2.nfe;
    }
    r_f21_D2.test_name = test_name;
    r_f21_D2.nfe = f21_D2 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f21_D2);

    test_name = "f21_D3";
    int f21_D3 = 0;
    d = 3;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f21_D3{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f21_D3 = a_de::differentialEvolution(
            tb3::f21,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f21_D3 += r_f21_D3.nfe;
    }
    r_f21_D3.test_name = test_name;
    r_f21_D3.nfe = f21_D3 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f21_D3);

    test_name = "f21_D4";
    int f21_D4 = 0;
    d = 4;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f21_D4{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f21_D4 = a_de::differentialEvolution(
            tb3::f21,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f21_D4 += r_f21_D4.nfe;
    }
    r_f21_D4.test_name = test_name;
    r_f21_D4.nfe = f21_D4 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f21_D4);

    test_name = "f22_D5";
    int f22_D5 = 0;
    d = 5;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f22_D5{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f22_D5 = a_de::differentialEvolution(
            tb3::f22,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f22_D5 += r_f22_D5.nfe;
    }
    r_f22_D5.test_name = test_name;
    r_f22_D5.nfe = f22_D5 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f22_D5);

    test_name = "f22_D8";
    int f22_D8 = 0;
    d = 8;
    np = 20;
    iteration_max = 8000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f22_D8{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f22_D8 = a_de::differentialEvolution(
            tb3::f22,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f22_D8 += r_f22_D8.nfe;
    }
    r_f22_D8.test_name = test_name;
    r_f22_D8.nfe = f22_D8 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f22_D8);

    test_name = "f22_D10";
    int f22_D10 = 0;
    d = 10;
    np = 20;
    iteration_max = 10000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f22_D10{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f22_D10 = a_de::differentialEvolution(
            tb3::f22,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f22_D10 += r_f22_D10.nfe;
    }
    r_f22_D10.test_name = test_name;
    r_f22_D10.nfe = f22_D10 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f22_D10);

    test_name = "f23_D2";
    int f23_D2 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f23_D2{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f23_D2 = a_de::differentialEvolution(
            tb3::f23,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f23_D2 += r_f23_D2.nfe;
    }
    r_f23_D2.test_name = test_name;
    r_f23_D2.nfe = f23_D2 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f23_D2);

    test_name = "f23_D3";
    int f23_D3 = 0;
    d = 3;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f23_D3{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f23_D3 = a_de::differentialEvolution(
            tb3::f23,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f23_D3 += r_f23_D3.nfe;
    }
    r_f23_D3.test_name = test_name;
    r_f23_D3.nfe = f23_D3 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f23_D3);

    test_name = "f23_D4";
    int f23_D4 = 0;
    d = 4;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f23_D4{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f23_D4 = a_de::differentialEvolution(
            tb3::f23,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f23_D4 += r_f23_D4.nfe;
    }
    r_f23_D4.test_name = test_name;
    r_f23_D4.nfe = f23_D4 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f23_D4);

    test_name = "f24_D5";
    int f24_D5 = 0;
    d = 5;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f24_D5{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f24_D5 = a_de::differentialEvolution(
            tb3::f24,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f24_D5 += r_f24_D5.nfe;
    }
    r_f24_D5.test_name = test_name;
    r_f24_D5.nfe = f24_D5 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f24_D5);

    test_name = "f24_D6";
    int f24_D6 = 0;
    d = 6;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f24_D6{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f24_D6 = a_de::differentialEvolution(
            tb3::f24,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f24_D6 += r_f24_D6.nfe;
    }
    r_f24_D6.test_name = test_name;
    r_f24_D6.nfe = f24_D6 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f24_D6);

    test_name = "f24_D7";
    int f24_D7 = 0;
    d = 7;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f24_D7{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f24_D7 = a_de::differentialEvolution(
            tb3::f24,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f24_D7 += r_f24_D7.nfe;
    }
    r_f24_D7.test_name = test_name;
    r_f24_D7.nfe = f24_D7 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f24_D7);

    test_name = "f25";
    int f25 = 0;
    d = 1;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = -0.3523861;
    Results r_f25{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f25 = a_de::differentialEvolution(
            tb3::f25,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f25 += r_f25.nfe;
    }
    r_f25.test_name = test_name;
    r_f25.nfe = f25 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f25);

    test_name = "f26";
    int f26 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = -0.3523861;
    Results r_f26{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f26 = a_de::differentialEvolution(
            tb3::f26,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f26 += r_f26.nfe;
    }
    r_f26.test_name = test_name;
    r_f26.nfe = f26 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f26);

    test_name = "f27";
    int f27 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f27{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f27 = a_de::differentialEvolution(
            tb3::f27,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f27 += r_f27.nfe;
    }
    r_f27.test_name = test_name;
    r_f27.nfe = f27 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f27);

    test_name = "f28_n1";
    int f28_n1 = 0;
    d = 2;
    np = 20;
    iteration_max = 5000;
    lower = -10.0;
    upper = 10.0;
    vtr = 0.4074616;
    Results r_f28_n1{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n1 = a_de::differentialEvolution(
            tb3::f28_n1,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f28_n1 += r_f28_n1.nfe;
    }
    r_f28_n1.test_name = test_name;
    r_f28_n1.nfe = f28_n1 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n1);

    test_name = "f28_n2";
    int f28_n2 = 0;
    vtr = 18.0586967;
    Results r_f28_n2{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n2 = a_de::differentialEvolution(
            tb3::f28_n2,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f28_n2 += r_f28_n2.nfe;
    }
    r_f28_n2.test_name = test_name;
    r_f28_n2.nfe = f28_n2 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n2);

    test_name = "f28_n3";
    int f28_n3 = 0;
    vtr = 227.7657500;
    Results r_f28_n3{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n3 = a_de::differentialEvolution(
            tb3::f28_n3,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f28_n3 += r_f28_n3.nfe;
    }
    r_f28_n3.test_name = test_name;
    r_f28_n3.nfe = f28_n3 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n3);

    test_name = "f28_n4";
    int f28_n4 = 0;
    vtr = 2429.4147670;
    Results r_f28_n4{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n4 = a_de::differentialEvolution(
            tb3::f28_n4,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f28_n4 += r_f28_n4.nfe;
    }
    r_f28_n4.test_name = test_name;
    r_f28_n4.nfe = f28_n4 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n4);

    test_name = "f28_n5";
    int f28_n5 = 0;
    vtr = 24776.5183423;
    Results r_f28_n5{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n5 = a_de::differentialEvolution(
            tb3::f28_n5,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f28_n5 += r_f28_n5.nfe;
    }
    r_f28_n5.test_name = test_name;
    r_f28_n5.nfe = f28_n5 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n5);

    test_name = "f28_n6";
    int f28_n6 = 0;
    vtr = 249293.0182630;
    Results r_f28_n6{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f28_n6 = a_de::differentialEvolution(
            tb3::f28_n6,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f28_n6 += r_f28_n6.nfe;
    }
    r_f28_n6.test_name = test_name;
    r_f28_n6.nfe = f28_n6 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f28_n6);

    test_name = "f29";
    int f29 = 0;
    d = 5;
    np = 20;
    iteration_max = 10000;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;
    Results r_f29{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f29 = a_de::differentialEvolution(
            tb3::f29,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f29 += r_f29.nfe;
    }
    r_f29.test_name = test_name;
    r_f29.nfe = f29 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f29);

    test_name = "f30";
    int f30 = 0;
    d = 2;
    np = 30;
    iteration_max = 10000;
    lower = -1.0e4;
    upper = 1.0e4;
    vtr = 0.000888085;
    Results r_f30{};

    for (int i = 0; i < testbed_3_trial_num; i++)
    {
        r_f30 = a_de::differentialEvolution(
            tb3::f30,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        f30 += r_f30.nfe;
    }
    r_f30.test_name = test_name;
    r_f30.nfe = f30 / testbed_3_trial_num;
    testbed_3.emplace(test_name, r_f30);

    std::cout << "Testbed 3 Results\n";
    for (const auto& [key, value] : testbed_3)
    {
        std::cout << "test name: " << value.test_name
                  << ", nfe: " << value.nfe << "\n";
    }

    ////////////////////////////// MODERN TESTBED BEGINS //////////////////////////////

    test_name = "michalewicz_m5";
    int mic_5 = 0;
    d = 2;
    np = 30;
    iteration_max = 10000;
    lower = 0.0;
    upper = 3.14159265358979323846;
    vtr = -1.8012;
    Results r_mic_5{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_mic_5 = a_de::differentialEvolution(
            tbm::michalewicz_m5,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        mic_5 += r_mic_5.nfe;
    }

    r_mic_5.test_name = test_name;
    r_mic_5.nfe = mic_5 / testbed_trial_num;
    testbed_modern.emplace(test_name, r_mic_5);

    test_name = "michalewicz_m20";
    int mic_20 = 0;
    d = 2;
    np = 30;
    iteration_max = 10000;
    lower = 0.0;
    upper = 3.14159265358979323846;
    vtr = -1.8012;
    Results r_mic_20{};

    for (int i = 0; i < testbed_trial_num; i++)
    {
        r_mic_20 = a_de::differentialEvolution(
            tbm::michalewicz_m20,
            d,
            np,
            iteration_max,
            lower,
            upper,
            vtr
        );
        mic_20 += r_mic_20.nfe;
    }

    r_mic_20.test_name = test_name;
    r_mic_20.nfe = mic_20 / testbed_trial_num;
    testbed_modern.emplace(test_name, r_mic_20);

    std::cout << "Modern Testbed Results\n";
    for (const auto& [key, value] : testbed_modern)
    {
        std::cout << "test name: " << value.test_name
                  << ", nfe: " << value.nfe << "\n";
    }
}