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

#define F0R(i, a) for (_ll i=0; i<(a); i++)
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    vector<_ll> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    vector<_ll> pmax(n);
    pmax[0] = arr[0];
    FOR(i, 1, n) {
        pmax[i] = max(pmax[i - 1], arr[i]);
        if(i % 2) arr[i] = pmax[i];
    }

    _ll ans = 0;
    F0R(i, n) {
        if(i % 2 == 0) {
            _ll a = INT_MAX, b = INT_MAX;
            if(i > 0) a = arr[i - 1];
            if(i < n - 1) b = arr[i + 1];
            if(arr[i] >= min(a, b)) {
                ans += arr[i] - min(a, b) + 1;
            }
        }
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


