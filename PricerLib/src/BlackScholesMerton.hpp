#pragma once

namespace pricer {
	namespace bsm {
		double get_option_price(bool is_call, double spot, double strike, double rate, double volatility, double maturity);

		double get_option_price_dividend(bool is_call, double spot, double strike, double rate, double dividend, double volatility, double maturity);

		double get_delta(bool is_call, double spot, double strike, double rate, double dividend, double volatility, double maturity);

		double get_gamma(double spot, double strike, double rate, double dividend, double volatility, double maturity);

		double get_theta();

		double get_vega(bool is_call, double spot, double strike, double rate, double dividend, double volatility, double maturity);

		double get_rho();
	}
}
