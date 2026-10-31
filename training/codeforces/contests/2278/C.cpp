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
    int n;
    cin >> n;
    
    vector<_ll> arr(n);
    bool ones_inside = true;
    _ll sum = 0;
    F0R(i, n) {
        cin >> arr[i];
        if(i and i < n - 1) ones_inside = ones_inside and arr[i] == 1;
        sum += arr[i];
    }

    bool one_left = arr[0] == 1;
    bool one_right = arr[n - 1] == 1;

    if(ones_inside and one_left and one_right) {
        cout << -1 << nl;
        return;
    }
    if(!ones_inside) {
        cout << sum - 1 << nl;
        return;
    }
    cout << arr[0] + arr[n - 1] - 1 << nl;
    
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


