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
    int n;
    cin >> n;
    
    vector<_ll> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    sort(all(arr));

    _ll curr = arr[0];
    _ll ans = 0;
    _ll cost = 0;
    _ll rsub = 0;
    
    FOR(i, 1, n) {
        if(arr[i] == curr) continue;
        if(i <= n / 2) {
            ans += (arr[i] - rsub) - curr;
            cost += i * ((arr[i] - rsub) - curr);
            rsub += (arr[i] - rsub) - curr;
        } else {
            ans += (arr[i] - rsub) - curr;
            cost += (n - i) * ((arr[i] - rsub) - curr) ;
            curr += (arr[i] - rsub) - curr;
        }
        debug(ans, curr, cost);
    }
    cout << cost << ' ' << ans << nl; 
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


