#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include <local/debug.h>
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef int64_t _ll;

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define nl endl

_ll ask(_ll a, _ll b) {
    cout << "? " << a << ' ' << b << nl;
    _ll ans;
    cin >> ans;
    return ans;
}

void ans(_ll a) {
    cout << "! " << a << nl;
}


void solve() {
    _ll r = 0;

    F0R(k, 30) {
        _ll pow2_k = 1LL << k;
        _ll pow2_k1 = 1LL << (k + 1);

        _ll a = pow2_k - r;
        _ll b = a + pow2_k1;

        _ll g = ask(a, b);

        if(g == pow2_k1) {
            r += pow2_k;
        }
    }

    ans(r);
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


