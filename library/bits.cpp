// All functions assume unsigned 64-bit input unless noted.
// For 32-bit values, cast up: bit::popcount((unsigned long long)x).
// Functions marked UB require the precondition x != 0.

namespace bit {

	// ============================================================
	//  Population count
	// ============================================================

	// Number of set bits.
	inline int popcount(unsigned long long x) {
		return __builtin_popcountll(x);
	}

	// Same as popcount, but explicitly emits the hardware 'popcnt'
	// instruction. Safe on GCC 13+ (unlike the global target pragma).
	// Only worth calling in hot loops.
	__attribute__((target("popcnt")))
	inline int popcount_fast(unsigned long long x) {
		return __builtin_popcountll(x);
	}

	// ============================================================
	//  Bit scanning
	// ============================================================

	// Index of the lowest set bit (0-indexed). UB if x == 0.
	// Common idiom: i = bit::ctz(m); m &= m - 1;
	inline int ctz(unsigned long long x) {
		return __builtin_ctzll(x);
	}

	// Number of leading zeros. UB if x == 0.
	inline int clz(unsigned long long x) {
		return __builtin_clzll(x);
	}

	// 1-indexed position of the lowest set bit, or 0 if x == 0.
	// (Unlike ctz, this one is safe for x == 0.)
	inline int ffs(unsigned long long x) {
		return __builtin_ffsll(x);
	}

	// Parity of set bits: 1 if odd, 0 if even.
	inline int parity(unsigned long long x) {
		return __builtin_parityll(x);
	}

	// ============================================================
	//  Logs and powers of two
	// ============================================================

	// Number of bits needed to represent x: floor(log2(x)) + 1.
	// width(0) == 0.
	inline int width(unsigned long long x) {
		return x ? 64 - __builtin_clzll(x) : 0;
	}

	// floor(log2(x)). log2(0) == -1.
	inline int log2(unsigned long long x) {
		return x ? 63 - __builtin_clzll(x) : -1;
	}

	// ceil(log2(x)). ceil_log2(1) == 0, ceil_log2(2) == 1, ceil_log2(3) == 2.
	inline int ceil_log2(unsigned long long x) {
		return x <= 1 ? 0 : 64 - __builtin_clzll(x - 1);
	}

	// Is x a power of two? (x == 0 is not a power of two.)
	inline bool is_pow2(unsigned long long x) {
		return x && !(x & (x - 1));
	}

	// Smallest power of two >= x. next_pow2(0) == 1.
	inline unsigned long long next_pow2(unsigned long long x) {
		return x <= 1 ? 1 : 1ULL << ceil_log2(x);
	}

	// Largest power of two <= x. prev_pow2(0) == 0.
	inline unsigned long long prev_pow2(unsigned long long x) {
		return x ? 1ULL << log2(x) : 0;
	}

	// ============================================================
	//  Single-bit manipulation
	// ============================================================

	// Lowest set bit as a value, not an index. UB if x == 0.
	// Equivalent to x & -x.
	inline unsigned long long lowest(unsigned long long x) {
		return x & (~x + 1);
	}

	// Clear the lowest set bit. Iterate set bits with x &= clear_lowest(x).
	inline unsigned long long clear_lowest(unsigned long long x) {
		return x & (x - 1);
	}

	// Set the lowest unset bit.
	inline unsigned long long set_lowest_zero(unsigned long long x) {
		return x | (x + 1);
	}

	// ============================================================
	//  Bit reversal
	// ============================================================

	inline unsigned int reverse32(unsigned int x) {
		x = ((x >> 1)  & 0x55555555u) | ((x & 0x55555555u) << 1);
		x = ((x >> 2)  & 0x33333333u) | ((x & 0x33333333u) << 2);
		x = ((x >> 4)  & 0x0F0F0F0Fu) | ((x & 0x0F0F0F0Fu) << 4);
		x = ((x >> 8)  & 0x00FF00FFu) | ((x & 0x00FF00FFu) << 8);
		return (x >> 16) | (x << 16);
	}

	inline unsigned long long reverse64(unsigned long long x) {
		return ((unsigned long long)reverse32((unsigned int)x) << 32)
			|  reverse32((unsigned int)(x >> 32));
	}

} // namespace bit

