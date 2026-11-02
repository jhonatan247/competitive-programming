#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

#include "algo/modular.h"

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

const _ll MX = 100001;

const _ll MOD7 = 1000000007;
const _ll MOD = MOD7;

using Mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

vector<int> sieve(int n) {
    vector<bool> is_prime((n / 2) + 1, true);
    vector<int> primes;
    if (n >= 2) primes.push_back(2);
    for (int i = 3; i * i <= n; i += 2) {
        if (is_prime[i / 2]) {
            for (int j = i * i; j <= n; j += 2 * i) {
                is_prime[j / 2] = false;
            }
        }
    }
    for (int i = 3; i <= n; i += 2) {
        if (is_prime[i / 2]) primes.push_back(i);
    }
    return primes;
}

void solve(_vi primes) {
    _ll n;
    cin >> n;
    
    int next_prime = 0;

    Mint ans = 0;
    _ll acc = 1;
    while(acc <= n) {
        _ll next_factor = -1;
        F0R(i, next_prime) {
            if(acc * primes[i] < acc * primes[next_prime]) {
                next_factor = primes[i];
                break;
            }
        }
        _ll next_acc
        if(next_factor == -1) {
            next_factor = primes[next_prime];
            next_prime++;
        }

    }

    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    _vi primes = sieve(MX);

    int T = 1;
    cin >> T;

    while(T--) {
        solve(primes);
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


