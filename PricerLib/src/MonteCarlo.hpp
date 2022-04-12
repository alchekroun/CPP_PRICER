#pragma once
#include <vector>

namespace pricer {
	namespace mcarlo {

		std::pair<double, double> get_option_price(bool is_call, double s0, double strike, double rate, double volatility, double maturity, int nb_path);

		std::vector<double> sim_trajectory();
		double get_option_price();
	}
}
