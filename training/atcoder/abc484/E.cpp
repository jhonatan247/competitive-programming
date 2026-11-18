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

#define F0R(i, a) for (int i=0; i<(a); i++)

#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

const char nl = '\n';

void solve() {
    _ll n, l, r;
    cin >> n >> l >> r;
    
    vector<_ll> arr(n);
    _ll sum = 0;
    F0R(i, n) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(all(arr));

    _ll ans = 0;
    _ll j = n - 1;

    debug(arr);

    F0R(i, n) {
        debug(sum, i, j, ans);
        if(sum < l) {
            sum -= arr[i];
            continue;
        }
        if(arr[i] > r) break;
        
        while(j > i and sum > r) {
            sum -= arr[j];
            j--;
        }
        
        ans += j - i + 1;
        sum -= arr[i];
    }

    cout << ans << nl;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int T = 1;
    #ifdef LOCAL
    debug_print("LOCAL_MULTI_TEST_CASE_WARNING");
    cin >> T;
    #endif

    while(T--) {
        solve();
        debug_print("TEST_CASE_DIV_LINE");
    }

    debug_print("EXECUTION_TIME");
    return 0;
}


