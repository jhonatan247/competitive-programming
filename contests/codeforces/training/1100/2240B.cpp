#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

#include "modular.h"

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

const _ll MOD7 = 1000000007;
const _ll MOD9 = 1000000009;
const _ll MOD = 998244353;

using Mint = Modular<std::integral_constant<decay<decltype(MOD)>::type, MOD>>;

void solve() {
    _ll n, m, r, c;
    cin >> n >> m >> r >> c;
    
    Mint base = 2;

    cout << power(base, n * m - (n - r + 1) * (m - c + 1)) << nl; 
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


