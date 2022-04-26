#pragma once

namespace pricer {
	namespace forward {

		/**
		 * @brief Calculate price of a forward contract
		 * @param rate Riskless rate
		 * @param s0 Initial spot
		 * @param maturity Contract maturity
		 * @param q Fees
		 * @param dividend Dividend yield
		 * @param dividend_per_year Dividends to pay by year
		 * @return Contract price
		 */
		double get_price(double rate, double s0, double maturity, double q = 0, double dividend = 0, int dividend_per_year = 0);
	}
}