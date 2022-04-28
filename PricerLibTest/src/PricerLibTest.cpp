#include <utils.hpp>

#include "pch.h"
#include "CppUnitTest.h"
#include "PricerLib.hpp"
#include "utils.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pricer_lib_test {
	TEST_CLASS(pricer_lib_test) {
		double const spot_ = 100;
		double const strike_ = 60;
		double const rate_ = 0.02;
		double const vol_ = 0.25;
		double const maturity_ = 1;
		double const dividend_ = 0;

public:
	TEST_METHOD(utils_get_payoff) {
		// WHEN
		auto const result = pricer::utils::get_payoff(true, spot_, strike_);

		// THEN
		Assert::AreEqual(40., custom_round(result, 0));
	}

	TEST_METHOD(utils_normal_cdf) {
		// THEN
		Assert::AreEqual(0.5, custom_round(pricer::utils::normal_cdf(0), 4));
		Assert::AreEqual(0.6915, custom_round(pricer::utils::normal_cdf(0.5), 4));
		Assert::AreEqual(0.8414, custom_round(pricer::utils::normal_cdf(1), 4));
		Assert::AreEqual(0.5988, custom_round(pricer::utils::normal_cdf(0.25), 4));
	}

	TEST_METHOD(utils_normal_pdf) {
		// THEN
		Assert::AreEqual(0.399, custom_round(pricer::utils::normal_pdf(0), 4));
		Assert::AreEqual(0.3521, custom_round(pricer::utils::normal_pdf(0.5), 4));
		Assert::AreEqual(0.242, custom_round(pricer::utils::normal_pdf(1), 4));
		Assert::AreEqual(0.3867, custom_round(pricer::utils::normal_pdf(0.25), 4));
	}

	TEST_METHOD(utils_mean) {
		// GIVEN
		std::vector<double> const v1{ 1., 2., 3. };

		// WHEN
		auto const result = pricer::utils::mean(v1);

		// THEN
		Assert::AreEqual(2., custom_round(result, 0));
	}

	TEST_METHOD(utils_stdd) {
		// GIVEN
		std::vector<double> const v1{ 1., 2., 3. };

		// WHEN
		auto const result = pricer::utils::mean(v1);

		// THEN
		Assert::AreEqual(2., custom_round(result, 0));
	}

	TEST_METHOD(mc_get_option_price_basic) {
		// GIVEN
		int const nb_path = 3000000;

		// WHEN
		auto const option_price = pricer::mcarlo::get_option_price(true, spot_, strike_, rate_, vol_, maturity_, nb_path);

		// THEN
		Assert::AreEqual(41.4, custom_round(option_price.first, 1));
	}

	TEST_METHOD(mc_get_option_price_optimized) {
		// GIVEN
		int const nb_path = 1200000;

		// WHEN
		auto const option_price = pricer::mcarlo::get_option_price(true, spot_, strike_, rate_, vol_, maturity_, nb_path, pricer::mcarlo::optimized);

		// THEN
		Assert::AreEqual(41.4, custom_round(option_price.first, 1));

	}

	TEST_METHOD(binomial_get_option_price) {
		// GIVEN

		// WHEN
		double const result = pricer::binomial::get_option_price(true, true, 1, spot_, strike_, maturity_, rate_, vol_);
		// THEN
		Assert::AreEqual(41.2, custom_round(result, 2));
	}

	TEST_METHOD(binomial_get_up_coeff) {
		// GIVEN
		double const volatility = 0.02081;
		int const periods = 4;
		double const maturity = 1;

		// WHEN
		double const result = pricer::binomial::get_up_coeff(volatility, periods, maturity);

		// THEN
		Assert::AreEqual(1.02, custom_round(result, 2));
	}

	TEST_METHOD(binomial_get_down_coeff) {
		// GIVEN
		double const volatility = 0.02081;
		int const periods = 4;
		double const maturity = 1;

		// WHEN
		double const result = pricer::binomial::get_down_coeff(volatility, periods, maturity);

		// THEN
		Assert::AreEqual(0.99, custom_round(result, 2));
	}

	TEST_METHOD(binomial_get_neutral_risk_proba) {
		// GIVEN
		double const up_coeff = pricer::binomial::get_up_coeff(vol_, 1, maturity_);
		double const down_coeff = pricer::binomial::get_down_coeff(vol_, 1, maturity_);

		// WHEN
		double const result = pricer::binomial::get_neutral_risk_proba(rate_, maturity_, up_coeff, down_coeff);

		// THEN
		Assert::AreEqual(0.48, custom_round(result, 2));

	}

	TEST_METHOD(bsm_get_option_price) {
		// GIVEN

		// WHEN
		double const result = pricer::bsm::get_option_price(true, spot_, strike_, rate_, vol_, maturity_, dividend_);

		// THEN
		Assert::AreEqual(41.31, custom_round(result, 2));
	}

	TEST_METHOD(bsm_get_delta) {
		// GIVEN

		// WHEN
		double const result = pricer::bsm::get_delta(true, spot_, strike_, rate_, vol_, maturity_, dividend_);

		// THEN
		Assert::AreEqual(0.99, custom_round(result, 2));
	}

	TEST_METHOD(bsm_get_theta) {
		// GIVEN

		// WHEN
		double const result = pricer::bsm::get_theta(true, spot_, strike_, rate_, vol_, maturity_, dividend_);

		// THEN
		Assert::AreEqual(-1.54, custom_round(result, 2));
	}

	TEST_METHOD(bsm_get_gamma) {
		// GIVEN

		// WHEN
		double const result = pricer::bsm::get_gamma(spot_, strike_, rate_, vol_, maturity_, dividend_);

		// THEN
		Assert::AreEqual(0.01, custom_round(result, 2));
	}

	TEST_METHOD(bsm_get_vega) {
		// GIVEN

		// WHEN
		double const result = pricer::bsm::get_vega(true, spot_, strike_, rate_, vol_, maturity_, dividend_);

		// THEN
		Assert::AreEqual(3.19, custom_round(result, 2));
	}

	TEST_METHOD(bsm_get_rho) {
		// GIVEN

		// WHEN
		double const result = pricer::bsm::get_rho(true, spot_, strike_, rate_, vol_, maturity_, dividend_);

		// THEN
		Assert::AreEqual(57.47, custom_round(result, 2));
	}
	};
}
