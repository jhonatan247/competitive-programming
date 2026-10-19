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
    
    n++;

    vector<_ll> a(n);
    FOR (i, 1, n) {
        cin >> a[i];
    }
    vector<_ll> b(n);
    FOR (i, 1, n) {
        cin >> b[i];
    }
    
    debug(b);
    debug(a);

    FORd(i, 1, n) {
        debug(i);
        if(i == 1) {
            if(a[i] <= b[i]) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
            return;
        }
        if(a[i] <= b[i]) {
            a[i] = b[i];
            continue;
        }
        a[i - 1] += a[i] - b[i];
        a[i] = b[i];
        
        debug(a);
    }
    
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIVISION_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


