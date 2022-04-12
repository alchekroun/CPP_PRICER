#include <iostream>
#include "PricerLib.hpp"


int main()
{
	std::cout << pricer::binomial::get_option_price(false, false, 100, 98, 4, 0.00077, 0.020810837345409724) << std::endl;
}
