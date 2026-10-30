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

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(a) a.rbegin(), a.rend()
#define fill0(a) memset(a, 0, sizeof a)
#define fill(a, v) memset(a, v, sizeof a)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';

void solve() {
    int n;
    cin >> n;
    
    _vl L;
    _vl R;
    F0R(i, n) {
        _ll val;
        cin >> val;
        if(val > 0) {
            R.pb(val);
        } else {
            L.pb(val);
        }
    }

    sort(all(L));
    debug(L);
    sort(all(R), greater<_ll>());
    debug(R);

    _ll ans = 0;
    _ll pos = 0;
    while(sz(L) or sz(R)) {
        _ll next;
        if(sz(L) and sz(R)) {
            if(abs(L.back() - pos) <= abs(R.back() - pos)) {
                next = L.back();
                L.pop_back();
            } else {
                next = R.back();
                R.pop_back();
            }
        } else if(sz(L)) {
            next = L.back();
            L.pop_back();
        } else {
            next = R.back();
            R.pop_back();
        }
        ans += abs(next - pos);
        pos = next;
    }
    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    debug_print("LOCAL_MULTI_TEST_CASE_WARNING");
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


