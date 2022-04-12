#pragma once

namespace pricer {
    namespace binomial {
        double get_option_price(bool is_euro, bool is_call, double s0, double strike, int periods, double rate, double volatility);
    }
}
