#pragma once

namespace pricer {
	namespace binomial {
		double get_option_price(bool is_euro, bool is_call, int periods, double s0, double strike, double maturity, double rate, double volatility);
		double get_up_coeff(double volatility, int periods, double maturity);
		double get_down_coeff(double volatility, int periods, double maturity);
		double get_neutral_risk_proba(double rate, double maturity, double up_coeff, double down_coeff);
	}
}
