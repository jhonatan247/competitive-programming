#include <algo/modular.h>

#include <cassert>
#include <cstdint>
#include <sstream>

using CompositeModular = Modular<std::integral_constant<int, 12>>;
using PrimeModular = Modular<std::integral_constant<int, 1'000'000'007>, true>;
using SmallPrime = modular<std::integral_constant<int, 7>, true>;

void test_normalization_and_accessors() {
    assert(CompositeModular(-1).value() == 11);
    assert(CompositeModular(25).value() == 1);
    assert(CompositeModular(0).is_zero());
    assert(CompositeModular(1).is_one());
    assert(CompositeModular::modulus() == 12);
    assert(PrimeModular::has_prime_modulus());
    assert(!CompositeModular::has_prime_modulus());
}

void test_arithmetic() {
    using Mint = SmallPrime;
    assert((Mint(5) + Mint(6)).value() == 4);
    assert((Mint(2) - Mint(5)).value() == 4);
    assert((Mint(3) * Mint(5)).value() == 1);
    assert((Mint(3) / Mint(5)).value() == 2);
    assert((-Mint(3)).value() == 4);

    Mint value = 6;
    assert((++value).value() == 0);
    assert((value--).value() == 0);
    assert(value.value() == 6);
    assert((--value).value() == 5);
}

void test_powers_and_inverses() {
    using Mint = SmallPrime;
    assert(Mint(3).power(0).value() == 1);
    assert(Mint(3).power(4).value() == 4);
    assert(Mint::power_of(Mint(3), 4).value() == 4);
    assert(Mint(3).inverse().value() == 5);
    assert(Mint::inverse_of(3).value() == 5);
    assert(Mint::inverse_prime(3).value() == 5);
    assert((Mint(3) * Mint(3).inverse()).is_one());

    using Composite = Modular<std::integral_constant<int, 10>>;
    assert(Composite(3).inverse().value() == 7);
    assert((Composite(3) * Composite(3).inverse()).is_one());
}

void test_streaming_and_wide_multiplication() {
    using Mint = Modular<std::integral_constant<long long, 4'000'000'007>>;
    assert((Mint(3'000'000'000LL) * Mint(3'000'000'000LL)).value() ==
           250'000'028LL);

    std::stringstream stream("-15");
    Mint value;
    stream >> value;
    assert(value.value() == 3'999'999'992LL);

    stream.str("");
    stream.clear();
    stream << value;
    assert(stream.str() == "3999999992");
}

void test_dynamic_modulus() {
    using Mint = DynamicModular<int>;

    Mint::set_modulus(7);
    assert(Mint::modulus() == 7);
    assert((Mint(3) * Mint(5)).value() == 1);
    assert(Mint(3).inverse().value() == 5);
    assert(Mint(3).inverse(true).value() == 5);

    Mint::set_modulus(10);
    assert(Mint::modulus() == 10);
    assert(Mint(-3).value() == 7);
    assert((Mint(3) * Mint(3).inverse()).is_one());
    assert(Mint(3).power(4).value() == 1);
}

int main() {
    test_normalization_and_accessors();
    test_arithmetic();
    test_powers_and_inverses();
    test_streaming_and_wide_multiplication();
    test_dynamic_modulus();
}
