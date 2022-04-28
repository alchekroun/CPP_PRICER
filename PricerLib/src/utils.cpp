#include "utils.hpp"

#include <algorithm>
#include <cmath>
#include <numeric>

double pricer::utils::get_payoff(bool const is_call, double const spot, double const strike) {
	return is_call ? std::max(spot - strike, 0.0) : std::max(strike - spot, 0.0);
}

double pricer::utils::normal_cdf(double const x) {
	return 0.5 * std::erfc(-x * sqrt(0.5));
}

double pricer::utils::normal_pdf(double const x, double const mean, double const std) {
	double const pi = 2 * asin(1.0);
	return exp(-pow((x - mean) / std, 2) / 2) / (std * sqrt(2 * pi));
}

double pricer::utils::mean(std::vector<double> const& values) {
	return std::accumulate(std::begin(values), std::end(values), 0.0) / static_cast<double>(values.size());
}

double pricer::utils::stdd(std::vector<double> const& values) {
	auto const mean_values = mean(values);
	std::vector<double> diff(values.size());
	std::transform(begin(values), end(values), begin(diff),
		[&mean_values](double const x) {
			return x - mean_values;
		});

	double const sq_sum = std::inner_product(begin(diff), end(diff), begin(diff), 0.0);
	return std::sqrt(sq_sum / static_cast<double>(values.size()));
}
