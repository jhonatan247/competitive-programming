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
#define F0Rd(i,a) for (_ll i = (a)-1; i >= 0; i--)
#define FOR(i, a, b) for (_ll i=a; i<(b); i++)
#define FORd(i,a,b) for (_ll i = (b)-1; i >= a; i--)
#define TRAV(a,x) for (auto& a : x)
#define TRAVd(a,x) for (auto a = x.rbegin(); a != x.rend(); ++a)

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
    int n, q;
    cin >> n >> q;
    
    map<int, _vpi> I;

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        
        I[x].pb(mp(r, l));
    }
    
    _vi ans(n + 2, 0);

    TRAV(e, I) {
        auto &intervals = e.sc;
        sort(all(intervals));
        while(sz(intervals)) {
            auto curr = intervals.back();
            intervals.pop_back();
            int r = curr.fr;
            int l = curr.sc;
            while(sz(intervals) and intervals.back().fr + 1 >= l) {
                l = min(l, intervals.back().sc);
                r = max(r, intervals.back().fr);
                intervals.pop_back();
            }
            ans[l]++;
            ans[r + 1]--;
        }
    }

    FOR(i, 1, n + 1) {
        ans[i] += ans[i - 1];
        if(i > 1) cout << ' ';
        cout << ans[i];
    }
    cout << nl;
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


