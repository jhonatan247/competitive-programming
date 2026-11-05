#pragma once
#include "local/local_library_usage_warning.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <limits>
#include <type_traits>
#include <utility>

template <typename Modulus, bool modulus_is_prime = false>
class Modular {
    static_assert(std::is_integral_v<decltype(Modulus::value)>);
    static_assert(Modulus::value > 0);

public:
    using value_type = std::remove_cv_t<decltype(Modulus::value)>;
    using Type = value_type;
    using wide_type = __int128_t;

    constexpr Modular() : value_(0) {}

    template <typename T>
    constexpr Modular(T value) : value_(normalize(value)) {}

    static constexpr value_type modulus() {
        return static_cast<value_type>(Modulus::value);
    }

    static constexpr bool has_prime_modulus() {
        return modulus_is_prime;
    }

    constexpr value_type value() const {
        return value_;
    }

    constexpr value_type operator()() const {
        return value_;
    }

    constexpr bool is_zero() const {
        return value_ == 0;
    }

    constexpr bool is_one() const {
        return value_ == 1;
    }

    constexpr Modular operator+() const {
        return *this;
    }

    constexpr Modular operator-() const {
        return Modular(value_ == 0 ? 0 : modulus() - value_);
    }

    constexpr Modular& operator+=(const Modular& other) {
        value_ += other.value_;
        if (value_ >= modulus()) value_ -= modulus();
        return *this;
    }

    constexpr Modular& operator-=(const Modular& other) {
        if (value_ < other.value_) value_ += modulus();
        value_ -= other.value_;
        return *this;
    }

    constexpr Modular& operator*=(const Modular& other) {
        value_ = normalize(static_cast<wide_type>(value_) * other.value_);
        return *this;
    }

    constexpr Modular& operator/=(const Modular& other) {
        return *this *= other.inverse();
    }

    constexpr Modular& operator++() {
        if (++value_ == modulus()) value_ = 0;
        return *this;
    }

    constexpr Modular& operator--() {
        if (value_ == 0) value_ = modulus();
        --value_;
        return *this;
    }

    constexpr Modular operator++(int) {
        Modular result(*this);
        ++*this;
        return result;
    }

    constexpr Modular operator--(int) {
        Modular result(*this);
        --*this;
        return result;
    }

    Modular& operator=(value_type value) {
        value_ = normalize(value);
        return *this;
    }

    Modular power(std::uint64_t exponent) const {
        Modular base = *this;
        Modular result = 1;
        while (exponent != 0) {
            if (exponent & 1) result *= base;
            base *= base;
            exponent >>= 1;
        }
        return result;
    }

    Modular inverse() const {
        if constexpr (modulus_is_prime) {
            return inverse_prime(value_);
        }
        return inverse_of(value_);
    }

    static Modular inverse_of(value_type value) {
        auto [gcd, coefficient] = extended_gcd(value, modulus());
        assert(gcd == 1);
        return Modular(coefficient);
    }

    static Modular inverse_prime(value_type value) {
        assert(value != 0);
        assert(modulus_is_prime);
        return Modular(value).power(static_cast<std::uint64_t>(modulus() - 2));
    }

    static Modular power_of(Modular base, std::uint64_t exponent) {
        return base.power(exponent);
    }

    static constexpr value_type normalize(value_type value) {
        value %= modulus();
        if constexpr (std::is_signed_v<value_type>) {
            if (value < 0) value += modulus();
        }
        return value;
    }

    template <typename T>
    static constexpr value_type normalize(T value) {
        if constexpr (std::is_signed_v<T> ||
                      std::is_same_v<std::remove_cv_t<T>, __int128_t>) {
            wide_type remainder = static_cast<wide_type>(value) %
                                  static_cast<wide_type>(modulus());
            if (remainder < 0) remainder += modulus();
            return static_cast<value_type>(remainder);
        } else {
            using unsigned_wide_type = __uint128_t;
            return static_cast<value_type>(
                static_cast<unsigned_wide_type>(value) %
                static_cast<unsigned_wide_type>(modulus()));
        }
    }

    friend constexpr Modular operator+(Modular lhs, const Modular& rhs) {
        return lhs += rhs;
    }

    friend constexpr Modular operator-(Modular lhs, const Modular& rhs) {
        return lhs -= rhs;
    }

    friend constexpr Modular operator*(Modular lhs, const Modular& rhs) {
        return lhs *= rhs;
    }

    friend constexpr Modular operator/(Modular lhs, const Modular& rhs) {
        return lhs /= rhs;
    }

    friend constexpr bool operator==(const Modular& lhs, const Modular& rhs) {
        return lhs.value_ == rhs.value_;
    }

    friend constexpr bool operator!=(const Modular& lhs, const Modular& rhs) {
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& stream, const Modular& number) {
        return stream << number.value_;
    }

    friend std::istream& operator>>(std::istream& stream, Modular& number) {
        std::intmax_t input;
        stream >> input;
        if (stream) number = Modular(input);
        return stream;
    }

private:
    value_type value_;

    static std::pair<wide_type, wide_type> extended_gcd(
        wide_type a, wide_type b) {
        wide_type x0 = 1;
        wide_type x1 = 0;
        while (b != 0) {
            wide_type quotient = a / b;
            wide_type next_a = a - quotient * b;
            a = b;
            b = next_a;
            wide_type next_x = x0 - quotient * x1;
            x0 = x1;
            x1 = next_x;
        }
        return {a, x0};
    }
};

template <typename Modulus, bool modulus_is_prime = false>
using modular = Modular<Modulus, modulus_is_prime>;
