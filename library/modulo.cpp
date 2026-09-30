#include <bits/stdc++.h>
using namespace std;

namespace modulo {

    using i64 = long long;
    using i128 = __int128_t;

    // ---------------------------------------------------------------------------
    // Basic modular operations
    // ---------------------------------------------------------------------------

    // Normalize x into the range [0, mod).
    i64 normalize_mod(i64 x, i64 mod) {
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }

    // (a + b) % mod
    i64 add_mod(i64 a, i64 b, i64 mod) {
        a = normalize_mod(a, mod);
        b = normalize_mod(b, mod);
        i64 res = a + b;
        if (res >= mod) res -= mod;
        return res;
    }

    // (a - b) % mod
    i64 sub_mod(i64 a, i64 b, i64 mod) {
        a = normalize_mod(a, mod);
        b = normalize_mod(b, mod);
        i64 res = a - b;
        if (res < 0) res += mod;
        return res;
    }

    // (a * b) % mod, safe against overflow using __int128.
    i64 mul_mod(i64 a, i64 b, i64 mod) {
        a = normalize_mod(a, mod);
        b = normalize_mod(b, mod);
        return (i128)a * b % mod;
    }
    
    //  TODO: research
    // base^exp % mod using binary exponentiation.
    i64 pow_mod(i64 base, i64 exp, i64 mod) {
        base = normalize_mod(base, mod);
        i64 result = 1 % mod;
        while (exp > 0) {
            if (exp & 1) result = mul_mod(result, base, mod);
            base = mul_mod(base, base, mod);
            exp >>= 1;
        }
        return result;
    }

    // ---------------------------------------------------------------------------
    // Modular inverse
    // ---------------------------------------------------------------------------

    // Extended Euclidean algorithm.
    // Returns gcd(a, b) and sets x, y such that a*x + b*y = gcd(a, b).
    i64 extended_gcd(i64 a, i64 b, i64 &x, i64 &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        i64 x1, y1;
        i64 g = extended_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return g;
    }

    // Modular inverse using extended Euclidean algorithm.
    // Returns x such that a * x ≡ 1 (mod mod).
    // Throws if inverse does not exist (i.e., gcd(a, mod) != 1).
    i64 inv_mod_extgcd(i64 a, i64 mod) {
        a = normalize_mod(a, mod);
        i64 x, y;
        i64 g = extended_gcd(a, mod, x, y);
        if (g != 1) {
            throw invalid_argument("modular inverse does not exist");
        }
        return normalize_mod(x, mod);
    }

    // Modular inverse for prime modulus using Fermat's little theorem:
    // a^(p-2) ≡ a^{-1} (mod p) for prime p and a not divisible by p.
    i64 inv_mod_prime(i64 a, i64 prime_mod) {
        a = normalize_mod(a, prime_mod);
        if (a == 0) {
            throw invalid_argument("0 has no inverse modulo prime");
        }
        return pow_mod(a, prime_mod - 2, prime_mod);
    }

    // Modular division: (a / b) % mod = a * b^{-1} % mod.
    // Works for any coprime b and mod.
    i64 div_mod(i64 a, i64 b, i64 mod) {
        return mul_mod(a, inv_mod_extgcd(b, mod), mod);
    }

    // ---------------------------------------------------------------------------
    // Combinatorics modulo a prime.
    // Precomputes factorials and inverse factorials up to max_n.
    // Requires mod to be prime and max_n < mod.
    // ---------------------------------------------------------------------------
    class ModCombinatorics {
    public:
        i64 mod;
        vector<i64> fact;
        vector<i64> inv_fact;

        ModCombinatorics(i64 mod, int max_n) : mod(mod), fact(max_n + 1), inv_fact(max_n + 1) {
            fact[0] = 1;
            for (int i = 1; i <= max_n; ++i) {
                fact[i] = mul_mod(fact[i - 1], i, mod);
            }
            inv_fact[max_n] = inv_mod_prime(fact[max_n], mod);
            for (int i = max_n; i >= 1; --i) {
                inv_fact[i - 1] = mul_mod(inv_fact[i], i, mod);
            }
        }

