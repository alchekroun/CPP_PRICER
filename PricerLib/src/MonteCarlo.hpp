#pragma once
#include <vector>

namespace pricer {
	namespace mcarlo {
        /**
         * @brief Calculate the option price with a Monte Carlo simulation
         * @param is_call boolean is Call
         * @param s0 Initial Spot
         * @param strike Strike
         * @param rate Riskless rate
         * @param volatility Underlying volatility
         * @param maturity Contract maturity
         * @param nb_path Number of path used for MC
         * @return Option price
         */
        std::pair<double, double> get_option_price(bool is_call, double s0, double strike, double rate, double volatility, double maturity, int nb_path);
	}
}
