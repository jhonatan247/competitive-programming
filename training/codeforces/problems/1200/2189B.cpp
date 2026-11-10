#ifdef LOCAL
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

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    _ll n, x;
    cin >> n >> x;
    
    _vl a(n);
    _vl b(n);
    _vl c(n);
    
    _vl cnt(n, 0);
    _ll curr = 0;

    _ll best = LLONG_MIN;
    
    F0R(i, n) {
        cin >> a[i] >> b[i] >> c[i];
        cnt[i] = b[i] - 1;
        curr += a[i] * cnt[i];
        best = max(best, a[i] * b[i] - c[i]);
    }

    if(curr >= x) {
        cout << 0 << nl;
        return;
    }
    if(best <= 0) {
        cout << -1 << nl;
        return;
    }
    _ll ans = (x - curr + best - 1) / best;
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


