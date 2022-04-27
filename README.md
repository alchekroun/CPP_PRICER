# CPP_PRICER

## Description

CPP_PRICER is a school project. Decomposed into two separated parts. Firstly the library ```PricerLib``` used to calculate derivatives prices. Secondly the application example that use ```PricerLib```

## Installation

You can easily download the library ```PricerLib```. And add to your project with:
```c++
#include "PricerLib.hpp"
```

## Project

The following project is composed of three parts:
- App : Main application that uses ```PricerLib```
- ```PricerLib``` : Main library
- PricerLibTest : Main library tests

## PricerLib

Firstly it gives the price of an vanilla option given three methods :
- Binomial Trees
- MonteCarlo
- Black Scholes & Merton formula

Secondly it gives the price of an vanilla future/forward and a swap.

### Binomial Trees

The library implements binomial tree.

### Monte Carlo

Two methods are implemented for Monte Carlo, the basic one, and the optimised one. The basic one does a basic simulation. Basic.
The optimised one implements two variance reduction. The control variates and the antithetic variates. For the same accuracy it takes 30 million paths to obtain the same result as the optimized version obtained in 1.2 million.

### Black Scholes & Merton

The library basicly implements the formula of BSM. My main ressource was the book of John C. Hull.

## Authors

- [Mengru Gao](https://github.com/Mengrulune)
- [Alexandre Chekroun](https://github.com/alchekroun)

## References

- [Binomial distribution wikipedia page](https://en.wikipedia.org/wiki/Binomial_distribution)
- "Options, Futures, and Other Derivatives" - John C. Hull
- [Control variates wikipediage page](https://en.wikipedia.org/wiki/Control_variates)
- [Antithetic variates wikipediage page](https://en.wikipedia.org/wiki/Antithetic_variates)