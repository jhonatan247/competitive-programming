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

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    vector<int> coins(3, 0);
    const int bill = 1000;
    const int coin100 = 100;
    const int coin10 = 10;
    F0R(i, n) {
        if(arr[i] % bill == 0) continue;
        int change = bill - arr[i] % bill;
        coins[2] += change / coin100;
        change %= coin100;
        coins[1] += change / coin10;
        change %= coin10;
        coins[0] += change;
        debug(coins);
    }

    F0R(i, sz(coins)) {
        if(i) cout << ' ';
        cout << coins[i];
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


