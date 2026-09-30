#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#pragma GCC optimize ("O3")

#if defined(__x86_64__) || defined(__i386__)
    #pragma GCC target ("sse4")
#elif defined(__aarch64__)
    #pragma GCC target ("arch=armv8-a+crc")
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long _ll;
typedef unsigned long long _ull;
typedef long double _ld;

typedef __int128_t _i128;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;
const int MOD = 1000000007;

// Normalize x into the range [0, mod).
_ll norm_mod(_ll x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}
// (a + b) % MOD
_ll add_mod(_ll a, _ll b) {
    a = norm_mod(a);
    b = norm_mod(b);
    _ll res = a + b;
    if (res >= MOD) res -= MOD;
    return res;
}
// (a - b) % MOD
_ll sub_mod(_ll a, _ll b) {
    a = norm_mod(a);
    b = norm_mod(b);
    _ll res = a - b;
    if (res < 0) res += MOD;
    return res;
}
// (a * b) % MOD, safe against overflow using __int128.
_ll mul_mod(_ll a, _ll b) {
    a = norm_mod(a);
    b = norm_mod(b);
    return (_i128)a * b % MOD;
}
//  TODO: research
// base^exp % MOD using binary exponentiation.
_ll pow_mod(_ll base, _ll exp) {
    base = norm_mod(base);
    _ll result = 1 % MOD;
    while (exp > 0) {
        if (exp & 1) result = mul_mod(result, base);
        base = mul_mod(base, base);
        exp >>= 1;
    }
    return result;
}
// Modular inverse for prime modulus using Fermat's little theorem:
// a^(p-2) ≡ a^{-1} (mod p) for prime p and a not divisible by p.
_ll inv_mod_prime(_ll a) {
    a = norm_mod(a);
    if (a == 0) {
        throw invalid_argument("0 has no inverse modulo prime");
    }
    return pow_mod(a, MOD - 2);
}


void solve() {
   _ll n;
   cin >> n;

   _ll res = mul_mod(mul_mod(mul_mod(n, n - 1), n - 2), inv_mod_prime(6));
   cout << res << endl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
        #ifdef LOCAL
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef LOCAL
        cerr << endl << "finished in "
            << static_cast<double>(clock()) / CLOCKS_PER_SEC
            << " sec" << endl;
    #endif

    return 0;
}
