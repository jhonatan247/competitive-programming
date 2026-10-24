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

#define F0R(i, a) for (_ll i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

int divCnt(int n) {
    int cnt = 0;
    for(_ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cnt ++;
            if(n / i != i) cnt++;
        }
    }
    return cnt;
}

void solve() {
    int x, y;
    cin >> x >> y;
    
    if(x == y) {
        cout << "1" << nl;
    } else {
        cout << divCnt(abs(x - y)) << nl;
    }

    F0R(i, x) {
        if(i) cout << ' ';
        cout << '1';
    }
    F0R(i, y) {
        if(x or i) cout << ' ';
        cout << "-1";
    }
    cout << nl;
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


