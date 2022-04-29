#include <iostream>

#include "PricerLib.hpp"


int main() {

	double const spot = 100;
	double const strike = 60;
	double const rate = 0.02;
	double const vol = 0.25;
	double const maturity = 1;
	double const dividend = 0.02;

	std::cout << "-# Binomial :" << pricer::binomial::get_option_price(true, true, 50, spot, strike, maturity, rate, vol) << std::endl;

	int const nb_path = 1200000;

	auto const p = pricer::mcarlo::get_option_price(true, spot, strike, rate, vol, maturity, nb_path);
	std::cout << "\n-# MC : " << p.first << "\t" << p.second << std::endl;

	std::cout << "\n-# BSM : " << pricer::bsm::get_option_price(true, spot, strike, rate, vol, maturity, dividend) << std::endl;

	std::cout << "Delta : " << pricer::bsm::get_delta(true, spot, strike, rate, vol, maturity, dividend) << std::endl;
	std::cout << "Theta : " << pricer::bsm::get_theta(true, spot, strike, rate, vol, maturity, dividend) << std::endl;
	std::cout << "Gamma : " << pricer::bsm::get_gamma(spot, strike, rate, vol, maturity, dividend) << std::endl;
	std::cout << "Vega : " << pricer::bsm::get_vega(true, spot, strike, rate, vol, maturity, dividend) << std::endl;
	std::cout << "Rho : " << pricer::bsm::get_rho(true, spot, strike, rate, vol, maturity, dividend) << std::endl;
}
