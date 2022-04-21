#pragma once

namespace pricer {
	namespace binomial {

		/**
		 * @brief Calculate the price of a vanilla option with BSM formula
		 * @param is_euro True if it is a European option, otherwise it is a American option
		 * @param is_call True if it is a call, otherwise it is a put
		 * @param periods Number of periods
		 * @param s0 Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @return Option price
		 */
		double get_option_price(bool is_euro, bool is_call, int periods, double s0, double strike, double maturity, double rate, double volatility);

		/**
		 * @brief Calculate the up coefficient for the binomial model.
		 * @param volatility Underlying volatility
		 * @param periods Number of periods
		 * @param maturity Contract maturity
		 * @return up coefficient
		 */
		double get_up_coeff(double volatility, int periods, double maturity);

		/**
		 * @brief Calculate the down coefficient for the binomial model.
		 * @param volatility Underlying volatility
		 * @param periods Number of periods
		 * @param maturity Contract maturity
		 * @return down coefficient
		 */
		double get_down_coeff(double volatility, int periods, double maturity);

		/**
		 * @brief Calculate the risk neutral probability for the binomial model.
		 * @param rate Riskless rate
		 * @param maturity Contract maturity
		 * @param up_coeff Up coefficient
		 * @param down_coeff Down coefficient
		 * @return Risk neutral probability
		 */
		double get_neutral_risk_proba(double rate, double maturity, double up_coeff, double down_coeff);

	}
}
