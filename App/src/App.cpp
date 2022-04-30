#include <iostream>

#include "PricerLib.hpp"


int main() {

	enum choice_option {
		vanillas,
		forward
	};

	enum vanillas_methodos {
		binomial,
		bsm,
		montecarlo
	};

	int user_choice_product = 0;
	int user_choice_methodo = 0;

	while (user_choice_product >= 0) {
		std::cout << "Welcome to the pricer, what do you want to price ?" << std::endl << "0: Vanillas\t1: Forwards" << std::endl;
		std::cin >> user_choice_product;

		if (user_choice_product == vanillas) {
			bool is_call;
			double spot, strike, rate, vol, maturity, dividend;
			std::cout << "Call ? (1: yes/0: no)";
			std::cin >> is_call;
			std::cout << "Spot : ";
			std::cin >> strike;
			std::cout << "Strike : ";
			std::cin >> spot;
			std::cout << "Rate : ";
			std::cin >> rate;
			std::cout << "Volatility : ";
			std::cin >> vol;
			std::cout << "Maturity : ";
			std::cin >> maturity;
			std::cout << "Dividend : ";
			std::cin >> dividend;
			std::cout << "Which method ?" << std::endl << "0: Binomial Tree\t1: BSM Formula\t2: Monte Carlo" << std::endl;
			std::cin >> user_choice_methodo;
			if (user_choice_methodo == binomial) {
				bool is_euro;
				std::cout << "European ? (1: yes/0: no)";
				std::cin >> is_euro;

				std::cout << "-# Binomial :" << pricer::binomial::get_option_price(is_euro, is_call, 1, spot, strike, maturity, rate, vol) << std::endl;

			}
			else if (user_choice_methodo == bsm) {
				std::cout << "\n-# BSM : " << pricer::bsm::get_option_price(is_call, spot, strike, rate, vol, maturity, dividend) << std::endl;
				std::cout << "Delta : " << pricer::bsm::get_delta(is_call, spot, strike, rate, vol, maturity, dividend) << std::endl;
				std::cout << "Theta : " << pricer::bsm::get_theta(is_call, spot, strike, rate, vol, maturity, dividend) << std::endl;
				std::cout << "Gamma : " << pricer::bsm::get_gamma(spot, strike, rate, vol, maturity, dividend) << std::endl;
				std::cout << "Vega : " << pricer::bsm::get_vega(is_call, spot, strike, rate, vol, maturity, dividend) << std::endl;
				std::cout << "Rho : " << pricer::bsm::get_rho(is_call, spot, strike, rate, vol, maturity, dividend) << std::endl;

			}
			else if (user_choice_methodo == montecarlo) {
				int const nb_path = 1200000;
				auto const p = pricer::mcarlo::get_option_price(is_call, spot, strike, rate, vol, maturity, nb_path, pricer::mcarlo::optimized);
			}
			else {
				std::cout << "Please enter a valid choice";
			}
		}
		else if (user_choice_product == forward) {
			double s0, rate, maturity, q, dividend, dividend_per_year;
			std::cout << "Initial spot : ";
			std::cin >> s0;
			std::cout << "Rate : ";
			std::cin >> rate;
			std::cout << "maturity : ";
			std::cin >> maturity;
			std::cout << "Cost : ";
			std::cin >> q;
			std::cout << "Dividend : ";
			std::cin >> dividend;
			std::cout << "Dividend per year : ";
			std::cin >> dividend_per_year;

			std::cout << "Froward price : " << pricer::forward::get_price(rate, s0, maturity, q, dividend, dividend_per_year) << std::endl;
		}
		else {
			std::cout << "Please enter a valid choice";
		}
	}
}
