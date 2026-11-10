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
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define ins insert

const char nl = '\n';

_ll compute_group(_vi &arr) {
    if(!sz(arr)) return 0;

    int mid = sz(arr) / 2;
    int mid_pos = arr[mid];
    
    int start = mid_pos - mid;

    _ll cost = 0;
    F0R(i, sz(arr)) {
        _ll pos = start + i;
        if(i < mid) {
            cost += pos - arr[i];
        }
        if(i > mid) {
            cost += arr[i] - pos;        
        }
    }

    return cost;
}

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    _vi A;
    _vi B;
    F0R(i, n) {
        if(s[i] == 'a') {
            A.pb(i);
        } else {
            B.pb(i);
        }
    }

    _ll ans = min(compute_group(A), compute_group(B));
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


