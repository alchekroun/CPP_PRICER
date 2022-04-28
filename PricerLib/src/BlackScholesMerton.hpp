#pragma once

namespace pricer {
	namespace bsm {

		/**
		 * @brief Calculate the price of a vanilla option with BSM formula
		 * @param is_call True if it is a call, otherwise it is a put
		 * @param spot Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @param dividend Dividend rate
		 * @return Option price
		 */
		double get_option_price(bool is_call, double spot, double strike, double rate, double volatility, double maturity, double dividend = 0);

		/**
		 * @brief Calculate the delta of a vanilla option with dividend with BSM formula
		 * @param is_call True if it is a call, otherwise it is a put
		 * @param spot Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @param dividend Dividend rate
		 * @return Delta
		 */
		double get_delta(bool is_call, double spot, double strike, double rate, double volatility, double maturity, double dividend = 0);

		/**
		 * @brief Calculate the gamma of a vanilla option with dividend with BSM formula
		 * @param spot Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @param dividend Dividend rate
		 * @return gamma
		 */
		double get_gamma(double spot, double strike, double rate, double volatility, double maturity, double dividend = 0);

		/**
		 * @brief Calculate the theta of a vanilla option with dividend with BSM formula
		 * @param is_call True if it is a call, otherwise it is a put
		 * @param spot Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @param dividend Dividend rate
		 * @return Theta
		 */
		double get_theta(bool is_call, double spot, double strike, double rate, double volatility, double maturity, double dividend = 0);

		/**
		 * @brief Calculate the vega of a vanilla option with dividend with BSM formula
		 * @param is_call True if it is a call, otherwise it is a put
		 * @param spot Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @param dividend Dividend rate
		 * @return Vega
		 */
		double get_vega(bool is_call, double spot, double strike, double rate, double volatility, double maturity, double dividend = 0);

		/**
		 * @brief Calculate the vega of a vanilla option with dividend with BSM formula
		 * @param is_call True if it is a call, otherwise it is a put
		 * @param spot Underlying spot
		 * @param strike Strike
		 * @param rate Riskless rate
		 * @param volatility Underlying volatility
		 * @param maturity Contract maturity
		 * @param dividend Dividend rate
		 * @return Vega
		 */
		double get_rho(bool is_call, double spot, double strike, double rate, double volatility, double maturity, double dividend = 0);
	}
}
