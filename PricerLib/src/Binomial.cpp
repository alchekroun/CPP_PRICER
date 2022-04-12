#include "Binomial.hpp"

#include <memory>
#include <vector>

#include "utils.hpp"


class node {
public:
	double underlying;
	double price;

	node(double const u, double const p = 0.0) : underlying(u), price(p) {}
};

std::vector<std::vector<std::shared_ptr<node>>> init_nodes(double const s0, int const periods, double const up_coeff, double const down_coeff) {
	std::shared_ptr<node> first_node(new node(s0));
	std::vector<std::vector<std::shared_ptr<node>>> nodes{ { first_node } };

	for (auto period = 1; period <= periods; period++) {
		std::vector<std::shared_ptr<node>> row;
		for (auto n = 0; n <= period; n++) {
			std::shared_ptr<node> tmp_node(new node(s0 * pow(up_coeff, n) * pow(down_coeff, period - n)));
			row.emplace_back(tmp_node);
		}
		nodes.push_back(row);
	}

	return nodes;
}

double get_neutral_risk_proba(double const rate, double const up_coeff, double const down_coeff) {
	return (1 + rate - down_coeff) / (up_coeff - down_coeff);
}

double calculate_option_price(std::vector<std::vector<std::shared_ptr<node>>> const& tree, bool const is_euro, bool const is_call, int const periods, double const strike, double const n_r_proba, double const rate) {

	for (auto period = periods; period >= 0; period--) {
		for (auto n = 0; n <= period; n++) {
			auto& tmp_node = tree[period][n];
			if (period == periods) {
				tmp_node->price = get_payoff(is_call, tmp_node->underlying, strike);
			}
			else {
				auto const value = (n_r_proba * tree[period + 1][n + 1]->price + (1 - n_r_proba) * tree[period + 1][n]->price) / (1 + rate);
				if (is_euro) {
					tmp_node->price = value;
				}
				else {
					tmp_node->price = std::max(value, get_payoff(is_call, tmp_node->underlying, strike));
				}
			}
		}
	}

	return tree[0][0]->price;

}


double pricer::binomial::get_option_price(bool const is_euro, bool const is_call, double const s0, double const strike, int const periods, double const rate, double const volatility)
{
	// TODO : Manage arbitrage exception

	auto const up_coeff = exp(volatility * sqrt(periods));
	auto const down_coeff = 1.0 / up_coeff;
	auto const n_r_proba = get_neutral_risk_proba(rate, up_coeff, down_coeff);
	auto const tree = init_nodes(s0, periods, up_coeff, down_coeff);

	return calculate_option_price(tree, is_euro, is_call, periods, strike, n_r_proba, rate);
}

