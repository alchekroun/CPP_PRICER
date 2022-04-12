#include "BlackScholesMerton.hpp"

#include <utility>

#include "utils.hpp"


std::pair<double, double> get_d1_d2(double const spot, double const strike, double const vol, double const rate, double const dividend, double const maturity) {
	double const d1 = (log(spot / strike) + maturity * (rate - dividend + pow(vol, 2) / 2)) / (vol * sqrt(maturity));
	double const d2 = d1 - vol * sqrt(maturity);

	return { d1, d2 };
}


double pricer::bsm::get_option_price(bool const is_call, double const spot, double const strike, double const rate, double const volatility, double const maturity) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, 0, maturity);
	double price = 0;
	if (is_call) {
		price = spot * normal_cdf(d1_d2.first) - strike * exp(-rate * maturity) * normal_cdf(d1_d2.second);
	}
	else {
		price = strike * exp(-rate * maturity) * normal_cdf(-d1_d2.second) - spot * normal_cdf(-d1_d2.first);
	}
	return price;
}

double pricer::bsm::get_option_price_dividend(bool const is_call, double const spot, double const strike, double const rate, double const dividend, double const volatility, double const maturity) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);
	double price = 0;
	if (is_call) {
		price = spot * exp(-dividend * maturity) * normal_cdf(d1_d2.first) - strike * exp(-rate * maturity) * normal_cdf(d1_d2.second);
	}
	else {
		price = strike * exp(-rate * maturity) * normal_cdf(-d1_d2.second) - spot * exp(-dividend * maturity) * normal_cdf(-d1_d2.first);
	}
	return price;
}

double pricer::bsm::get_delta(bool const is_call, double const spot, double const strike, double const rate, double const dividend, double const volatility, double const maturity) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, 0, maturity);

	return is_call ? exp(-dividend * maturity) * normal_cdf(d1_d2.first) : exp(-dividend * maturity) * (normal_cdf(d1_d2.first) - 1);
}

double pricer::bsm::get_gamma(double const spot, double const strike, double const rate, double const dividend, double const volatility, double const maturity) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, 0, maturity);

	return exp(-dividend * maturity) / (spot * volatility * sqrt(maturity)) * normal_cdf(d1_d2.first);
}

double pricer::bsm::get_vega(bool const is_call, double const spot, double const strike, double const rate, double const dividend, double const volatility, double const maturity) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, 0, maturity);
	auto const d1_used = is_call ? d1_d2.first : -d1_d2.first;

	// TODO : get THE PDF
	return 0.0;
}


