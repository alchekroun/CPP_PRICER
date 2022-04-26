#include "utils.hpp"

#include <cmath>

double custom_round(double const value, int const decimal) {
	double const multiplier = pow(10., decimal);
	return std::ceil(value * multiplier) / multiplier;
}
