#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

// >>> ~/cp/library/algo/modular.h
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}
 
template <typename T>
class Modular {
    public:
    using Type = typename decay<decltype(T::value)>::type;
 
    constexpr Modular() : value() {}
    template <typename U>
    Modular(const U& x) {
        value = normalize(x);
    }
 
    template <typename U>
    static Type normalize(const U& x) {
        Type v;
        if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
        else v = static_cast<Type>(x % mod());
        if (v < 0) v += mod();
        return v;
    }
 
    const Type& operator()() const {
        return value; 
    }
    template <typename U>
    explicit operator U() const {
        return static_cast<U>(value); 
    }
    constexpr static Type mod() {
        return T::value; 
    }
 
    Modular& operator+=(const Modular& other) {
        value += other.value; value -= (value >= mod()) * mod(); return *this; 
    }
    Modular& operator-=(const Modular& other) {
        value -= other.value; value += (value < 0) * mod(); return *this; 
    }
    template <typename U> Modular& operator+=(const U& other) {
        return *this += Modular(other);
    }
    template <typename U> Modular& operator-=(const U& other) {
        return *this -= Modular(other);
    }
    Modular& operator++() {
        return *this += 1;
    }
    Modular& operator--() {
        return *this -= 1;
    }
    Modular operator++(int) {
        Modular result(*this); *this += 1; return result;
    }
    Modular operator--(int) {
        Modular result(*this); *this -= 1; return result;
    }
    Modular operator-() const {
        return Modular(-value);
    }
 
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
        return *this;
    }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
        int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
        value = normalize(int64_t(uint64_t(value) * uint64_t(rhs.value) - uint64_t(q) * uint64_t(mod())));
        return *this;
    }
    template <typename U = T>
    typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
        return *this;
    }
 
    Modular& operator/=(const Modular& other) {
        return *this *= Modular(inverse(other.value, mod()));
    }
 
    friend const Type& abs(const Modular& x) {
        return x.value;
    }
 
    template <typename U>
    friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
    template <typename U>
    friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
    template <typename V, typename U>
    friend V& operator>>(V& stream, Modular<U>& number);
 
    private:
    Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
    return lhs.value == rhs.value;
}
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) {
    return lhs == Modular<T>(rhs);
}
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) == rhs;
}
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) {
    return !(lhs == rhs);
}
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) {
    return !(lhs == rhs);
}
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
    return lhs.value < rhs.value;
}
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) += rhs;
}
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) += rhs;
}
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) -= rhs;
}
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) *= rhs;
}
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) {
    return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) {
    return Modular<T>(lhs) /= rhs;
}
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}
 
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
    return stream << number();
}
 
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}
 
// using ModType = int;
 
// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;
 
// constexpr int md = 998244353;
// using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
// <<< ~/cp/library/algo/modular.h
// >>> ~/cp/library/algo/bits.h
#include <bits/stdc++.h>
using namespace std;

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

// <<< ~/cp/library/algo/bits.h

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int x;
    cin >> x;
    
    int b = x % 11;
    if(x >= b * 111 and (x - b * 111) % 11 == 0) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


