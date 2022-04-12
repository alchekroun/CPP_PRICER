#pragma once
#include <vector>

double get_payoff(bool const is_call, double const spot, double const strike);

double normal_cdf(double x);

double mean(std::vector<double> const& values);

double stdd(std::vector<double> const& values);