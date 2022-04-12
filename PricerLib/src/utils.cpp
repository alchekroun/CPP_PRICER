#include "utils.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

double get_payoff(bool const is_call, double const spot, double const strike) {
	return is_call ? std::max(spot - strike, 0.0) : std::max(strike - spot, 0.0);
}

double normal_cdf(double const x) {
	return std::erfc(-x / std::sqrt(x)) / 2;
}

double mean(std::vector<double> const& values) {
	return std::accumulate(std::begin(values), std::end(values), 0.0) / static_cast<double>(values.size());
}

double stdd(std::vector<double> const& values) {
	auto const mean_values = mean(values);
	std::vector<double> diff(values.size());
	std::transform(begin(values), end(values), begin(diff),
		[&mean_values](double const x) {
			return x - mean_values;
		});

	double const sq_sum = std::inner_product(begin(diff), end(diff), begin(diff), 0.0);
	return std::sqrt(sq_sum / static_cast<double>(values.size()));
}
