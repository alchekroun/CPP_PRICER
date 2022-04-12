#pragma once
#include <vector>

namespace pricer {
	namespace mcarlo {

		std::vector<double> sim_trajectory();
		double get_option_price();
	}
}
