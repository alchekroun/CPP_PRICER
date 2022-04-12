#pragma once

double get_payoff(bool const is_call, double const spot, double const strike);

double normal_cdf(double x);