#ifdef LOCAL
    #define _GLIBCXX_DEBUG
    #include "local/debug.h"
#else
    #define debug(...) ((void)0)
    #define debug_print(...) ((void)0)
#endif

#include <bits/stdc++.h>
#include <cassert>

#include <atcoder/all>

using namespace std;

typedef long long _ll;
typedef long double _ld;

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';
const int MX = 100001;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    _ll x, y;
    cin >> x >> y;
    
    vector<int> a(n);
    F0R(i, n) {
        cin >> a[i];
    }
    
    vector<int> b(m);
    F0R(i, m) {
        cin >> b[i];
    }

    sort(all(a), greater<int>());
    sort(all(b), greater<int>());
    debug(a);
    debug(b);

    int ans = 0;

    debug(x, y);
    
    while(sz(a) and sz(b)) {
        int curra = sz(a) ? a.back() : INT_MAX;
        int currb = sz(b) ? b.back() : INT_MAX;
        if(currb <= curra and y * k >= currb) {
            int kbills = currb / k;
            if(currb % k != 0) kbills++;
            y -= kbills;
            x += kbills * k - currb;
            b.pop_back();
            ans++;
            debug(x, y);

        } else if(y * k + x >= curra) {
            int bills = x >= curra ? curra : x;
            int kbills = (curra - bills) / k;
            if((curra - bills) % k != 0) kbills++;
            x -= bills;
            y -= kbills;
            x += kbills * k - (curra - bills);
            a.pop_back();
            ans++;
            debug(x, y);
        } else {
            break;
        }
    }

    cout << ans << nl;
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


