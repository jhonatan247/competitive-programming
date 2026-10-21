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
    int n, s;
    cin >> n >> s;
    s--;
    _ll l;
    cin >> l;
    
    vector<_ll> a(n - 1);
    F0R(i, n - 1) {
        cin >> a[i];
    }

    vector<_ll> d(n, 0);

    int mr = 0;
    FOR(i, s + 1, n) {
        d[i] = d[i - 1] + a[i - 1];
        if(d[i] <= l) mr++;
    }
    int ml = 0;
    F0Rd(i, s) {
        d[i] = d[i + 1] + a[i];
        if(d[i] <= l) ml++;
    }

    int maxd = max(ml, mr);


    FORd(w, maxd + 1, n) {
        for(int i = max(s - w + 1, 0); i < s and i + w < n; i++) {
            int r = i + w;
            if((2 * d[i] + d[r]) <= l or d[i] + 2 * d[r] <= l) {
                maxd = r - i;
                cout << maxd + 1 << nl;
                return;
            }
        }
    }
    
    cout << maxd + 1 << nl;

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


