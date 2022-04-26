#include "Forward.hpp"

#include <cmath>

double pricer::forward::get_price(double const rate, double const s0, double const maturity, double const q, double const dividend, int const dividend_per_year) {
	double const price = s0 * exp(rate * maturity);

	if (dividend < 0.00001) {
		return price;
	}

	double dividend_yield = 0;

	for (auto i = 0.; i < dividend_per_year * maturity; i++) {
		dividend_yield += dividend * exp((rate - q) * (maturity - i/dividend_per_year));
	}

	return price - dividend_yield;
}

