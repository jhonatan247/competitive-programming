#pragma once
#include "local/local_library_usage_warning.h"

#include <bits/stdc++.h>
#include <cassert>

namespace bit {

	template <typename T>
	using unsigned_type = std::make_unsigned_t<T>;

	template <typename T>
	constexpr int bit_count = std::numeric_limits<unsigned_type<T>>::digits;

	template <typename T>
	constexpr unsigned_type<T> as_unsigned(T value) {
		static_assert(std::is_integral_v<T>);
		return static_cast<unsigned_type<T>>(value);
	}

	template <typename T>
	int count_set_bits(T value) {
		using U = unsigned_type<T>;
		if constexpr (sizeof(U) <= sizeof(unsigned int)) {
			return __builtin_popcount(static_cast<unsigned int>(as_unsigned(value)));
		} else if constexpr (sizeof(U) <= sizeof(unsigned long)) {
			return __builtin_popcountl(static_cast<unsigned long>(as_unsigned(value)));
		} else {
			return __builtin_popcountll(static_cast<unsigned long long>(as_unsigned(value)));
		}
	}

	template <typename T>
	int count_trailing_zero_bits(T value) {
		using U = unsigned_type<T>;
		U x = as_unsigned(value);
		if (x == 0) return bit_count<T>;
		if constexpr (sizeof(U) <= sizeof(unsigned int)) {
			return __builtin_ctz(static_cast<unsigned int>(x));
		} else if constexpr (sizeof(U) <= sizeof(unsigned long)) {
			return __builtin_ctzl(static_cast<unsigned long>(x));
		} else {
			return __builtin_ctzll(static_cast<unsigned long long>(x));
		}
	}

	template <typename T>
	int count_leading_zero_bits(T value) {
		using U = unsigned_type<T>;
		U x = as_unsigned(value);
		if (x == 0) return bit_count<T>;
		if constexpr (sizeof(U) <= sizeof(unsigned int)) {
			return __builtin_clz(static_cast<unsigned int>(x)) -
				(std::numeric_limits<unsigned int>::digits - bit_count<T>);
		} else if constexpr (sizeof(U) <= sizeof(unsigned long)) {
			return __builtin_clzl(static_cast<unsigned long>(x)) -
				(std::numeric_limits<unsigned long>::digits - bit_count<T>);
		} else {
			return __builtin_clzll(static_cast<unsigned long long>(x)) -
				(std::numeric_limits<unsigned long long>::digits - bit_count<T>);
		}
	}

	template <typename T>
	int count_set_bit_parity(T value) {
		return count_set_bits(value) & 1;
	}

	template <typename T>
	int bit_width(T value) {
		return bit_count<T> - count_leading_zero_bits(value);
	}

	template <typename T>
	int highest_set_bit_index(T value) {
		int width = bit_width(value);
		return width == 0 ? -1 : width - 1;
	}

	template <typename T>
	int lowest_set_bit_index(T value) {
		return as_unsigned(value) == 0 ? -1 : count_trailing_zero_bits(value);
	}

	template <typename T>
	int index_of_least_significant_set_bit(T value) {
		return lowest_set_bit_index(value);
	}

	template <typename T>
	int index_of_most_significant_set_bit(T value) {
		return highest_set_bit_index(value);
	}

	template <typename T>
	int floor_log2(T value) {
		return highest_set_bit_index(value);
	}

	template <typename T>
	bool is_power_of_two(T value) {
		auto x = as_unsigned(value);
		return x != 0 && (x & (x - 1)) == 0;
	}

	template <typename T>
	int ceil_log2(T value) {
		int floor = floor_log2(value);
		return value <= 1 ? 0 : floor + !is_power_of_two(value);
	}

	template <typename T>
	unsigned_type<T> lowest_set_bit(T value) {
		using U = unsigned_type<T>;
		U x = as_unsigned(value);
		return x & (U(0) - x);
	}

	template <typename T>
	unsigned_type<T> least_significant_set_bit(T value) {
		return lowest_set_bit(value);
	}

	template <typename T>
	unsigned_type<T> highest_set_bit(T value) {
		int index = highest_set_bit_index(value);
		return index < 0 ? 0 : unsigned_type<T>(1) << index;
	}

	template <typename T>
	unsigned_type<T> most_significant_set_bit(T value) {
		return highest_set_bit(value);
	}

	template <typename T>
	unsigned_type<T> clear_lowest_set_bit(T value) {
		auto x = as_unsigned(value);
		return x & (x - 1);
	}

	template <typename T>
	unsigned_type<T> set_lowest_unset_bit(T value) {
		auto x = as_unsigned(value);
		return x | (x + 1);
	}

	template <typename T>
	bool is_bit_set(T value, int index) {
		return index >= 0 && index < bit_count<T> &&
			((as_unsigned(value) >> index) & 1) != 0;
	}

	template <typename T>
	unsigned_type<T> set_bit(T value, int index) {
		return index < 0 || index >= bit_count<T>
			? as_unsigned(value)
			: as_unsigned(value) | (unsigned_type<T>(1) << index);
	}

	template <typename T>
	unsigned_type<T> clear_bit(T value, int index) {
		return index < 0 || index >= bit_count<T>
			? as_unsigned(value)
			: as_unsigned(value) & ~(unsigned_type<T>(1) << index);
	}

