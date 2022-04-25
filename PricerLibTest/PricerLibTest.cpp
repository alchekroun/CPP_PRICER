#include "pch.h"
#include "CppUnitTest.h"
#include "PricerLib.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace pricer_lib_test {
	TEST_CLASS(pricer_lib_test) {
		double const spot_ = 100;
		double const strike_ = 60;
		double const rate_ = 0.02;
		double const vol_ = 0.25;
		double const maturity_ = 2;

public:

	TEST_METHOD(mc_get_option_price_basic) {
		int const nb_path = 1200000;
		auto const option_price = pricer::mcarlo::get_option_price(true, spot_, strike_, rate_, vol_, maturity_, nb_path);
		Assert::AreEqual(1.0, option_price.first);
	}

	TEST_METHOD(mc_get_option_price_optimized) {
		int const nb_path = 1200000;
		auto const option_price = pricer::mcarlo::get_option_price(true, spot_, strike_, rate_, vol_, maturity_, nb_path, pricer::mcarlo::optimized);
		Assert::AreEqual(1.0, option_price.first);

	}

	TEST_METHOD(binomial_get_option_price) {

	}

	TEST_METHOD(binomial_get_up_coeff) {

	}

	TEST_METHOD(binomial_get_down_coeff) {

	}

	TEST_METHOD(binomial_get_neutral_risk_proba) {

	}

	TEST_METHOD(bsm_get_option_price) {

	}

	TEST_METHOD(bsm_get_odelta) {

	}

	TEST_METHOD(bsm_get_theta) {

	}

	TEST_METHOD(bsm_get_gamma) {

	}

	TEST_METHOD(bsm_get_vega) {

	}

	TEST_METHOD(bsm_get_rho) {

	}
	};
}
