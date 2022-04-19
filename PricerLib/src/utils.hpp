#pragma once
#include <vector>

/**
 * @brief Payoff of a vanilla option
 * @param is_call True if it is a call, otherwise it is a put
 * @param spot Underlying spot
 * @param strike Contract strike
 * @return payoff Payoff of the vanilla option
 */
double get_payoff(bool const is_call, double const spot, double const strike);

/**
 * @brief Cumulative distribution function for a normal random variable 0, 1
 * @param x Upper limit
 * @return CDF
 */
double normal_cdf(double x);

/**
 * @brief Probability Density function for a normal random variable (mean, std)
 * @param x Value
 * @param mean 0 as default
 * @param std 1 as default
 * @return pdf of X
 */
double normal_pdf(double x, double mean = 0, double std = 1);


/**
 * @brief Mean
 * @param values Container whose values are used
 * @return mean of `values`
 */
double mean(std::vector<double> const& values);

/**
 * @brief Standard derivation
 * @param values Container whose values are used
 * @return Standard derivation of `values`
 */
double stdd(std::vector<double> const& values);