	template <typename T>
	unsigned_type<T> toggle_bit(T value, int index) {
		return index < 0 || index >= bit_count<T>
			? as_unsigned(value)
			: as_unsigned(value) ^ (unsigned_type<T>(1) << index);
	}

	template <typename T>
	unsigned_type<T> mask_for_bits(int count) {
		using U = unsigned_type<T>;
		if (count <= 0) return 0;
		if (count >= bit_count<T>) return ~U(0);
		return static_cast<U>((U(1) << count) - U(1));
	}

	template <typename T>
	unsigned_type<T> mask_for_range(int left, int right) {
		if (left < 0 || right < left || right >= bit_count<T>) return 0;
		return mask_for_bits<T>(right - left + 1) << left;
	}

	template <typename T>
	unsigned_type<T> extract_bits(T value, int left, int right) {
		if (left < 0 || right < left || right >= bit_count<T>) return 0;
		return (as_unsigned(value) & mask_for_range<T>(left, right)) >> left;
	}

	template <typename T>
	unsigned_type<T> replace_bits(T value, int left, int right,
								unsigned_type<T> replacement) {
		if (left < 0 || right < left || right >= bit_count<T>) {
			return as_unsigned(value);
		}
		auto mask = mask_for_range<T>(left, right);
		return (as_unsigned(value) & ~mask) |
			((replacement << left) & mask);
	}

	template <typename T>
	unsigned_type<T> next_power_of_two(T value) {
		using U = unsigned_type<T>;
		U x = as_unsigned(value);
		if (x <= 1) return 1;
		int exponent = ceil_log2(x);
		return exponent >= bit_count<T> ? 0 : U(1) << exponent;
	}

	template <typename T>
	unsigned_type<T> previous_power_of_two(T value) {
		return highest_set_bit(value);
	}

	template <typename T, typename Function>
	void for_each_set_bit(T value, Function function) {
		auto x = as_unsigned(value);
		while (x != 0) {
			int index = count_trailing_zero_bits(x);
			function(index);
			x = clear_lowest_set_bit(x);
		}
	}

	template <typename T, typename Function>
	void for_each_submask(T mask, Function function) {
		auto submask = as_unsigned(mask);
		while (true) {
			function(submask);
			if (submask == 0) break;
			submask = (submask - 1) & as_unsigned(mask);
		}
	}

	template <typename T>
	constexpr T gray_code(T value) {
		using U = unsigned_type<T>;
		U x = as_unsigned(value);
		return static_cast<T>(x ^ (x >> 1));
	}

	template <typename T>
	constexpr T inverse_gray_code(T value) {
		using U = unsigned_type<T>;
		U result = as_unsigned(value);
		for (U shifted = result >> 1; shifted != 0; shifted >>= 1) {
			result ^= shifted;
		}
		return static_cast<T>(result);
	}

	template <typename T>
	constexpr T rotate_left(T value, int shift) {
		using U = unsigned_type<T>;
		constexpr int width = bit_count<T>;
		U x = as_unsigned(value);
		shift = ((shift % width) + width) % width;
		return static_cast<T>((x << shift) | (x >> ((width - shift) % width)));
	}

	template <typename T>
	constexpr T rotate_right(T value, int shift) {
		using U = unsigned_type<T>;
		constexpr int width = bit_count<T>;
		U x = as_unsigned(value);
		shift = ((shift % width) + width) % width;
		return static_cast<T>((x >> shift) | (x << ((width - shift) % width)));
	}

	template <typename T>
	constexpr unsigned_type<T> reverse_bits(T value) {
		using U = unsigned_type<T>;
		U x = as_unsigned(value);
		U result = 0;
		for (int i = 0; i < bit_count<T>; ++i) {
			result = (result << 1) | (x & 1);
			x >>= 1;
		}
		return result;
	}

	// Compatibility names for older solutions.
	template <typename T> int popcount(T x) { return count_set_bits(x); }
	template <typename T> int popcount_fast(T x) { return count_set_bits(x); }
	template <typename T> int ctz(T x) { return count_trailing_zero_bits(x); }
	template <typename T> int clz(T x) { return count_leading_zero_bits(x); }
	template <typename T> int ffs(T x) { return lowest_set_bit_index(x) + 1; }
	template <typename T> int parity(T x) { return count_set_bit_parity(x); }
	template <typename T> int width(T x) { return bit_width(x); }
	template <typename T> int log2(T x) { return floor_log2(x); }
	template <typename T> bool is_pow2(T x) { return is_power_of_two(x); }
	template <typename T> auto next_pow2(T x) { return next_power_of_two(x); }
	template <typename T> auto prev_pow2(T x) { return previous_power_of_two(x); }
	template <typename T> auto lowest(T x) { return lowest_set_bit(x); }
	template <typename T> auto clear_lowest(T x) { return clear_lowest_set_bit(x); }
	template <typename T> auto set_lowest_zero(T x) { return set_lowest_unset_bit(x); }
	inline unsigned int reverse32(unsigned int x) { return reverse_bits(x); }
	inline unsigned long long reverse64(unsigned long long x) { return reverse_bits(x); }

}
