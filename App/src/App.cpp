#include <iostream>

#include "PricerLib.hpp"


int main()
{
	std::cout << pricer::binomial::get_option_price(false, false, 100, 98, 4, 0.00077, 0.020810837345409724) << std::endl;

	double const spot = 100;
	double const strike = 95;
	double const rate = 0.1;
	double const vol = 0.2;
	double const maturity = 1;

	std::cout << pricer::bsm::get_option_price(true, spot, strike, rate, vol, maturity) << std::endl;

	int const nb_path = 1200000;

	auto const p = pricer::mcarlo::get_option_price(true, spot, strike, rate, vol, maturity, nb_path);
	std::cout << p.first << "\t" << p.second << std::endl;
}