        // n choose r modulo mod
        i64 nCr(int n, int r) const {
            if (r < 0 || r > n) return 0;
            return mul_mod(fact[n], mul_mod(inv_fact[r], inv_fact[n - r], mod), mod);
        }

        // n permute r modulo mod
        i64 nPr(int n, int r) const {
            if (r < 0 || r > n) return 0;
            return mul_mod(fact[n], inv_fact[n - r], mod);
        }
    };

    // ---------------------------------------------------------------------------
    // Lucas theorem for nCr modulo a prime p.
    // Useful when n and r are large and p is small.
    // Precomputes factorials up to p-1.
    // ---------------------------------------------------------------------------
    class LucasCombinatorics {
    public:
        i64 prime_mod;
        vector<i64> fact;
        vector<i64> inv_fact;

        LucasCombinatorics(i64 prime_mod) : prime_mod(prime_mod), fact(prime_mod), inv_fact(prime_mod) {
            fact[0] = 1;
            for (i64 i = 1; i < prime_mod; ++i) {
                fact[i] = mul_mod(fact[i - 1], i, prime_mod);
            }
            inv_fact[prime_mod - 1] = inv_mod_prime(fact[prime_mod - 1], prime_mod);
            for (i64 i = prime_mod - 1; i >= 1; --i) {
                inv_fact[i - 1] = mul_mod(inv_fact[i], i, prime_mod);
            }
        }

        // Small nCr where n, r < prime_mod
        i64 nCr_small(i64 n, i64 r) const {
            if (r < 0 || r > n) return 0;
            return mul_mod(fact[n], mul_mod(inv_fact[r], inv_fact[n - r], prime_mod), prime_mod);
        }

        // nCr modulo prime_mod using Lucas theorem.
        i64 nCr(i64 n, i64 r) const {
            if (r < 0 || r > n) return 0;
            if (r == 0) return 1;
            // Lucas: nCr(n, r) ≡ nCr(n%p, r%p) * nCr(n/p, r/p) (mod p)
            return mul_mod(nCr_small(n % prime_mod, r % prime_mod),
                           nCr(n / prime_mod, r / prime_mod),
                           prime_mod);
        }
    };

    // ---------------------------------------------------------------------------
    // ModInt: a convenient wrapper for modular arithmetic with a fixed modulus.
    // The modulus must be provided as a template parameter.
    // ---------------------------------------------------------------------------
    template<i64 MOD>
    class ModInt {
        i64 value;
    public:
        ModInt() : value(0) {}
        ModInt(i64 v) : value(normalize_mod(v, MOD)) {}

        static ModInt raw(i64 v) {
            ModInt x;
            x.value = v;
            return x;
        }

        i64 val() const { return value; }

        ModInt operator+(const ModInt& other) const {
            return ModInt(add_mod(value, other.value, MOD));
        }
        ModInt operator-(const ModInt& other) const {
            return ModInt(sub_mod(value, other.value, MOD));
        }
        ModInt operator*(const ModInt& other) const {
            return ModInt(mul_mod(value, other.value, MOD));
        }
        ModInt operator/(const ModInt& other) const {
            return *this * other.inv();
        }

        ModInt& operator+=(const ModInt& other) {
            value = add_mod(value, other.value, MOD);
            return *this;
        }
        ModInt& operator-=(const ModInt& other) {
            value = sub_mod(value, other.value, MOD);
            return *this;
        }
        ModInt& operator*=(const ModInt& other) {
            value = mul_mod(value, other.value, MOD);
            return *this;
        }
        ModInt& operator/=(const ModInt& other) {
            *this *= other.inv();
            return *this;
        }

        ModInt pow(i64 exp) const {
            return ModInt(pow_mod(value, exp, MOD));
        }

        ModInt inv() const {
            return ModInt(inv_mod_extgcd(value, MOD));
        }

        bool operator==(const ModInt& other) const { return value == other.value; }
        bool operator!=(const ModInt& other) const { return value != other.value; }
    };

} // namespace modulo
