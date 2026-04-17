#include <iostream>
#include <vector>
#include <map>
#include "DE.hpp"
#include "a_DE.hpp"
#include "TestBed_1.hpp"
#include "TestBed_2.hpp"
#include "TestBed_3.hpp"
#include "TestBed_Modern.hpp"

//NON-ADAPTIVE testing 
//Testing for Testbeds 1 through 3 as well as Modern
//All results stored in a std::map 
int main()
{
    std::map<std::string, Results> f_to_res{};
    std::map<std::string, Results> testbed_2{};
    std::map<std::string, Results> testbed_3{};
    std::map<std::string, Results> testbed_modern{};

    std::string test_name = "";
    int d = 0;
    int np = 0;
    int iteration_max = 0;
    double f = 0.0;
    double cr = 0.0;
    double lower;
    double upper;
    double vtr = 0.0;

    //TESTBED 1 BEGINS-----------------------------------------------------
    //dejong_f1 required specs
    test_name = "f1";
    d = 3;
    np = 5;
    iteration_max = 100;
    f = 0.9;
    cr = 0.1;
    lower = -5.12;
    upper = 5.12;
    vtr = 1e-6;

    //dejong f1 test
    Results r_f1 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f1); 
   
    //dejong f2 test
    test_name = "f2";
    d = 2;
    np = 10;
    f = 0.9;
    cr = 0.9;
    lower = -2.048;
    upper = 2.048;
    vtr = 1e-6;
    iteration_max = 500;

    Results r_f2 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f2); 

    //dejong f3 test
    test_name = "f3";
    d = 5;
    np = 5;
    f = 0.9;
    cr = 0.0;
    lower = -2.048;
    upper = 2.048;
    vtr = 1e-6;
    iteration_max = 500;

    Results r_f3 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f3); 

    //dejong f4 test
    test_name = "f4";
    d = 30;
    np = 10;
    f = 0.9;
    cr = 0.0;
    lower = -1.28;
    upper = 1.28;
    vtr = 1e-6;
    iteration_max = 1000;

    Results r_f4 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f4); 

    //dejong f5 test (Shekel’s Foxholes)
    test_name = "f5";
    d = 2;
    np = 15;
    f = 0.9;
    cr = 0.0;
    lower = -65.536;
    upper = 65.536;
    vtr = 1e-6;
    iteration_max = 2000;

    Results r_f5 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f5); 

    //dejong f6 test (Corana)
    test_name = "f6";
    d = 4;
    np = 10;
    f = 0.5;
    cr = 0.0;
    lower = -1000;
    upper = 1000;
    vtr = 1e-6;
    iteration_max = 1000;

    Results r_f6 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f6); 

    //dejong f7 test (Griewank)
    test_name = "f7";
    d = 10;
    np = 25;
    f = 0.5;
    cr = 0.2;
    lower = -400;
    upper = 400;
    vtr = 1e-6;
    iteration_max = 1000;

    Results r_f7 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f7); 

    //dejong f8 test (Zimmermann)
    test_name = "f8";
    d = 2;
    np = 10;
    f = 0.9;
    cr = 0.9;
    lower = -400;
    upper = 400;
    vtr = 1e-6;
    iteration_max = 1000;

    Results r_f8 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f8); 

    //dejong f9 test (Polynomial T8)
    test_name = "f9_T8";
    d = 9; // 2k+1 with k=4
    np = 60;
    f = 0.6;
    cr = 1.0;
    lower = -100;
    upper = 100;
    vtr = 1e-6;
    iteration_max = 2000;

    Results r_f9_T8 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f9_T8); 

    // dejong f9 test (Polynomial T16)
    test_name = "f9_T16";
    d = 17;
    np = 100;
    f = 0.6;
    cr = 1.0;
    lower = -100;
    upper = 100;
    vtr = 1e-6;
    iteration_max = 2000;

    Results r_f9_T16 = de::differentialEvolution(
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

    f_to_res.emplace(test_name, r_f9_T16); 

    std::cout << "-----Test Bed 1 RESULTS-----\n";

    for (const auto& [name, res] : f_to_res)
    {
        std::cout << name << ":\n";

        std::cout << "  Best cost: " << res.best_cost << "\n";

        std::cout << "  Best vector: ";
        for (double v : res.best_vector)
        {
            std::cout << v << " ";
        }
        std::cout << "\n";

        std::cout << "  NFE: " << res.nfe << "\n";
        std::cout << "----------------------------------------\n";
    }

    test_name = "f11_D30";
    d = 30;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1.0;
    upper = 1.0;
    vtr = 1e-10;

    Results r_f11_D30 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_f11_D30);

    test_name = "f11_D100";
    d = 100;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1.0;
    upper = 1.0;
    vtr = 1e-10;

    Results r_f11_D100 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_f11_D100);

    test_name = "kat_10";
    d = 10;
    np = 15;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1.05;

    Results r_kat = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_kat);
    
    test_name = "kat_30";
    d = 30;
    np = 15;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -1000.0;
    upper = 1000.0;
    vtr = 1.05;

    Results r_kat_30 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_kat_30);

    test_name = "f14_D20";
    d = 20;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -600.0;
    upper = 600.0;
    vtr = 1e-3;

    Results r_f14_D20 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_f14_D20);

    test_name = "f14_D100";
    d = 100;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.1;
    lower = -600.0;
    upper = 600.0;
    vtr = 1e-3;

    Results r_f14_D100 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_f14_D100);

    test_name = "f15_D30";
    d = 30;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.1;
    lower = -30.0;
    upper = 30.0;
    vtr = 1e-3;

    Results r_f15_D30 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_f15_D30);

    test_name = "f15_D100";
    d = 100;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.1;
    lower = -30.0;
    upper = 30.0;
    vtr = 1e-3;

    Results r_f15_D100 = de::differentialEvolution(
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

    testbed_2.emplace(test_name, r_f15_D100);

    std::cout << "-----Test Bed 2 RESULTS-----\n";

    for (const auto& [name, res] : testbed_2)
    {
        std::cout << name << ":\n";

        std::cout << "  Best cost: " << res.best_cost << "\n";

        std::cout << "  Best vector: ";
        for (double v : res.best_vector)
        {
            std::cout << v << " ";
        }
        std::cout << "\n";

        std::cout << "  NFE: " << res.nfe << "\n";
        std::cout << "----------------------------------------\n";
    }

    //TESTBED 3 BEGINS-----------------------------------------------------
    test_name = "f16";
    d = 1;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f16 = de::differentialEvolution(
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

    testbed_3.emplace(test_name, r_f16);

    test_name = "f17";
    d = 1;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -12.8708855;   // paper uses relative-accuracy target; use your chosen practical VTR if needed

    Results r_f17 = de::differentialEvolution(
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

    testbed_3.emplace(test_name, r_f17);

    test_name = "f18";
    d = 2;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;

    Results r_f18 = de::differentialEvolution(
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

    testbed_3.emplace(test_name, r_f18);

    test_name = "f19_b05";
    d = 2;
    np = 40;
    iteration_max = 10000;
    f = 1.0;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;

    Results r_f19_b05 = de::differentialEvolution(
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
    
    testbed_3.emplace(test_name, r_f19_b05);

    // f19 beta = 1.0  (wrapper needed)
    test_name = "f19_b10";
    d = 2;
    np = 40;
    iteration_max = 10000;
    f = 1.0;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -186.7309088;

    Results r_f19_b10 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f19_b10);

    // f20 Six-hump Camel
    test_name = "f20";
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -1.0316285;

    Results r_f20 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f20);

    // f21 D = 2
    test_name = "f21_D2";
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f21_D2 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f21_D2);

    // f21 D = 3
    test_name = "f21_D3";
    d = 3;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f21_D3 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f21_D3);

    // f21 D = 4
    test_name = "f21_D4";
    d = 4;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f21_D4 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f21_D4);

    // f22 D = 5
    test_name = "f22_D5";
    d = 5;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f22_D5 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f22_D5);

    // f22 D = 8
    test_name = "f22_D8";
    d = 8;
    np = 20;
    iteration_max = 8000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f22_D8 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f22_D8);

    // f22 D = 10
    test_name = "f22_D10";
    d = 10;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f22_D10 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f22_D10);

    // f23 D = 2
    test_name = "f23_D2";
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f23_D2 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f23_D2);

    // f23 D = 3
    test_name = "f23_D3";
    d = 3;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f23_D3 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f23_D3);

    // f23 D = 4
    test_name = "f23_D4";
    d = 4;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f23_D4 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f23_D4);

    // f24 D = 5
    test_name = "f24_D5";
    d = 5;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f24_D5 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f24_D5);

    // f24 D = 6
    test_name = "f24_D6";
    d = 6;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f24_D6 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f24_D6);

    // f24 D = 7
    test_name = "f24_D7";
    d = 7;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f24_D7 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f24_D7);

    // f25
    test_name = "f25";
    d = 1;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -0.3523861;

    Results r_f25 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f25);

    // f26
    test_name = "f26";
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = -0.3523861;

    Results r_f26 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f26);

    // f27
    test_name = "f27";
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f27 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f27);

    // f28 n = 1..6 (wrappers needed)
    test_name = "f28_n1";
    d = 2;
    np = 20;
    iteration_max = 5000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 0.4074616;

    Results r_f28_n1 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f28_n1);

    test_name = "f28_n2";
    vtr = 18.0586967;
    Results r_f28_n2 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f28_n2);

    test_name = "f28_n3";
    vtr = 227.7657500;
    Results r_f28_n3 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f28_n3);

    test_name = "f28_n4";
    vtr = 2429.4147670;
    Results r_f28_n4 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f28_n4);

    test_name = "f28_n5";
    vtr = 24776.5183423;
    Results r_f28_n5 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f28_n5);

    test_name = "f28_n6";
    vtr = 249293.0182630;
    Results r_f28_n6 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f28_n6);

    // f29
    test_name = "f29";
    d = 5;
    np = 20;
    iteration_max = 10000;
    f = 0.5;
    cr = 0.0;
    lower = -10.0;
    upper = 10.0;
    vtr = 1e-6;

    Results r_f29 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f29);

    // f30
    test_name = "f30";
    d = 2;
    np = 30;
    iteration_max = 10000;
    f = 0.5;
    cr = 1.0;
    lower = -1.0e4;
    upper = 1.0e4;
    vtr = 0.000888085;

    Results r_f30 = de::differentialEvolution(
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
    testbed_3.emplace(test_name, r_f30);

    
    std::cout << "-----Test Bed 3 RESULTS-----\n";
    for (const auto& [name, res] : testbed_3)
    {
        std::cout << name << ":\n";

        std::cout << "  Best cost: " << res.best_cost << "\n";

        std::cout << "  Best vector: ";
        for (double v : res.best_vector)
        {
            std::cout << v << " ";
        }
        std::cout << "\n";

        std::cout << "  NFE: " << res.nfe << "\n";
        std::cout << "----------------------------------------\n";
    }

    test_name = "rastrigin_D10";
    d = 10;
    np = 50;              
    iteration_max = 2000;
    f = 0.5;
    cr = 0.9;            
    lower = -5.12;
    upper = 5.12;
    vtr = 1e-6;

    Results r_rastrigin = de::differentialEvolution(
        tbm::rastrigin,
        d,
        np,
        iteration_max,
        f,
        cr,
        lower,
        upper,
        vtr
    );

    testbed_modern.emplace(test_name, r_rastrigin);

    test_name = "michalewicz_D10_m10";
    d = 10;
    np = 50;              
    iteration_max = 5000; 
    f = 0.6;
    cr = 0.9;
    lower = 0.0;
    upper = 3.14159265358979323846;
    vtr = -9.0;       

    Results r_michalewicz = de::differentialEvolution(
        tbm::michalewicz_m10,
        d,
        np,
        iteration_max,
        f,
        cr,
        lower,
        upper,
        vtr
    );

    f_to_res.emplace(test_name, r_michalewicz);
}