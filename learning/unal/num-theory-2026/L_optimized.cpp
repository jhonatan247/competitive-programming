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

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> arr(n);
    F0R(i, n) {
        cin >> arr[i];
    }
    
    sort(all(arr));

    _ll ans = 0;
    debug(arr);
    F0R(i, n) {
        int lo = lower_bound(arr.begin() + i + 1, arr.end(), l - arr[i]) - arr.begin();
        int hi = upper_bound(arr.begin() + i + 1, arr.end(), r - arr[i]) - arr.begin();
        debug(l - arr[i], r - arr[i]);
        debug(lo, hi);

        ans += hi - lo;
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


