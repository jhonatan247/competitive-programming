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

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

_ll parity_cost(const string& a, const string &b, bool parity) {
    _ll accum = 0, cost = 0;
    for(_ll i = parity; i < sz(a); i+=2) {
        accum += (a[i] == '1') - (b[i] == '1');
        cost += llabs(accum);
    }

    if(accum != 0) return -1;
    return cost;
}

void solve() {
    int n;
    cin >> n;
    
    string a, b;
    cin >> a >> b;
    
    _ll even_cost = parity_cost(a, b, 0);
    _ll odd_cost = parity_cost(a, b, 1);

    if(even_cost == -1 or odd_cost == -1) {
        cout << -1 << nl;
        return;
    }

    cout << even_cost + odd_cost << nl;
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


