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
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    _ll n, m, k;
    cin >> n >> m >> k;
    
    n++;

    vector<_ll> arr(n);
    FOR(i, 1, n) {
        cin >> arr[i];
    }
    
    _vb ans(n, false);
    _vl psum(n, 0);

    _ll len = 0;
    
    debug(n, m, k);
    debug(arr);

    FOR(i, 1, n) {
        _ll next = psum[i - 1] + arr[i];
        debug(next, psum);
        if(next <= k) {
            psum[i] = next;
            ans[i] = true;
        } else {
            psum[i] = psum[i - 1];
        }
        len++;
        if(len >= m and ans[i - m + 1]) {
            psum[i] -= arr[i - m + 1];
            len--;
        }
    }

    FOR(i, 1, n) {
        if(ans[i]) {
            cout << "Yes" << nl;
        } else {
            cout << "No" << nl;
        }
    }
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


