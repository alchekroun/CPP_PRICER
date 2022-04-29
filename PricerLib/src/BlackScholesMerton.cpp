#include "BlackScholesMerton.hpp"

#include <iostream>
#include <utility>

#include "utils.hpp"


std::pair<double, double> get_d1_d2(double const spot, double const strike, double const vol, double const rate, double const dividend, double const maturity) {
	double const d1 = (log(spot / strike) + maturity * (rate - dividend + pow(vol, 2) / 2)) / (vol * sqrt(maturity));
	double const d2 = d1 - vol * sqrt(maturity);

	return { d1, d2 };
}


double pricer::bsm::get_option_price(bool const is_call, double const spot, double const strike, double const rate, double const volatility, double const maturity, double const dividend) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);
	if (is_call) {
		return spot * exp(-dividend * maturity) * utils::normal_cdf(d1_d2.first) - strike * exp(-rate * maturity) * utils::normal_cdf(d1_d2.second);
	}
	return strike * exp(-rate * maturity) * utils::normal_cdf(-d1_d2.second) - spot * exp(-dividend * maturity) * utils::normal_cdf(-d1_d2.first);
}

double pricer::bsm::get_delta(bool const is_call, double const spot, double const strike, double const rate, double const volatility, double const maturity, double const dividend) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);

	return is_call ? exp(-dividend * maturity) * utils::normal_cdf(d1_d2.first) : exp(-dividend * maturity) * (utils::normal_cdf(d1_d2.first) - 1);
}

double pricer::bsm::get_gamma(double const spot, double const strike, double const rate, double const volatility, double const maturity, double const dividend) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);

	return exp(-dividend * maturity) * utils::normal_pdf(d1_d2.first) / (spot * volatility * sqrt(maturity));
}

double pricer::bsm::get_theta(bool const is_call, double const spot, double const strike, double const rate, double const volatility, double const maturity, double const dividend) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);
	auto const d2_used = is_call ? d1_d2.second : -d1_d2.second;

	return -(spot * utils::normal_pdf(d1_d2.first) * volatility * exp(-dividend * maturity) / (2 * sqrt(maturity))) + dividend * spot * utils::normal_cdf(d1_d2.first) * exp(-dividend * maturity) - rate * strike * exp(-rate * maturity) * utils::normal_cdf(d2_used);
}

double pricer::bsm::get_vega(bool const is_call, double const spot, double const strike, double const rate, double const volatility, double const maturity, double const dividend) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);
	auto const d1_used = is_call ? d1_d2.first : -d1_d2.first;

	return spot * exp(-dividend * maturity) * sqrt(maturity) * utils::normal_pdf(d1_used);
}

double pricer::bsm::get_rho(bool const is_call, double const spot, double const strike, double const rate, double const volatility, double const maturity, double const dividend) {
	auto const d1_d2 = get_d1_d2(spot, strike, volatility, rate, dividend, maturity);
	auto const d2_used = is_call ? d1_d2.second : -d1_d2.second;
	auto const rho = strike * maturity * exp(-rate * maturity) * utils::normal_cdf(d2_used);

	return rho * (is_call ? 1 : -1);
}


