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

typedef tuple<int,int,int> _ti;
typedef tuple<_ll,_ll,_ll> _tl;
typedef vector<_ti> _vti;
typedef vector<_tl> _vtl;

#define _fr(x) get<0>(x)
#define _sc(x) get<1>(x)
#define _th(x) get<2>(x)
#define _fo(x) get<3>(x)
#define mt(...) make_tuple(__VA_ARGS__)

#define F0R(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n;
    cin >> n;
    
    _vtl banks(n);
    F0R(i, n) {
        _ll fr, sc, th;
        cin >> fr >> sc >> th;
        banks[i] = mt(fr, sc, th);
    }

    debug(banks);

    F0R(i, n - 1) {
        auto curr = banks[i];
        FOR(j, i + 1, n) {
            auto next = banks[j];
            _ll x = _fr(curr)  - _fr(next);
            x *= x;

            _ll y = _sc(curr) - _sc(next);
            y *= y;

            _ll r = _th(curr) + _th(next);
            r *= r;

            _ll r_diff = _th(curr) - _th(next);
            r_diff *= r_diff;

            debug(x, y, r, r_diff);

            if(x + y <= r and x + y >= r_diff) {
                cout << "NO" << nl;
                return;
            }
        }
    }

    cout << "SI" << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


