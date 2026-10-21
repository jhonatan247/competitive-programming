#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "local/debug.h"
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

typedef long long _ll;
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n;
    cin >> n;
    
    vector<_ll> a(n);
    F0R(i, n) {
        cin >> a[i];
    }
    
    _ll ans = a[0];
    _ll L = 0;
    _ll H = 0;
    F0R(i, n) {
        ans = max({ans, a[i] + H, a[i] - L});
        L = min({a[i], a[i] + 2 * L});
        H = max({a[i], a[i] + 2 * H});
    }

    cout << ans << nl;
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


