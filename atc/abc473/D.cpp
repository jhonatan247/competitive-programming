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
typedef complex<_ld> _cd;

typedef pair<int, int> _pi;
typedef pair<_ll,_ll> _pl;
typedef pair<_ld,_ld> _pd;

typedef vector<int> _vi;
typedef vector<bool> _vb;
typedef vector<string> _vs;
typedef vector<_ld> _vd;
typedef vector<_ll> _vl;
typedef vector<_cd> _vcd;
typedef vector<_pi> _vpi;
typedef vector<_pl> _vpl;

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void dfs(_vi & ans, int indx, int rem) {
    if(indx == sz(ans)) {
        if(rem % indx) return;

        ans[indx - 1] = rem / indx;
        F0R(i, sz(ans)) {
            if(i) cout << ' ';
            cout << ans[i];
        }
        cout << nl;
        return;
    }

    for(_ll m = 0; m * indx <= rem; m++) {
        ans[indx - 1] = m;
        dfs(ans, indx + 1, rem - indx * m);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    _vi ans = _vi(n, 0);

    dfs(ans, 1, k);

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


