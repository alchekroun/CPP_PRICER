#include <algorithm>
#include <cmath>
#include "utils.hpp"

double get_payoff(bool const is_call, double const spot, double const strike) {
	return is_call ? std::max(spot - strike, 0.0) : std::max(strike - spot, 0.0);
}

double normal_cdf(double const x) {
	return std::erfc(-x / std::sqrt(x)) / 2;
}
