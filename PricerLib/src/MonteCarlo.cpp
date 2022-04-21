#include "MonteCarlo.hpp"

#include <iostream>
#include <numeric>
#include <random>

#include "utils.hpp"

std::pair<double, double> get_option_price_basic(bool const is_call, double const s0, double const strike, double const rate, double const volatility, double const maturity, int const nb_path) {
	// Randomness generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> d(0, 1);

	// Variables
	std::vector<double> spot(nb_path);
	std::vector<double> option_price(nb_path);

	for (auto i = 0; i < nb_path; i++) {
		auto const epsilon = d(gen);

		spot[i] = s0 * exp((rate - 0.5 * pow(volatility, 2)) * maturity + volatility * epsilon * sqrt(maturity));
		option_price[i] = get_payoff(is_call, spot[i], strike);
	}

	double const final_option_price = exp(-rate * maturity) * mean(option_price);

	double const error = exp(-rate * maturity) * stdd(option_price) / sqrt(nb_path);

	std::pair<double, double> const interval(final_option_price - error, final_option_price + error);
	std::cout << "C0 : " << final_option_price << "\tInterval  = [" << interval.first << ", " << interval.second << "]" << "\tControle : " << interval.second - interval.first << std::endl;

	return { final_option_price, error };
}

std::pair<double, double> get_option_price_optimized(bool const is_call, double const s0, double const strike, double const rate, double const volatility, double const maturity, int const nb_path) {

	// Randomness generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> d(0, 1);

	// Variables
	std::vector<double> spot(nb_path);
	std::vector<double> option_price(nb_path);
	std::vector<double> average_var_ctrl(nb_path);	// Control variables

	for (auto i = 0; i < nb_path; i++) {
		auto const epsilon = d(gen);

		spot[i] = s0 * exp((rate - 0.5 * pow(volatility, 2)) * maturity + volatility * epsilon * sqrt(maturity));
		option_price[i] = get_payoff(is_call, spot[i], strike);

		auto const var_ctrl = option_price[i] - spot[i] + s0 * exp(rate * maturity);

		// Antithetic
		auto const anti_spot = s0 * exp((rate - 0.5 * pow(volatility, 2)) * maturity + volatility * -epsilon * sqrt(maturity));
		auto const anti_option_price = get_payoff(is_call, spot[i], strike);

		auto const anti_var_ctrl = anti_option_price - anti_spot + s0 * exp(rate * maturity);

		average_var_ctrl[i] = (var_ctrl + anti_var_ctrl) / 2;
	}

	double const final_option_price = exp(-rate * maturity) * mean(average_var_ctrl);

	double const error = exp(-rate * maturity) * stdd(average_var_ctrl) / sqrt(nb_path);

	std::pair<double, double> const interval(final_option_price - error, final_option_price + error);
	std::cout << "C0 : " << final_option_price << "\tInterval  = [" << interval.first << ", " << interval.second << "]" << "\tControle : " << interval.second - interval.first << std::endl;

	return { final_option_price, error };
}

std::pair<double, double> pricer::mcarlo::get_option_price(bool const is_call, double const s0, double const strike, double const rate, double const volatility, double const maturity, int const nb_path, int const methodo) {
	if (methodo == optimized) {
		return get_option_price_optimized(is_call, s0, strike, rate, volatility, maturity, nb_path);
	}
	return get_option_price_basic(is_call, s0, strike, rate, volatility, maturity, nb_path);
}

