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

typedef vector<_vi> _vvi;
typedef vector<_vb> _vvb;
typedef vector<_vs> _vvs;
typedef vector<_vd> _vvd;
typedef vector<_vl> _vvl;
typedef vector<_vcd> _vvcd;
typedef vector<_vpi> _vvpi;
typedef vector<_vpl> _vvpl;

typedef vector<_vvi> _vvvi;
typedef vector<_vvb> _vvvb;
typedef vector<_vvs> _vvvs;
typedef vector<_vvd> _vvvd;
typedef vector<_vvl> _vvvl;
typedef vector<_vvcd> _vvvcd;
typedef vector<_vvpi> _vvvpi;
typedef vector<_vvpl> _vvvpl;

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

bool half(_pl &point) {
    return point.sc > 0 or (point.sc == 0 and point.fr > 0);
}

_ll cross(_pl &a, _pl &b) { 
    return  a.fr * b.sc - a.sc * b.fr;
} 

bool comparator(_pl &a, _pl &b) {
    if(half(a) == half(b)) {
        return cross(a, b) > 0;
    }
    return half(a) > half(b);
};

void solve() {
    int n;
    cin >> n;
    
    vector<pair<_ll,_ll>> arr(n);
    F0R(i, n) {
        _ll fr, sc;
        cin >> fr >> sc;
        arr[i] = mp(fr, sc);
    }

    sort(all(arr), comparator);

    arr.reserve(n * 2);

    F0R(i, n) {
        arr.pb(arr[i]);
    }

    _ll ans = 1;
    
    _ll r = 1;
    F0R(l, n) {
        if(r <= l) r = l + 1;
        assert(l < r);
        while(true) {
            auto a = arr[l];
            auto b = arr[r];
            if(cross(a, b) > 0) r++;
            else break;
        }
        ans = max(ans, r - l);
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


