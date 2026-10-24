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
typedef unsigned _ui;

typedef vector<_ui> _vui;

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
    _ui n, k;
    cin >> n >> k;
    
    _vui A(n);
    F0R(i, n) {
        cin >> A[i];
    }

    map<_ui, _ui> prev;
    prev[0] = 0;
    _ui last = 0;
    _ui ans = 0;

    _vui P(n + 1);
    P[0] = 0;

    FOR(i, 1, n + 1) {
        P[i] = (P[i - 1] + A[i - 1]) % k;
        if(prev.count(P[i]) and prev[P[i]] >= last) {
            last = i;
            ans++;
        }
        prev[P[i]] = i;
    }

    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    #warning "LOCAL ONLY: reading T for multi-test"
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


