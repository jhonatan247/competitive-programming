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
    int n, x1, x2, k;
    cin >> n >> x1 >> x2 >> k;
    
    if(n <= 3) {
        cout << 1 << nl;
        return;
    }
    
    if(x1 > x2) swap(x1, x2);
    
    assert(x1 < x2);

    int da = x2 - x1;
    int db = n - x2 + x1;
    
    assert(da < n and da >= 1);
    assert(db < n and db >= 1);

    cout << k + min(da, db) << nl;
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


