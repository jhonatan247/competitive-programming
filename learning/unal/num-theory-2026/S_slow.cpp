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

_ll ans = LLONG_MAX;

void compute(_vi &arr, _vl& psum, int i, int k, _ll accum) {
    int n = sz(arr);
    if(i + k == n) {
        ans = min(ans, accum);
        return;
    }
    if(k == 0) {
        accum += psum[n - 1] - psum[i - 1];
        ans = min(ans, accum);
        return;
    }

    compute(arr, psum, i + 1, k, accum + abs(arr[i - 1] - arr[i]));

    compute(arr, psum, i + 1, k - 1, accum);
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    _vi arr(n);
    _vl psum(n, 0);
    F0R(i, n) {
        cin >> arr[i];
        if(i) {
            psum[i] = psum[i - 1] + abs(arr[i - 1] - arr[i]);
        }
    }
    
    ans = LLONG_MAX;
    compute(arr, psum, 1, k - 1, 0);
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


