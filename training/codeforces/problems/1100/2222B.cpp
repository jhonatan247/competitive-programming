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

_ll partition_sum(_vl &part, int cnt) {
    sort(all(part), greater<_ll>());
    _ll sum = 0;
    while(sz(part)) {
        if(part.back() < 0) {
            if(sz(part) == 1 and cnt) break;
            sum += part.back();
            part.pop_back();
        } else {
            if(sz(part) <= cnt) break;
            sum += part.back();
            part.pop_back();
        }
    }
    return sum;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    _vl odds;
    _vl evens;
    F0R(i, n) {
        int a;
        cin >> a;
        if((i + 1) % 2) {
            odds.pb(a);
        } else {
            evens.pb(a);
        }
    }

    int odd_cnt = 0;
    int even_cnt = 0;
    F0R(i, m) {
        int x;
        cin >> x;
        odd_cnt += x % 2;
        even_cnt += x % 2 == 0;
    }
    
    _ll ans = 0;
    ans += partition_sum(odds, odd_cnt);
    ans += partition_sum(evens, even_cnt);
    
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


