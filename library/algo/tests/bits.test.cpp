#include <algo/bits.h>

#include <cassert>
#include <cstdint>
#include <vector>

namespace {

void test_bit_counts() {
    static_assert(bit::bit_count<std::uint8_t> == 8);
    static_assert(bit::bit_count<std::uint32_t> == 32);
    static_assert(bit::bit_count<std::uint64_t> == 64);

    assert(bit::count_set_bits(std::uint8_t(0)) == 0);
    assert(bit::count_set_bits(std::uint64_t(0xf0f0)) == 8);
    assert(bit::count_set_bits(std::uint64_t(-1)) == 64);
    assert(bit::count_trailing_zero_bits(std::uint32_t(0)) == 32);
    assert(bit::count_trailing_zero_bits(std::uint32_t(40)) == 3);
    assert(bit::count_leading_zero_bits(std::uint8_t(0)) == 8);
    assert(bit::count_leading_zero_bits(std::uint8_t(1)) == 7);
    assert(bit::count_leading_zero_bits(std::uint32_t(1)) == 31);
    assert(bit::count_set_bit_parity(0b101101u) == 0);
}

void test_set_bit_queries() {
    assert(bit::bit_width(0u) == 0);
    assert(bit::bit_width(16u) == 5);
    assert(bit::highest_set_bit_index(0u) == -1);
    assert(bit::highest_set_bit_index(40u) == 5);
    assert(bit::lowest_set_bit_index(0u) == -1);
    assert(bit::lowest_set_bit_index(40u) == 3);
    assert(bit::index_of_least_significant_set_bit(40u) == 3);
    assert(bit::index_of_most_significant_set_bit(40u) == 5);
    assert(bit::lowest_set_bit(40u) == 8);
    assert(bit::highest_set_bit(40u) == 32);
    assert(bit::least_significant_set_bit(0u) == 0);
    assert(bit::most_significant_set_bit(0u) == 0);
    assert(bit::clear_lowest_set_bit(40u) == 32);
    assert(bit::set_lowest_unset_bit(0b1011u) == 0b1111u);

    assert(bit::is_bit_set(0b1010u, 1));
    assert(!bit::is_bit_set(0b1010u, 0));
    assert(!bit::is_bit_set(0b1010u, -1));
    assert(bit::set_bit(0u, 3) == 8);
    assert(bit::clear_bit(15u, 2) == 11);
    assert(bit::toggle_bit(10u, 1) == 8);
    assert(bit::set_bit(10u, 32) == 10);
}

void test_powers_and_masks() {
    assert(!bit::is_power_of_two(0u));
    assert(bit::is_power_of_two(64u));
    assert(!bit::is_power_of_two(65u));
    assert(bit::floor_log2(0u) == -1);
    assert(bit::floor_log2(63u) == 5);
    assert(bit::ceil_log2(0u) == 0);
    assert(bit::ceil_log2(65u) == 7);
    assert(bit::next_power_of_two(0u) == 1);
    assert(bit::next_power_of_two(65u) == 128);
    assert(bit::previous_power_of_two(65u) == 64);
    assert(bit::previous_power_of_two(0u) == 0);

    assert(bit::mask_for_bits<std::uint8_t>(0) == 0);
    assert(bit::mask_for_bits<std::uint8_t>(4) == 0x0f);
    assert(bit::mask_for_bits<std::uint8_t>(8) == 0xff);
    assert(bit::mask_for_range<std::uint8_t>(2, 5) == 0x3c);
    assert(bit::mask_for_range<std::uint8_t>(-1, 2) == 0);
    assert(bit::extract_bits(0b11010110u, 2, 5) == 5);
    assert(bit::replace_bits(0b11000011u, 2, 5, 0b1010u) == 0b11101011u);
    assert(bit::replace_bits(0b11000011u, -1, 5, 0) == 0b11000011u);
}

void test_iteration_and_encodings() {
    std::vector<int> set_bit_indices;
    bit::for_each_set_bit(0b10110100u, [&](int index) {
        set_bit_indices.push_back(index);
    });
    assert((set_bit_indices == std::vector<int>{2, 4, 5, 7}));

    std::vector<unsigned> submasks;
    bit::for_each_submask(0b101u, [&](unsigned submask) {
        submasks.push_back(submask);
    });
    assert((submasks == std::vector<unsigned>{5, 4, 1, 0}));

    for (std::uint32_t value = 0; value < 1000; ++value) {
        assert(bit::inverse_gray_code(bit::gray_code(value)) == value);
    }
    assert(bit::rotate_left(std::uint8_t(0b10000001), 1) == 0b00000011);
    assert(bit::rotate_right(std::uint8_t(0b10000001), 1) == 0b11000000);
    assert(bit::reverse_bits(std::uint8_t(0b00010110)) == 0b01101000);
}

}  // namespace

int main() {
    test_bit_counts();
    test_set_bit_queries();
    test_powers_and_masks();
    test_iteration_and_encodings();
}